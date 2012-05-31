package polytechTours.DI4.bdd;

import java.util.Vector;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

/** Interaction entre une récolte et la base de données.
 * Met en place les méthodes d'ajout, modification et suppression d'éléments dans la table de récolte*/
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
	
	/** "Instentiation" de la base de données
	 * @param context	Contexte de l'application
	 */
	public RecolteBDD(Context context) {
		bdd = new GestionBDD(context, BDD_NAME, null, BDD_VESTION);
	}
	
	/** Ouvre la base de données
	 */
	public void open(){
		db = bdd.getWritableDatabase();
	}
	
	/*Ferme la base de données
	 */
	public void close() {
		db.close();
	}
	
	// non utilisé,brise le principe d'encapsulation
	/*public SQLiteDatabase getDB(){
		return db;
	}*/
	
	/** Ajoute ou met à jour une récolte dans la base de données
	 * @param recolte 	La récolte
	 * @return Identifiant de la nouvelle récolte en cas de création, le nombre de valeur modifié en cas de mise à jour ou -1 en cas d'échec
	 */
	public long insinsertOrUpdateRecolte(Recolte recolte){
		long value = insertRecolte(recolte);
		if( value < 0){
			Vector<Recolte> recoltes = getRecoltes(recolte.getPege_id());
			for(Recolte tmp : recoltes)
				if(tmp.getNom().compareTo(recolte.getNom()) == 0){
					recolte.setId(tmp.getId());
					value = updateRecolte(recolte);
					break;
				}
				else
					value = -1;
		}
		return value;
	}
	
	/** Ajoute une nouvelle récolte à la base de données
	 * @param recolte	La récolte à ajouter
	 * @return Identifiant de la nouvelle récolte ou -1 en cas d'échec
	 */
	public long insertRecolte( Recolte recolte){
		ContentValues values = new ContentValues();
		values.put(COL_NOM, recolte.getNom());
		values.put(COL_PIEGE_ID, recolte.getPege_id());
		values.put(COL_NOMBRE, recolte.getNombre());
		return db.insert(TABLE_RECOLTE, null, values);
	}
	
	/** Met à jour une récolte dans la base de données
	 * @param recolte	La récolte à modifier
	 * @return Nombre de colonnes modifiées
	 */
	public int updateRecolte( Recolte recolte){
		ContentValues values = new ContentValues();
		values.put(COL_NOM, recolte.getNom());
		values.put(COL_PIEGE_ID, recolte.getPege_id());
		values.put(COL_NOMBRE, recolte.getNombre());
		return db.update(TABLE_RECOLTE, values, COL_ID + " = " + recolte.getId(), null);
	}
	
	/** Supprime une récolte de la base de données
	 * @param id	Identifiant de la récolte à supprimer
	 * @return Nombre de recoltes supprimées
	 */
	public int removeRecolteWithID(int id){
		return db.delete(TABLE_RECOLTE, COL_ID + " = " + id, null);
	}
	
	/** Importe une récolterecolte de la base de données
	 * @param nom	Nom de la récolte
	 * @param piege_id	Identifiant du piège possedant cette récolte
	 * @return La recolte ciblé
	 */
	public Recolte getRecolteWithNOM(String nom, int piege_id){
		Cursor recolte = db.query(TABLE_RECOLTE, new String[]{COL_ID, COL_PIEGE_ID, COL_NOM, COL_NOMBRE}, COL_NOM + " LIKE \"" + nom + "\" AND " + COL_PIEGE_ID +" LIKE \"" + piege_id + "\"", null, null, null, null);
		return CursorToRecolte(recolte);		
	}
	
	/** Importe une récolte de la base de données
	 * @param id	Identifiant de la récolte
	 * @param piege_id	Identifiant du piège possedant cette récolte
	 * @return La recolte ciblée
	 */
	public Recolte getRecolteWithID(String id, int piege_id){
		Cursor recolte = db.query(TABLE_RECOLTE, new String[]{COL_ID, COL_PIEGE_ID, COL_NOM, COL_NOMBRE}, COL_ID + " LIKE \"" + id + "\" AND " + COL_PIEGE_ID +" LIKE \"" + piege_id + "\"", null, null, null, null);
		return CursorToRecolte(recolte);		
	}

	/** Importe toutes les récoltes du piège depuis la base de données
	 * @param piege_id 	Identifiant du piège
	 * @return Vecteur de récolte appartenant au piège  
	 */
	public Vector<Recolte> getRecoltes(int piege_id){
		Vector<Recolte> recoltes = null;
		Cursor cp = db.query(TABLE_RECOLTE, new String[]{COL_ID, COL_PIEGE_ID, COL_NOM, COL_NOMBRE}, COL_PIEGE_ID + " LIKE \"" + piege_id + "\"", null, null, null, null);
		cp.moveToFirst();
		for(int i=0; i < cp.getCount() ; ++i) {
			cp.moveToPosition(i);
			if(recoltes == null)
				recoltes = new Vector<Recolte>();
			
			Recolte recolte = CursorToRecolte(cp);
			recoltes.add(recolte);
		}
			
		cp.close();
		return recoltes;
	}
	
	/** Convertit une ligne de la base de données en récolte
	 * @param cc	curseur de la base de données
	 * @return Une récolte
	 */
	private Recolte CursorToRecolte(Cursor cr) {
		if(cr.getCount() == 0)
			return null;
		
		cr.moveToFirst();
		
		Recolte recolte = new Recolte();
		
		recolte.setId(cr.getInt(NUM_COL_ID));
		recolte.setPege_id(cr.getInt(NUM_COL_PIEGE_ID));
		recolte.setNom(cr.getString(NUM_COL_NOM));
		recolte.setNombre(cr.getInt(NUM_COL_NOMBRE));
		
		cr.close();
		
		return recolte;
	}
	
}
