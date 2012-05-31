package polytechTours.DI4.fast_count;
/** 
* @file info.java 
* @brief  le Activity pour afficher l'information d'image
* @author zhangzheng
* @date 2012/5/30  
* @version 0.1 
*/ 
import java.io.File;

import polytechTours.DI4.R;
import polytechTours.DI4.GesionIdentification.FileManager;
import polytechTours.DI4.bdd.Recolte;
import polytechTours.DI4.bdd.RecolteBDD;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageSwitcher;
import android.widget.ImageView;
import android.widget.Gallery.LayoutParams;
import android.widget.ViewSwitcher.ViewFactory;
/** 
* @class info 
* @brief le Activity pour afficher l'information d'image
*   
*/ 
public class Info extends Fragment implements ViewFactory
{
	private Activity activity;
	private RecolteBDD bdd; 
	private Recolte recolte;
	private int piege_id;
	private DatePicker dateView;
	private EditText nombreIndividuView;
	private EditText nomIndividuView;
	private String nomIndividu;
	private ImageView InfoSwitcher;   
	private String cheminImage;
	
	public Info( String chemin, int id )
	{
		piege_id = id;
		cheminImage = chemin;
	}

	@Override
    public void onAttach(Activity activity)  
	{
        super.onAttach(activity);
        this.activity = activity; //Sauvegarde de l'activity
	}
	
	@Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {		
		//Le fragment prend la forme du fichier layout XML passer en parametre, ici reponse.xml
        return inflater.inflate( R.layout.fast_count_info, container, false); 
    }
	
	public void onActivityCreated(Bundle savedInstanceState) 
	{  
		super.onActivityCreated(savedInstanceState);       
        InfoSwitcher = (ImageView) activity.findViewById(R.id.Switcher2);
        
        SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); 
        piege_id = (int)preferences.getLong("PIEGE_ID", -1);

        //ouverture de la base de données
        bdd = new RecolteBDD(activity.getBaseContext());
        bdd.open();
        
        //mettre l'image dans un ImageView
        BitmapFactory.Options options = new BitmapFactory.Options();
		options.inJustDecodeBounds = true;
		
		
		options.inJustDecodeBounds = false;
		int be = options.outHeight/100;
		if (be <= 0) {  be = 10;  }
		
		options.inSampleSize = be;
		Bitmap bitmap = BitmapFactory.decodeFile( FileManager.getSavePath() + File.separator + cheminImage ,options);       
        
        InfoSwitcher.setImageBitmap(bitmap);
        
      //récupère les paramètres de l'application
        dateView = (DatePicker) activity.findViewById(R.id.datePicker1 );
        nombreIndividuView = (EditText) activity.findViewById(R.id.NombreIndividu );
        nomIndividuView = (EditText) activity.findViewById(R.id.NomIndividu );
        nomIndividuView.setText(nomIndividu);
        	
        recolte = bdd.getRecolteWithNOM(nomIndividu, piege_id);
		if(recolte == null)
			recolte = new Recolte();
		
        nombreIndividuView.setText(String.valueOf(recolte.getNombre()));
        
        //creation de la recolte
       	
		/**gestion du bouton valider**/
		final Button bouttonValider= (Button) activity.findViewById(R.id.valider);
		bouttonValider.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                recolte.setNom(nomIndividu);
                if(nombreIndividuView.getText().toString() != "")
                	recolte.setNombre(Integer.parseInt(nombreIndividuView.getText().toString()));
                else
                	recolte.setNombre(0);
                recolte.setDate_recolte(dateView.getDayOfMonth()+ "/"+ dateView.getMonth() +1 + "/" + dateView.getYear());
                recolte.setPege_id(piege_id);
                
            	bdd.insinsertOrUpdateRecolte(recolte);
            	
            	Image image = new Image();
            	
        		FragmentManager manager = activity.getFragmentManager();
        		Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
        				
        		if( fragmentEnCours != null )
        		{
        			FragmentTransaction transaction = manager.beginTransaction();
        				transaction.remove( fragmentEnCours );
        			transaction.commit();
        		}
        		
        		FragmentTransaction transaction = manager.beginTransaction();
        			transaction.add( R.id.linearLayout2, image, "enCours" );
        		transaction.commit();
        		
            }
		});
		
		/**gestion du bouton annuler**/
		final Button bouttonAnnuler = (Button) activity.findViewById(R.id.annuler);
		bouttonAnnuler.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) 
            {        
            	Image image = new Image();
            	
        		FragmentManager manager = activity.getFragmentManager();
        		Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
        				
        		if( fragmentEnCours != null )
        		{
        			FragmentTransaction transaction = manager.beginTransaction();
        				transaction.remove( fragmentEnCours );
        			transaction.commit();
        		}
        		
        		FragmentTransaction transaction = manager.beginTransaction();
        			transaction.add( R.id.linearLayout2, image, "enCours" );
        		transaction.commit();
            }
		});
	}

	public View makeView() {
		ImageView iv = new ImageView(activity);
        iv.setBackgroundColor(0xFF000000);
        iv.setScaleType(ImageView.ScaleType.FIT_CENTER);
        iv.setLayoutParams(new ImageSwitcher.LayoutParams(LayoutParams.FILL_PARENT,LayoutParams.FILL_PARENT));
        return iv;
	}
	
}