package polytechTours.DI4.fast_count;
/** 
* @file Windows.java 
* @brief  le Layout principal
* @author zhangzheng
* @date 2012/5/30  
* @version 0.1 
*/ 
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

import polytechTours.DI4.R;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Gallery;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.ScrollView;

/** 
* @class Windows 
* @brief le Layout principal
*   
*/ 
public class Windows extends RelativeLayout {

	private Context mContext;             
	private static ArrayList<String> paths = new ArrayList<String>();   /**< le path des photos*/
	private ScrollView s ;                              /**< le ScrollView ou on met des photos*/
	
	public String photoURL;                            /**< l'url des photos*/
	public RelativeLayout k;                            /**< le Layout ou on met des photos*/
	
	public Windows(Context context) {
		super(context);
		mContext = context;
		setupViews();
		
	}

	public Windows(Context context, AttributeSet attrs)  {
		super(context, attrs);
		mContext = context;
		setupViews();
		
	}
	/**  
     * @brief mettre les photos dans le Layout K 
     *  
     */
	public void setupViews(){		
		
		final LayoutInflater mLayoutInflater = LayoutInflater.from(getContext());
		View v = mLayoutInflater.inflate(R.layout.fast_count_gallery, null);		
		s=  (ScrollView) v.findViewById(R.id.scrollView1);
		
		//lire les photos dans maps
		Map<String,Bitmap> maps = new TreeMap<String, Bitmap>();
		try {
			maps = buildThum();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		//base sur le nombre de photos,on crée un Layout k
		int li=paths.size()/6;
		int hi=210*(li+1);
		
		 k=new RelativeLayout(mContext);		
		RelativeLayout.LayoutParams  rlp = new RelativeLayout.LayoutParams(1500,hi);
		k.setLayoutParams(rlp);
		
		
		//on ajouter l'image dans Layout k
		Iterator<String> it = maps.keySet().iterator();
		int i = 0;	
		
		while (it.hasNext()) {
			String path = (String) it.next();  
			Bitmap bm = maps.get(path);  			
			
			//imageView pour mettre un photo
			ImageView image = new ImageView(mContext);
			
			// la taille d'imageView
			image.setAdjustViewBounds(true);
			image.setMaxHeight(200);
			image.setMaxWidth(200);
			
			// le position d'image
			int line=i/6;
			int colone=i-line*6;
			image.setX(215*colone);
			image.setY(210*line);			
			
			image.setImageBitmap(bm);
			image.setScaleType(ImageView.ScaleType.FIT_XY);
			image.setLayoutParams(new Gallery.LayoutParams(200, 200));
			image.setId(i++);
			
	        k.addView(image);			
			image.setOnTouchListener(listener);
		}
		
		addView(v);
	}	
	/**  
     * @brief quand on touche l'image,on transmet l'url d'image a photoURL 
     *  
     */
	OnTouchListener listener = new OnTouchListener() {
		public boolean onTouch(View v, MotionEvent event) {			
			
			if(event.getAction() == MotionEvent.ACTION_DOWN){
				String path = paths.get(v.getId());
				photoURL=path;				
			}
			return false;
		}
	};
	/**  
     * @brief   get Absolute Path
     *  
     */	
	private static ArrayList<String> imagePath(File file) {
		ArrayList<String> list = new ArrayList<String>();

		File[] files = file.listFiles();
		for (File f : files) {
			list.add(f.getAbsolutePath());
		}
		Collections.sort(list);
		return list;
	}

	/**  
     * @brief  lire l'image dans la structure map
     *  
     */	
	private Map<String,Bitmap> buildThum() throws FileNotFoundException {
		
		//le path des images
		File baseFile = new File("/sdcard/Pictures/Inno");		
		Map<String,Bitmap> maps = new TreeMap<String, Bitmap>();
		
		if (baseFile != null && baseFile.exists()) {
			paths = imagePath(baseFile);

			if (!paths.isEmpty()) {				
				
				for (int i = 0; i < paths.size(); i++) {
					
					String fName=paths.get(i).toString();
					String end = fName.substring(fName.lastIndexOf(".") + 1, fName.length()).toLowerCase();
				//si la format du ficher est jpg,gif,png,jpeg,bmp, on le met dans la structure map
				 if (end.equals("jpg") || end.equals("gif") || end.equals("png")  || end.equals("jpeg") || end.equals("bmp"))
					 {
					 BitmapFactory.Options options = new BitmapFactory.Options();
					 options.inJustDecodeBounds = true;
					 Bitmap bitmap =BitmapFactory.decodeFile(paths.get(i),options);
					 
					 options.inJustDecodeBounds = false;
					 int be = options.outHeight/100;
					 if (be <= 0) {  be = 10;  }
					 
					 options.inSampleSize = be;
					 bitmap = BitmapFactory.decodeFile(paths.get(i),options);
					 maps.put(paths.get(i), bitmap);}
					 
				}
			}
		}

		return maps;
	}
}
