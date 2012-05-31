package polytechTours.DI4;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Calendar;
import java.util.Vector;

import polytechTours.DI4.bdd.Campagne;
import polytechTours.DI4.bdd.CampagneBDD;
import polytechTours.DI4.bdd.Parcelle;
import polytechTours.DI4.bdd.ParcelleBDD;
import polytechTours.DI4.bdd.Piege;
import polytechTours.DI4.bdd.PiegeBDD;
import polytechTours.DI4.bdd.Recolte;
import polytechTours.DI4.bdd.RecolteBDD;
import polytechTours.DI4.bdd.UtilisateurBDD;

import android.content.Context;
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
	public static void Export(Context context, int utilisateur_id){
		/*declearations*/
		Vector<Campagne> campagnes = new Vector<Campagne>();
		Vector<Parcelle> parcelles = new Vector<Parcelle>();
		Vector<Piege> pieges = new Vector<Piege>();
		Vector<Recolte> recoltes = new Vector<Recolte>();
		File csv = null;
		
		//** création du fichier **//
		//Chemin de sauvegarde memoire interne : /Pictures/Inno/csv/
	    File mediaStorageDir = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES), "Inno");
			
	    if (! mediaStorageDir.exists()){
	        if (! mediaStorageDir.mkdirs()){
	            Log.d("exportCSV", "failed to create directory Inno");
	            return;
	        }
	    }
	    
	    File exportCSV = new File(mediaStorageDir.getPath() + File.separator + "export");
	    if(!exportCSV.exists())
		    if(exportCSV.mkdir() == false ){
		    	Log.d("exportCSV", "failed to create directory export");
		    	return;
		    }
	    
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
			StringBuilder sb = new StringBuilder();
			sb.append(exportCSV.getPath());
			sb.append(File.separator);
			sb.append("export_");
			sb.append(utilisateurNom);
			sb.append("_");
			sb.append(mYear);
			sb.append("_");
			sb.append(mMonth);
			sb.append("_");
			sb.append(mDay);
			sb.append(".csv");
			
			System.out.println(sb.toString());
			csv = new File(exportCSV.getPath() + File.separator + "export_" + utilisateurNom + "_" + mYear + "_" + mMonth + "_" + mDay + ".csv");
			csv.createNewFile();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		if(!csv.exists()){
	    	Log.d("exportCSV", "failed to create file");
	    	return;
	    }
	    
	    //ouverture en écriture
	    //écriture des entêtes.
	    try {
			FileWriter fw = new FileWriter(csv, true);
			BufferedWriter output = new BufferedWriter(fw);
			
			//écriture des entêtes
			String str = Campagne.headerCSV() + ";";
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
							str = campagne.toCSV() + ";";
							str += parcelle.toCSV() + ";";
							str += piege.toCSV() + ";";
							str += recolte.toCSV() + "\n";
							
							output.write(str);
							
						}
					}
				}
				
				output.close();
				
			}	
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
