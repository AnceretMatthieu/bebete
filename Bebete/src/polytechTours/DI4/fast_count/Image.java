package polytechTours.DI4.fast_count;
/** 
* @file Image.java 
* @brief  L'entrée du programme
* @author zhangzheng
* @date 2012/5/30  
* @version 0.1 
*/ 
import polytechTours.DI4.R;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.View;
import android.view.View.OnClickListener;

import android.widget.ScrollView;
import android.widget.Toast;
/** 
* @class Image 
* @brief L'entrée du programme 
*   
*/ 

public class Image extends Activity {
    
	private Windows w;             /**< le Layout principal*/
	private ScrollView s;	        /**< le ScrollView ou on met les photos*/
	private int piege_id;
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) 
	{
	    MenuInflater inflater = getMenuInflater();
	    inflater.inflate( R.layout.actionbar, menu); 
	    return true;
	}
	
	@Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fast_count_main);        
        
        w = (Windows) findViewById(R.id.windows);
        s=(ScrollView) findViewById(R.id.scrollView1);        
        s.addView(w.k);             /**< w.k c'est Layout pour mettre les photos*/
        
        //obtenir l'url d'image qui est transmis du WINDOWS
        Intent intent=getIntent();
        piege_id = (int) intent.getLongExtra("PIEGE_ID", -1);
        
        w.k.setOnClickListener(new OnClickListener() {
           
        	
        	public void onClick(View v) {
        		//Toast.makeText(Image.this, "111", Toast.LENGTH_SHORT).show();
            	//quand on click l'image on transmet l'url d'image à l'autre Activity info.class
            	Intent activInfo=new Intent(Image.this,Info.class);
            	
                Bundle bundle=new Bundle(); 
                bundle.putString("url", w.photoURL);
                bundle.putLong("PIEGE_ID", piege_id);
                activInfo.putExtras(bundle);
                
                startActivity(activInfo);
            }
        });
        
      
    }
}