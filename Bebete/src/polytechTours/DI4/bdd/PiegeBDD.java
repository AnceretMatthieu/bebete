package polytechTours.DI4.bdd;

import java.util.Vector;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

/** Interaction entre un Piège et la base de données.
 * Met en place les méthodes d'ajout, modification et suppression d'éléments dans la table de piège*/
public class PiegeBDD {
	private static final String BDD_NAME = "gestion.db";
	private static final String TABLE_CAMPAGNE = "TABLE_PIEGE";
	private static final int BDD_VESTION = 1;
	
	private static final String COL_ID = "ID";
	private static final int NUM_COL_ID = 0; 
	
	private static final String COL_PARCEL_ID = "PARCEL_ID";
	private static final int NUM_COL_CAMP_ID = 1;
	
	private static final String COL_NOM = "NOM";
	private static final int NUM_COL_NOM = 2;
	
	private static final String COL_DATE_DEBUT = "DATE_DEBUT";
	private static final int NUM_COL_DATE_DEBUT = 3;
	
	private static final String COL_DATE_FIN = "DATE_FIN";
	private static final int NUM_COL_DATE_FIN = 4;
	
	private static final String COL_ADRESSE = "ADRESSE";
	private static final int NUM_COL_ADRESSE = 5;
	
	private static final String	COL_LATITUDE = "LATITUDE";
	private static final int NUM_COL_LATITUDE = 6;
	
	private static final String	COL_LONGITUDE = "LONGITUDE";
	private static final int NUM_COL_LONGITUDE = 7;
	
	private static final String COL_DESCRIPTION = "DESCRIPTION";
	private static final int NUM_COL_DESCRIPTION = 8;
	
	private SQLiteDatabase db;
	private GestionBDD bdd;
	
	/** "Instentiation" de la base de données
	 * @param context	Contexte de l'application
	 */
	public PiegeBDD(Context context) {
		bdd = new GestionBDD(context, BDD_NAME, null, BDD_VESTION);
	}
	
	/** Ouvre la base de données
	 */
	public void open(){
		db = bdd.getWritableDatabase();
	}
	
	/** Ferme la base de données
	 */
	public void close() {
		db.close();
	}
	
	// non utilisé, brise le principe d'encapsulation
	/*public SQLiteDatabase getDB(){
		return db;
	}*/
	
	/** Ajoute un nouveau piège à la base de données
	 * @param piege	Le piège à ajouter
	 * @return Identifiant du nouveau piège ou -1 en cas d'échec
	 */
	public long insertPiege( Piege piege){
		ContentValues values = new ContentValues();
		values.put(COL_PARCEL_ID, piege.getParcelle_id());
		values.put(COL_NOM, piege.getNom());
		values.put(COL_DATE_DEBUT, piege.getDate_debut());
		values.put(COL_DATE_FIN, piege.getDate_fin());
		values.put(COL_ADRESSE, piege.getAdresse());
		values.put(COL_LATITUDE, piege.getLatitude());
		values.put(COL_LONGITUDE, piege.getLongitude());
		values.put(COL_DESCRIPTION, piege.getDescription());
		return db.insert(TABLE_CAMPAGNE, null, values);
	}
	
	/** Met à jour un piège dans la base de données
	 * @param piege	Le piège à modifier
	 * @return Nombre de colonnes modifiées
	 */
	public int updateCamapagne(Piege piege){
		ContentValues values = new ContentValues();
		values.put(COL_PARCEL_ID, piege.getParcelle_id());
		values.put(COL_NOM, piege.getNom());
		values.put(COL_DATE_DEBUT, piege.getDate_debut());
		values.put(COL_DATE_FIN, piege.getDate_fin());
		values.put(COL_ADRESSE, piege.getAdresse());
		values.put(COL_LATITUDE, piege.getLatitude());
		values.put(COL_LONGITUDE, piege.getLongitude());
		values.put(COL_DESCRIPTION, piege.getDescription());
		return db.update(TABLE_CAMPAGNE, values, COL_ID + " = " + piege.getId(), null);
	}
	
	/** Supprime un piège de la base de données
	 * @param id	Identifiant du piège à supprimer
	 * @return Nombre de pièges supprimés
	 */
	public int removePiegeWithID(int id){
		return db.delete(TABLE_CAMPAGNE, COL_ID + " = " + id, null);
	}
	
	/** Importe un piège de la base de données
	 * @param nom	Nom du piège
	 * @param parcelle_id	Identifiant de la parcelle possedant ce piège
	 * @return Le piège ciblé
	 */
	public Piege getPiegeWithNOM(String nom, int parcelle_id){
		Piege piege;
		Cursor cp = db.query(TABLE_CAMPAGNE, new String[]{COL_ID, COL_PARCEL_ID, COL_NOM, COL_DATE_DEBUT, COL_DATE_FIN, COL_ADRESSE, COL_LATITUDE, COL_LONGITUDE, COL_DESCRIPTION}, COL_NOM + " LIKE \"" + nom + "\" AND " + COL_PARCEL_ID + " LIKE \"" + parcelle_id + "\"", null, null, null, null);
		cp.moveToFirst();
		piege = CursorToPiege(cp);
		cp.close();
		
		return piege;		
	}

	/** Importe un piège de la base de données
	 * @param id	Identifiant du piège
	 * @param parcelle_id	Identifiant de la parcelle possedant ce piège
	 * @return Le piège ciblé
	 */
	public Piege getPiegeWithID(int id, int parcelle_id){
		Piege piege;
		Cursor cp = db.query(TABLE_CAMPAGNE, new String[]{COL_ID, COL_PARCEL_ID, COL_NOM, COL_DATE_DEBUT, COL_DATE_FIN, COL_ADRESSE, COL_LATITUDE, COL_LONGITUDE, COL_DESCRIPTION}, COL_ID + " LIKE \"" + id + "\" AND " + COL_PARCEL_ID + " LIKE \"" + parcelle_id + "\"", null, null, null, null);
		cp.moveToFirst();
		piege = CursorToPiege(cp);
		cp.close();
		
		return piege;		
	}
	
	/** Importe touts les pièges de la parcelle depuis la base de données
	 * @param parcelle_id 	Identifiant de la parcelle
	 * @return Vecteur de pièges appartenant à la parcelle  
	 */
	public Vector<Piege> getPieges(int parcelle_id){
		Vector<Piege> pieges = null;
		Cursor cp = db.query(TABLE_CAMPAGNE, new String[]{COL_ID, COL_PARCEL_ID, COL_NOM, COL_DATE_DEBUT, COL_DATE_FIN, COL_ADRESSE, COL_LATITUDE, COL_LONGITUDE, COL_DESCRIPTION}, COL_PARCEL_ID + " LIKE \"" + parcelle_id + "\"", null, null, null, null);
		cp.moveToFirst();
		for(int i=0; i < cp.getCount() ; ++i) {
			cp.moveToPosition(i);
			if(pieges == null)
				pieges = new Vector<Piege>();
			
			Piege piege = CursorToPiege(cp);
			pieges.add(piege);
		}
			
		cp.close();
		return pieges;
	}
	
	/** Convertit une ligne de la base de données en piège
	 * @param cc	curseur de la base de données
	 * @return Un piège
	 */
	private Piege CursorToPiege(Cursor cc) {
		// TODO Auto-generated method stub
		if(cc.getCount() == 0)
			return null;
		
		Piege piege = new Piege();
		
		piege.setId(cc.getInt(NUM_COL_ID));
		piege.setParcelle_id(cc.getInt(NUM_COL_CAMP_ID));
		piege.setNom(cc.getString(NUM_COL_NOM));
		piege.setDate_debut(cc.getString(NUM_COL_DATE_DEBUT));
		piege.setDate_fin(cc.getString(NUM_COL_DATE_FIN));
		piege.setAdresse(cc.getString(NUM_COL_ADRESSE));
		piege.setLatitude(cc.getString(NUM_COL_LATITUDE));
		System.out.println(cc.getString(NUM_COL_LATITUDE).toString());
		System.out.println(cc.getString(NUM_COL_LONGITUDE).toString());
		piege.setLongitude(cc.getString(cc.getColumnIndex(COL_LONGITUDE)));
		piege.setDescription(cc.getString(NUM_COL_DESCRIPTION));
		
		return piege;
	}
	
}
