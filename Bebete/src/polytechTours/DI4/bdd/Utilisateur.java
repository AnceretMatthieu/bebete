package polytechTours.DI4.bdd;

/** Classe definissanr un utilisateur
 * Elle prends en compte : 
 * 	L'identifiant de l'utilisateur - 
 * 	Le nom de l'utilisateur - 
 */
public class Utilisateur {
	private int id;
	private String nom;
	
	/** Indique l'idantifiant de l'utilisateur
	 * @return 	Identitifiant de l'utilisateur
	 */
	public int getId() {
		return id;
	}
	
	/** Modifie l'idantifiant de ll'utilisateur
	 * @param id	Identifiant de l'utilisateur
	 * @note ne garenti pas la coherance de la base de données
	 */
	public void setId(int id) {
		this.id = id;
	}
	
	/** Indique le nom de l'utilisateur
	 * @return Nom de l'utilisateur
	 */
	public String getNom() {
		return nom;
	}
	
	/** Modifie le nom de l'utilisateur
	 * @param nom Nom de l'utilisateur
	 */
	public void setNom(String nom) {
		this.nom = nom;
	}
	@Override
	/** Sérialise l'Utilisateur
	 * @return l'Ultisateur sous forme texte
	 */
	public String toString() {
		return "Utilisateur [id=" + id + ", nom=" + nom + "]";
	}	
	
	/** Renvoie les attributs de l'Utilisateur au format CSV avec le point-virgule comme séparateur 
	 * @return l'Utilisateur sous la forme CSV
	 */
	public String toCSV(){
		return id + ";" + nom;
	}
	
	/** Renvoie l'entête des colonnes du format CSV
	 * @return L'entête des colonnes
	 */
	public String headerCSV() {
		return "id;nom";
	}	
}
