package polytechTours.DI4.bdd;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

/**Interaction entre un Utilisateur et la base de données
 * Mete en place les methodes d'ajout, modification et suppression d'elements dans la table de recolte*/

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
	
	/** "Instentiation" de la base de donnée
	 * @param context	Contexte de l'application
	 */
	public UtilisateurBDD(Context context) {
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
	
	// non utilisé, prise le principe d'encapsulation
	/*public SQLiteDatabase getDB(){
		return db;
	}*/
	
	/** Ajoute un utilisateur à la base de données
	 * @param utilisateur	L'utilisateur à ajouter
	 * @return Identifiant de l'utilisateur ou -1 en cas d'écheque
	 */
	public long insertUtilisateur( Utilisateur utilisateur){
		ContentValues values = new ContentValues();
		values.put(COL_NOM, utilisateur.getNom());
		return db.insert(TABLE_USER, null, values);
	}
	
	/** Met a jour un utilisateur dans la base de données
	 * @param utilisateur	L'utilisateur à modifier
	 * @return Nombre de colonnes modifié
	 */
	public int updateUtilisateur(Utilisateur utilisateur){
		ContentValues values = new ContentValues();
		values.put(COL_NOM, utilisateur.getNom());
		return db.update(TABLE_USER, values, COL_ID + " = " + utilisateur.getId(), null);
	}
	
	/** Supprime un utilisateur de la base de données
	 * @param id	Identifiant de l'utilisateur a supprimer
	 * @return Nombre d'utilsateurs supprimés
	 */
	public int removeUtilisateurWithID(int id){
		return db.delete(TABLE_USER, COL_ID + " = " + id, null);
	}
	
	/** Importe un utilisateur de la base de données
	 * @param nom	Nom de l'utilisateur
	 * @return L'utilisateur ciblé
	 */
	public Utilisateur getUtilisateurWithNOM(String nom){
		Cursor utilisateur = db.query(TABLE_USER, new String[]{COL_ID, COL_NOM}, COL_NOM + " LIKE \"" + nom + "\"", null, null, null, null);
		return CursorToUtilisateur(utilisateur);		
	}
	
	/** Importe un utilisateur de la base de données
	 * @param id	Identifiant de l'utilisateur
	 * @return L'utilisateur ciblé
	 */
	public Utilisateur getUtilisateurWithID(int id){
		Cursor utilisateur = db.query(TABLE_USER, new String[]{COL_ID, COL_NOM}, COL_ID + " = " + id, null, null, null, null);
		return CursorToUtilisateur(utilisateur);		
	}

	/** Convertit une ligne de la base de données en un utilisateur
	 * @param cc	curseur de la base de données
	 * @return Un utilisateur
	 */
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
