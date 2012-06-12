package polytechTours.DI4.bdd;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteDatabase.CursorFactory;

//en cas de problème avec la cohérence de la table :
//>http://www.sqlite.org/cvstrac/wiki?p=ForeignKeyTriggers
/**Gestion de la base de données
 * Création et Réinitialisation de la base de données
 */
public class GestionBDD extends SQLiteOpenHelper {
	//private static final String BDD_NAME = "gestion.db";
	
	private static final String TABLE_USER = "TABLE_USER";
	private static final String TABLE_CAMPAGNE = "TABLE_CAMPAGNE";
	private static final String TABLE_PARCELLE = "TABLE_PARCELLE";
	private static final String TABLE_PIEGE = "TABLE_PIEGE";
	private static final String TABLE_RECOLTE = "TABLE_RECOLTE";
	
	private static final String COL_ID = "ID";
	private static final String COL_USER_ID = "UTILISATEUR_ID";
	private static final String COL_CAMP_ID = "CAMPAGNE_ID";
	private static final String COL_PARCEL_ID = "PARCEL_ID";
	private static final String COL_PIEGE_ID = "PIEGE_ID";
	
	private static final String COL_NOM = "NOM";
	private static final String COL_DATE_DEBUT = "DATE_DEBUT";
	private static final String COL_DATE_FIN = "DATE_FIN";
	private static final String COL_DATE_RECOLTE = "DATE_RECOLTE";
	private static final String COL_ADRESSE = "ADRESSE";
	private static final String COL_LATITUDE = "LATITUDE";
	private static final String COL_LONGITUDE = "LONGITUDE";
	private static final String COL_DESCRIPTION = "DESCRIPTION";
	private static final String COL_NOMBRE = "NOMBRE";
	
	/** Commande SQLite pour la création de la table utilisateur
	 * @return Commande SQLite au format texte
	 */
	private static final String CREATE_USER_DB = 
			"CREATE TABLE " +
					TABLE_USER + " (" +
					COL_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
					COL_NOM + " TEXT NOT NULL, "+
					"UNIQUE (" + COL_NOM + "));";
	
	/** Commande SQLite pour la création de la table campagne
	 * @return Commande SQLite au format texte
	 */
	private static final String CREATE_CAMPAGNE_DB = 
			"CREATE TABLE " +
					TABLE_CAMPAGNE + " (" +
					COL_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
					COL_USER_ID + " INTEGER NOT NULL, " +
					COL_NOM + " TEXT NOT NULL, " +
					COL_DATE_DEBUT + " DATE, " +
					COL_DATE_FIN + " DATE, " +
					COL_ADRESSE + " VARCHAR(250), " +
					COL_LATITUDE + " VARCHAR(25), " +
					COL_LONGITUDE + " VARCHAR(25), " +
					COL_DESCRIPTION + " VARCHAR(1024), " +
					"FOREIGN KEY("+ COL_USER_ID + ") REFERENCES " + TABLE_USER + "(" + COL_ID + ") ON DELETE CASCADE, " +
					"UNIQUE (" + COL_USER_ID + "," + COL_NOM + "));";
	
	/** Commande SQLite pour la création de la table parcelle
	 * @return Commande SQLite au format texte
	 */
	private static final String CREATE_PARCEL_DB = 
			"CREATE TABLE " +
					TABLE_PARCELLE + " (" +
					COL_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
					COL_CAMP_ID + " INTEGER NOT NULL, " +
					COL_NOM + " TEXT NOT NULL, " +
					COL_DATE_DEBUT + " DATE, " +
					COL_DATE_FIN + " DATE, " +
					COL_ADRESSE + " VARCHAR(250), " +
					COL_LATITUDE + " VARCHAR(25), " +
					COL_LONGITUDE + " VARCHAR(25), " +
					COL_DESCRIPTION + " VARCHAR(1024), " +
					"FOREIGN KEY(" + COL_CAMP_ID + ") REFERENCES " + TABLE_CAMPAGNE + "(" + COL_ID + ") ON DELETE CASCADE, " +
					"UNIQUE (" + COL_CAMP_ID + "," + COL_NOM + "));";
	
	/** Commande SQLite pour la création de la table piège
	 * @return Commande SQLite au format texte
	 */
	private static final String CREATE_PIEGE_DB = 
			"CREATE TABLE " +
					TABLE_PIEGE + " (" +
					COL_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
					COL_PARCEL_ID + " INTEGER NOT NULL, " +
					COL_NOM + " TEXT NOT NULL, " +
					COL_DATE_DEBUT + " DATE, " +
					COL_DATE_FIN + " DATE, " +
					COL_ADRESSE + " VARCHAR(250), " +
					COL_LATITUDE + " VARCHAR(25), " +
					COL_LONGITUDE + " VARCHAR(25), " +
					COL_DESCRIPTION + " VARCHAR(1024), " +
					"FOREIGN KEY(" + COL_PARCEL_ID +") REFERENCES " + TABLE_PARCELLE + "(" + COL_ID + ") ON DELETE CASCADE, " +
					"UNIQUE (" + COL_PARCEL_ID + "," + COL_NOM + "," + COL_DATE_FIN + "));";
	
	/** Commande SQLite pour la création de la table recolte
	 * @return Commande SQLite au format texte
	 */
	private static final String CREATE_RECOLTE_DB = 
			"CREATE TABLE " + 
					TABLE_RECOLTE + "(" +
					COL_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " + 
					COL_PIEGE_ID + " INTEGER NOT NULL, " + 
					COL_NOM + " VARCHAR(50), " +
					COL_NOMBRE + " INTEGER, " +
					COL_DATE_RECOLTE + " DATE, " +
					"FOREIGN KEY(" + COL_PIEGE_ID +") REFERENCES " + TABLE_PARCELLE + "(" + COL_ID + ") ON DELETE CASCADE, " +
					"UNIQUE (" + COL_PIEGE_ID + "," + COL_NOM + "));";
	
	/** Constructeur de GestionBDD en lien avec SQLiteOpenHelper*/
	public GestionBDD(Context context, String name, CursorFactory factory, int version) {
		super(context, name, factory, version);
	}
	
	@Override
	public void onCreate(SQLiteDatabase db){	
		db.execSQL("PRAGMA foreign_keys = ON"); //force la contraintes sur les clefs etrangere
		db.execSQL(CREATE_USER_DB); //création de la table utilisateur
		db.execSQL(CREATE_CAMPAGNE_DB); //création de la table campagne
		db.execSQL(CREATE_PARCEL_DB); //création de la table parcelle
		db.execSQL(CREATE_PIEGE_DB); //création de la table piège
		db.execSQL(CREATE_RECOLTE_DB); //création de la table piège
	}
	
	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		// On détruit et on recrée la table
		db.execSQL("DROP TABLE " + TABLE_USER + ";");
		db.execSQL("DROP TABLE " + TABLE_CAMPAGNE + ";");
		db.execSQL("DROP TABLE " + TABLE_PARCELLE + ";");
		db.execSQL("DROP TABLE " + TABLE_PIEGE + ";");
		db.execSQL("DROP TABLE " + TABLE_RECOLTE + ";");
		onCreate(db);
	}
}
