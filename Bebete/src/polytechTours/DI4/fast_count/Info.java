package polytechTours.DI4.fast_count;
/** 
* @file info.java 
* @brief  le Activity pour afficher l'information d'image
* @author zhangzheng
* @date 2012/5/30  
* @version 0.1 
*/ 
import polytechTours.DI4.R;
import polytechTours.DI4.bdd.Recolte;
import polytechTours.DI4.bdd.RecolteBDD;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.View;
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
public class Info extends Activity implements ViewFactory{
	private RecolteBDD bdd; 
	private Recolte recolte;
	private int piege_id;
	private DatePicker dateView;
	private EditText nombreIndividuView;
	private EditText nomIndividuView;
	private String nomIndividu;
	private ImageView InfoSwitcher;   /**< le ImageView ou on met l'image*/
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) 
	{
	    MenuInflater inflater = getMenuInflater();
	    inflater.inflate( R.layout.actionbar, menu); 
	    return true;
	}
	
	public void onCreate(Bundle savedInstanceState) {
        
		super.onCreate(savedInstanceState);
        setContentView(R.layout.fast_count_info);        
        InfoSwitcher = (ImageView) findViewById(R.id.Switcher2);
        
        //obtenir l'url d'image qui est transmis du WINDOWS
        Intent intent=getIntent();
        String url=intent.getStringExtra("url");
        piege_id = (int) intent.getLongExtra("PIEGE_ID", -1);
        
        //obtenir le nom de l'individu
        String[] tokens = url.split("/");
        nomIndividu = tokens[tokens.length -1].substring(0, tokens[tokens.length -1].length() - 4);

        //ouverture de la base de données
        bdd = new RecolteBDD(getBaseContext());
        bdd.open();
        
        //mettre l'image dans un ImageView
        BitmapFactory.Options options = new BitmapFactory.Options();
		options.inJustDecodeBounds = true;
		Bitmap bitmap =BitmapFactory.decodeFile(url,options);
		
		options.inJustDecodeBounds = false;
		int be = options.outHeight/100;
		if (be <= 0) {  be = 10;  }
		
		options.inSampleSize = be;
		bitmap = BitmapFactory.decodeFile(url,options);       
        
        InfoSwitcher.setImageBitmap(bitmap);
        
      //récupère les paramètres de l'application
        dateView = (DatePicker) findViewById(R.id.datePicker1 );
        nombreIndividuView = (EditText) findViewById(R.id.NombreIndividu );
        nomIndividuView = (EditText) findViewById(R.id.NomIndividu );
        nomIndividuView.setText(nomIndividu);
        	
        recolte = bdd.getRecolteWithNOM(nomIndividu, piege_id);
		if(recolte == null)
			recolte = new Recolte();
		
        nombreIndividuView.setText(String.valueOf(recolte.getNombre()));
        
        //creation de la recolte
       	
        

		/**gestion du bouton valider**/
		final Button bouttonValider= (Button) findViewById(R.id.valider);
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
        		
            	Intent activInfo=new Intent(Info.this,Image.class);
            	startActivity(activInfo);
            }
		});
		
		/**gestion du bouton annuler**/
		final Button bouttonAnnuler = (Button) findViewById(R.id.annuler);
		bouttonAnnuler.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {        
        		
            	Intent activInfo=new Intent(Info.this,Image.class);
            	startActivity(activInfo);
            }
		});
	}

	public View makeView() {
		// TODO Auto-generated method stub
		ImageView iv = new ImageView(this);
        iv.setBackgroundColor(0xFF000000);
        iv.setScaleType(ImageView.ScaleType.FIT_CENTER);
        iv.setLayoutParams(new ImageSwitcher.LayoutParams(LayoutParams.FILL_PARENT,LayoutParams.FILL_PARENT));
        return iv;
	}
	
}