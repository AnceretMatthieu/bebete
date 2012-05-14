package polytechTours.DI4;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class RecolteBDD {
	private static final String BDD_NAME = "gestion.db";
	private static final int BDD_VESTION = 1;
	private static final String TABLE_RECOLTE = "TABLE_RECOLTE";
	
	private static final String COL_ID = "ID";
	private static final int NUM_COL_ID = 0;
	private static final String COL_PIEGE_ID = "PIEGE_ID";
	private static final int NUM_COL_PIEGE_ID = 1;
	private static final String COL_NOM = "NOM";
	private static final int NUM_COL_NOM = 2;
	private static final String COL_NOMBRE = "NOMBRE";
	private static final int NUM_COL_NOMBRE = 3;
	
	private SQLiteDatabase db;
	private GestionBDD bdd;
	
	public RecolteBDD(Context context) {
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
	
	public long insinsertOrUpdateRecolte(int id, Recolte recolte){
		long value = insertRecolte(recolte);
		if( value < 0)
			value = updateRecolte(id, recolte);
		return value;
	}
	
	public long insertRecolte( Recolte recolte){
		ContentValues values = new ContentValues();
		values.put(COL_NOM, recolte.getNom());
		values.put(COL_PIEGE_ID, recolte.getPege_id());
		values.put(COL_NOMBRE, recolte.getNombre());
		return db.insert(TABLE_RECOLTE, null, values);
	}
	
	public int updateRecolte(int id, Recolte recolte){
		ContentValues values = new ContentValues();
		values.put(COL_NOM, recolte.getNom());
		values.put(COL_PIEGE_ID, recolte.getPege_id());
		values.put(COL_NOMBRE, recolte.getNombre());
		return db.update(TABLE_RECOLTE, values, COL_ID + " = " + id, null);
	}
	
	public int removeRecolteWithID(int id){
		return db.delete(TABLE_RECOLTE, COL_ID + " = " + id, null);
	}
	
	public Recolte getRecolteWithNOM(String nom){
		Cursor recolte = db.query(TABLE_RECOLTE, new String[]{COL_ID, COL_PIEGE_ID, COL_NOM, COL_NOMBRE}, COL_NOM + " LIKE \"" + nom + "\"", null, null, null, null);
		return CursorToRecolte(recolte);		
	}

	private Recolte CursorToRecolte(Cursor cr) {
		if(cr.getCount() == 0)
			return null;
		
		cr.moveToFirst();
		
		Recolte recolte = new Recolte();
		
		recolte.setId(cr.getInt(NUM_COL_ID));
		recolte.setId(cr.getInt(NUM_COL_PIEGE_ID));
		recolte.setNom(cr.getString(NUM_COL_NOM));
		recolte.setNombre(cr.getInt(NUM_COL_NOMBRE));
		
		cr.close();
		
		return recolte;
	}
	
}
