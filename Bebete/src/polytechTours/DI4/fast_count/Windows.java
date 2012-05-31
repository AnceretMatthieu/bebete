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
import java.util.Vector;
import java.util.zip.Inflater;

import polytechTours.DI4.R;
import polytechTours.DI4.GesionIdentification.FileManager;
import polytechTours.DI4.GesionIdentification.ReacherQR;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.AttributeSet;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.View.OnClickListener;
import android.widget.Gallery;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.ScrollView;

/** 
* @class Windows 
* @brief le Layout principal
*   
*/ 
public class Windows extends RelativeLayout implements OnClickListener
{
	private Context mContext;             
	private static Vector<String> listChemin = new Vector<String>();   
	private ScrollView s ;                              /**< le ScrollView ou on met des photos*/
	public String photoURL;                            /**< l'url des photos*/
	public RelativeLayout k;    /**< le Layout ou on met des photos*/
	private Activity activity;
	
	public void setActivity(Activity activity) {
		this.activity = activity;
	}

	public Windows(Context context) {
		super(context);
		mContext = context;
		try {
			setupViews();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	public Windows(Context context, AttributeSet attrs)  {
		super(context, attrs);
		mContext = context;
		try {
			setupViews();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	/**  
     * @brief mettre les photos dans le Layout K 
     *  
     */
	public void setupViews() throws FileNotFoundException{		
		 
		final LayoutInflater mLayoutInflater = LayoutInflater.from(getContext());
		View v = mLayoutInflater.inflate(R.layout.fast_count_gallery, null);		
		s = (ScrollView) v.findViewById(R.id.scrollView1);
		
		//lire les photos dans maps
		Map<String,Bitmap> maps = new TreeMap<String, Bitmap>();
		maps = buildThum();
		
		//base sur le nombre de photos,on crÃ©e un Layout k
		int li = listChemin.size()/6;
		int hi = 210*(li+1);
		
		k = new RelativeLayout(mContext);		
		RelativeLayout.LayoutParams rlp = new RelativeLayout.LayoutParams(1500,hi);
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
			image.setScaleType(ImageView.ScaleType.FIT_CENTER);
			image.setLayoutParams(new Gallery.LayoutParams(200, 200));
			image.setId(i++);
			image.setOnClickListener(this);
			Log.d("LOL", "Image correctement affiché" );
	        k.addView(image);			
		}
		addView(v); 
	}	
	
	/**  
     * @brief  lire l'image dans la structure map
     *  
     */	
	private Map<String,Bitmap> buildThum()
	{	
		Map<String,Bitmap> maps = new TreeMap<String, Bitmap>();
		
		ReacherQR reacher = new ReacherQR();
		listChemin = reacher.listeImageResultat();
		
		for( int i = 0; i < listChemin.size(); i++ )
		{
			Bitmap bitmap = BitmapFactory.decodeFile( FileManager.getSavePath() + File.separator + listChemin.get(i) );
			maps.put( listChemin.get(i), bitmap );
			Log.d("LOL", "chemin " + listChemin.get(i) );
		}
		return maps;
	}

	public void onClick(View v) 
	{
		String path = listChemin.get(v.getId());
		photoURL=path;			
		Log.d("LOL", "117 " + path );
		
		SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); 
        int piege_id = (int)preferences.getLong("PIEGE_ID", -1);
		
		Info info = new Info( path, piege_id );
		info.getId();
		
		FragmentManager manager = activity.getFragmentManager();
		Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
				
		if( fragmentEnCours != null )
		{
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.remove( fragmentEnCours );
			transaction.commit();
		}
		
		FragmentTransaction transaction = manager.beginTransaction();
			transaction.add( R.id.linearLayout2, info, "enCours" );
		transaction.commit();
	}
}
