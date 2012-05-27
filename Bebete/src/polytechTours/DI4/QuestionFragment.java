package polytechTours.DI4;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.sql.Timestamp;
import java.util.Date;
import java.util.Vector;


import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.Fragment;
import android.app.FragmentTransaction;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.hardware.Camera;
import android.hardware.Camera.PictureCallback;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.IBinder;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.Gallery;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

public class QuestionFragment extends Fragment implements OnClickListener 
{
	private Camera mCamera;
	private CameraPreview mPreview;
	private FrameLayout preview;
	private BebeteActivity activity;
	private static boolean aquis = false;
	private ReacherQR reacher;
	private Dialog dialog;
	private Dialog dialogAlerte;
	
	private static Question currentQuestion;
	private Vector<Question> listQuestion = new Vector<Question>();
	private Vector<Reponse> listReponseChoisi = new Vector<Reponse>();
	private Vector<ReponseFragment> listReponseFragment = new Vector<ReponseFragment>();
	private int navigation;
	private ImageButton retour;
	private ImageButton suivant;
	private ImageButton alerte;
	private Button boutonEnregistrer;
	private Button boutonAnnuler;
	private Button boutonSubmit;
	private Button boutonAnnulerAlerte;
	private Resultat resultat;
	private boolean dialogVisible;
	private boolean dialogAlerteVisible;
	
	public QuestionFragment()
	{
		reacher = new ReacherQR();
		Question question = reacher.getQuestionRoot();
		currentQuestion = question;
		listQuestion.add(question);
		navigation = 0;
		dialogVisible = false;
		dialogAlerteVisible = false;
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
		 retour.setVisibility(ImageButton.VISIBLE);
		 retour.setEnabled(false);
		 suivant = (ImageButton)activity.findViewById(R.id.histo_droite);
		 suivant.setOnClickListener( this );
		 suivant.setVisibility(ImageButton.VISIBLE);
		 suivant.setEnabled(false);
		 alerte = (ImageButton)activity.findViewById(R.id.imageAlerte );
		 alerte.setVisibility(ImageView.VISIBLE);
		 alerte.setOnClickListener(this);
		 
		 //changeUI();
		 
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
    }
    
    @Override
    public void onResume() 
    {
        super.onResume();
        Log.d("QuestionFragment", "Resume QuestionFragent" );
        mCamera = getCameraInstance();
        mPreview.update(mCamera);
        changeUI();
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
	    
	    FragmentTransaction transaction = activity.getFragmentManager().beginTransaction();
			for( int i = 0; i < listReponseFragment.size(); i++ )
			{
				transaction.remove( listReponseFragment.get(i) );
			}
		transaction.commit();
	}
	
	@Override
	public void onDetach()
	{
		super.onDetach();
		Log.d( "QuestionFragment", "Fragment Detach" );
    	//releaseCamera();
    	retour.setVisibility(ImageButton.INVISIBLE);
    	suivant.setVisibility(ImageButton.INVISIBLE);
    	alerte.setVisibility(ImageButton.INVISIBLE);
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
	    		mCamera.startPreview();
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
						Log.d("Affichage Resultat", "Le resultat doit s'afficher");
						resultat = reponse.getResultat();
						afficherResultat( resultat );
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
			else if( arg0.getId() == suivant.getId() )  //Suivant cliqué dans l'historique
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
			else if( dialogVisible && arg0.getId() == boutonAnnuler.getId() )  //Annuler cliqué dans le dialog de resultat
			{
				dialogVisible = false;
				dialog.dismiss();
			}
			else if( dialogVisible && arg0.getId() == boutonEnregistrer.getId() ) //Enregistrer clique dans le dialog de resultat
			{
				SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
		        
				//*************Code temporaire*****************************************
				int piegeID = (int)preferences.getLong("PIEGE_ID", -1);
		        //int piegeID = 117;
		        //*********************************************************************
				
		        RecolteBDD bdd = new RecolteBDD(activity.getApplicationContext());
		        bdd.open();
		        Recolte recolte = bdd.getRecolteWithNOM( resultat.getNom() );
		        
		        if( recolte == null )
		        {
		        	recolte = new Recolte();
		        	recolte.setNom(resultat.getNom());
		        }
		        
		        recolte.setPege_id( piegeID );
		        recolte.setNombre( recolte.getNombre() + 1 );
		        bdd.insinsertOrUpdateRecolte( recolte.getId(), recolte );
		        bdd.close();
		        
		        Log.d("Resultat", "Bete : " + recolte.getNom() + " nombre : " + recolte.getNombre() );
		        
		        dialog.dismiss();
		        dialogVisible = false;
		        
			}
			else if( arg0.getId() == alerte.getId() )
			{
				if( !dialogAlerteVisible )
				{
					afficherAlerte();
				}
			}
			else if( dialogAlerteVisible && arg0.getId() ==  boutonAnnulerAlerte.getId() ) //Bouton annuler cliqué sur le dialog alerte
			{
				dialogAlerte.dismiss();
				dialogAlerteVisible = false;
			}
			else if( dialogAlerteVisible && arg0.getId() == boutonSubmit.getId() )   //Bouton submit cliqué sur le dialog alerte
			{
				EditText detail = (EditText)dialogAlerte.findViewById(R.id.detail);
				Date date = new Date();				
				
				if( detail.getText().length() != 0 )
				{
					File rapport = new File(Environment.getExternalStorageDirectory(), "Innophyt" + File.separator + "Incident");
					if (!rapport.exists()) 
					{
	                    if (!rapport.mkdirs()) 
	                    {
	                            Log.d("FileManager", "Cannot create directory: " + rapport.toString());
	                    }
					}
	
	                Bitmap bitmap;
	                View v1 = getView(); 
	                v1.setDrawingCacheEnabled(true);
	                bitmap = Bitmap.createBitmap(v1.getDrawingCache());
	                v1.setDrawingCacheEnabled(false);
	
	                File rapportFile = new File( rapport.getPath() + File.separator + "Incident" + date.getTime() + ".txt" );
	                File imageFile = new File( rapport.getPath() + File.separator + "Incident" + date.getTime() +".jpg"  );
	                
	                try 
	                {
						FileOutputStream fo = new FileOutputStream( rapportFile );
						FileOutputStream fos = new FileOutputStream(imageFile);
						
						try 
						{	
							fo.write( new String("********* " + date.toString() + " **********\n" ).getBytes() );
							fo.write( detail.getText().toString().getBytes() );
							fo.write( new String("\n" ).getBytes() );
							fo.write( new String("********************************************\n" ).getBytes() );
							
							fo.close();

		                	ByteArrayOutputStream fout = new ByteArrayOutputStream();
		                    bitmap.compress(Bitmap.CompressFormat.JPEG, 90, fout);
		                    
		                    fos.write( fout.toByteArray() );
		                    fos.close();
							
							MediaScannerConnection.scanFile(activity, new String[] { rapportFile.toString() }, null, new MediaScannerConnection.OnScanCompletedListener() 
		                    {
		                        public void onScanCompleted(String path, Uri uri) 
		                        {
		                            Log.d("ExternalStorage", "Scanned " + path + ":");
		                            Log.d("ExternalStorage", "-> uri=" + uri);
		                        }
		                    }
		                    );
							
							MediaScannerConnection.scanFile(activity, new String[] { imageFile.toString() }, null, new MediaScannerConnection.OnScanCompletedListener() 
		                    {
		                        public void onScanCompleted(String path, Uri uri) 
		                        {
		                            Log.d("ExternalStorage", "Scanned " + path + ":");
		                            Log.d("ExternalStorage", "-> uri=" + uri);
		                        }
		                    }
		                    );
						}
						catch (IOException e)
						{
							e.printStackTrace();
						}
					} 
	                catch (FileNotFoundException e1) 
	                {
	                	e1.printStackTrace();
					}
	                
	                bitmap.recycle();
				}
				else
				{
					AlertDialog.Builder builder = new AlertDialog.Builder(activity.getApplicationContext());
					builder.setMessage("Veuillez décrire votre problème")
						.setCancelable(false)
						.setPositiveButton("Ok", new DialogInterface.OnClickListener() 
													  {
															public void onClick(DialogInterface dialog, int id) 
															{
																//this.dismiss();
															}
													  });
					AlertDialog alert = builder.create();
				}
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
			texteAide.setVisibility(EditText.GONE);
		}
		else
		{
			texteAide.setVisibility(EditText.VISIBLE);
		}
		
		if( currentQuestion.getVignette() == Question.OEIL )
		{
			ImageView image = (ImageView)activity.findViewById(R.id.imageOeil );
			image.setVisibility( ImageView.VISIBLE );
			ImageView image1 = (ImageView)activity.findViewById(R.id.imageLoupe );
			image1.setVisibility( ImageView.GONE );
		}
		else if( currentQuestion.getVignette() == Question.LOUPE )
		{
			ImageView image = (ImageView)activity.findViewById(R.id.imageLoupe );
			image.setVisibility( ImageView.VISIBLE );
			ImageView image1 = (ImageView)activity.findViewById(R.id.imageOeil );
			image1.setVisibility( ImageView.GONE );
		}
		else if( currentQuestion.getVignette() == Question.BOTH )
		{
			ImageView image = (ImageView)activity.findViewById(R.id.imageLoupe );
			image.setVisibility( ImageView.VISIBLE );
			ImageView image1 = (ImageView)activity.findViewById(R.id.imageOeil );
			image1.setVisibility( ImageView.VISIBLE );
		}
		
		ImageView image = (ImageView)activity.findViewById(R.id.imageQuestion );
		image.setImageBitmap( BitmapFactory.decodeFile(Environment.getExternalStoragePublicDirectory(
					Environment.DIRECTORY_PICTURES) + File.separator + "Inno/" + currentQuestion.getCheminImage() )  );
		
		if( currentQuestion.getCheminImage() == "" )
		{
			image.setVisibility(ImageView.GONE);
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
			 
			 if( navigation != listQuestion.size()-1  )
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
	
	private void afficherResultat( Resultat resultat )
	{
		dialog = new Dialog( activity );
		dialog.setOwnerActivity(activity);
	       
		dialog.setContentView(R.layout.resultat);
		dialog.setTitle("Résultat");
		dialog.setCancelable(true);
		dialog.setCanceledOnTouchOutside(true);
		
		dialogVisible = true;
		
		TextView nom = (TextView)dialog.findViewById(R.id.nom );
		nom.setText( resultat.getNom() );
		
		TextView type = (TextView)dialog.findViewById(R.id.type );
		type.setText( resultat.getType() );
		
		TextView regimeAlimentaire = (TextView)dialog.findViewById(R.id.regimeAlimentaire );
		regimeAlimentaire.setText( resultat.getRegimeAlimentaire() );
		
		boutonEnregistrer = (Button)dialog.findViewById(R.id.button1);
		boutonEnregistrer.setOnClickListener(this);
		
		boutonAnnuler = (Button)dialog.findViewById(R.id.button2);
		boutonAnnuler.setOnClickListener(this);
		
		Bitmap[] bitmaps = new Bitmap[resultat.getListeImage().size()];
		
		for( int i = 0; i < resultat.getListeImage().size(); i++ )
		{
			bitmaps[i] = BitmapFactory.decodeFile(Environment.getExternalStoragePublicDirectory(
					Environment.DIRECTORY_PICTURES) + File.separator + "Inno/" + resultat.getListeImage().get(i) );
		}
		
		Gallery gallery = (Gallery)dialog.findViewById(R.id.gallery1); 
		
		ImageAdapter adapter = new ImageAdapter( activity );
		adapter.setmImageIds(bitmaps );
		gallery.setAdapter( adapter );
		
		dialog.show();
	}
	
	private void afficherAlerte()
	{
		dialogAlerte = new Dialog( activity );
		dialogAlerte.setOwnerActivity(activity);
	       
		dialogAlerte.setContentView(R.layout.alerte);
		dialogAlerte.setTitle("Incident");
		dialogAlerte.setCancelable(false);
		dialogAlerte.setCanceledOnTouchOutside(true);
		
		dialogAlerteVisible = true;
		
		boutonSubmit = (Button)dialogAlerte.findViewById( R.id.button1 );
		boutonSubmit.setOnClickListener(this);
		
		boutonAnnulerAlerte = (Button)dialogAlerte.findViewById( R.id.button2 );
		boutonAnnulerAlerte.setOnClickListener( this );
		
		dialogAlerte.show();
	}
}
