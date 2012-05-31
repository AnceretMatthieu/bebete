package polytechTours.DI4.bdd;

/** Classe définissant une récolte
 * Elle prend en compte  : 
 * 	L'identifiant dans la base de données - 
 * 	L'identifiant du piège qui la possède - 
 * 	Un nom - 
 * 	Un nombre - 
 *  Une date - 
 */
public class Recolte {
	private int id;
	private int piege_id;
	private String nom;
	private int nombre;
	private String date_recolte;
	
	/** Indique l'identifiant de la récolte
	 * @return 	Identitifiant de la récolte
	 */
	public int getId() {
		return id;
	}
	
	/** Modifie l'identifiant de la récolte
	 * @param id	Identifiant de la récolte
	 * @note ne garantit pas la cohérance de la base de données
	 */
	public void setId(int id) {
		this.id = id;
	}
	
	/** Indique l'identifiant du piège possedant la récolte
	 * @return Identifiant d'une campagne
	 */
	public int getPege_id() {
		return piege_id;
	}
	
	/** Modifie le propriétaire de la récolte
	 * @param piege_id	Idantifiant du nouveau piège
	 */
	public void setPege_id(int piege_id) {
		this.piege_id = piege_id;
	}
	
	/** Indique le nom de la récolte
	 * @return Nom de la récolte
	 */
	public String getNom() {
		return nom;
	}
	
	/** Modifie le nom de la récolte
	 * @param nom	Nouveau nom de la récolte
	 */
	public void setNom(String nom) {
		this.nom = nom;
	}
	
	/** Indique le nombre d'insectes trouvés
	 * @return Nombre d'individus
	 */
	public int getNombre() {
		return nombre;
	}
	
	/** Modifie le nombre d'insectes trouvés
	 * @param nombre	Nombre d'individus
	 */
	public void setNombre(int nombre) {
		this.nombre = nombre;
	}
	
	/** Indique la date de la collecte du piège
	 * @return date de la levée du piège
	 */
	public String getDate_recolte() {
		return date_recolte;
	}
	
	/** Modifie la date de la collecte du piège
	 * @param date_recolte Date de la levée du piège
	 */
	public void setDate_recolte(String date_recolte) {
		this.date_recolte = date_recolte;
	}
	@Override
	/** Sérialise la récolte
	 * @return la Recolte sous forme texte
	 */
	public String toString() {
		return "Recolte [id=" + id + ", piege_id=" + piege_id + ", nom=" + nom
				+ ", nombre=" + nombre + ", date_recolte=" + date_recolte + "]";
	}
	
	/** Renvoie les attributs de la Récolte au format CSV avec le point-virgule comme séparateur 
	 * @return la Recolte sous la forme CSV
	 */
	public String toCSV(){
		return id + ";" + piege_id + ";" + nom + ";" + date_recolte + ";" + nombre;
	}
	
	/** Renvoie l'entête des colonnes du format CSV
	 * @return L'entête des colonnes
	 */
	public static String headerCSV() {
		return "id;piege_id;nom;nombre;date_recolte";
	}
}
