package polytechTours.DI4;

import android.app.ActionBar;
import android.app.Activity;
import android.app.Dialog;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;


public class BebeteActivity extends Activity 
{
	private FragmentManager manager;
	private int idFragmentQuestion;
	
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
    }
    
    @Override
    public boolean onOptionsItemSelected(MenuItem item) 
    {
    	if( item.getItemId() == R.id.menu_campagne )
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
    	else if( item.getItemId() == R.id.menu_identifier )
    	{
    		QuestionFragment questionView = new QuestionFragment();
    		idFragmentQuestion = questionView.getId();
			
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