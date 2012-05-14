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

import java.util.Calendar;
import java.util.TimeZone;
import java.util.Vector;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.DatePickerDialog;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.app.DatePickerDialog.OnDateSetListener;
import android.app.Fragment;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.DatePicker;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.EditText;


public class GestionCampagne extends Fragment
{
	private CampagnesButton campagnes;
	private Activity activity;
	private CampagneBDD bdd;
	private int utilisateur_id;
	private RadioGroup radiogroup;
	
    // On déclare les variables nécessaires pour le GPS
	private LocationManager locationMgr = null;
	Location curent_location = null;
	
	//Listener pour GPS
    private LocationListener onLocationChange = new LocationListener() {
    	 public void onStatusChanged(String provider, int status, Bundle extras) { }
    	 public void onProviderEnabled(String provider) { }
    	 public void onProviderDisabled(String provider) { }
    	 public void onLocationChanged(Location location)
    	 {
	    	 curent_location = location;
    	 }
    };
    
	private class CampagnesButton{
		private Vector<Campagne> vect_campagnes = null;
		private Vector<RadioButton> vect_radioButton = null;
		private int active_campagne = 0;
		
		public CampagnesButton(Vector<Campagne> vect_campagnes){
			this.vect_campagnes = vect_campagnes;

			vect_radioButton = new Vector<RadioButton> ();
			if(this.vect_campagnes == null)
				this.vect_campagnes = new  Vector<Campagne>();
			else{
				for (Campagne campagne : vect_campagnes) {
					RadioButton radiobt = new RadioButton(activity); //creation d un radiobouton
					radiobt.setText(campagne.getNom()); //texte du bouton
					vect_radioButton.add(radiobt);
					radiogroup.addView(radiobt);
				}
			}
		}

		public void insertCampagne(Campagne campagne){
			String name = campagne.getNom();
			boolean trouve = false;
			
			for ( RadioButton radiobt : vect_radioButton) {
				String btname = radiobt.getText().toString();
				if(btname.equalsIgnoreCase(name)){
					alertbox("Attention !", "La campagne existe déja.");
					trouve = true;
					break;
				}
			}
			if(trouve == false){
				bdd.insertCampagne(campagne);
				vect_campagnes.add(campagne);
				RadioButton radiobt = new RadioButton(activity); //creation d un radiobouton
				radiobt.setText(campagne.getNom()); //texte du bouton
				vect_radioButton.add(radiobt);
				radiogroup.addView(radiobt);
				radiobt.setChecked(true);
			}
		}
		
		public void removeCampagne(Campagne campagne){
			int i = 0;
			for (Campagne eachcampagne : vect_campagnes) {
				if(eachcampagne.getId() == campagne.getId()){
					bdd.removeCampagneWithID(campagne.getId());
					vect_radioButton.remove(i);
					vect_campagnes.remove(i);
					radiogroup.removeViewAt(i);
				}
				else
					i++;
			}
		}
		
		public void updateCampagne(Campagne campagne){
			int i = 0;
			for (Campagne eachcampagne : vect_campagnes) {
				if(eachcampagne.getId() == campagne.getId()){
					bdd.updateCamapagne(campagne);
					vect_campagnes.set(i, campagne);
					vect_radioButton.elementAt(i).setText(campagne.getNom());
				}
				else
					i++;
			}
		}
		
		public void setActive_campagne(int active_campagne) {
			this.active_campagne = active_campagne;
		}
		
		public Campagne getCurent_campagne(){
			return vect_campagnes.elementAt(active_campagne);
		}
		
		public int count() {
			return vect_campagnes.size();
		}
		
		public void setCheck(int i){
			vect_radioButton.elementAt(i).setChecked(true);
		}
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
	      .setNeutralButton(android.R.string.ok,
	         new DialogInterface.OnClickListener() {
	         public void onClick(DialogInterface dialog, int whichButton){}
	         })
	      .show();
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
		/**gestion du gps **/   
		//festion des réseau et du temps de pull
		locationMgr = (LocationManager) activity.getSystemService(Context.LOCATION_SERVICE);
		locationMgr.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 10000, 0, onLocationChange);
		locationMgr.requestLocationUpdates(LocationManager.GPS_PROVIDER, 10000, 0,onLocationChange);
		
		/** init variables**/
		bdd = new CampagneBDD(activity);
        bdd.open();
        
		SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
        utilisateur_id = (int)preferences.getLong("UTILISATEUR_ID", -1);
        if(utilisateur_id == -1)
        	alertbox("Attention !", "Sélectionner un utilisateur");
        
		radiogroup = new RadioGroup(activity); //groupe d'affichage pour la liste de radiobouton
		
		//affichage des parametres d'un bouton
		radiogroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
			public void onCheckedChanged(RadioGroup rg, int checkedId){
				for(int i=0; i<rg.getChildCount(); i++) {
	                   if(rg.getChildAt(i).getId() == checkedId) {
	                	   campagnes.setActive_campagne(i);
	                	   Campagne campagne = campagnes.getCurent_campagne();
	                	   
					    	/*affichage des elements dans leurs champs respectif*/
					    	EditText nomCampagne = (EditText)activity.findViewById( R.id.nomCampagne );
							nomCampagne.setText(campagne.getNom());
							
							EditText descriptionCamapgne = (EditText)activity.findViewById( R.id.descriptionCamapgne );
							descriptionCamapgne.setText(campagne.getDescription());
							
							EditText debutCampagne = (EditText)activity.findViewById( R.id.debutCampagne );
							debutCampagne.setText(campagne.getDate_debut());
							
							EditText finCampagne = (EditText)activity.findViewById( R.id.finCampagne );
							finCampagne.setText(campagne.getDate_fin());
							
							EditText gpsCampagne = (EditText)activity.findViewById( R.id.gpsCampagne);
				    		gpsCampagne.setText(campagne.getLatitude() + ";" + campagne.getLongitude());
				    		
							EditText adresseCampagne = (EditText)activity.findViewById( R.id.adresseCampagne );
							adresseCampagne.setText(campagne.getAdresse());	
							
							break;
	                   }
				}
	        }
		});
		
        campagnes = new CampagnesButton(bdd.getCampagnes(utilisateur_id));
        if(campagnes.count() != 0)
        	campagnes.setCheck(0);
        
        /** phrase de selection de campagne **/
		LinearLayout layout_liste = (LinearLayout)activity.findViewById( R.id.linearLayout4 );
        TextView tv = new TextView(activity);
		tv.setText(R.string.selectionnerCampagne);
		layout_liste.addView(tv);
		
		/**date picker**/
		//date de debut
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
		
		//date de fin
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
		
		/**GPS**/
		//recuperation de la position & stocage dans le champ curent_location
		final Button localiserGPS = (Button) activity.findViewById(R.id.localiserGPS);
		localiserGPS.setOnClickListener(new View.OnClickListener() {
		    public void onClick(View v) {
		        if(curent_location != null){
		        	EditText gpsCampagne = (EditText)activity.findViewById( R.id.gpsCampagne);
		        	gpsCampagne.setText(curent_location.getLatitude() + " ; " + curent_location.getLongitude());
		        }
		        else
		        	alertbox("Attention !", "Pas de signale GPS");
		    }

		});
		/**gestion du bouton selectionner**/
		final Button buttonselectionner = (Button) activity.findViewById(R.id.selectionner);
		buttonselectionner.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
            	if(campagnes.count() != 0){
					SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
	
					// stock l identifiant de la campagne
		    		SharedPreferences.Editor editor = preferences.edit();
		    		editor.putLong("CAMPAGNE_ID", campagnes.getCurent_campagne().getId()); 
		    		editor.commit();
		    		
		    		FragmentManager manager = activity.getFragmentManager();  
		    		
		        	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
		    		
		    		if( fragmentEnCours != null )
		    		{
		    			FragmentTransaction transaction = manager.beginTransaction();
		    				transaction.remove( fragmentEnCours );
		    			transaction.commit();
		    		}
		    		
		    		GestionParcelle gestionParcelle = new GestionParcelle();
		    		FragmentTransaction transaction = manager.beginTransaction();
						transaction.add( R.id.linearLayout2, gestionParcelle, "enCours" );
					transaction.commit();
					
            	}else
            		alertbox("Attention !", "Créez une campagne pour pouvoir la sélectionner");

            }
        });
		
		/**gestion du bouton modifier**/
		final Button buttonmodifier = (Button) activity.findViewById(R.id.modifier);
		buttonmodifier.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	if(campagnes.count() != 0){
	            	Campagne campagne = campagnes.getCurent_campagne();
	            	
		        	EditText nomCampagne = (EditText)activity.findViewById( R.id.nomCampagne );
		        	campagne.setNom(nomCampagne.getText().toString());
		    		
		    		EditText descriptionCamapgne = (EditText)activity.findViewById( R.id.descriptionCamapgne );
		    		campagne.setDescription(descriptionCamapgne.getText().toString());
		    		
		    		EditText debutCampagne = (EditText)activity.findViewById( R.id.debutCampagne );
		    		campagne.setDate_debut(debutCampagne.getText().toString());
		    		
		    		EditText finCampagne = (EditText)activity.findViewById( R.id.finCampagne );
		    		campagne.setDate_fin(finCampagne.getText().toString());
		    		
		    		EditText gpsCampagne = (EditText)activity.findViewById( R.id.gpsCampagne);
		    		String str[] = gpsCampagne.getText().toString().trim().split(";");
		    		if(str.length == 2){
			    		campagne.setLatitude(str[0]);
			    		campagne.setLongitude(str[1]);
		    		}else{
			    		campagne.setLatitude("pas de valeur");
			    		campagne.setLongitude("pas de valeur");
		    		}
		    		System.out.print(campagne.getLatitude() + "|" + campagne.getLongitude() + "|");
		    		
		    		EditText adresseCampagne = (EditText)activity.findViewById( R.id.adresseCampagne );
		    		campagne.setAdresse(adresseCampagne.getText().toString());	
		    		
		    		campagnes.updateCampagne(campagne);
            	}
            	else
                	alertbox("Attention !", "Créez une campagne pour pouvoir la modifier");
            }
        });
		
		/**gestion du bouton creer**/
		final Button buttoncreer = (Button) activity.findViewById(R.id.creer);
		buttoncreer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
	            	
            	Campagne campagne = new Campagne();
            	
	        	EditText nomCampagne = (EditText)activity.findViewById( R.id.nomCampagne );
	        	campagne.setNom(nomCampagne.getText().toString());
	    		
	    		EditText descriptionCamapgne = (EditText)activity.findViewById( R.id.descriptionCamapgne );
	    		campagne.setDescription(descriptionCamapgne.getText().toString());
	    		
	    		EditText debutCampagne = (EditText)activity.findViewById( R.id.debutCampagne );
	    		campagne.setDate_debut(debutCampagne.getText().toString());
	    		
	    		EditText finCampagne = (EditText)activity.findViewById( R.id.finCampagne );
	    		campagne.setDate_fin(finCampagne.getText().toString());
	    		
	    		EditText adresseCampagne = (EditText)activity.findViewById( R.id.adresseCampagne );
	    		campagne.setAdresse(adresseCampagne.getText().toString());	
	    		
	    		EditText gpsCampagne = (EditText)activity.findViewById( R.id.gpsCampagne);
	    		String str[] = gpsCampagne.getText().toString().trim().split(";");
	    		if(str.length == 2){
		    		campagne.setLatitude(str[0]);
		    		campagne.setLongitude(str[1]);
	    		}
	    		else{
		    		campagne.setLatitude("pas de valeur");
		    		campagne.setLongitude("pas de valeur");
	    		}
	    			    	    		
	    		campagne.setUtilisateur_id(utilisateur_id);
	    		
	    		campagnes.insertCampagne(campagne);
            }
        });
		
		/**gestion du bouton supprimer**/
		final Button buttonsupprimer= (Button) activity.findViewById(R.id.supprimer);
		buttonsupprimer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	if(campagnes.count() != 0){
               	
		    		/** creation d une alerte boxe avant la suppression*/
		    		AlertDialog deleteAlert = new AlertDialog.Builder(activity).create();
		    		deleteAlert.setTitle(R.string.attention);
		    		//deleteAlert.setMessage(R.string.supprimerCampagne);
		    		deleteAlert.setMessage("Voulez-vous supprimer cette campagne ?"); //On ne met pas le texte ainsi, mais la forme precedante rencontre un probleme de type qui n est pas encore resolue
		    		/**si oui**/
		    		deleteAlert.setButton(DialogInterface.BUTTON_POSITIVE,"Oui", new DialogInterface.OnClickListener(){
		
		    			public void onClick(DialogInterface dialog, int which) {  
		                	campagnes.removeCampagne(campagnes.getCurent_campagne());	    				
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
                	alertbox("Attention !", "Créez une campagne pour pouvoir la supprimer");
            	
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
    	bdd.close();
    }
}
