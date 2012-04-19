package polytechTours.DI4;

import java.util.Vector;

public class Question 
{
	private String question;
	private String aide;
	private String cheminImage;
	private Vector<Reponse> listReponse = new Vector<Reponse>();
	
	public Question()
	{
		question = "";
		aide = "";
		cheminImage= "";
	}
	
	public Question( String ques, String help, String path )
	{
		question = ques;
		aide = help;
		path = cheminImage;
		remplirListeReponse();
	}
		
	//******************************************
	private void remplirListeReponse()
	{
		//parse XML pour retrouver ces reponses
		Reponse rep1 = new Reponse();
		listReponse.add(rep1);
		Reponse rep2 = new Reponse();
		listReponse.add(rep2);
		/*Reponse rep3 = new Reponse();
		listReponse.add(rep3);
		Reponse rep4 = new Reponse();
		listReponse.add(rep4);
		Reponse rep5 = new Reponse();
		listReponse.add(rep5);
		Reponse rep6 = new Reponse();
		listReponse.add(rep6);*/
	}
	
	//******************************************
	public String getQuestion() {
		return question;
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
