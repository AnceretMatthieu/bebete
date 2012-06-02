package polytechTours.DI4.GesionIdentification;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Date;
import java.util.Vector;

import polytechTours.DI4.BebeteActivity;
import polytechTours.DI4.R;
import polytechTours.DI4.R.id;
import polytechTours.DI4.R.layout;
import polytechTours.DI4.bdd.Recolte;
import polytechTours.DI4.bdd.RecolteBDD;
import polytechTours.DI4.bdd.Utilisateur;
import polytechTours.DI4.bdd.UtilisateurBDD;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.Fragment;
import android.app.FragmentTransaction;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.hardware.Camera;
import android.hardware.Camera.PictureCallback;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.Gallery;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

/**
 * @author Julien Teruel
 * Classe la plus cons�quente g�rant la cam�ra, les questions, l'affichage, l'historique d'o� sa taille cons�quente
 * Pour plus de d�tails sur cette classe se reporter au rapport
 * Vie de la classe :
 *  Au depart on parse le fichier XML, on obtient la question root de base
 *  currentQuestion est la � afficher, changeUI() adapte l'interface graphique � currentQuestion
 */
public class QuestionFragment extends Fragment implements OnClickListener 
{
	//************ Partie Camera *******************
	/**
	 * L'objet cam�ra 
	 */
	private Camera mCamera;
	
	/**
	 * La zone de preview de la vue cam�ra
	 */
	private CameraPreview mPreview;
	
	/**
	 * Deuxieme partie de la zone d'affichage
	 */
	private FrameLayout preview;
	
	/**
	 * L'activity principale, sauvegarder pour utilisation future
	 */
	private BebeteActivity activity;
	
	/**
	 * Bool�en g�rant l'acc�s concurrent � la cam�ra
	 */
	private static boolean aquis = false;
	
	//********************************************************
	
	
	//**************** Partie Historique *********************
	/**
	 * Le parser XML
	 */
	private ReacherQR reacher;
	
	/**
	 * La question courante sur laquelle se base l'interface graphique
	 */
	private static Question currentQuestion;
	
	/**
	 * La liste des questions vue par l'utilisateur
	 */
	private Vector<Question> listQuestion = new Vector<Question>();
	
	/**
	 * La liste des reponses choisie par l'utilisateur ( taille - 1 par rapport a listQuestion, l'utilisateur voit une question de plus que ce qu'il a r�pondue)
	 */
	private Vector<Reponse> listReponseChoisi = new Vector<Reponse>();
	
	/**
	 * La liste des r�ponse Fragment de la question en cours, n�cessaire pour retrouver la r�ponses choisie par l'utilisateur
	 */
	private Vector<ReponseFragment> listReponseFragment = new Vector<ReponseFragment>();
	
	/**
	 * Int de navigation dans l'historique
	 */
	private int navigation;
	//*********************************************************
	
	
	// *********** Partie affichage des Dialog ****************
	/**
	 * Le dialog affichant le r�sultat trouver en fin d'arbre
	 */
	private Dialog dialog;
	
	/**
	 * Le dialog d'alerte correspondant � l'appuie sur le bouton d'alerte 
	 */
	private Dialog dialogAlerte;
	
	/**
	 * Indique si le dialog resultat est actuellement visible
	 */
	private boolean dialogVisible;
	
	/**
	 * Indique si le dialog d'alerte est visible � l'ecran
	 */
	private boolean dialogAlerteVisible;
	
	/**
	 * Bouton enregistrer du dialog Resultat
	 */
	private Button boutonEnregistrer;
	
	/**
	 * Bouton annuler du dialog Resultat
	 */
	private Button boutonAnnuler;
	
	/**
	 * Bouton enregistrer du dialog Alerte
	 */
	private Button boutonSubmit;
	
	/**
	 * Bouton annuler du dialog Alerte
	 */
	private Button boutonAnnulerAlerte;
	
	/**
	 * Objet resultat contenant toutes les informations n�cessaire � afficher
	 */
	private Resultat resultat;
	//****************************************************************************
	
	//Boutons de l'action bar
	private ImageButton retour;
	private ImageButton suivant;
	private ImageButton alerte;
	
	/**
	 * Constructeur par d�faut, le XML est parser, l'affichage se modifie pour correspondre � la currentQuestion
	 */
	public QuestionFragment()
	{
		reacher = new ReacherQR();
		Question question = reacher.getQuestionRoot();
		currentQuestion = question;
		listQuestion.add(question);
		navigation = 0;
		dialogVisible = false;
		dialogAlerteVisible = false;
		BitmapFactory.Options options = new BitmapFactory.Options();
		options.inSampleSize = 8;
	}
	
	//******* Les m�thodes sont dans l'ordre du cycle de vie d'un fragment pour plus de d�tails http://developer.android.com/guide/topics/fundamentals/fragments.html *********
	// Pour plus de d�tails sur le cycle de vie et leur implications voir le rapport
	
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
    	retour.setVisibility(ImageButton.INVISIBLE);
    	suivant.setVisibility(ImageButton.INVISIBLE);
    	alerte.setVisibility(ImageButton.INVISIBLE);
	}
	 
    //********************************* M�thodes pratiques hors du cycle de vie du fragment *******************************************
    
	//********************* Partie Camera ********************************************
    /** A safe way to get an instance of the Camera object. */
    public Camera getCameraInstance() //Retourne null si la camera n'a pas pu etre acquise
    {
    	if( !aquis )   //Si la camera n'est pas deja acquise
    	{
    		Camera c = null;
    		
	        try 
	        {
	            c = Camera.open();  //Obtention de la camera de base 
	            
	            Camera.Parameters params = c.getParameters(); //Activation des param�tres de base de la cam�ra
	    		params.setWhiteBalance( Camera.Parameters.WHITE_BALANCE_AUTO );
	    		params.setFocusMode(Camera.Parameters.FOCUS_MODE_AUTO);
	    		params.setAntibanding( Camera.Parameters.ANTIBANDING_AUTO );
	    		c.setParameters(params);
	    		
	    		aquis = true;
	    		mCamera.startPreview();
	        }
	        catch (Exception e)
	        {
	           Log.d("Camera", "la camera n'est pas accessible ou n'existe pas");
	        }
	        return c; 
    	}
    	else
    	{
    		Log.d("Camera", "getCameraInstance camera non relach�" );
    		
    		return mCamera;
    	}
    }
      
    /**
     * Release de la camera, si elle a �t� acquise
     */
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
    
    /**
     * Gestion de la capture d'image via le flux de la cam�ra
     */
    private PictureCallback mPicture = new PictureCallback()  
	{
		public void onPictureTaken(byte[] data, Camera camera)
		{
			//Test d'appel � l'intent de gestion de photo d'Android consid�rer trop long mais laiss� ici au cas ou
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
	        	//Ecriture de l'image dans le fichier
	            FileOutputStream fos = new FileOutputStream(pictureFile);
	            fos.write(data);
	            fos.close();
	            Log.d("tag", "File created : " + pictureFile.getAbsolutePath() );
	            FileManager.updateFileSystem(pictureFile, activity);
	        }
	        catch (FileNotFoundException e) 
	        {
	            Log.d("tag", "File not found: " + e.getMessage());
	        } 
	        catch (IOException e) 
	        {
	            Log.d("tag", "Error accessing file: " + e.getMessage());
	        }
		}	
	};
	//************************************************************************************************
	//************************************************************************************************
	
	/**
	 * Fonction d�licate, elle g�re tous les clics dans cette interface graphique dense
	 * On regarde en priorit� si une question a �t� cliqu� sinon on regarde si c'est un bouton de gestion d'historique,
	 * sinon on regarde finalement si c'est un bouton d'un des deux dialogs, celui de resultat ou d'alerte
	 */
	public void onClick(View arg0) 
	{
		//*********** Parcour de tous les framgents pour tester si une checkbox a �t� cocher ******************************
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
							Log.d("Historique", "Nouvelle question cr�er");
							listReponseChoisi.add( reponse );
							currentQuestion = reacher.findQuestionById( reponse.getIdQuestionSuivante() );
							listQuestion.add( currentQuestion );  //Rajout dans l'historique de la question 
						}
						else 
						{
							if( reponse.getId() == listReponseChoisi.get( navigation ).getId() )//Si on a choisie la meme reponse
							{
								Log.d("Historique", "M�me r�ponse selectionner id = " +  reponse.getId() );
								currentQuestion = listQuestion.get(navigation+1);
							}
							else
							{
								Log.d("Historique", "Question diff�rente selectionn�");
								
								for( int k = navigation; k < listReponseChoisi.size(); k++ )//nettoie la liste des reponses depuis la question chang�
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
						//Mise � jour de l'affichage des boutons en fonction des changements dans l'historique
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
						//Si on a choisi une questione en fin d'arbre, cela fait pop up la fenetre de resultat
						Log.d("Affichage Resultat", "Le resultat doit s'afficher");
						resultat = reponse.getResultat();
						afficherResultat( resultat );
					}
				}
			}
		}
		//****************************************************************************************
		
		if( !checkBox ) //Si on rentre ici aucune question n'a �t� selectionn�es
		{
			if( arg0.getId() == retour.getId() ) //Retour cliqu� dans l'historique
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
			else if( arg0.getId() == suivant.getId() )  //Suivant cliqu� dans l'historique
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
			else if( dialogVisible && arg0.getId() == boutonAnnuler.getId() )  //Annuler cliqu� dans le dialog de resultat
			{
				dialogVisible = false;
				dialog.dismiss();
			}
			else if( dialogVisible && arg0.getId() == boutonEnregistrer.getId() ) //Enregistrer clique dans le dialog de resultat
			{
				SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); 
		        int piege_id = (int)preferences.getLong("PIEGE_ID", -1);
		        
		        RecolteBDD bdd = new RecolteBDD(activity.getBaseContext());
		        bdd.open();
		        
		        Recolte recolte = bdd.getRecolteWithNOM( resultat.getNom(), piege_id );
				
		        if(recolte == null)
				{
					recolte = new Recolte();
				}
		        
		        Date date = new Date();		
		        recolte.setNom(resultat.getNom());
                recolte.setNombre( recolte.getNombre() + 1 );
                recolte.setPege_id(piege_id);
                
            	bdd.insinsertOrUpdateRecolte(recolte);
            	
            	 Log.d("Resultat", "Bete : " + recolte.getNom() + " nombre : " + recolte.getNombre() );
            	
            	bdd.close();
		        
		        dialog.dismiss();
		        dialogVisible = false;
		        
			}
			else if( arg0.getId() == alerte.getId() )  //Bouton alerte cliqu� dans l'action bar
			{
				if( !dialogAlerteVisible )
				{
					afficherAlerte();
				}
			}
			else if( dialogAlerteVisible && arg0.getId() ==  boutonAnnulerAlerte.getId() ) //Bouton annuler cliqu� sur le dialog alerte
			{
				dialogAlerte.dismiss();
				dialogAlerteVisible = false;
			}
			else if( dialogAlerteVisible && arg0.getId() == boutonSubmit.getId() )   //Bouton submit cliqu� sur le dialog alerte
			{
				//Enregistrement de l'erreur : un fichier texte contenant le text de l'utilisateur avec la date en haut du fichier
				// Une capture d'�cran utilisateur
				// La derniere capture camera effectu� par l'utilisateur
				EditText detail = (EditText)dialogAlerte.findViewById(R.id.detail);
				Date date = new Date();				
				
				if( detail.getText().length() != 0 )
				{	
	                Bitmap bitmap;
	                View v1 = getView(); 
	                v1.setDrawingCacheEnabled(true);
	                bitmap = Bitmap.createBitmap(v1.getDrawingCache());
	                v1.setDrawingCacheEnabled(false);
	
	                File rapportFile = new File( FileManager.getSaveIncidentPath() + File.separator + "Rapport utilisateur - " + date.getTime() + ".txt" );
	                File imageFile = new File( FileManager.getSaveIncidentPath() + File.separator + "Screen application en cours - " + date.getTime() +".jpg"  );
	                
	                try 
	                {
						FileOutputStream fo = new FileOutputStream( rapportFile );
						FileOutputStream fos = new FileOutputStream(imageFile);
						
						try 
						{	
							fo.write( new String("********* " + date.toString() + " **********\n" ).getBytes() );
							fo.write( detail.getText().toString().getBytes() );
							fo.write( new String("********************************************\n" ).getBytes() );
							fo.close();

		                	ByteArrayOutputStream fout = new ByteArrayOutputStream();
		                    bitmap.compress(Bitmap.CompressFormat.JPEG, 90, fout);
		                    
		                    fos.write( fout.toByteArray() );
		                    fos.close();
							
		                    FileManager.updateFileSystem( rapportFile, activity);
		                    FileManager.updateFileSystem( imageFile, activity);
		                    
		                    bitmap.recycle();
		                    
		                    //Copie de la derniere capture d'ecran effectu� par l'utilisateur
		                    File screenCap = new File( FileManager.getSaveIncidentPath() + File.separator + "Dernier Screen Utilisateur - " + date.getTime() + ".jpg" );
		                    File original = new File( FileManager.getSavePath() + File.separator + "temp.jpg" );
		                    
		                    FileInputStream in = new FileInputStream(original);
		                    FileOutputStream out = new FileOutputStream( screenCap );
		                    
		                    byte[] buffer = new byte[in.available()];
		                    
		                    in.read(buffer);
		                    out.write(buffer);
		                    
		                    in.close();
		                    out.close();
		                    
		                    FileManager.updateFileSystem( screenCap, activity);
		                    //******************************************************************
		                    
		                    dialogAlerte.dismiss();
		    				dialogAlerteVisible = false;		                    
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
				}
				else
				{
					AlertDialog.Builder builder = new AlertDialog.Builder(activity);
					builder.setMessage("Veuillez donner une description de votre probl�me.")
						.setCancelable(false)
						.setPositiveButton("Ok", new DialogInterface.OnClickListener() 
													  {
															public void onClick(DialogInterface dialog, int id) 
															{
																//this.dismiss();
															}
													  });
					AlertDialog alert = builder.create();
					alert.show();
				}
			}
			else if( aquis )
			{
				mCamera.takePicture(null, null, mPicture);
				mCamera.startPreview();	
			}
		}
	}

	/**
	 * Fonction qui adapte l'UI de QuestionFragment pour correspondre � la currentQuestion
	 */
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
		image.setImageBitmap( BitmapFactory.decodeFile( FileManager.getSavePath() + File.separator + currentQuestion.getCheminImage() )  );
		
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
			LinearLayout innerLayout1 = new LinearLayout( activity );  // 1 Layout par Fragment !!!!!!!!! Sinon pas d'affichage du fragment et pas de message d'erreur non plus 
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
	
	/**
	 * Fonction pr�vue pour le futur si un traitement diff�rent est requis lors d'un changement via d'UI via l'historique.
	 * Pour l'instant �quivaut � changeUI();
	 */
	private void changeUIviaHisto()
	{
		currentQuestion = listQuestion.get(navigation);
		changeUI();
	}
	
	/**
	 * Affiche un Dialog de r�stultat bas� sur les infos contenue dans l'objet r�sultat 
	 * @param resultat
	 */
	private void afficherResultat( Resultat resultat )
	{
		dialog = new Dialog( activity );
		dialog.setOwnerActivity(activity);
	       
		dialog.setContentView(R.layout.resultat);
		dialog.setTitle("R�sultat");
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
			bitmaps[i] = BitmapFactory.decodeFile( FileManager.getSavePath() + File.separator + resultat.getListeImage().get(i) );
		}
		
		Gallery gallery = (Gallery)dialog.findViewById(R.id.gallery1); 
		
		ImageAdapter adapter = new ImageAdapter( activity );
		adapter.setmImageIds(bitmaps );
		gallery.setAdapter( adapter );
		
		dialog.show();
	}
	
	/**
	 * Affiche le dialog d'alerte standard
	 */
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

	public Camera getmCamera() {
		return mCamera;
	}

	public PictureCallback getmPicture() {
		return mPicture;
	}
	
	
}
