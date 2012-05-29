package polytechTours.DI4;

import android.app.ActionBar;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageButton;

/**
 * @author Julien Teruel
 *
 * Classe démarrant l'activité principale de l'application
 * Elle gère les fragments d'interface graphique en réaction aux clics sur l'action bar
 */

public class BebeteActivity extends Activity 
{
	/**
	 * Le fragment manager permettant gérer les fragments
	 */
	private FragmentManager manager;
	
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
        
        GestionUtilisateur gestionutilisateur = new GestionUtilisateur();
        
        //**********************Code à enlever par la suite************************
        //Creation d'un piege auto pour test rapide d'insertion sur la BDD
        Piege piege = new Piege();
        piege.setNom("toto");
        piege.setId(117);
        
        PiegeBDD bdd = new PiegeBDD(getApplicationContext());
        bdd.open();
        bdd.insertPiege(piege);
        bdd.close();
        
        //*************************************************************************
		
		miseAjourAffichage();
		
		//On mets le fragment de base en place
		FragmentTransaction transaction = manager.beginTransaction();
			transaction.add( R.id.linearLayout2, gestionutilisateur, "enCours" );
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
}