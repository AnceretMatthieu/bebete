package polytechTours.DI4;


import polytechTours.DI4.gestion_projet.GestionCampagne;
import polytechTours.DI4.gestion_projet.GestionParcelle;
import polytechTours.DI4.gestion_projet.GestionPiege;
import polytechTours.DI4.gestion_projet.GestionUtilisateur;
import polytechTours.DI4.gestion_projet.Securite;

import java.security.spec.ECPoint;

import polytechTours.DI4.fast_count.Image;


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
import android.widget.ImageButton;
import android.widget.Toast;


public class BebeteActivity extends Activity 
{
	private FragmentManager manager;
	@Override
	public boolean onCreateOptionsMenu(Menu menu) 
	{
	    MenuInflater inflater = getMenuInflater();
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
        
		SharedPreferences preferences = getPreferences(Context.MODE_PRIVATE); //récupère les paramètres de l'application
		SharedPreferences.Editor editor = preferences.edit();
		editor.putLong("UTILISATEUR_ID", -1);
		editor.putLong("CAMPAGNE_ID", -1); 
		editor.putLong("PARCELLE_ID", -1);
		editor.putLong("PIEGE_ID", -1); 
		editor.commit();
		
        GestionUtilisateur gestionutilisateur = new GestionUtilisateur();
		
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
    	else if( item.getItemId() == R.id.menu_exporter )
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
    		if(Securite.valideProjet(this) == true){
    		
	    		SharedPreferences preferences = getPreferences(Context.MODE_PRIVATE); 
	            int piege_id = (int)preferences.getLong("PIEGE_ID", -1);
	            
	    		Intent i =new Intent(BebeteActivity.this,polytechTours.DI4.fast_count.Image.class);     	
	            
	    		Bundle bundle=new Bundle(); 
	            bundle.putLong("PIEGE_ID", piege_id);
	            i.putExtras(bundle);
	            
	            startActivity(i);
    		}
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
    
    /*methodes*/
	protected void alertbox(String title, String mymessage){
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