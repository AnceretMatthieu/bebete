package polytechTours.DI4;

import java.util.Vector;

public class Resultat
{
	private String id;
	private String nom;
	private String type;
	private String regimeAlimentaire;
	private String information;
	private Vector<String> listeImage = new Vector<String>();
	
	//****** Getters setters
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public String getRegimeAlimentaire() {
		return regimeAlimentaire;
	}
	public void setRegimeAlimentaire(String regimeAlimentaire) {
		this.regimeAlimentaire = regimeAlimentaire;
	}
	public String getInformation() {
		return information;
	}
	public void setInformation(String information) {
		this.information = information;
	}
	public Vector<String> getListeImage() {
		return listeImage;
	}
	public void setListeImage(Vector<String> listeImage) {
		this.listeImage = listeImage;
	}
	
	

}
