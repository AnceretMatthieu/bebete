package polytechTours.DI4;

import java.util.Vector;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class CampagneBDD {
	private static final String BDD_NAME = "gestion.db";
	private static final String TABLE_CAMPAGNE = "TABLE_CAMPAGNE";
	private static final int BDD_VESTION = 1;
	
	private static final String COL_ID = "ID";
	private static final int NUM_COL_ID = 0; 
	private static final String COL_USER_ID = "UTILISATEUR_ID";
	private static final int NUM_COL_USER_ID = 1; 
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
	
	public CampagneBDD(Context context) {
		bdd = new GestionBDD(context, BDD_NAME, null, BDD_VESTION);
	}
	
	public void open(){
		db = bdd.getWritableDatabase();
	}
	
	public void close() {
		db.close();
	}
	
	public SQLiteDatabase getDB(){
		return db;
	}
	
	public long insertCampagne( Campagne campagne){
		ContentValues values = new ContentValues();
		values.put(COL_USER_ID, campagne.getUtilisateur_id());
		values.put(COL_NOM, campagne.getNom());
		values.put(COL_DATE_DEBUT, campagne.getDate_debut());
		values.put(COL_DATE_FIN, campagne.getDate_fin());
		values.put(COL_ADRESSE, campagne.getAdresse());
		values.put(COL_LATITUDE, campagne.getLatitude());
		values.put(COL_LONGITUDE, campagne.getLongitude());
		values.put(COL_DESCRIPTION, campagne.getDescription());
		return db.insert(TABLE_CAMPAGNE, null, values);
	}
	
	public int updateCamapagne(Campagne campagne){
		ContentValues values = new ContentValues();
		values.put(COL_USER_ID, campagne.getUtilisateur_id());
		values.put(COL_NOM, campagne.getNom());
		values.put(COL_DATE_DEBUT, campagne.getDate_debut());
		values.put(COL_DATE_FIN, campagne.getDate_fin());
		values.put(COL_ADRESSE, campagne.getAdresse());
		values.put(COL_LATITUDE, campagne.getLatitude());
		values.put(COL_LONGITUDE, campagne.getLongitude());
		values.put(COL_DESCRIPTION, campagne.getDescription());
		return db.update(TABLE_CAMPAGNE, values, COL_ID + " = " + campagne.getId(), null);
	}
	
	public int removeCampagneWithID(int id){
		return db.delete(TABLE_CAMPAGNE, COL_ID + " = " + id, null);
	}
	
	public Campagne getCampagneWithNOM(String nom, int utilisateur_id){
		Campagne campagne;
		Cursor cc = db.query(TABLE_CAMPAGNE, new String[]{COL_ID, COL_USER_ID, COL_NOM, COL_DATE_DEBUT, COL_DATE_FIN, COL_ADRESSE, COL_LATITUDE, COL_LONGITUDE, COL_DESCRIPTION}, COL_NOM + " LIKE \"" + nom + "\" AND " + COL_USER_ID + " LIKE \"" + utilisateur_id + "\"", null, null, null, null);
		cc.moveToFirst();
		campagne = CursorToCampagne(cc);
		cc.close();
		
		return campagne;		
	}

	public Vector<Campagne> getCampagnes(int utilisateur_id){
		Vector<Campagne> campagnes = null;
		Cursor cc = db.query(TABLE_CAMPAGNE, new String[]{COL_ID, COL_USER_ID, COL_NOM, COL_DATE_DEBUT, COL_DATE_FIN, COL_ADRESSE, COL_LATITUDE, COL_LONGITUDE, COL_DESCRIPTION}, COL_USER_ID + " LIKE \"" + utilisateur_id + "\"", null, null, null, null);
		cc.moveToFirst();
		for(int i=0; i < cc.getCount() ; ++i) {
			cc.moveToPosition(i);
			if(campagnes == null)
				campagnes = new Vector<Campagne>();
			
			Campagne campagne = CursorToCampagne(cc);
			campagnes.add(campagne);
		}
			
		cc.close();
		return campagnes;
	}
	
	private Campagne CursorToCampagne(Cursor cc) {
		// TODO Auto-generated method stub
		if(cc.getCount() == 0)
			return null;
		
		Campagne campagne = new Campagne();
		
		campagne.setId(cc.getInt(NUM_COL_ID));
		campagne.setUtilisateur_id(cc.getInt(NUM_COL_USER_ID));
		campagne.setNom(cc.getString(NUM_COL_NOM));
		campagne.setDate_debut(cc.getString(NUM_COL_DATE_DEBUT));
		campagne.setDate_fin(cc.getString(NUM_COL_DATE_FIN));
		campagne.setAdresse(cc.getString(NUM_COL_ADRESSE));
		campagne.setLatitude(cc.getString(NUM_COL_LATITUDE));
		System.out.println(cc.getString(NUM_COL_LATITUDE).toString());
		System.out.println(cc.getString(NUM_COL_LONGITUDE).toString());
		campagne.setLongitude(cc.getString(cc.getColumnIndex(COL_LONGITUDE)));
		campagne.setDescription(cc.getString(NUM_COL_DESCRIPTION));
		
		return campagne;
	}
	
}
