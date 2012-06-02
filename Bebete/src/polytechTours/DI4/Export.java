package polytechTours.DI4;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Calendar;
import java.util.Vector;

import polytechTours.DI4.GesionIdentification.FileManager;
import polytechTours.DI4.bdd.Campagne;
import polytechTours.DI4.bdd.CampagneBDD;
import polytechTours.DI4.bdd.Parcelle;
import polytechTours.DI4.bdd.ParcelleBDD;
import polytechTours.DI4.bdd.Piege;
import polytechTours.DI4.bdd.PiegeBDD;
import polytechTours.DI4.bdd.Recolte;
import polytechTours.DI4.bdd.RecolteBDD;
import polytechTours.DI4.bdd.Utilisateur;
import polytechTours.DI4.bdd.UtilisateurBDD;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Environment;
import android.util.Log;

/**méthodes d'export des données de l'application*/
public class Export {

	/** Export au format CSV toutes les campagnes, les parcelles, les pièges et le nombre d'insectes trouvés pour un utilisateur
	 * @param context	Contexte de l'application
	 * @param utilisateur_id	Identifiant de l'utilisateur
	 * @note Le résultat est sauvegardé dans le répertoire utilisateur de l'application : /Pictures/Inno/csv/
	 * son nom est "export_#NOM_DE_L_UTILISATEUR#_ANNEE_MOI_JOUR.csv", les valeurs sont celles courantes à l'export
	 */
	public static void Export(Activity activity, int utilisateur_id){
		/*declearations*/
		
		Context context = activity.getApplicationContext();
		Vector<Campagne> campagnes = new Vector<Campagne>();
		Vector<Parcelle> parcelles = new Vector<Parcelle>();
		Vector<Piege> pieges = new Vector<Piege>();
		Vector<Recolte> recoltes = new Vector<Recolte>();
		StringBuffer path =  new StringBuffer();
		Utilisateur utilisateur;
		File csv = null;
		
		//** création du fichier **//
		//Chemin de sauvegarde memoire interne : /Pictures/Inno/csv/
	    
	    File exportCSV = new File( FileManager.getSavePath() + File.separator + "export");
	    if(!exportCSV.exists())
		    if(exportCSV.mkdir() == false ){
		    	Log.d("exportCSV", "failed to create directory export");
		    	return;
		    }
	    
	    //FileManager.updateFileSystem(exportCSV, activity);
	    
	    //Obtient la date actuelle        
		final Calendar c = Calendar.getInstance();        
		int mYear = c.get(Calendar.YEAR);        
		int mMonth = c.get(Calendar.MONTH);
		int mDay = c.get(Calendar.DAY_OF_MONTH);
		
		//obtention du nom de l'utilisateur
		UtilisateurBDD utilisateurBDD = new UtilisateurBDD(context);
		utilisateurBDD.open();
		String utilisateurNom = utilisateurBDD.getUtilisateurWithID(utilisateur_id).getNom();
		utilisateurBDD.close();
		
	    try {

	    	path.append(exportCSV.getPath());
			path.append(File.separator);
			path.append("export_");
			path.append(utilisateurNom);
			path.append("_");
			path.append(mYear);
			path.append("_");
			path.append(mMonth);
			path.append("_");
			path.append(mDay);
			path.append(".csv");
			
			csv = new File(path.toString());
			if(csv.exists())
				csv.delete();
			csv.createNewFile();
			if(!csv.exists()){
				Log.d("exportCSV", "failed to create file export");
				return;
			}
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		if(!csv.exists()){
	    	Log.d("exportCSV", "failed to create file");
	    	return;
	    }
	    
		//utilisateur
		UtilisateurBDD bdd = new UtilisateurBDD(context);
		bdd.open();
			utilisateur = bdd.getUtilisateurWithID(utilisateur_id);
		bdd.close();
		
	    //ouverture en écriture
	    //écriture des entêtes.
	    try {
			FileWriter fw = new FileWriter(csv, true);
			BufferedWriter output = new BufferedWriter(fw);
			
			//écriture des entêtes
			String str = Utilisateur.headerCSV() + ";";
			str += Campagne.headerCSV() + ";";
			str += Parcelle.headerCSV() + ";";
			str += Piege.headerCSV() + ";";
			str += Recolte.headerCSV() + "\n";
			
			output.write(str);

		    
			/*récuperation des campagnes*/
			CampagneBDD campagneBDD = new CampagneBDD(context);
			campagneBDD.open();
			campagnes = campagneBDD.getCampagnes(utilisateur_id);
			campagneBDD.close();
			
			//parcours des parcelles campagne par campagne
			for (Campagne campagne : campagnes) {
				ParcelleBDD parcelleBDD = new ParcelleBDD(context);
				parcelleBDD.open();
				parcelles = parcelleBDD.getParcelles(campagne.getId());	
				parcelleBDD.close();
				
				if(parcelles != null)
				for (Parcelle parcelle : parcelles) {
					/*récupération des pièges*/
					PiegeBDD piegeBDD = new PiegeBDD(context);
					piegeBDD.open();
					pieges = piegeBDD.getPieges(parcelle.getId());	
					piegeBDD.close();
					
					if(pieges != null)
					for (Piege piege : pieges) {
						/*récupération des effectifs*/
						RecolteBDD recolteBDD = new RecolteBDD(context);
						recolteBDD.open();
						recoltes = recolteBDD.getRecoltes(piege.getId());	
						recolteBDD.close();
						
						if(recoltes != null)
						for(Recolte recolte : recoltes){
							str = utilisateur.toCSV() + ";";
							str += campagne.toCSV() + ";";
							str += parcelle.toCSV() + ";";
							str += piege.toCSV() + ";";
							str += recolte.toCSV() + "\n";
							
							output.write(str);
							
						}
					}
				}
				
				output.close();
				FileManager.updateFileSystem( exportCSV, activity);
				
				alertbox(activity, "Exportation CSV", "le fichier " + path.toString() + " � bien �t� enregistr�");
			}	
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
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
}
