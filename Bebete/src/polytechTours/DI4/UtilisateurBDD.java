package polytechTours.DI4;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class UtilisateurBDD {
	private static final String BDD_NAME = "gestion.db";
	private static final int BDD_VESTION = 1;
	private static final String TABLE_USER = "TABLE_USER";
	
	private static final String COL_ID = "ID";
	private static final int NUM_COL_ID = 0;
	private static final String COL_NOM = "NOM";
	private static final int NUM_COL_NOM = 1;
	
	private SQLiteDatabase db;
	private GestionBDD bdd;
	
	public UtilisateurBDD(Context context) {
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
	
	public long insertUtilisateur( Utilisateur utilisateur){
		ContentValues values = new ContentValues();
		values.put(COL_NOM, utilisateur.getNom());
		return db.insert(TABLE_USER, null, values);
	}
	
	public int updateUtilisateur(int id, Utilisateur utilisateur){
		ContentValues values = new ContentValues();
		values.put(COL_NOM, utilisateur.getNom());
		return db.update(TABLE_USER, values, COL_ID + " = " + id, null);
	}
	
	public int removeUtilisateurWithID(int id){
		return db.delete(TABLE_USER, COL_ID + " = " + id, null);
	}
	
	public Utilisateur getUtilisateurWithNOM(String nom){
		Cursor utilisateur = db.query(TABLE_USER, new String[]{COL_ID, COL_NOM}, COL_NOM + " LIKE \"" + nom + "\"", null, null, null, null);
		return CursorToUtilisateur(utilisateur);		
	}

	private Utilisateur CursorToUtilisateur(Cursor cu) {
		if(cu.getCount() == 0)
			return null;
		
		cu.moveToFirst();
		
		Utilisateur utilisateur = new Utilisateur();
		
		utilisateur.setId(cu.getInt(NUM_COL_ID));
		utilisateur.setNom(cu.getString(NUM_COL_NOM));
		
		cu.close();
		
		return utilisateur;
	}
	
}
