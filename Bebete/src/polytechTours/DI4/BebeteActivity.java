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


public class BebeteActivity extends Activity 
{
	private FragmentManager manager;
	@Override
	public boolean onCreateOptionsMenu(Menu menu) 
	{
	    MenuInflater inflater = getMenuInflater();
	    menu.setGroupVisible( 0, true );
	    inflater.inflate( R.layout.actionbar, menu); 
	    return true;
	}
	
    @Override 
    public void onCreate(Bundle savedInstanceState) 
    {
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        manager = this.getFragmentManager();  
        
        ActionBar actionBar = getActionBar();
        View mActionBarView = getLayoutInflater().inflate(R.layout.action_bar_custom, null);
        actionBar.setCustomView(mActionBarView);
        actionBar.setDisplayOptions(ActionBar.DISPLAY_SHOW_CUSTOM);
        ImageButton gauche = (ImageButton)this.findViewById( R.id.histo_gauche );
        gauche.setEnabled(false);
        ImageButton droite = (ImageButton)this.findViewById( R.id.histo_droite );
        droite.setEnabled(false);
        
        GestionUtilisateur gestionutilisateur = new GestionUtilisateur();
        
        //**********************Code � enlever par la suite************************
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
		
		FragmentTransaction transaction = manager.beginTransaction();
			transaction.add( R.id.linearLayout2, gestionutilisateur, "enCours" );
		transaction.commit();
    }
    
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
    		//Question question = new Question ("Coucou je suis Dynamique", "Je peux m�me afficher un texte d'aide", "" );
    		QuestionFragment questionView = new QuestionFragment();
    		questionView.getId();
			
    		miseAjourAffichage();
			
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, questionView, "enCours" );
			transaction.commit();
    	}
    	
    	return true;
    }
    
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
    
   /* @Override 
    public void onPause()
    {
    	super.onPause();
    	
    	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
    	
    	Log.d("Activity", "onPause Fragment Question" );
    	
    	if( fragmentEnCours != null && fragmentEnCours.getId() == idFragmentQuestion )
    	{
    		Log.d("Activity", "onPause Fragment Question" );
    		QuestionFragment fragment = (QuestionFragment)fragmentEnCours;
    		fragment.onPause(); 
    	}
    }
    
    @Override
    public void onDestroy ()
    {
    	super.onDestroy();
    	
    	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
    	
    	if( fragmentEnCours != null && fragmentEnCours.getId() == idFragmentQuestion )
    	{
    		Log.d("Activity", "onDestroy" );
    		QuestionFragment fragment = (QuestionFragment)fragmentEnCours;
    		fragment.onDestroy(); 
    	}
    }*/
}