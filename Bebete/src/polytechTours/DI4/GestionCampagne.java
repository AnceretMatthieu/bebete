/*package polytechTours.DI4;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class GestionCampagne extends Fragment
{
	public GestionCampagne()
	{
		super();
	}
	
	@Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {	
        // Inflate the layout for this fragment
        return inflater.inflate( R.layout.gestioncampagne, container, false);
        
    }
}*/

package polytechTours.DI4;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.Struct;
import java.text.BreakIterator;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;
import java.util.TimeZone;
import java.util.Vector;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.DatePickerDialog;
import android.app.DatePickerDialog.OnDateSetListener;
import android.app.Dialog;
import android.app.Fragment;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.location.Location;
import android.location.LocationManager;
import android.net.ParseException;
import android.os.Bundle;
import android.text.format.DateFormat;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.CompoundButton.OnCheckedChangeListener;
import android.widget.DatePicker;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.ScrollView;
import android.widget.Button;
import android.widget.TextView;
import android.widget.EditText;


public class GestionCampagne extends Fragment
{

	private Activity activity;
	private File path_campagne; //chemin du dossier application/campagnes
	private String [] liste_campagnes; //liste des fichiers dans application/campagnes
	private String active_campagne; //campagne selectionne
	private Vector<buttom_campagne> liste_buttom_campagne; //vecteur de buttom_campagne
    
	/*fait lien entre le nom de la campagne et l instance du bouton*/
	private class buttom_campagne{
		String campagne;
		RadioButton radiobutton;
	}
    
	/*affiche un date picker et retourne la date dans le champ passe en parametre*/
    private void datepikerdialog(final EditText champ) throws java.text.ParseException {

		int year = 0;
		int month = 0;
		int day = 0;
		
		if(champ.getText().toString().length() >= 9){ //une date est composé d'aumoins 9 caracters
			Log.d("debug", "La date est = " + champ.getText().toString()); 
			String [] date = champ.getText().toString().split("/");
			year = Integer.parseInt(date[2]);
			month = Integer.parseInt(date[1]);
			day = Integer.parseInt(date[0]);
			
		}else
		{
			TimeZone timeZone = TimeZone.getTimeZone("Europe/Copenhagen");
			Calendar cal=Calendar.getInstance();
			cal.setTimeZone(timeZone);
			
			year = cal.get(Calendar.YEAR);
			month = cal.get(Calendar.MONTH);
			day = cal.get(Calendar.DAY_OF_MONTH);
		}

		final OnDateSetListener odsl=new OnDateSetListener()
        {

		   public void onDateSet(DatePicker arg0, int year, int month, int dayOfMonth) {
			    // TODO Auto-generated method stub
			   champ.setText(dayOfMonth + "/" + ++month + "/" + year);//month [0,11] => +1
		   }
        };
        DatePickerDialog datePickDiag=new DatePickerDialog(activity,odsl,year,month-1,day);
	    datePickDiag.show();
	}
	/*message d alert, seul cancel est disponible*/
	protected void alertbox(String title, String mymessage){
	   new AlertDialog.Builder(activity)
	      .setMessage(mymessage)
	      .setTitle(title)
	      .setCancelable(true)
	      .setNeutralButton(android.R.string.cancel,
	         new DialogInterface.OnClickListener() {
	         public void onClick(DialogInterface dialog, int whichButton){}
	         })
	      .show();
	}
	
	/* ouvre ou ceer un fichier dans le repertoire de l'application
	 * celui-ci contient les donnees sur une campagne.
	 * Le nom de ce fichier (passé en parametre) est celui de la campagne.
	 * renvoie un flux en ecriture
	 */
	private BufferedWriter open_campagne(String name){
		BufferedWriter output;
		FileWriter fw = null;
		File file;
		try {
			file = new File(path_campagne + "/" +name + ".xml");
    	    
			if(!file.exists()){
				file.createNewFile();
    	    }
    	    
			fw = new FileWriter(file, true);

		} catch (IOException e) {
			// TODO Auto-generated catch block
			Log.d("erreur", e.toString());
		}
		
		liste_campagnes = path_campagne.list();
		
		output = new BufferedWriter(fw);	
		return output;
	}
	
	/*ferme un flux ouvert par open_campagne*/
	private void close_campagne(BufferedWriter flux){
		try {
			flux.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			Log.d("erreur", e.toString());
		}
	}
	
	/****************************************************
	 *              gestion de l affichage
	 ****************************************************/
	
    @Override
    public void onAttach(Activity activity)  
	{
        super.onAttach(activity);
        this.activity = activity;
	}

	@Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {	
        // Inflate the layout for this fragment
        return inflater.inflate( R.layout.gestioncampagne, container, false);
                
    }
	
	@Override
	public void onActivityCreated (Bundle savedInstanceState)
	{
		super.onActivityCreated(savedInstanceState);
		
		/** init variables**/
        path_campagne = this.activity.getDir("bebete", Context.MODE_PRIVATE);
        liste_campagnes = path_campagne.list();       
        path_campagne = new File(path_campagne.toString() + "/campagne/");
        path_campagne.mkdir();
        liste_campagnes = path_campagne.list();
        liste_buttom_campagne = new Vector<GestionCampagne.buttom_campagne>();
        active_campagne = null;
        
        /** phrase de selection de campagne **/
		LinearLayout layout_liste = (LinearLayout)activity.findViewById( R.id.linearLayout4 );
        TextView tv = new TextView(activity);
		tv.setText(R.string.selectionnerCampagne);
		layout_liste.addView(tv);

		//close_campagne(open_campagne("campagne" + liste_campagnes.length));
		
		/** affichage de la liste de bouton **/
		final RadioGroup radiogroup = new RadioGroup(activity); //groupe d'affichage pour la liste de radiobouton
		
		if( liste_campagnes != null)
			for(int i = 0; i < liste_campagnes.length; i++) { //pour chaque campagnes trouvee
				/** gestion des boutons **/
				RadioButton radiobt = new RadioButton(activity); //creation d un radiobouton
				radiobt.setText(liste_campagnes[i].split("\\.")[0]); //texte du bouton
				radiobt.setOnCheckedChangeListener(new OnCheckedChangeListener() //evenement
				{
				    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked)
				    {
				        if ( isChecked )
				        {
				        	/*lien entre le bouton et la liste de campagne **/
				        	for (buttom_campagne liste_bc : liste_buttom_campagne) {
								if(liste_bc.radiobutton == buttonView){
									active_campagne = liste_bc.campagne;
								}
							}
				        	/*affichage des elements dans leurs champs respectif*/
				        	EditText nomCampagne = (EditText)activity.findViewById( R.id.nomCampagne );
				    		nomCampagne.setText("Campagne n° " + buttonView.getText());
				    		
				    		EditText descriptionCamapgne = (EditText)activity.findViewById( R.id.descriptionCamapgne );
				    		descriptionCamapgne.setText("Campagne n° NAN");
				    		
				    		EditText debutCampagne = (EditText)activity.findViewById( R.id.debutCampagne );
				    		debutCampagne.setText("Campagne n° NAN");
				    		
				    		EditText finCampagne = (EditText)activity.findViewById( R.id.finCampagne );
				    		finCampagne.setText("Campagne n° NAN");
				    		
				    		EditText adresseCampagne = (EditText)activity.findViewById( R.id.adresseCampagne );
				    		adresseCampagne.setText("Campagne n° NAN");			    		
				        }
				    }
				});
				/* affichage des bouton */
				radiogroup.addView(radiobt);
				
				/**gestion de la liste de campagne**/
				buttom_campagne bc = new buttom_campagne(); //instanci une class
				bc.campagne = liste_campagnes[i]; //donne la nom de la campgne
				bc.radiobutton = radiobt; //affecte le radiobouton corespondant (celui qui vien d'etre crer)
				liste_buttom_campagne.add(bc); //ajoute cette instace a la liste
			}
		
		final EditText editTextdebutCampagne = (EditText) activity.findViewById(R.id.debutCampagne);
		editTextdebutCampagne.setOnClickListener(new View.OnClickListener(){
				public void onClick(View v) {
					try {
						datepikerdialog(editTextdebutCampagne);
					} catch (java.text.ParseException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
	    );
		
		final EditText editTextfinCampagne = (EditText) activity.findViewById(R.id.finCampagne);
		editTextfinCampagne.setOnClickListener(new View.OnClickListener(){
				public void onClick(View v) {
					try {
						datepikerdialog(editTextfinCampagne);
					} catch (java.text.ParseException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
	    );
		/**gestion du bouton selectionner**/
		final Button buttonselectionner = (Button) activity.findViewById(R.id.selectionner);
		buttonselectionner.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
    			if(active_campagne != null){
    				//fonctionelle mais non acheve
    				SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
	
    				// stock l'addresse complete de la camapgne.xml dans un setings nomé "path_active_campagne"
    				// le bute est de pouvoir le recuperer dans GestionParcel.java
		    		SharedPreferences.Editor editor = preferences.edit();
		    		editor.putString("path_active_campagne", path_campagne + active_campagne); 
		    		editor.commit();
		    		
		    		//cette partie n'a rien a faire là !!!
		    		//cela veriefie que la campagne selectionné est bien dans "path_active_campagne"
		    		//en l'affichant dans le champ "adresseCampagne"
	            	String storedPreference = preferences.getString("path_active_campagne", "");
	            	
	            	EditText adresseCampagne = (EditText)activity.findViewById( R.id.adresseCampagne );
	            	Log.d("debug", "the campagne_id is = " + storedPreference); 
		    		adresseCampagne.setText(storedPreference);
    			}else
    			{
            		//Si aucune campagne n est selectionne
    				//alertbox(R.string.attention, R.string.selectionCampagne);
            		alertbox("Attention", "Sélectionner une campagne avant de continuer");	//On ne met pas le texte ainsi, mais la forme precedante rencontre un probleme de type qui n est pas encore resolue
    			}
	    		    		
            }
        });
		
		/**gestion du bouton modifier**/
		final Button buttonmodifier = (Button) activity.findViewById(R.id.modifier);
		buttonmodifier.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	
    			if(active_campagne != null){
    				
    			}else
    			{
            		//alertbox(R.string.attention, R.string.selectionCampagne);
            		alertbox("Attention", "Sélectionner une campagne avant de continuer");	//On ne met pas le texte ainsi, mais la forme precedante rencontre un probleme de type qui n est pas encore resolue
    			}
            }
        });
		
		/**gestion du bouton supprimer**/
		final Button buttonsupprimer= (Button) activity.findViewById(R.id.supprimer);
		buttonsupprimer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	
            	if(active_campagne != null){
            		/** creation d une alerte boxe avant la suppression*/
	        		AlertDialog deleteAlert = new AlertDialog.Builder(activity).create();
	        		deleteAlert.setTitle(R.string.attention);
	        		//deleteAlert.setMessage(R.string.supprimerCampagne);
	        		deleteAlert.setMessage("Voulez-vous supprimer cette campagne ?"); //On ne met pas le texte ainsi, mais la forme precedante rencontre un probleme de type qui n est pas encore resolue
	        		/**si oui**/
	        		deleteAlert.setButton(DialogInterface.BUTTON_POSITIVE,"Oui", new DialogInterface.OnClickListener(){
	
	        			public void onClick(DialogInterface dialog, int which) {               
				        	/*lien entre le bouton et la liste de campagne **/
	        				int j = 0;
	        				
	        				/*recherche de la campgne dans la liste de type buttom_campagne*/
	        				buttom_campagne liste_bc;
	        				for(j =0; j < liste_buttom_campagne.size(); ++j){
				        		liste_bc = liste_buttom_campagne.elementAt(j);
								if(liste_bc.campagne == active_campagne){
									liste_buttom_campagne.remove(liste_bc); //delete
									radiogroup.removeViewAt(j); //suppression de la liste
									break;
								}
	        				}
	        				//suppression du campagne.xml
	        				new File(path_campagne +"/"+ active_campagne).delete();
	        				liste_campagnes = path_campagne.list();
	        				active_campagne = null; //il n'y a plus de campagne selectionne
	        			}
	        		});
	        		
	        		deleteAlert.setButton(DialogInterface.BUTTON_NEGATIVE,"Non", new DialogInterface.OnClickListener(){
	        			public void onClick(DialogInterface dialog, int which) { 
	        				//rien a faire
	        			}
	        		});
	        		
	        		deleteAlert.show();
            	} 
            	else
            	{
            		//alertbox(R.string.attention, R.string.selectionCampagne);
            		alertbox("Attention", "Sélectionner une campagne avant de continuer"); //On ne met pas le texte ainsi, mais la forme precedante rencontre un probleme de type qui n est pas encore resolue
            	}
            }
        });
		
		layout_liste.addView(radiogroup);
	}
	
	@Override
	public void onPause()
	{
	    super.onPause();
	}
	
    @Override
    public void onResume() 
    {
        super.onResume();
    }
    
    @Override
    public void onDestroy ()
    {
    	super.onDestroy();
    }
}
