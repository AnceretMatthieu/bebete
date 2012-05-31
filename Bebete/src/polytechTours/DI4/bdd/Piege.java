package polytechTours.DI4.bdd;

/** Classe définissant un piège
 * Elle prend en compte  : 
 * 	L'identifiant dans la base de données - 
 * 	L'identifiant de la parcelle qui le possède - 
 * 	Un nom - 
 * 	Une date de debut - 
 * 	Une date de fin - 
 * 	Une adresse - 
 * 	Une latitude - 
 * 	Une longitude - 
 * 	Une description
 */
public class Piege {

	private int id;
	private int parcelle_id;
	private String nom;
	private String date_debut;
	private String date_fin;
	private String adresse;
	private String latitude;
	private String longitude;
	private String description;
		
	/** Indique l'identifiant du piège
	 * @return 	Identitifiant du piège
	 */
	public int getId() {
		return id;
	}

	/** Modifie l'identifiant du piège
	 * @param id	Identifiant du piège
	 * @note ne garantit pas la cohérance de la base de données
	 */
	public void setId(int id) {
		this.id = id;
	}

	/** Indique l'identifiant de la parcelle possédant le piège
	 * @return Identifiant d'une parcelle
	 */
	public int getParcelle_id() {
		return parcelle_id;
	}
	
	/** Modifie le propriétaire du piège
	 * @param parcelle_id	Identifiant de la nouvelle parcelle
	 */
	public void setParcelle_id(int parcelle_id) {
		this.parcelle_id = parcelle_id;
	}
	
	/** Indique le nom du piège
	 * @return Nom du piège
	 */
	public String getNom() {
		return nom;
	}
	
	/** Modifie le nom du piège
	 * @param nom	Nouveau nom du piège
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
	 * @return Adresse du piège
	 */
	public String getAdresse() {
		return adresse;
	}
	
	/** Modifie l'adresse du piège
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
	/** Sérialise du piège
	 * @return le piège sous forme texte
	 */
	public String toString() {
		return "Campagne [id=" + id + ", parcelle_id=" + parcelle_id
				+ ", nom=" + nom + ", date_debut=" + date_debut + ", date_fin="
				+ date_fin + ", adresse=" + adresse + ", latitude=" + latitude
				+ ", longitude=" + longitude + ", description=" + description
				+ "]";
	}
	
	/** Renvoie les attributs du piège au format CSV avec le point-virgule comme séparateur 
	 * @return le piège sous la forme CSV
	 */
	public String toCSV() {
		return id + ";" + parcelle_id
				+ ";" + nom + ";" + date_debut + ";"
				+ date_fin + ";" + adresse + ";" + latitude
				+ ";" + longitude + ";" + description;
	}
	
	/** Renvoie l'entête des colonnes du format CSV
	 * @return L'entête des colonnes
	 */
	public static String headerCSV(){
		return "id;utilisateur_id;nom;date_debut;date_fin;adresse;adresse;latitude;longitude;description";
	}
	
}
