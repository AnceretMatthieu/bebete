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


public class GestionPiege extends Fragment
{
	private PiegesButton pieges;
	private Activity activity;
	private PiegeBDD bdd;
	private int piege_id;
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
    
	private class PiegesButton{
		private Vector<Piege> vect_pieges = null;
		private Vector<RadioButton> vect_radioButton = null;
		private int active_piege = 0;
		
		public PiegesButton(Vector<Piege> vect_pieges){
			this.vect_pieges = vect_pieges;

			vect_radioButton = new Vector<RadioButton> ();
			if(this.vect_pieges == null)
				this.vect_pieges = new  Vector<Piege>();
			else{
				for (Piege piege : vect_pieges) {
					RadioButton radiobt = new RadioButton(activity); //creation d un radiobouton
					radiobt.setText(piege.getNom()); //texte du bouton
					vect_radioButton.add(radiobt);
					radiogroup.addView(radiobt);
				}
			}
		}

		public void insertPiege(Piege piege){
			String name = piege.getNom();
			boolean trouve = false;
			
			for ( RadioButton radiobt : vect_radioButton) {
				String btname = radiobt.getText().toString();
				if(btname.equalsIgnoreCase(name)){
					alertbox("Attention !", "Le piège existe déja.");
					trouve = true;
					break;
				}
			}
			if(trouve == false){
				bdd.insertPiege(piege);
				vect_pieges.add(piege);
				RadioButton radiobt = new RadioButton(activity); //creation d un radiobouton
				radiobt.setText(piege.getNom()); //texte du bouton
				vect_radioButton.add(radiobt);
				radiogroup.addView(radiobt);
				radiobt.setChecked(true);
			}
		}
		
		public void removePiege(Piege piege){
			int i = 0;
			for (Piege eachpiege : vect_pieges) {
				if(eachpiege.getId() == piege.getId()){
					bdd.removePiegeWithID(piege.getId());
					vect_radioButton.remove(i);
					vect_pieges.remove(i);
					radiogroup.removeViewAt(i);
				}
				else
					i++;
			}
		}
		
		public void updatePiege(Piege piege){
			int i = 0;
			for (Piege eachpiege : vect_pieges) {
				if(eachpiege.getId() == piege.getId()){
					bdd.updateCamapagne(piege);
					vect_pieges.set(i, piege);
					vect_radioButton.elementAt(i).setText(piege.getNom());
				}
				else
					i++;
			}
		}
		
		public void setActive_piege(int active_piege) {
			this.active_piege = active_piege;
		}
		
		public Piege getCurent_piege(){
			return vect_pieges.elementAt(active_piege);
		}
		
		public int count() {
			return vect_pieges.size();
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
        return inflater.inflate( R.layout.gestionpieges, container, false);
                
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
		bdd = new PiegeBDD(activity);
        bdd.open();
        
		SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
        piege_id = (int)preferences.getLong("PARCELLE_ID", -1);
        if(piege_id == -1)
        	alertbox("Attention !", "Sélectionner un utilisateur");
        
		radiogroup = new RadioGroup(activity); //groupe d'affichage pour la liste de radiobouton
		
		//affichage des parametres d'un bouton
		radiogroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
			public void onCheckedChanged(RadioGroup rg, int checkedId){
				for(int i=0; i<rg.getChildCount(); i++) {
	                   if(rg.getChildAt(i).getId() == checkedId) {
	                	   pieges.setActive_piege(i);
	                	   Piege piege = pieges.getCurent_piege();
	                	   
					    	/*affichage des elements dans leurs champs respectif*/
					    	EditText nomPiege = (EditText)activity.findViewById( R.id.nomPiege );
							nomPiege.setText(piege.getNom());
							
							EditText descriptionPiege = (EditText)activity.findViewById( R.id.descriptionPiege );
							descriptionPiege.setText(piege.getDescription());
							
							EditText debutPiege = (EditText)activity.findViewById( R.id.debutPiege );
							debutPiege.setText(piege.getDate_debut());
							
							EditText finPiege = (EditText)activity.findViewById( R.id.finPiege );
							finPiege.setText(piege.getDate_fin());
							
							EditText gpsPiege = (EditText)activity.findViewById( R.id.gpsPiege);
				    		gpsPiege.setText(piege.getLatitude() + ";" + piege.getLongitude());
				    		
							EditText adressePiege = (EditText)activity.findViewById( R.id.adressePiege );
							adressePiege.setText(piege.getAdresse());	
							
							SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
							
							// stock l identifiant de la piege
				    		SharedPreferences.Editor editor = preferences.edit();
				    		editor.putLong("PIEGE_ID", pieges.getCurent_piege().getId()); 
				    		editor.commit();
				    		
				    		break;
	                   }
				}
	        }
		});
		
        pieges = new PiegesButton(bdd.getPieges(piege_id));
        if(pieges.count() != 0)
        	pieges.setCheck(0);
        
        /** phrase de selection de piege **/
		LinearLayout layout_liste = (LinearLayout)activity.findViewById( R.id.linearLayout4 );
        TextView tv = new TextView(activity);
		tv.setText(R.string.selectionnerPiege);
		layout_liste.addView(tv);
		
		/**date picker**/
		//date de debut
		final EditText editTextdebutPiege = (EditText) activity.findViewById(R.id.debutPiege);
		editTextdebutPiege.setOnClickListener(new View.OnClickListener(){
				public void onClick(View v) {
					try {
						datepikerdialog(editTextdebutPiege);
					} catch (java.text.ParseException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
	    );
		
		//date de fin
		final EditText editTextfinPiege = (EditText) activity.findViewById(R.id.finPiege);
		editTextfinPiege.setOnClickListener(new View.OnClickListener(){
				public void onClick(View v) {
					try {
						datepikerdialog(editTextfinPiege);
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
		        	EditText gpsPiege = (EditText)activity.findViewById( R.id.gpsPiege);
		        	gpsPiege.setText(curent_location.getLatitude() + " ; " + curent_location.getLongitude());
		        }
		        else
		        	alertbox("Attention !", "Pas de signale GPS");
		    }

		});
		/**gestion du bouton selectionner**/
		final Button buttonselectionner = (Button) activity.findViewById(R.id.selectionner);
		buttonselectionner.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
            	if(pieges.count() != 0){
					SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
	
					// stock l identifiant de la piege
		    		SharedPreferences.Editor editor = preferences.edit();
		    		editor.putLong("PIEGE_ID", pieges.getCurent_piege().getId()); 
		    		editor.commit();
            	}else
            		alertbox("Attention !", "Créez une piege pour pouvoir la sélectionner");

            }
        });
		
		/**gestion du bouton modifier**/
		final Button buttonmodifier = (Button) activity.findViewById(R.id.modifier);
		buttonmodifier.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	if(pieges.count() != 0){
	            	Piege piege = pieges.getCurent_piege();
	            	
		        	EditText nomPiege = (EditText)activity.findViewById( R.id.nomPiege );
		        	piege.setNom(nomPiege.getText().toString());
		    		
		    		EditText descriptionPiege = (EditText)activity.findViewById( R.id.descriptionPiege );
		    		piege.setDescription(descriptionPiege.getText().toString());
		    		
		    		EditText debutPiege = (EditText)activity.findViewById( R.id.debutPiege );
		    		piege.setDate_debut(debutPiege.getText().toString());
		    		
		    		EditText finPiege = (EditText)activity.findViewById( R.id.finPiege );
		    		piege.setDate_fin(finPiege.getText().toString());
		    		
		    		EditText gpsPiege = (EditText)activity.findViewById( R.id.gpsPiege);
		    		String str[] = gpsPiege.getText().toString().trim().split(";");
		    		if(str.length == 2){
			    		piege.setLatitude(str[0]);
			    		piege.setLongitude(str[1]);
		    		}else{
			    		piege.setLatitude("pas de valeur");
			    		piege.setLongitude("pas de valeur");
		    		}
		    		System.out.print(piege.getLatitude() + "|" + piege.getLongitude() + "|");
		    		
		    		EditText adressePiege = (EditText)activity.findViewById( R.id.adressePiege );
		    		piege.setAdresse(adressePiege.getText().toString());	
		    		
		    		pieges.updatePiege(piege);
            	}
            	else
                	alertbox("Attention !", "Créez une piege pour pouvoir la modifier");
            }
        });
		
		/**gestion du bouton creer**/
		final Button buttoncreer = (Button) activity.findViewById(R.id.creer);
		buttoncreer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
	            	
            	Piege piege = new Piege();
            	
	        	EditText nomPiege = (EditText)activity.findViewById( R.id.nomPiege );
	        	piege.setNom(nomPiege.getText().toString());
	    		
	    		EditText descriptionPiege = (EditText)activity.findViewById( R.id.descriptionPiege );
	    		piege.setDescription(descriptionPiege.getText().toString());
	    		
	    		EditText debutPiege = (EditText)activity.findViewById( R.id.debutPiege );
	    		piege.setDate_debut(debutPiege.getText().toString());
	    		
	    		EditText finPiege = (EditText)activity.findViewById( R.id.finPiege );
	    		piege.setDate_fin(finPiege.getText().toString());
	    		
	    		EditText adressePiege = (EditText)activity.findViewById( R.id.adressePiege );
	    		piege.setAdresse(adressePiege.getText().toString());	
	    		
	    		EditText gpsPiege = (EditText)activity.findViewById( R.id.gpsPiege);
	    		String str[] = gpsPiege.getText().toString().trim().split(";");
	    		if(str.length == 2){
		    		piege.setLatitude(str[0]);
		    		piege.setLongitude(str[1]);
	    		}
	    		else{
		    		piege.setLatitude("pas de valeur");
		    		piege.setLongitude("pas de valeur");
	    		}
	    		
	    		piege.setUtilisateur_id(piege_id);
	    		
	    		pieges.insertPiege(piege);
            }
        });
		
		/**gestion du bouton supprimer**/
		final Button buttonsupprimer= (Button) activity.findViewById(R.id.supprimer);
		buttonsupprimer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	if(pieges.count() != 0){
               	
		    		/** creation d une alerte boxe avant la suppression*/
		    		AlertDialog deleteAlert = new AlertDialog.Builder(activity).create();
		    		deleteAlert.setTitle(R.string.attention);
		    		//deleteAlert.setMessage(R.string.supprimerPiege);
		    		deleteAlert.setMessage("Voulez-vous supprimer cette piege ?"); //On ne met pas le texte ainsi, mais la forme precedante rencontre un probleme de type qui n est pas encore resolue
		    		/**si oui**/
		    		deleteAlert.setButton(DialogInterface.BUTTON_POSITIVE,"Oui", new DialogInterface.OnClickListener(){
		
		    			public void onClick(DialogInterface dialog, int which) {  
		                	pieges.removePiege(pieges.getCurent_piege());	    				
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
                	alertbox("Attention !", "Créez une piege pour pouvoir la supprimer");
            	
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
