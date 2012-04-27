package polytechTours.DI4;

import java.util.Vector;

public class Question 
{
	private String id;
	private String question;
	private String aide;
	private String cheminImage;
	private Vector<Reponse> listReponse = new Vector<Reponse>();
	
	public Question()
	{
		id = "";
		question = "";
		aide = "";
		cheminImage= "";
	}
	
	public Question( String ques, String help, String path )
	{
		question = ques;
		aide = help;
		cheminImage = path;
	}
		
	//******************************************
	
	public String getQuestion() {
		return question;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public void setQuestion(String question) {
		this.question = question;
	}

	public String getAide() {
		return aide;
	}

	public void setAide(String aide) {
		this.aide = aide;
	}

	public String getCheminImage() {
		return cheminImage;
	}

	public void setCheminImage(String cheminImage) {
		this.cheminImage = cheminImage;
	}

	public Vector<Reponse> getListReponse() {
		return listReponse;
	}

	public void setListReponse(Vector<Reponse> listReponse) {
		this.listReponse = listReponse;
	}
}
