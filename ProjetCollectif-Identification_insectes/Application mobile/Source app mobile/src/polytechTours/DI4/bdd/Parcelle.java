package polytechTours.DI4.bdd;

/** Classe définissant une parcelle
 * Elle prend en compte  : 
 * 	L'identifiant dans la base de données - 
 * 	L'identifiant de la campagne qui la possède - 
 * 	Un nom - 
 * 	Une date de debut - 
 * 	Une date de fin - 
 * 	Une adresse - 
 * 	Une latitude - 
 * 	Une longitude - 
 * 	Une description 
 */
public class Parcelle {

	private int id;
	private int campagne_id;
	private String nom;
	private String date_debut;
	private String date_fin;
	private String adresse;
	private String latitude;
	private String longitude;
	private String description;
	
	/** Indique l'identifiant de la parcelle
	 * @return 	Identifiant de la parcelle
	 */
	public int getId() {
		return id;
	}

	/** Modifie l'identifiant de la parcelle
	 * @param id	Identifiant de la campagne
	 * @note ne garantit pas la cohérance de la base de données
	 */
	public void setId(int id) {
		this.id = id;
	}

	/** Indique l'identifiant de la campagne possédant la parcelle
	 * @return Identifiant d'une campagne
	 */
	public int getCampagne_id() {
		return campagne_id;
	}

	/** Modifie le propriétaire de la parcelle
	 * @param campagne_id	Identifiant d'une nouvelle campagne
	 */
	public void setCampagne_id(int campagne_id) {
		this.campagne_id = campagne_id;
	}
	
	/** Indique le nom de la parcelle
	 * @return Nom de la parcelle
	 */
	public String getNom() {
		return nom;
	}
	
	/** Modifie le nom de la parcelle
	 * @param nom	Nouveau nom de la parcelle
	 */
	public void setNom(String nom) {
		this.nom = nom;
	}
	
	/** Indique la date de début
	 * @retun Date de début en format texte
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
	 * @retun Date de fin en format texte
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
	 * @return Adresse de la parcelle
	 */
	public String getAdresse() {
		return adresse;
	}
	
	/** Modifie l'adresse de la parcelle
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
	/** Sérialise la parcelle
	 * @return la parcelle sous forme texte
	 */
	public String toString() {
		return "Parcelle [id=" + id + ", campagne_id=" + campagne_id
				+ ", nom=" + nom + ", date_debut=" + date_debut + ", date_fin="
				+ date_fin + ", adresse=" + adresse + ", latitude=" + latitude
				+ ", longitude=" + longitude + ", description=" + description
				+ "]";
	}
	
	/** Renvoie les attributs de la parcelle au format CSV avec le point-virgule comme séparateur 
	 * @return la parcelle sous la forme CSV
	 */
	public String toCSV() {
		return id + ";" + campagne_id
				+ ";" + nom + ";" + date_debut + ";"
				+ date_fin + ";" + adresse + ";" + latitude
				+ ";" + longitude + ";" + description;
	}
	
	/** Renvoie l'entête des colonnes du format CSV
	 * @return L'entête des colonnes
	 */
	public static String headerCSV() {
		return "parcelle_id;campagne_id;parcelle_nom;parcelle_date_debut;parcelle_date_fin;parcelle_adresse;parcelle_latitude;parcelle_longitude;parcelle_description";
	}
	
	
}
