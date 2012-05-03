package polytechTours.DI4;

import java.io.File;

import android.app.Activity;
import android.app.Dialog;
import android.app.Fragment;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Environment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemLongClickListener;
import android.widget.CheckBox;
import android.widget.Gallery;
import android.widget.ImageView;
import android.widget.TextView;

public class ReponseFragment extends Fragment implements OnItemLongClickListener, OnClickListener 
{	
	private Activity activity;
	private Dialog dialog;
	private QuestionFragment frag;
	private Reponse reponse;
	private boolean select;
	private int checkboxId;
	
	public ReponseFragment()
	{
		
	}
	
	public ReponseFragment( QuestionFragment frag, Reponse rep )
	{
		this.frag = frag;
		reponse = rep;
	}
	
	public ReponseFragment( QuestionFragment frag, Reponse rep, boolean select )
	{
		this.frag = frag;
		reponse = rep;
		this.select = select;
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
		//Setup UI here
		
		if( reponse != null )
		{
			Bitmap[] bitmaps = new Bitmap[reponse.getListeImage().size()];
			
			for( int i = 0; i < reponse.getListeImage().size(); i++ )
			{
				bitmaps[i] = BitmapFactory.decodeFile(Environment.getExternalStoragePublicDirectory(
						Environment.DIRECTORY_PICTURES) + File.separator + "Inno/" + reponse.getListeImage().get(i) );
			}
			reponse.setmImageIds(bitmaps);
			
			Gallery gallery = (Gallery)this.getView().findViewById(R.id.gallery1); // pour obtenir la gallerie relative a la question et pas toujours la memem commune connue de activity
			gallery.setOnItemLongClickListener(this);
			
			ImageAdapter adapter = new ImageAdapter( activity );
			adapter.setmImageIds(reponse.getmImageIds() );
			gallery.setAdapter( adapter );
			
			CheckBox box = (CheckBox)this.getView().findViewById( R.id.checkBox1 );
			box.setOnClickListener(frag);
	        box.setText( reponse.getReponse() );
	        checkboxId = box.getId();
	        
	        if( select )
	        {
	        	box.setChecked(true);
	        }
	        
	        TextView legende = (TextView)this.getView().findViewById( R.id.textView1 );
	        legende.setText( reponse.getLegende() );
		}
	}
	
	public int getCheckboxId()
	{
		return checkboxId;
	}
	
	public Reponse getReponse() {
		return reponse;
	}

	public void setReponse(Reponse reponse) {
		this.reponse = reponse;
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
		Bitmap resizedBitmap = Bitmap.createScaledBitmap(screenCap, 600, 375, false );
		screenCap.recycle();
		
		ImageView image = (ImageView) dialog.findViewById(R.id.image44);
		image.setImageBitmap( resizedBitmap );
		image.setOnClickListener(this);
		
		ImageView image2 = (ImageView) dialog.findViewById(R.id.image45);
		ImageAdapter imA = (ImageAdapter)arg0.getAdapter();
		image2.setImageBitmap( imA.getListImage()[(int)id] );
		image2.setOnClickListener(this);
		
		dialog.show();
	
		return true;
	}

}
