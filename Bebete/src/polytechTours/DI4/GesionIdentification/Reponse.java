package polytechTours.DI4.GesionIdentification;

import java.util.Vector;


import android.graphics.Bitmap;

public class Reponse 
{
	private String id;
	private String reponse;
	private String legende;
	private String idQuestionSuivante;
	private Vector<String> listeImage = new Vector<String>();
	private Bitmap[] bitmaps;
	private Resultat resultat;
	
	public Reponse()
	{
		reponse = "";
		legende = "";
		idQuestionSuivante="";
	}
	
	public Reponse(String rep )
	{
		reponse = rep;
		legende = "";
	}
	
	//**************************************
	
	public String getReponse() {
		return reponse;
	}

	public Resultat getResultat() {
		return resultat;
	}

	public void setResultat(Resultat resultat) {
		this.resultat = resultat;
	}

	public Vector<String> getListeImage() {
		return listeImage;
	}

	public void setListeImage(Vector<String> listeImage) {
		this.listeImage = listeImage;
	}

	public String getLegende() {
		return legende;
	}

	public void setLegende(String legende) {
		this.legende = legende;
	}

	public void setReponse(String reponse) {
		this.reponse = reponse;
	}

	public Bitmap[] getmImageIds() {
		return bitmaps;
	}

	public void setmImageIds(Bitmap[] mImageIds) {
		this.bitmaps = mImageIds;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getIdQuestionSuivante() {
		return idQuestionSuivante;
	}

	public void setIdQuestionSuivante(String idQuestionSuivante) {
		this.idQuestionSuivante = idQuestionSuivante;
	}
}
