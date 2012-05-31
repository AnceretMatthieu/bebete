package polytechTours.DI4.gestion_projet;

import java.util.Calendar;
import java.util.TimeZone;
import java.util.Vector;

import polytechTours.DI4.R;
import polytechTours.DI4.bdd.Parcelle;
import polytechTours.DI4.bdd.ParcelleBDD;
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

/** Gestion de l'affichage des parcelles,
 * Création, Sélection, édition, suppression
 */
public class GestionParcelle extends Fragment
{
	private ParcellesButton parcelles;
	private Activity activity;
	private ParcelleBDD bdd;
	private int campagne_id;
	private RadioGroup radiogroup;
	
    // On déclare les variables nécessaires pour le GPS
	private LocationManager locationMgr = null;
	Location curent_location = null;
	
	/**Gestion du GPS pour récupérer la position courante*/
    private LocationListener onLocationChange = new LocationListener() {
    	 public void onStatusChanged(String provider, int status, Bundle extras) { }
    	 public void onProviderEnabled(String provider) { }
    	 public void onProviderDisabled(String provider) { }
    	 public void onLocationChanged(Location location)
    	 {
	    	 curent_location = location;
    	 }
    };
    
    /** Relation entre l'affichage et les parcelles*/
	private class ParcellesButton{
		private Vector<Parcelle> vect_parcelles = null;
		private Vector<RadioButton> vect_radioButton = null;
		private int active_parcelle = 0;
		
		/** Création des boutons en fonction d'une liste de parcelles
		 * @param vect_parcelles	Vecteur de parcelles
		 */
		public ParcellesButton(Vector<Parcelle> vect_parcelles){
			this.vect_parcelles = vect_parcelles;

			vect_radioButton = new Vector<RadioButton> ();
			if(this.vect_parcelles == null)
				this.vect_parcelles = new  Vector<Parcelle>();
			else{
				for (Parcelle parcelle : vect_parcelles) {
					RadioButton radiobt = new RadioButton(activity); //création d'un radiobouton
					radiobt.setText(parcelle.getNom()); //texte du bouton
					vect_radioButton.add(radiobt);
					radiogroup.addView(radiobt);
				}
			}
		}

		/** Supprime une parcelle de l'affichage
		 * @param parcelle	Parcelle supprimée
		 */
		public void insertParcelle(Parcelle parcelle){
			String name = parcelle.getNom();
			boolean trouve = false;
			
			for ( RadioButton radiobt : vect_radioButton) {
				String btname = radiobt.getText().toString();
				if(btname.equalsIgnoreCase(name)){
					alertbox("Attention !", "La parcelle existe déja.");
					trouve = true;
					break;
				}
			}
			if(trouve == false){
				bdd.insertParcelle(parcelle);
				vect_parcelles.add(parcelle);
				RadioButton radiobt = new RadioButton(activity); //création d'un radiobouton
				radiobt.setText(parcelle.getNom()); //texte du bouton
				vect_radioButton.add(radiobt);
				radiogroup.addView(radiobt);
				radiobt.setChecked(true);
			}
		}
		
		/** Met à jour une parcelle
		 * @param parcelle	Parcelle à modifier
		 */
		public void removeParcelle(Parcelle parcelle){
			int i = 0;
			for (Parcelle eachparcelle : vect_parcelles) {
				if(eachparcelle.getId() == parcelle.getId()){
					bdd.removeParcelleWithID(parcelle.getId());
					vect_radioButton.remove(i);
					vect_parcelles.remove(i);
					radiogroup.removeViewAt(i);
				}
				else
					i++;
			}
		}
		
		/** Définit la parcelle active
		 * @param parcelle	Numero de la parcelle à activer
		 */
		public void updateParcelle(Parcelle parcelle){
			int i = 0;
			for (Parcelle eachparcelle : vect_parcelles) {
				if(eachparcelle.getId() == parcelle.getId()){
					bdd.updateCamapagne(parcelle);
					vect_parcelles.set(i, parcelle);
					vect_radioButton.elementAt(i).setText(parcelle.getNom());
				}
				else
					i++;
			}
		}
		
		/** Définit la parcelle active
		 * @return Parcelle sélectionnée
		 */
		public void setActive_parcelle(int active_parcelle) {
			this.active_parcelle = active_parcelle;
		}
		
		/** Indique la parcelle active
		 * @return Parcelle sélectionnée
		 */
		public Parcelle getCurent_parcelle(){
			return vect_parcelles.elementAt(active_parcelle);
		}
		 
		/** Indique le nombre de parcelles
		 * @return Nombre de parcelles
		 */
		public int count() {
			return vect_parcelles.size();
		}
		
		/** Definit la parcelle sélectionné
		 * @param i	 Numero de la parcelle a sellectionner
		 */
		public void setCheck(int i){
			vect_radioButton.elementAt(i).setChecked(true);
		}
	}
    
	/** Affiche une date picker et retourne la date dans le champ passé en paramètre
	 * @param champ	Champ de l'affichage à modifier*/
	private void datepikerdialog(final EditText champ) throws java.text.ParseException {

		int year = 0;
		int month = 0;
		int day = 0;
		
		if(champ.getText().toString().length() >= 9){ //une date est composée d'au moins 9 caractères
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
    
	/** message d'alerte, seul valider est disponible
	 * @param title	Titre de l'alerte
	 * @param mymessage Message de l'alerte*/
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
	
	//****************************************************
	//*              gestion de l'affichage
	//****************************************************
	
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
        return inflater.inflate( R.layout.gestionparcelle, container, false);
                
    }
	
	@Override
	public void onActivityCreated (Bundle savedInstanceState)
	{
		super.onActivityCreated(savedInstanceState);
		/**gestion du gps **/   
		//(GPS) Gestion des réseaux et du temps de pull
		locationMgr = (LocationManager) activity.getSystemService(Context.LOCATION_SERVICE);
		locationMgr.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 10000, 0, onLocationChange);
		locationMgr.requestLocationUpdates(LocationManager.GPS_PROVIDER, 10000, 0,onLocationChange);
		
		/** init variables**/
		bdd = new ParcelleBDD(activity);
        bdd.open();
        
        /** Récupere l'identifiant de la campagne depuis les paramètres de l'application
         * Affiche un message en cas de problème et renvoie à la page de sélection des campagnes **/
		SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //récupere les paramètres de l'application
        campagne_id = (int)preferences.getLong("CAMPAGNE_ID", -1);
        if(campagne_id == -1){
        	Securite.valideProjet(activity);
        }
        
        /** Zone d'affichage des Parcelles **/
		radiogroup = new RadioGroup(activity); //groupe d'affichage pour la liste de radiobouton
		
		/*Gestion de la sélection d'une parcelle*/
		radiogroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
			public void onCheckedChanged(RadioGroup rg, int checkedId){
				for(int i=0; i<rg.getChildCount(); i++) {
	                   if(rg.getChildAt(i).getId() == checkedId) {
	                	   parcelles.setActive_parcelle(i);
	                	   Parcelle parcelle = parcelles.getCurent_parcelle();
	                	   
					    	/*affichage des éléments dans leurs champs respectifs*/
					    	EditText nomParcelle = (EditText)activity.findViewById( R.id.nomParcelle );
							nomParcelle.setText(parcelle.getNom());
							
							EditText descriptionParcelle = (EditText)activity.findViewById( R.id.descriptionParcelle );
							descriptionParcelle.setText(parcelle.getDescription());
							
							EditText debutParcelle = (EditText)activity.findViewById( R.id.debutParcelle );
							debutParcelle.setText(parcelle.getDate_debut());
							
							EditText finParcelle = (EditText)activity.findViewById( R.id.finParcelle );
							finParcelle.setText(parcelle.getDate_fin());
							
							EditText gpsParcelle = (EditText)activity.findViewById( R.id.gpsParcelle);
				    		gpsParcelle.setText(parcelle.getLatitude() + ";" + parcelle.getLongitude());
				    		
							EditText adresseParcelle = (EditText)activity.findViewById( R.id.adresseParcelle );
							adresseParcelle.setText(parcelle.getAdresse());	
							
							break;
	                   }
				}
	        }
		});
		
		/** Sélection de la première parcelle lors de l'initialisation de la vue*/
        parcelles = new ParcellesButton(bdd.getParcelles(campagne_id));
        if(parcelles.count() != 0)
        	parcelles.setCheck(0);
        
        /** phrase de sélection de parcelle **/
		LinearLayout layout_liste = (LinearLayout)activity.findViewById( R.id.linearLayout4 );
        TextView tv = new TextView(activity);
		tv.setText(R.string.selectionnerParcelle);
		layout_liste.addView(tv);
		
		/**date picker**/
		//date de debut
		final EditText editTextdebutParcelle = (EditText) activity.findViewById(R.id.debutParcelle);
		editTextdebutParcelle.setOnClickListener(new View.OnClickListener(){
				public void onClick(View v) {
					try {
						datepikerdialog(editTextdebutParcelle);
					} catch (java.text.ParseException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
	    );
		
		//date de fin
		final EditText editTextfinParcelle = (EditText) activity.findViewById(R.id.finParcelle);
		editTextfinParcelle.setOnClickListener(new View.OnClickListener(){
				public void onClick(View v) {
					try {
						datepikerdialog(editTextfinParcelle);
					} catch (java.text.ParseException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
	    );
		
		/**GPS**/
		//récuperation de la position & stockage dans le champ curent_location
		final Button localiserGPS = (Button) activity.findViewById(R.id.localiserGPS);
		localiserGPS.setOnClickListener(new View.OnClickListener() {
		    public void onClick(View v) {
		        if(curent_location != null){
		        	EditText gpsParcelle = (EditText)activity.findViewById( R.id.gpsParcelle);
		        	gpsParcelle.setText(curent_location.getLatitude() + " ; " + curent_location.getLongitude());
		        }
		        else
		        	alertbox("Attention !", "Pas de signale GPS");
		    }

		});
		/**gestion du bouton sélectionner**/
		final Button buttonselectionner = (Button) activity.findViewById(R.id.selectionner);
		buttonselectionner.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
            	if(parcelles.count() != 0){
					SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //recupere les setings de l'application
	
					// stock l'identifiant de la parcelle
		    		SharedPreferences.Editor editor = preferences.edit();
		    		editor.putLong("PARCELLE_ID", parcelles.getCurent_parcelle().getId()); 
		    		editor.putLong("PIEGE_ID", -1); 
		    		editor.commit();
		    		
		    		FragmentManager manager = activity.getFragmentManager();  
		    		
		        	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
		    		
		    		if( fragmentEnCours != null )
		    		{
		    			FragmentTransaction transaction = manager.beginTransaction();
		    				transaction.remove( fragmentEnCours );
		    			transaction.commit();
		    		}
		    		
		    		GestionPiege gestionPiege = new GestionPiege();
		    		FragmentTransaction transaction = manager.beginTransaction();
						transaction.add( R.id.linearLayout2, gestionPiege, "enCours" );
					transaction.commit();
            	}else
            		alertbox("Attention !", "Créez une parcelle pour pouvoir la sélectionner");

            }
        });
		
		/**gestion du bouton modifier**/
		final Button buttonmodifier = (Button) activity.findViewById(R.id.modifier);
		buttonmodifier.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	if(parcelles.count() != 0){
	            	Parcelle parcelle = parcelles.getCurent_parcelle();
	            	
		        	EditText nomParcelle = (EditText)activity.findViewById( R.id.nomParcelle );
		        	parcelle.setNom(nomParcelle.getText().toString());
		    		
		    		EditText descriptionParcelle = (EditText)activity.findViewById( R.id.descriptionParcelle );
		    		parcelle.setDescription(descriptionParcelle.getText().toString());
		    		
		    		EditText debutParcelle = (EditText)activity.findViewById( R.id.debutParcelle );
		    		parcelle.setDate_debut(debutParcelle.getText().toString());
		    		
		    		EditText finParcelle = (EditText)activity.findViewById( R.id.finParcelle );
		    		parcelle.setDate_fin(finParcelle.getText().toString());
		    		
		    		EditText gpsParcelle = (EditText)activity.findViewById( R.id.gpsParcelle);
		    		String str[] = gpsParcelle.getText().toString().trim().split(";");
		    		if(str.length == 2){
			    		parcelle.setLatitude(str[0]);
			    		parcelle.setLongitude(str[1]);
		    		}else{
			    		parcelle.setLatitude("pas de valeur");
			    		parcelle.setLongitude("pas de valeur");
		    		}
		    		
		    		EditText adresseParcelle = (EditText)activity.findViewById( R.id.adresseParcelle );
		    		parcelle.setAdresse(adresseParcelle.getText().toString());	
		    		
		    		parcelles.updateParcelle(parcelle);
            	}
            	else
                	alertbox("Attention !", "Créez une parcelle pour pouvoir la modifier");
            }
        });
		
		/**gestion du bouton créer**/
		final Button buttoncreer = (Button) activity.findViewById(R.id.creer);
		buttoncreer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {

	        	EditText nomParcelle = (EditText)activity.findViewById( R.id.nomParcelle );
	        	
	        	if(nomParcelle.getText().toString() != ""){
	            	Parcelle parcelle = new Parcelle();
	            	
		        	parcelle.setNom(nomParcelle.getText().toString());
		    		
		    		EditText descriptionParcelle = (EditText)activity.findViewById( R.id.descriptionParcelle );
		    		parcelle.setDescription(descriptionParcelle.getText().toString());
		    		
		    		EditText debutParcelle = (EditText)activity.findViewById( R.id.debutParcelle );
		    		parcelle.setDate_debut(debutParcelle.getText().toString());
		    		
		    		EditText finParcelle = (EditText)activity.findViewById( R.id.finParcelle );
		    		parcelle.setDate_fin(finParcelle.getText().toString());
		    		
		    		EditText adresseParcelle = (EditText)activity.findViewById( R.id.adresseParcelle );
		    		parcelle.setAdresse(adresseParcelle.getText().toString());	
		    		
		    		EditText gpsParcelle = (EditText)activity.findViewById( R.id.gpsParcelle);
		    		String str[] = gpsParcelle.getText().toString().trim().split(";");
		    		if(str.length == 2){
			    		parcelle.setLatitude(str[0]);
			    		parcelle.setLongitude(str[1]);
		    		}
		    		else{
			    		parcelle.setLatitude("pas de valeur");
			    		parcelle.setLongitude("pas de valeur");
		    		}
		    		
		    		parcelle.setCampagne_id(campagne_id);
		    		
		    		parcelles.insertParcelle(parcelle);
	        	}
	        	else{
	        		alertbox("Attention !", "Donner un nom à votre parcelle");
	        	}
            }
        });
		
		/**gestion du bouton supprimer**/
		final Button buttonsupprimer= (Button) activity.findViewById(R.id.supprimer);
		buttonsupprimer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	if(parcelles.count() != 0){
               	
		    		/** création d'une alerte boxe avant la suppression*/
		    		AlertDialog deleteAlert = new AlertDialog.Builder(activity).create();
		    		deleteAlert.setTitle(R.string.attention);
		    		//deleteAlert.setMessage(R.string.supprimerParcelle);
		    		deleteAlert.setMessage("Voulez-vous supprimer cette parcelle ?"); //On ne met pas le texte ainsi, mais la forme précédente rencontre un problème de type qui n'est pas encore résolu
		    		/**si oui**/
		    		deleteAlert.setButton(DialogInterface.BUTTON_POSITIVE,"Oui", new DialogInterface.OnClickListener(){
		
		    			public void onClick(DialogInterface dialog, int which) {  
		                	parcelles.removeParcelle(parcelles.getCurent_parcelle());	    				
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
                	alertbox("Attention !", "Créez une parcelle pour pouvoir la supprimer");
            	
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
