package polytechTours.DI4;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Vector;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Intent;
import android.hardware.Camera;
import android.hardware.Camera.PictureCallback;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.CompoundButton;
import android.widget.CompoundButton.OnCheckedChangeListener;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;


public class QuestionFragment extends Fragment implements OnClickListener, OnCheckedChangeListener
{
	private Camera mCamera;
	private CameraPreview mPreview;
	private FrameLayout preview;
	private BebeteActivity activity;
	private static boolean aquis = false;
	private int nbReponse;
	
	private Question currentQuestion;
	private Vector<Question> listQuestion = new Vector<Question>();
	
	
	public QuestionFragment( Question question )
	{
		currentQuestion = question;
		listQuestion.add(question);
	}
	
	//*************************************************************************************************************
	private PictureCallback mPicture = new PictureCallback()  
											{
												public void onPictureTaken(byte[] data, Camera camera)
												{
													Uri uri = MediaFile.getOutputMediaFileUri( MediaFile.MEDIA_TYPE_IMAGE );
													Intent mIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
													mIntent.putExtra( MediaStore.EXTRA_OUTPUT, uri );
													startActivityForResult(mIntent, 1);
													
											        /*File pictureFile = MediaFile.getOutputMediaFile( MediaFile.MEDIA_TYPE_IMAGE);
													
											        if (pictureFile == null)
											        {
											            Log.d("tag", "Error creating media file, check storage permissions: ");
											            return;
											        }
									
											        try 
											        {
											            FileOutputStream fos = new FileOutputStream(pictureFile);
											            fos.write(data);
											            fos.close();
											            Log.d("tag", "File created : " + pictureFile.getAbsolutePath() );
											        } catch (FileNotFoundException e) {
											            Log.d("tag", "File not found: " + e.getMessage());
											        } catch (IOException e) {
											            Log.d("tag", "Error accessing file: " + e.getMessage());
											        }*/
												}	
											};
	
	
	
	//******* Les méthodes sont dans l'ordre du cycle de vie d'un fragment pour plus de détails http://developer.android.com/guide/topics/fundamentals/fragments.html *********
	
    @Override
    public void onAttach(Activity activity)  
	{
        super.onAttach(activity);
        Log.d("QuestionFragment", "Fragment Attach" );
        aquis = false;
        this.activity = (BebeteActivity)activity;
        nbReponse = 6;
	}
    
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
    	super.onCreate(savedInstanceState);
    	Log.d("QuestionFragment", "Fragment Create" );
    	mCamera = getCameraInstance();
    }
	
    @Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {	
    	 Log.d("QuestionFragment", "Fragment CreateView" );
        // Inflate the layout for this fragment
        return inflater.inflate( R.layout.question, container, false); 
    }
	
	@Override
	public void onActivityCreated (Bundle savedInstanceState)
	{
		 super.onActivityCreated(savedInstanceState);
		 Log.d("QuestionFragment", "Fragment activityCreated" );
		 
		 //Setup UI here
		 changeUI();
		 
		 mPreview = new CameraPreview(activity.getApplicationContext(), mCamera);
		 preview = (FrameLayout) activity.findViewById( R.id.camera_preview);
		 
		 try
		 {
			 preview.addView(mPreview);	
		 }
		 catch (Exception e)
		 {
	        // Camera is not available (in use or does not exist)
	     }
		 
		 preview.setOnClickListener( this );	 
	}
	
	@Override
    public void onStart() 
    {
        super.onStart();
        Log.d("QuestionFragment", "Start QuestionFragent" );
        mCamera = getCameraInstance();
        mPreview = new CameraPreview(activity, mCamera); 
    }
    
    @Override
    public void onResume() 
    {
        super.onResume();
        Log.d("QuestionFragment", "Start QuestionFragent" );
        mCamera = getCameraInstance();
    }

    /*
     * Fragment's life
     */
    
	@Override
	public void onPause()
	{
	    super.onPause();
	    Log.d("QuestionFragment", "Pause QuestionFragment" );
	    releaseCamera();
	}
	
	 @Override
    public void onStop()
    {
    	super.onStop();
    	Log.d( "QuestionFragment", "Fragment Stop" );
    	releaseCamera();
    }
	
	@Override
	public void onDestroyView()
	{
		super.onDestroyView();
		Log.d( "QuestionFragment", "Fragment DestroyView" );
    	releaseCamera();
	}
	
	@Override
	public void onDestroy()
	{
		super.onDestroy();
		Log.d( "QuestionFragment", "Fragment Destroy" );
    	releaseCamera();
	}
	
	@Override
	public void onDetach()
	{
		super.onDetach();
		Log.d( "QuestionFragment", "Fragment Detach" );
    	releaseCamera();
	}
	 
    //********************************* Méthodes pratiques hors du cycle de vie du fragment *******************************************
    
    /** A safe way to get an instance of the Camera object. */
    public Camera getCameraInstance()
    {
    	if( !aquis )
    	{
    		Camera c = null;
	        try {
	            c = Camera.open(); // attempt to get a Camera instance
	            Camera.Parameters params = c.getParameters();
	    		params.setWhiteBalance( Camera.Parameters.WHITE_BALANCE_AUTO );
	    		params.setFocusMode(Camera.Parameters.FOCUS_MODE_AUTO);
	    		params.setAntibanding( Camera.Parameters.ANTIBANDING_AUTO );
	    		c.setParameters(params);
	    		aquis = true;
	        }
	        catch (Exception e){
	            // Camera is not available (in use or does not exist)
	        }
	        return c; // returns null if camera is unavailable
    	}
    	else
    	{
    		Log.d("Camera", "getCameraInstance camera non relaché" );
    		//Trouver pourquoi la veille fige l'image
    		mCamera.startPreview();
    		return mCamera;
    	}
    }
      
    private void releaseCamera()
    {
        if ( aquis )
        {
        	Log.d("Camera", "Release Camera" );
        	
        	mCamera.stopPreview();
            mCamera.release();        // release the camera for other applications

            aquis = false;
        }
    }

	public void onClick(View arg0) 
	{
		if( aquis )
		{
			mCamera.takePicture(null, null, mPicture);
			mCamera.startPreview();	
		}
	}

	public void onCheckedChanged(CompoundButton arg0, boolean arg1) 
	{
		if( arg1 == true )
		{
			//arg0.getText() <- boucler sur la liste des reponses pour retouver la selectionner
			Log.d( "CheckBox", "Check " + arg0.getText() );
			
		}
		
	}
	
	private void changeUI( )
	{	
		EditText texteQuestion = (EditText)activity.findViewById(R.id.question);
		texteQuestion.setText( currentQuestion.getQuestion() );
		
		EditText texteAide = (EditText)activity.findViewById(R.id.aide);
		texteAide.setText( currentQuestion.getAide() );
		
		ImageView image = (ImageView)activity.findViewById(R.id.imageQuestion );
		image.setImageResource( R.drawable.menu );
		
		Vector<Reponse> listRep = currentQuestion.getListReponse();
		
		LinearLayout layout = (LinearLayout)activity.findViewById( R.id.linearLayout3 );
				 
		for( int i = 0; i < listRep.size(); i++ )
		{
			LinearLayout innerLayout1 = new LinearLayout( activity );  // 1 Layout par Fragment !!!!!
			    innerLayout1.setLayoutParams(new LinearLayout.LayoutParams( ViewGroup.LayoutParams.FILL_PARENT, 180 ) );
			    innerLayout1.setId(0x116+i);
				 
			 FragmentTransaction transaction = activity.getFragmentManager().beginTransaction();
				transaction.setTransition(4097);
				transaction.add( 0x116+i, new ReponseFragment(this, listRep.get(i) ), "rep"+i );
			 transaction.commit();
			 
			 layout.addView(innerLayout1);
		}
	}
}
