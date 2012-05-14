package polytechTours.DI4;

public class Recolte {
	private int id;
	private int pege_id;
	private String nom;
	private int nombre;
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getPege_id() {
		return pege_id;
	}
	public void setPege_id(int ipege_id) {
		this.pege_id = ipege_id;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public int getNombre() {
		return nombre;
	}
	public void setNombre(int nombre) {
		this.nombre = nombre;
	}
	@Override
	public String toString() {
		return "Recolte [id=" + id + ", ipege_id=" + pege_id + ", nom=" + nom
				+ ", nombre=" + nombre + "]";
	}
}
