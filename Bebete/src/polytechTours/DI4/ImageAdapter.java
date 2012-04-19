package polytechTours.DI4;

import android.content.Context;
import android.content.res.TypedArray;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Gallery;
import android.widget.ImageView;

public class ImageAdapter extends BaseAdapter 
{
	  int mGalleryItemBackground;
	  private Context mContext;

	    private Integer[] mImageIds = 
	    {
	            R.drawable.image1,
	            R.drawable.image2,
	            R.drawable.image3,
	            R.drawable.image4
	    };

	    public Integer[] getListImage()
	    {
	    	return mImageIds;
	    }
	    
	    public ImageAdapter(Context c) 
	    {
	        mContext = c;
	        TypedArray attr = mContext.obtainStyledAttributes(R.styleable.HelloGallery);
	        mGalleryItemBackground = attr.getResourceId(R.styleable.HelloGallery_android_galleryItemBackground, 0);
	        attr.recycle();
	    }

	    public int getCount() {
	        return mImageIds.length;
	    }
	    
	    public void setmImageIds(Integer[] mImageIds) {
			this.mImageIds = mImageIds;
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
	       
	        imageView.setImageResource(mImageIds[position]);
	        imageView.setLayoutParams(new Gallery.LayoutParams(280, 180));
	        imageView.setScaleType(ImageView.ScaleType.FIT_XY);
	        imageView.setBackgroundResource(mGalleryItemBackground);

	        return imageView;
	    }

}
