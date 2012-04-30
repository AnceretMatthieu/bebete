package polytechTours.DI4;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Vector;


import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentTransaction;
import android.graphics.BitmapFactory;
import android.hardware.Camera;
import android.hardware.Camera.PictureCallback;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;


public class QuestionFragment extends Fragment implements OnClickListener 
{
	private Camera mCamera;
	private CameraPreview mPreview;
	private FrameLayout preview;
	private BebeteActivity activity;
	private static boolean aquis = false;
	private ReacherQR reacher;
	
	private static Question currentQuestion;
	private static Vector<Question> listQuestion = new Vector<Question>();
	private static Vector<Reponse> listReponseChoisi = new Vector<Reponse>();
	private static Vector<ReponseFragment> listReponseFragment = new Vector<ReponseFragment>();
	private static int navigation;
	private ImageButton retour;
	private ImageButton suivant;
	
	public QuestionFragment()
	{
		reacher = new ReacherQR();
		Question question = reacher.getQuestionRoot();
		currentQuestion = question;
		listQuestion.add(question);
		navigation = 0;
	}
	
	//*************************************************************************************************************
	private PictureCallback mPicture = new PictureCallback()  
											{
												public void onPictureTaken(byte[] data, Camera camera)
												{
													/*Uri uri = MediaFile.getOutputMediaFileUri( MediaFile.MEDIA_TYPE_IMAGE );
													Intent mIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
													mIntent.putExtra( MediaStore.EXTRA_OUTPUT, uri );
													startActivityForResult(mIntent, 1);*/
													
											        File pictureFile = MediaFile.getOutputMediaFile( MediaFile.MEDIA_TYPE_IMAGE);
													
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
											        }
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
		 retour = (ImageButton)activity.findViewById(R.id.histo_gauche);
		 retour.setOnClickListener( this );
		 suivant = (ImageButton)activity.findViewById(R.id.histo_droite);
		 suivant.setOnClickListener( this );
			
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
		boolean checkBox = false;
		
		for( int i = 0; i < listReponseFragment.size(); i++ )
		{
			Log.d("ID", "arg0 : " + arg0.getId() + " listRep : " + listReponseFragment.get(i).getCheckboxId()  );
			if( arg0.getId() == listReponseFragment.get(i).getCheckboxId() )
			{
				CheckBox ch = (CheckBox)arg0;
				
				if( ch.getText() == listReponseFragment.get(i).getReponse().getReponse() )
				{
					checkBox = true;
					Reponse reponse = listReponseFragment.get(i).getReponse();
					
					if( !reponse.getIdQuestionSuivante().equalsIgnoreCase("") )
					{
						if( navigation == listQuestion.size()-1 ) //Si c'est une nouvelle question
						{
							Log.d("Historique", "Nouvelle question créer");
							listReponseChoisi.add( reponse );
							currentQuestion = reacher.findQuestionById( reponse.getIdQuestionSuivante() );
							listQuestion.add( currentQuestion );  //Rajout dans l'historique de la question 
						}
						else 
						{
							if( reponse.getId() == listReponseChoisi.get( navigation ).getId() )//Si on a choisie la meme reponse
							{
								Log.d("Historique", "Même réponse selectionner id = " +  reponse.getId() );
								currentQuestion = listQuestion.get(navigation+1);
							}
							else
							{
								Log.d("Historique", "Question différente selectionné");
								
								for( int k = navigation; k < listReponseChoisi.size(); k++ )//nettoie la liste des reponses depuis la question changé
								{
									listReponseChoisi.remove(k);
								}
								
								listReponseChoisi.add(reponse);
								
								for( int k = navigation+1; k < listQuestion.size(); k++ )
								{
									listQuestion.remove(k);
								}
	
								currentQuestion = reacher.findQuestionById( reponse.getIdQuestionSuivante() );
								listQuestion.add( currentQuestion );
							}
						}
						
						navigation++;
						
						Log.d("Navigation", "nav = " + navigation );
						if( navigation > 0 )
						{
							retour.setEnabled(true);
						}
						else
						{
							retour.setEnabled(false);
						}
						if( navigation < listQuestion.size()-1 )
						{
							suivant.setEnabled(true);
						}
						else
						{
							suivant.setEnabled(false);
						}
						
						changeUI();
					}
					else
					{
						//Afficher la morphoo espece trouvé
					}
				}
			}
		}
		
		if( !checkBox )
		{
			if( arg0.getId() == retour.getId() ) //Retour cliqué dans l'historique
			{
				navigation--;
				
				if( navigation == 0 )
				{
					retour.setEnabled(false);
				}
				if( navigation < listQuestion.size()-1 )
				{
					suivant.setEnabled(true);
				}
				changeUIviaHisto();
			}
			else if( arg0.getId() == suivant.getId() )
			{
				navigation++;
				
				if( navigation == listQuestion.size()-1 )
				{
					suivant.setEnabled(false);
				}
				if( navigation > 0 )
				{
					retour.setEnabled(true);
				}
				changeUIviaHisto();
			}
			else if( aquis )
			{
				mCamera.takePicture(null, null, mPicture);
				mCamera.startPreview();	
			}
		}
	}

	private void changeUI( )
	{	
		EditText texteQuestion = (EditText)activity.findViewById(R.id.question);
		texteQuestion.setText( currentQuestion.getQuestion() );
		
		EditText texteAide = (EditText)activity.findViewById(R.id.aide);
		texteAide.setText( currentQuestion.getAide() );
		if( currentQuestion.getAide() == "" )
		{
			texteAide.setVisibility(EditText.INVISIBLE);
		}
		else
		{
			texteAide.setVisibility(EditText.VISIBLE);
		}
		
		ImageView image = (ImageView)activity.findViewById(R.id.imageQuestion );
		image.setImageBitmap( BitmapFactory.decodeFile(Environment.getExternalStoragePublicDirectory(
					Environment.DIRECTORY_PICTURES) + File.separator + "Inno/" + currentQuestion.getCheminImage() )  );
		
		if( currentQuestion.getCheminImage() == "" )
		{
			image.setVisibility(ImageView.INVISIBLE);
		}
		else
		{
			image.setVisibility(ImageView.VISIBLE);
		}
		
		//Ajout des reponses dynamiquement
		Vector<Reponse> listRep = currentQuestion.getListReponse();
		
		LinearLayout layout = (LinearLayout)activity.findViewById( R.id.linearLayout3 );
		layout.removeAllViews();
		listReponseFragment.clear();
		
		for( int i = 0; i < listRep.size(); i++ )
		{
			LinearLayout innerLayout1 = new LinearLayout( activity );  // 1 Layout par Fragment !!!!!
			    innerLayout1.setLayoutParams(new LinearLayout.LayoutParams( ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT ) );
			    innerLayout1.setId(0x116+i);
				
			 boolean select = false;
			 
			 if( navigation != listQuestion.size()-1 )
			 {
				 Reponse repSelectionner = listReponseChoisi.get(navigation);
				 if( repSelectionner == listRep.get(i) )
				 {
					 select = true;
				 }
			 }
			    
			 FragmentTransaction transaction = activity.getFragmentManager().beginTransaction();
				transaction.setTransition(4097);
				ReponseFragment rep = new ReponseFragment(this, listRep.get(i), select );
				listReponseFragment.add( rep );
				transaction.add( 0x116+i, rep, "rep"+i );
			 transaction.commit();
			 
			 layout.addView(innerLayout1);
		}
	}
	
	private void changeUIviaHisto()
	{
		currentQuestion = listQuestion.get(navigation);
		changeUI();
	}
}
