package polytechTours.DI4.bdd;

import java.util.Vector;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

/** Interaction entre une Campagne et la base de données.
 * Met en place les méthodes d'ajout, modification et suppression d'éléments dans la table de campagne*/
public class ParcelleBDD {
	private static final String BDD_NAME = "gestion.db";
	private static final String TABLE_PARCELLE = "TABLE_PARCELLE";
	private static final int BDD_VESTION = 1;
	
	private static final String COL_ID = "ID";
	private static final int NUM_COL_ID = 0; 
	
	private static final String COL_CAMP_ID = "CAMPAGNE_ID";
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
	public ParcelleBDD(Context context) {
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
	/* public SQLiteDatabase getDB(){
		return db;
	}*/
	
	/** Ajoute une nouvelle parcelle à la base de données
	 * @param parcelle	La parcelle à ajouter
	 * @return Identifiant de la nouvelle parcelle ou -1 en cas d'échec
	 */
	public long insertParcelle( Parcelle parcelle){
		ContentValues values = new ContentValues();
		values.put(COL_CAMP_ID, parcelle.getCampagne_id());
		values.put(COL_NOM, parcelle.getNom());
		values.put(COL_DATE_DEBUT, parcelle.getDate_debut());
		values.put(COL_DATE_FIN, parcelle.getDate_fin());
		values.put(COL_ADRESSE, parcelle.getAdresse());
		values.put(COL_LATITUDE, parcelle.getLatitude());
		values.put(COL_LONGITUDE, parcelle.getLongitude());
		values.put(COL_DESCRIPTION, parcelle.getDescription());
		return db.insert(TABLE_PARCELLE, null, values);
	}
	
	/** Met à jour une parcelle dans la base de données
	 * @param parcelle	La parcelle à modifier
	 * @return Nombre de colonnes modifiées
	 */
	public int updateCamapagne(Parcelle parcelle){
		ContentValues values = new ContentValues();
		values.put(COL_CAMP_ID, parcelle.getCampagne_id());
		values.put(COL_NOM, parcelle.getNom());
		values.put(COL_DATE_DEBUT, parcelle.getDate_debut());
		values.put(COL_DATE_FIN, parcelle.getDate_fin());
		values.put(COL_ADRESSE, parcelle.getAdresse());
		values.put(COL_LATITUDE, parcelle.getLatitude());
		values.put(COL_LONGITUDE, parcelle.getLongitude());
		values.put(COL_DESCRIPTION, parcelle.getDescription());
		return db.update(TABLE_PARCELLE, values, COL_ID + " = " + parcelle.getId(), null);
	}
	
	/** Supprime une parcelle de la base de données
	 * @param id	Identifiant de la parcelle à supprimer
	 * @return Nombre de parcelles supprimées
	 */
	public int removeParcelleWithID(int id){
		return db.delete(TABLE_PARCELLE, COL_ID + " = " + id, null);
	}
	
	/** Importe une parcelle de la base de données
	 * @param nom	Nom de la parcelle
	 * @param campagne_id	Identifiant de la campagne possédant cette parcelle
	 * @return La parcelle ciblée
	 */
	public Parcelle getParcelleWithNOM(String nom, int campagne_id){
		Parcelle parcelle;
		Cursor cc = db.query(TABLE_PARCELLE, new String[]{COL_ID, COL_CAMP_ID, COL_NOM, COL_DATE_DEBUT, COL_DATE_FIN, COL_ADRESSE, COL_LATITUDE, COL_LONGITUDE, COL_DESCRIPTION}, COL_NOM + " LIKE \"" + nom + "\" AND " + COL_CAMP_ID + " LIKE \"" + campagne_id + "\"", null, null, null, null);
		cc.moveToFirst();
		parcelle = CursorToParcelle(cc);
		cc.close();
		
		return parcelle;		
	}

	/** Importe une parcelle de la base de données
	 * @param id	Identifiant de la parcelle
	 * @param campagne_id	Identifiant de l'utilisateur possédant cette camapagne
	 * @return La campagne ciblée
	 */
	public Parcelle getParcelleWithID(int id, int campagne_id){
		Parcelle parcelle;
		Cursor cc = db.query(TABLE_PARCELLE, new String[]{COL_ID, COL_CAMP_ID, COL_NOM, COL_DATE_DEBUT, COL_DATE_FIN, COL_ADRESSE, COL_LATITUDE, COL_LONGITUDE, COL_DESCRIPTION}, COL_ID + " LIKE \"" + id + "\" AND " + COL_CAMP_ID + " LIKE \"" + campagne_id + "\"", null, null, null, null);
		cc.moveToFirst();
		parcelle = CursorToParcelle(cc);
		cc.close();
		
		return parcelle;		
	}
	
	/** Importe toutes les parcelles de la campagne depuis la base de données
	 * @param campagne_id 	Identifiant de la campagne
	 * @return Vecteur de parcelles appartenant à la campagne  
	 */
	public Vector<Parcelle> getParcelles(int campagne_id){
		Vector<Parcelle> parcelles = null;
		Cursor cp = db.query(TABLE_PARCELLE, new String[]{COL_ID, COL_CAMP_ID, COL_NOM, COL_DATE_DEBUT, COL_DATE_FIN, COL_ADRESSE, COL_LATITUDE, COL_LONGITUDE, COL_DESCRIPTION}, COL_CAMP_ID + " LIKE \"" + campagne_id + "\"", null, null, null, null);
		cp.moveToFirst();
		for(int i=0; i < cp.getCount() ; ++i) {
			cp.moveToPosition(i);
			if(parcelles == null)
				parcelles = new Vector<Parcelle>();
			
			Parcelle parcelle = CursorToParcelle(cp);
			parcelles.add(parcelle);
		}
			
		cp.close();
		return parcelles;
	}
	
	/** Convertit une ligne de la base de données en parcelle
	 * @param cc	curseur de la base de données
	 * @return Une parcelle
	 */
	private Parcelle CursorToParcelle(Cursor cc) {
		// TODO Auto-generated method stub
		if(cc.getCount() == 0)
			return null;
		
		Parcelle parcelle = new Parcelle();
		
		parcelle.setId(cc.getInt(NUM_COL_ID));
		parcelle.setCampagne_id(cc.getInt(NUM_COL_CAMP_ID));
		parcelle.setNom(cc.getString(NUM_COL_NOM));
		parcelle.setDate_debut(cc.getString(NUM_COL_DATE_DEBUT));
		parcelle.setDate_fin(cc.getString(NUM_COL_DATE_FIN));
		parcelle.setAdresse(cc.getString(NUM_COL_ADRESSE));
		parcelle.setLatitude(cc.getString(NUM_COL_LATITUDE));
		System.out.println(cc.getString(NUM_COL_LATITUDE).toString());
		System.out.println(cc.getString(NUM_COL_LONGITUDE).toString());
		parcelle.setLongitude(cc.getString(cc.getColumnIndex(COL_LONGITUDE)));
		parcelle.setDescription(cc.getString(NUM_COL_DESCRIPTION));
		
		return parcelle;
	}
	
}
