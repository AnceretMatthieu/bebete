package polytechTours.DI4.fast_count;
/** 
* @file Image.java 
* @brief  L'entr�e du programme
* @author zhangzheng
* @date 2012/5/30  
* @version 0.1 
*/ 
import polytechTours.DI4.R;
import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ScrollView;
/** 
* @class Image 
* @brief L'entr�e du programme 
*   
*/ 

public class Image extends Fragment 
{
	private Windows w;             /**< le Layout principal*/
	private ScrollView s;	        /**< le ScrollView ou on met les photos*/
	private Activity activity;
	
	public void onAttach(Activity activity)  
	{
        super.onAttach(activity);
        this.activity = activity; //Sauvegarde de l'activity
	}
	
	@Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {		
		//Le fragment prend la forme du fichier layout XML passer en parametre, ici reponse.xml
        return inflater.inflate( R.layout.fast_count_main, container, false); 
    }
	
	@Override
	public void onActivityCreated (Bundle savedInstanceState)
	{
		super.onActivityCreated(savedInstanceState);       
		 w = (Windows) activity.findViewById(R.id.windows);
		 w.setActivity( activity );
	     s=(ScrollView) activity.findViewById(R.id.scrollView1);        
	     s.addView(w.k);        
	}
	
}