package polytechTours.DI4.bdd;

/** Classe définissant une campagne.
 * Elle prend en compte  :
 * 	L'identifiant dans la base de données - 
 * 	L'identifiant de l'utilisateur qui la possède - 
 * 	Un nom - 
 * 	Une date de début - 
 * 	Une date de fin - 
 * 	Une adresse - 
 * 	Une latitude - 
 * 	Une longitude - 
 * 	Une description - 
 */
public class Campagne {

	private int id;
	private int utilisateur_id;
	private String nom;
	private String date_debut;
	private String date_fin;
	private String adresse;
	private String latitude;
	private String longitude;
	private String description;
	
	/** Indique l'identifiant de la campagne
	 * @return 	Identitifiant de campagne
	 */
	public int getId() {
		return id;
	}
	
	/** Modifie l'identifiant de la campagne
	 * @param id	Identifiant de la camagne
	 * @note ne garantit pas la cohérance de la base de données
	 */
	public int setId(int id) {
		return this.id = id;
	}

	/** Indique l'identifiant de l'utilisateur possèdant la campagne
	 * @return Identifiant d'un utilisateur
	 */
	public int getUtilisateur_id() {
		return utilisateur_id;
	}

	/* Modifie le propriétaire de la campagne
	 * @param utilisateur_id	Identifiant du nouvel utilisateur
	 */
	public void setUtilisateur_id(int utilisateur_id) {
		this.utilisateur_id = utilisateur_id;
	}

	/** Indique le nom de la campagne
	 * @return Nom de la campagne
	 */
	public String getNom() {
		return nom;
	}
	
	/** Modifie le nom de la campagne
	 * @param nom	Nouveau nom de la campagne
	 */
	public void setNom(String nom) {
		this.nom = nom;
	}
	
	/** Indique la date de début
	 * @return Date de début en format texte
	 */
	public String getDate_debut() {
		return date_debut;
	}
	
	/** Modifie la date de début
	 * @param date_debut	Nouvelle date de début
	 */
	public void setDate_debut(String date_debut) {
		this.date_debut = date_debut;
	}
	
	/** Indique la date de fin
	 * @return Date de fin en format texte
	 */
	public String getDate_fin() {
		return date_fin;
	}
	
	/** Modifie la date de fin
	 * @param date_fin	Nouvelle date de fin
	 */
	public void setDate_fin(String date_fin) {
		this.date_fin = date_fin;
	}
	
	/** Indique l'adresse
	 * @return Adresse de la campagne
	 */
	public String getAdresse() {
		return adresse;
	}
	
	/** Modifie l'adresse de la campagne
	 * @param adresse	Nouvelle adresse
	 */
	public void setAdresse(String adresse) {
		this.adresse = adresse;
	}
	
	/** Indique la latitude sous forme texte
	 * @return Latidude 
	 */
	public String getLatitude() {
		return latitude;
	}

	/** Modifie la latitude
	 * @param latitude	Nouvelle latitude
	 */
	public void setLatitude(String latitude) {
		this.latitude = latitude;
	}

	/** Indique la longitude sous forme texte
	 * @return Longitude 
	 */
	public String getLongitude() {
		return longitude;
	}

	/** Modifie la longitude
	 * @param longitude	Nouvelle longitude
	 */
	public void setLongitude(String longitude) {
		this.longitude = longitude;
	}
	
	/** Donne la description
	 * @return description
	 */
	public String getDescription() {
		return description;
	}
	
	/** Modifie la description
	 * @param description	Nouvelle description
	 */
	public void setDescription(String description) {
		this.description = description;
	}
	
	@Override
	/** Sérialise la campagne
	 * @return la campagne sous forme texte
	 */
	public String toString() {
		return "Campagne [id=" + id + ", utilisateur_id=" + utilisateur_id
				+ ", nom=" + nom + ", date_debut=" + date_debut + ", date_fin="
				+ date_fin + ", adresse=" + adresse + ", latitude=" + latitude
				+ ", longitude=" + longitude + ", description=" + description
				+ "]";
	}
	
	/** Renvoie les atributs de la camagne au format CSV avec le point-virgule comme séparateur
	 * @return la campagne sous la forme CSV
	 */
	public String toCSV() {
		return id + ";" +utilisateur_id + ";" + nom + ";" + date_debut + ";" + date_fin + ";" + adresse + ";" + latitude	+ ";" + longitude + ";" + description;
	}
	
	/** Renvoie l'entête des colonnes du format CSV
	 * @return L'entête des colonnes
	 */
	public static String headerCSV(){
		return "campagne_id;utilisateur_id;campagne_nom;campagne_date_debut;campagne_date_fin;campagne_adresse;campagne_latitude;campagne_longitude;campagne_description";
	}
}
