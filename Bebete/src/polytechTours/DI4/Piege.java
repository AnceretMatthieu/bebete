package polytechTours.DI4;

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
	
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getUtilisateur_id() {
		return parcelle_id;
	}

	public void setUtilisateur_id(int campagne_id) {
		this.parcelle_id = campagne_id;
	}
	
	public String getNom() {
		return nom;
	}
	
	public void setNom(String nom) {
		this.nom = nom;
	}
	
	public String getDate_debut() {
		return date_debut;
	}
	
	public void setDate_debut(String date_debut) {
		this.date_debut = date_debut;
	}
	
	public String getDate_fin() {
		return date_fin;
	}
	
	public void setDate_fin(String date_fin) {
		this.date_fin = date_fin;
	}
	
	public String getAdresse() {
		return adresse;
	}
	
	public void setAdresse(String adresse) {
		this.adresse = adresse;
	}
	
	public String getLatitude() {
		return latitude;
	}

	public void setLatitude(String latitude) {
		this.latitude = latitude;
	}

	public String getLongitude() {
		return longitude;
	}

	public void setLongitude(String longitude) {
		this.longitude = longitude;
	}
	
	public String getDescription() {
		return description;
	}
	
	public void setDescription(String description) {
		this.description = description;
	}
	
	@Override
	public String toString() {
		return "Campagne [id=" + id + ", utilisateur_id=" + parcelle_id
				+ ", nom=" + nom + ", date_debut=" + date_debut + ", date_fin="
				+ date_fin + ", adresse=" + adresse + ", latitude=" + latitude
				+ ", longitude=" + longitude + ", description=" + description
				+ "]";
	}
	
	
}
