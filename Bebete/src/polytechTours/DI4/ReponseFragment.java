package polytechTours.DI4;

import java.io.File;

import android.app.Activity;
import android.app.Dialog;
import android.app.Fragment;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemLongClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Gallery;
import android.widget.ImageView;

public class ReponseFragment extends Fragment implements OnItemLongClickListener, OnClickListener 
{	
	private Activity activity;
	private Dialog dialog;
	private QuestionFragment frag;
	private Reponse reponse;
	
	public ReponseFragment()
	{	
	}
	
	public ReponseFragment( QuestionFragment frag, Reponse rep )
	{
		this.frag = frag;
		reponse = rep;
	}
	
	@Override
    public void onAttach(Activity activity)  
	{
        super.onAttach(activity);
        this.activity = activity;
	}
	
	@Override
	public void onActivityCreated (Bundle savedInstanceState)
	{
		super.onActivityCreated(savedInstanceState);
		
		Gallery gallery = (Gallery)this.getView().findViewById(R.id.gallery1); // pour obtenir la gallerie relative a la question et pas toujours la memem commune connue de activity
		gallery.setOnItemLongClickListener(this);
		
		ImageAdapter adapter = new ImageAdapter( activity );
		adapter.setmImageIds(reponse.getmImageIds() );
		gallery.setAdapter( adapter );
		
		//Setup UI here
		CheckBox box = (CheckBox)this.getView().findViewById( R.id.checkBox1 );
        box.setOnCheckedChangeListener(frag);
	}
	
	@Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {		
        return inflater.inflate( R.layout.reponse, container, false); 
    }

	public void onClick(View arg0) 
	{
		ImageView image = (ImageView) dialog.findViewById(R.id.image44);
		image.destroyDrawingCache();
		dialog.dismiss();
	}

	public boolean onItemLongClick(AdapterView<?> arg0, View arg1, int arg2, long id)
	{
		dialog = new Dialog( activity );
		dialog.setOwnerActivity(activity);
	       
		dialog.setContentView(R.layout.custom_dialog);
		dialog.setTitle("Comparaison");
		dialog.setCancelable(true);
		dialog.setCanceledOnTouchOutside(true);
		
		Bitmap screenCap = BitmapFactory.decodeFile(Environment.getExternalStoragePublicDirectory(
				Environment.DIRECTORY_PICTURES) + File.separator + "Inno/temp.jpg" );
		
		int width = screenCap.getWidth();
		int height = screenCap.getHeight();
		float scaleWidth = ((float) 550) / width;
		float scaleHeight = ((float) 550) / height;

		// CREATE A MATRIX FOR THE MANIPULATION

		Matrix matrix = new Matrix();

		// RESIZE THE BIT MAP

		matrix.postScale(scaleWidth, scaleHeight);

		// RECREATE THE NEW BITMAP
		Bitmap resizedBitmap = Bitmap.createBitmap(screenCap, 0, 0, width, height, matrix, false);
		screenCap.recycle();
		
		ImageView image = (ImageView) dialog.findViewById(R.id.image44);
		image.setImageBitmap( resizedBitmap );
		image.setOnClickListener(this);
		
		ImageView image2 = (ImageView) dialog.findViewById(R.id.image45);
		ImageAdapter imA = (ImageAdapter)arg0.getAdapter();
		image2.setImageResource( imA.getListImage()[(int)id] );
		image2.setOnClickListener(this);
		
		dialog.show();
	
		return true;
	}

}
