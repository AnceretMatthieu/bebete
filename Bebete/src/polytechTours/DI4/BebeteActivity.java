package polytechTours.DI4;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import polytechTours.DI4.GesionIdentification.FileManager;
import polytechTours.DI4.GesionIdentification.QuestionFragment;
import polytechTours.DI4.fast_count.Image;
import polytechTours.DI4.gestion_projet.GestionCampagne;
import polytechTours.DI4.gestion_projet.GestionParcelle;
import polytechTours.DI4.gestion_projet.GestionPiege;
import polytechTours.DI4.gestion_projet.GestionUtilisateur;
import android.app.ActionBar;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageButton;

/**
 * @author Julien Teruel
 *
 * Classe dï¿½marrant l'activitï¿½ principale de l'application
 * Elle gï¿½re les fragments d'interface graphique en rï¿½action aux clics sur l'action bar
 */

public class BebeteActivity extends Activity implements OnClickListener 
{
	/**
	 * Le fragment manager permettant gï¿½rer les fragments
	 */
	private FragmentManager manager;
	
	private ImageButton home;
	
	/**
	 * Rajout du menu droit dans l'action bar via inflation ï¿½ partir du fichier de layout actionbar.xml 
	 */
	@Override
	public boolean onCreateOptionsMenu(Menu menu) 
	{
	    MenuInflater inflater = getMenuInflater();
	    menu.setGroupVisible( 0, true );
	    inflater.inflate( R.layout.actionbar, menu); 
	    return true;
	}
	
	@Override
	public void onBackPressed() 
	{
		 AlertDialog.Builder builder = new AlertDialog.Builder(this);
         builder.setMessage("Etes-vous sûr de vouloir quitter ?")
                 .setCancelable(false)
                 .setPositiveButton("Oui",
                         new DialogInterface.OnClickListener() {
                             public void onClick(DialogInterface dialog,
                                     int id) {

                                 moveTaskToBack(true);
                             }
                         })
                 .setNegativeButton("Non",
                         new DialogInterface.OnClickListener() {
                             public void onClick(DialogInterface dialog,
                                     int id) {
                                 dialog.cancel();
                             }
                         });
         AlertDialog alert = builder.create();
         alert.show();    
    }
	
	/**
	 * Gestion de l'interface graphique de base
	 */
    @Override 
    public void onCreate(Bundle savedInstanceState) 
    {
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE); //Fixe la vue de l'application en Landscape
        
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        manager = this.getFragmentManager();  
        
        //Rajout de la partie gauche de l'action bar
        ActionBar actionBar = getActionBar();
        View mActionBarView = getLayoutInflater().inflate(R.layout.action_bar_custom, null);
        actionBar.setCustomView(mActionBarView);
        actionBar.setDisplayOptions(ActionBar.DISPLAY_SHOW_CUSTOM);
        
        //On cache les boutons responsables de l'historique dans la partie identification
        ImageButton gauche = (ImageButton)this.findViewById( R.id.histo_gauche );
        gauche.setEnabled(false);
        ImageButton droite = (ImageButton)this.findViewById( R.id.histo_droite );
        droite.setEnabled(false);
        
        home = (ImageButton)this.findViewById( R.id.home );
        home.setOnClickListener(this);
        
        //GestionUtilisateur gestionutilisateur = new GestionUtilisateur();
        MenuGPSFragment menu = new MenuGPSFragment(this);
		
		SharedPreferences preferences = getPreferences(Context.MODE_PRIVATE); //rï¿½cupï¿½re les paramï¿½tres de l'application
		SharedPreferences.Editor editor = preferences.edit();
		editor.putLong("UTILISATEUR_ID", -1);
		editor.putLong("CAMPAGNE_ID", -1); 
		editor.putLong("PARCELLE_ID", -1);
		editor.putLong("PIEGE_ID", -1); 
		editor.commit();
        System.out.println(Environment.getDataDirectory());
        //*************************************************************************
        //******* Gestion du 1er lancement ****************************************
        
        creerArbo();
        
        //*************************************************************************
		
		miseAjourAffichage();
		
		//On mets le fragment de base en place
		FragmentTransaction transaction = manager.beginTransaction();
			transaction.add( R.id.linearLayout2, menu, "enCours" );
		transaction.commit();
    }
    
    /**
     * Rï¿½action aux clics sur l'action bar -> chargement du fragments nï¿½cessaire
     * Le nouveau fragment est taggï¿½ "enCours" pour pouvoir le retrouver et l'enlever par la suite
     */
    @Override
    public boolean onOptionsItemSelected(MenuItem item) 
    {
    	if( item.getItemId() == R.id.menu_utilisateurs )
    	{
    		GestionUtilisateur gestionutilisateur = new GestionUtilisateur();
    		
    		miseAjourAffichage();
    		
    		FragmentTransaction transaction = manager.beginTransaction();
    			transaction.add( R.id.linearLayout2, gestionutilisateur, "enCours" );
    		transaction.commit();
    	}
    	else if( item.getItemId() == R.id.menu_campagne )
    	{
    		GestionCampagne gestionCampagne = new GestionCampagne();
			
			miseAjourAffichage();
			
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionCampagne, "enCours" );
			transaction.commit();
    	}
    	else if( item.getItemId() == R.id.menu_piege )
    	{   		
			GestionPiege gestionPiege = new GestionPiege();
			
			miseAjourAffichage();

			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionPiege, "enCours" );
			transaction.commit();
    	}
    	else if( item.getItemId() == R.id.menu_parcelle )
    	{    		
			GestionParcelle gestionParcelle = new GestionParcelle();
			
			miseAjourAffichage();

			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionParcelle, "enCours" );
			transaction.commit();
    	}
    	else if( item.getItemId() == R.id.menu_identifier )
    	{   		
    		QuestionFragment questionView = new QuestionFragment();
    		questionView.getId();
			
    		miseAjourAffichage();
			
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, questionView, "enCours" );
			transaction.commit();
    	}
		else if( item.getItemId() == R.id.export )
    	{
    		SharedPreferences preferences = getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
            int utilisateur_id = (int)preferences.getLong("UTILISATEUR_ID", -1);
            if(utilisateur_id == -1)
            	alertbox("Attention !", "Sélectionner un utilisateur");
            else
            	Export.Export(this, utilisateur_id);
    	}
    	else if( item.getItemId() == R.id.menu_fast_count )
    	{
    		Image info = new Image();
    		info.getId();
			
    		miseAjourAffichage();
			
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, info, "enCours" );
			transaction.commit();
    	}
    	
    	return true;
    }
    
    /**
     * Fonction pratique qui enlÃ©ve le fragment actuellement affichÃ© si il y en a un 
     */
    public void miseAjourAffichage()
    {
    	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
		
		if( fragmentEnCours != null )
		{
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.remove( fragmentEnCours );
			transaction.commit();
		}
    }

	public void onClick(View arg0) 
	{
		if( arg0.getId() == home.getId() )
		{
			MenuGPSFragment menu = new MenuGPSFragment(this);
			
    		miseAjourAffichage();
			
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, menu, "enCours" );
			transaction.commit();
		}
	}
	
	protected void alertbox(String title, String mymessage)
	{
		   new AlertDialog.Builder(this)
		      .setMessage(mymessage)
		      .setTitle(title)
		      .setCancelable(true)
		      .setNeutralButton(android.R.string.ok,
		         new DialogInterface.OnClickListener() {
		         public void onClick(DialogInterface dialog, int whichButton){}
		         })
		      .show();
	}
	
	public void creerArbo()
	{
		File dossier = new File( FileManager.getSaveIncidentPath() );
		FileManager.updateFileSystem( dossier, this );
	
		File fichierXML = new File( FileManager.getSavePath() + File.separator + "accueil.xml" );
		
		if( !fichierXML.exists() )
		{
			try 
			{
				FileOutputStream out = new FileOutputStream(fichierXML);
				
				try 
				{
					out.write( new String( "<?xml version=\"1.0\"?>").getBytes() );
					out.write( new String( "<arbre><branche id=\"b1\" type=\"accueil\" date=\"jj/mm/yyy\">" ).getBytes() );
					out.write( new String( "<question id=\"q1\" texte=\"Aucun fichier XML trouver\" observation=\"oeil\">" +
							"<media><legende>Veuillez vérifier que les fichiers ont bien été copiés dans /Innophyt/</legende>" +
							"</media> </question> </branche> </arbre>").getBytes() );
					out.close();

					FileManager.updateFileSystem(fichierXML, this);
				} 
				catch (IOException e) 
				{
					Log.d("Fichier de base", "Erreur lors de l'écriture du fichier XML de base");
					e.printStackTrace();
				}
				
			} 
			catch (FileNotFoundException e) 
			{
				Log.d("Fichier de base", "Erreur lors de la création des fichiers de base");
				e.printStackTrace();
			}			
		}
		
	}
}