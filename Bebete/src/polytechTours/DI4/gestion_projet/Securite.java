package polytechTours.DI4.gestion_projet;

import polytechTours.DI4.R;
import android.R.bool;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;

public class Securite {
	
	/** message d'alerte, seul valider est disponible
	 * @param title	Titre de l'alerte
	 * @param mymessage Message de l'alerte*/
	private static void alertbox(Activity activity, String title, String mymessage){
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
	
	public static boolean valideProjet(Activity activity){
		
		SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //récupère les paramètres de l'application
		int utilisateur_id = (int)preferences.getLong("UTILISATEUR_ID", -1);
		int campagne_id = (int)preferences.getLong("CAMPAGNE_ID", -1);
		int parcelle_id = (int)preferences.getLong("PARCELLE_ID", -1);
		int piege_id = (int)preferences.getLong("PIEGE_ID", -1);
        
		if(utilisateur_id == -1){
        	alertbox(activity, "Attention !", "Sélectionner un utilisateur");
        	
    		FragmentManager manager = activity.getFragmentManager();  
    		
        	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
    		
    		if( fragmentEnCours != null )
    		{
    			FragmentTransaction transaction = manager.beginTransaction();
    				transaction.remove( fragmentEnCours );
    			transaction.commit();
    		}
    		
    		GestionUtilisateur gestionUtilisateur = new GestionUtilisateur();
    		FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionUtilisateur, "enCours" );
			transaction.commit();
			return false;
		}
		else if(campagne_id == -1){
        	alertbox(activity, "Attention !", "Sélectionner une campagne");
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
			return false;
		}
		else if(parcelle_id == -1){
        	alertbox(activity, "Attention !", "Sélectionner une parcelle");
        	FragmentManager manager = activity.getFragmentManager();  
    		
        	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
    		
    		if( fragmentEnCours != null )
    		{
    			FragmentTransaction transaction = manager.beginTransaction();
    				transaction.remove( fragmentEnCours );
    			transaction.commit();
    		}
    		
    		GestionParcelle gestionParcelle = new GestionParcelle();
    		FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionParcelle, "enCours" );
			transaction.commit();
			return false;
		}
		else if(piege_id == -1){
        	alertbox(activity, "Attention !", "Sélectionner un piége");
        	
        	FragmentManager manager = activity.getFragmentManager();  
    		
        	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
    		
    		if( fragmentEnCours != null )
    		{
    			FragmentTransaction transaction = manager.beginTransaction();
    				transaction.remove( fragmentEnCours );
    			transaction.commit();
    		}
    		
    		GestionPiege gestionPiege = new GestionPiege();
    		FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionPiege, "enCours" );
			transaction.commit();
			return false;
		}
		return true;
	}
}
