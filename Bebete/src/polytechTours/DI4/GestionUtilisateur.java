package polytechTours.DI4;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;

public class GestionUtilisateur extends Fragment
{
	private Activity activity;
	
    private UtilisateurBDD bdd;
	
	protected void alertbox(String title, String mymessage){
		   new AlertDialog.Builder(activity)
		      .setMessage(mymessage)
		      .setTitle(title)
		      .setCancelable(true)
		      .setNeutralButton(android.R.string.ok,
		         new DialogInterface.OnClickListener() {
		         public void onClick(DialogInterface dialog, int whichButton){}
		         })
		      .show();
		}
	
	/****************************************************
	 *              gestion de l affichage
	 ****************************************************/
    @Override
    public void onAttach(Activity activity)  
	{
        super.onAttach(activity);
        this.activity = activity;
	}
	 @Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {	        
		// Inflate the layout for this fragment
        return inflater.inflate( R.layout.gestionutilisateur, container, false);		
    }
	 
	@Override
	public void onActivityCreated (Bundle savedInstanceState)
	{    
		super.onActivityCreated(savedInstanceState);
        
		bdd = new UtilisateurBDD(activity);
	    bdd.open();
	    
		//login
		final Button valider = (Button) activity.findViewById(R.id.ok_login);
		valider.setOnClickListener(new View.OnClickListener() {
		    public void onClick(View v) {
		    	EditText nomET = (EditText) activity.findViewById(R.id.nomUtilisateur);
		    	String nom = nomET.getText().toString();
		    	if(nom != null && nom.trim().length() > 0){
			    	Utilisateur utilisateur = bdd.getUtilisateurWithNOM(nom);
			        if(utilisateur != null){
	    				SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
	    				
	    				// stock l'identifiant de l'utilisateur
			    		SharedPreferences.Editor editor = preferences.edit();
			    		editor.putLong("UTILISATEUR_ID", utilisateur.getId()); 
			    		editor.commit();
			    		
			    		FragmentManager manager = activity.getFragmentManager();  
			    		
			        	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
			    		
			    		if( fragmentEnCours != null )
			    		{
			    			FragmentTransaction transaction = manager.beginTransaction();
			    				transaction.remove( fragmentEnCours );
			    			transaction.commit();
			    		}
			    		
			    		GestionCampagne gestionCampagne = new GestionCampagne();
			    		FragmentTransaction transaction = manager.beginTransaction();
							transaction.add( R.id.linearLayout2, gestionCampagne, "enCours" );
						transaction.commit();
					
					}else
					{
						alertbox("Attention !", "L'utilisateur n'existe pas.");
					}
		    	}
		    }
		});
		
		//creation utilisateur
		final Button creer = (Button) activity.findViewById(R.id.newUser);
		creer.setOnClickListener(new View.OnClickListener() {
		    public void onClick(View v) {
		    	EditText nomET = (EditText) activity.findViewById(R.id.nomUtilisateur);
		    	String nom = nomET.getText().toString();
		    	if(nom != null && nom.trim().length() > 0){
			    	Utilisateur utilisateur = new Utilisateur();
			    	utilisateur.setNom(nom);
			    	long test = bdd.insertUtilisateur(utilisateur);
			    	alertbox("Action accomplie !", "Le nouvel utilisateur à bien été enregistré.\n Il peut à present se connecter.");
		    	}
		    	else{
		    		alertbox("Attention !", "Indiquez un nom d'utilisateur.");
		    		//alertbox(R.string.attention, R.string.utilisatorNameNided);
		    	}
		    }
		});
    }
    	
	@Override
	public void onPause()
	{
	    super.onPause();
	}
    	
    @Override
    public void onResume() 
    {
        super.onResume();
    }
        
    @Override
    public void onDestroy ()
    {
    	super.onDestroy();
    	bdd.close();
    }

}
