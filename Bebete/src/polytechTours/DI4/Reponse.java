package polytechTours.DI4;

public class Reponse 
{
	private String reponse;
	private Integer[] mImageIds = { R.drawable.image1, R.drawable.image2, R.drawable.image3, R.drawable.image4 };
	
	public Reponse()
	{
		reponse = "Ah coucou";
	}
	
	//**************************************
	public String getReponse() {
		return reponse;
	}

	public void setReponse(String reponse) {
		this.reponse = reponse;
	}

	public Integer[] getmImageIds() {
		return mImageIds;
	}

	public void setmImageIds(Integer[] mImageIds) {
		this.mImageIds = mImageIds;
	}
}
