package polytechTours.DI4.GesionIdentification;

import polytechTours.DI4.R;
import polytechTours.DI4.R.styleable;
import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Bitmap;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Gallery;
import android.widget.ImageView;

/**
 * Classe gérant le moteur de la galerie d'image, tiré de la documentation Android et adpaté pour fonctionner avec des Bitmaps
 * Voir : http://developer.android.com/resources/tutorials/views/hello-gallery.html
 * Attention à l'utilisation de Bitmaps, il est nécessaire de les libérer (recycle) dès que possible, des dépassements mémoires
 * apparaissent très vite
 */
public class ImageAdapter extends BaseAdapter 
{
	  int mGalleryItemBackground;
	  private Context mContext;
	  private Bitmap[] bitmaps;

	  /**
	   * Fonction rajouté pour libérer tous les bitmaps avant de tuer la gallery
	   * Finalize -> "destructeur java" 
	   */
	  public void finalize()
	  {
		  for( int i = 0; i < bitmaps.length; i++ )
		  {
			  bitmaps[i].recycle();
		  }
	  }
	  
	    public ImageAdapter(Context c) 
	    {
	        mContext = c;
	        TypedArray attr = mContext.obtainStyledAttributes(R.styleable.HelloGallery);
	        mGalleryItemBackground = attr.getResourceId(R.styleable.HelloGallery_android_galleryItemBackground, 0);
	        attr.recycle();
	    }
	    
	    public Bitmap[] getListImage()
	    {
	    	return bitmaps;
	    }

	    public int getCount() {
	        return bitmaps.length;
	    }
	    
	    public void setmImageIds(Bitmap[] mImageIds) {
			this.bitmaps = mImageIds;
		}
	    
	    public Object getItem(int position) {
	        return position;
	    }

	    public long getItemId(int position) {
	        return position;
	    }

	    public View getView(int position, View convertView, ViewGroup parent)
	    {
	        ImageView imageView = new ImageView(mContext);
	        
	        imageView.setImageBitmap( bitmaps[position] );
	        imageView.setLayoutParams(new Gallery.LayoutParams(250, 200));
	        imageView.setScaleType(ImageView.ScaleType.CENTER_INSIDE);
	        imageView.setBackgroundResource(mGalleryItemBackground);

	        return imageView;
	    }

}
