package polytechTours.DI4;

import polytechTours.DI4.GesionIdentification.MenuGPSFragment;
import polytechTours.DI4.GesionIdentification.QuestionFragment;
import polytechTours.DI4.fast_count.Image;
import polytechTours.DI4.fast_count.Info;
import polytechTours.DI4.fast_count.Windows;
import polytechTours.DI4.gestion_projet.GestionCampagne;
import polytechTours.DI4.gestion_projet.GestionParcelle;
import polytechTours.DI4.gestion_projet.GestionPiege;
import polytechTours.DI4.gestion_projet.GestionUtilisateur;
import polytechTours.DI4.gestion_projet.Securite;
import android.app.ActionBar;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageButton;

/**
 * @author Julien Teruel
 *
 * Classe démarrant l'activité principale de l'application
 * Elle gère les fragments d'interface graphique en réaction aux clics sur l'action bar
 */

public class BebeteActivity extends Activity implements OnClickListener 
{
	/**
	 * Le fragment manager permettant gérer les fragments
	 */
	private FragmentManager manager;
	
	private ImageButton home;
	
	/**
	 * Rajout du menu droit dans l'action bar via inflation à partir du fichier de layout actionbar.xml 
	 */
	@Override
	public boolean onCreateOptionsMenu(Menu menu) 
	{
	    MenuInflater inflater = getMenuInflater();
	    menu.setGroupVisible( 0, true );
	    inflater.inflate( R.layout.actionbar, menu); 
	    return true;
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
		
		SharedPreferences preferences = getPreferences(Context.MODE_PRIVATE); //récupère les paramètres de l'application
		SharedPreferences.Editor editor = preferences.edit();
		editor.putLong("UTILISATEUR_ID", -1);
		editor.putLong("CAMPAGNE_ID", -1); 
		editor.putLong("PARCELLE_ID", -1);
		editor.putLong("PIEGE_ID", -1); 
		editor.commit();
        
        //*************************************************************************
		
		miseAjourAffichage();
		
		//On mets le fragment de base en place
		FragmentTransaction transaction = manager.beginTransaction();
			transaction.add( R.id.linearLayout2, menu, "enCours" );
		transaction.commit();
    }
    
    /**
     * Réaction aux clics sur l'action bar -> chargement du fragments nécessaire
     * Le nouveau fragment est taggé "enCours" pour pouvoir le retrouver et l'enlever par la suite
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
		else if( item.getItemId() == R.id.menu_parametre )
    	{
    		SharedPreferences preferences = getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
            int utilisateur_id = (int)preferences.getLong("UTILISATEUR_ID", -1);
            if(utilisateur_id == -1)
            	alertbox("Attention !", "Sélectionner un utilisateur");
            else
            	Export.Export(getBaseContext(), utilisateur_id);
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
     * Fonction pratique qui enlève le fragment actuellement affiché si il y en a un 
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
}