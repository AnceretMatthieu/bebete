package polytechTours.DI4.gestion_projet;

import java.util.Calendar;
import java.util.TimeZone;
import java.util.Vector;

import polytechTours.DI4.R;
import polytechTours.DI4.GesionIdentification.QuestionFragment;
import polytechTours.DI4.bdd.Piege;
import polytechTours.DI4.bdd.PiegeBDD;
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

/** Gestion de l'affichage des pi�ges,
 * Cr�ation, S�lection, �dition, suppression
 */
public class GestionPiege extends Fragment
{
	private PiegesButton pieges = null;
	private Activity activity = null;
	private PiegeBDD bdd = null;
	private int parcelle_id;
	private RadioGroup radiogroup = null;
	
    // On d�clare les variables n�cessaires pour le GPS
	private LocationManager locationMgr = null;
	Location curent_location = null;
	
	/**Gestion du GPS pour r�cup�rer la position courante*/
    private LocationListener onLocationChange = new LocationListener() {
    	 public void onStatusChanged(String provider, int status, Bundle extras) { }
    	 public void onProviderEnabled(String provider) { }
    	 public void onProviderDisabled(String provider) { }
    	 public void onLocationChanged(Location location)
    	 {
	    	 curent_location = location;
    	 }
    };
    
    /** Relation entre l'affichage et les pi�ges*/
	private class PiegesButton{
		private Vector<Piege> vect_pieges = null;
		private Vector<RadioButton> vect_radioButton = null;
		private int active_piege = 0;
		
		/** Cr�ation des boutons en fonction d'une liste de pi�ges
		 * @param vect_pieges	Vecteur de pi�ges
		 */
		public PiegesButton(Vector<Piege> vect_pieges){
			this.vect_pieges = vect_pieges;

			vect_radioButton = new Vector<RadioButton> ();
			if(this.vect_pieges == null)
				this.vect_pieges = new  Vector<Piege>();
			else{
				for (Piege piege : vect_pieges) {
					RadioButton radiobt = new RadioButton(activity); //cr�ation d'un radiobouton
					radiobt.setText(piege.getNom()); //texte du bouton
					vect_radioButton.add(radiobt);
					radiogroup.addView(radiobt);
				}
			}
		}
		
		/** Supprime un pi�ge de l'affichage
		 * @param piege	Pi�ge supprim�
		 */
		public void insertPiege(Piege piege){
			String name = piege.getNom();
			boolean trouve = false;
			
			for ( RadioButton radiobt : vect_radioButton) {
				String btname = radiobt.getText().toString();
				if(btname.equalsIgnoreCase(name)){
					alertbox("Attention !", "Le pi�ge existe d�ja.");
					trouve = true;
					break;
				}
			}
			if(trouve == false){
				int id = (int)bdd.insertPiege(piege);
				if(id != -1){
					piege.setId(id);
					vect_pieges.add(piege);
					RadioButton radiobt = new RadioButton(activity); //cr�ation d'un radiobouton
					radiobt.setText(piege.getNom()); //texte du bouton
					vect_radioButton.add(radiobt);
					radiogroup.addView(radiobt);
					radiobt.setChecked(true);
				}
				else
					alertbox("Attention !", "Le pi�ge n'a pas �t� cr��.");
			}
		}
		
		/** Met � jour un pi�ge
		 * @param piege		Pi�ge � modifier
		 */
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
		
		/** D�finit le pi�ge actif
		 * @param piege		Num�ro du pi�ge � activer
		 */
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
		
		/** D�finit le pi�ge actif
		 * @param active_piege Pi�ge s�lectionn�
		 */
		public void setActive_piege(int active_piege) {
			this.active_piege = active_piege;
		}
		
		/** Indique le pi�ge active
		 * @return Pi�ge s�lectionn�
		 */
		public Piege getCurent_piege(){
			return vect_pieges.elementAt(active_piege);
		}
		
		/** Indique le nombre de pi�ges
		 * @return Nombre de pi�ges
		 */
		public int count() {
			return vect_pieges.size();
		}
		
		/** D�finit le pi�ge s�lectionn�
		 * @param i		Numero du pi�ge � s�lectionner
		 */
		public void setCheck(int i){
			vect_radioButton.elementAt(i).setChecked(true);
		}
	}
    
	/** affiche une date picker et retourne la date dans le champ pass� en param�tre
	 * @param champ 	Champ de l'affichage � modifier*/
	private void datepikerdialog(final EditText champ) throws java.text.ParseException {

		int year = 0;
		int month = 0;
		int day = 0;
		
		if(champ.getText().toString().length() >= 9){ //une date est compos�e d'au moins 9 caract�res
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
	//****************************************************/
	
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
        /** R�cup�re l'identifiant de la parcelle depuis les param�tres de l'application
         * Affiche un message en cas de probl�me et renvoie � la page de s�lection des campagnes **/
		SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //r�cup�re les param�tres de l'application
        parcelle_id = (int)preferences.getLong("PARCELLE_ID", -1);
        if(parcelle_id == -1)
        	if(!Securite.valideProjet(activity))
        		return;
        
		/**gestion du gps **/   
		//(GPS) Gestion des r�seaux et du temps de pull
		locationMgr = (LocationManager) activity.getSystemService(Context.LOCATION_SERVICE);
		locationMgr.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 10000, 0, onLocationChange);
		locationMgr.requestLocationUpdates(LocationManager.GPS_PROVIDER, 10000, 0,onLocationChange);
		
		/** init variables**/
		bdd = new PiegeBDD(activity);
        bdd.open();
        
        
        /** Zone d'affichage des Pi�ges **/
		radiogroup = new RadioGroup(activity); //groupe d'affichage pour la liste de radiobouton
		
		/*Gestion de la s�lection d'un pi�ge*/
		radiogroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
			public void onCheckedChanged(RadioGroup rg, int checkedId){
				for(int i=0; i<rg.getChildCount(); i++) {
	                   if(rg.getChildAt(i).getId() == checkedId) {
	                	   pieges.setActive_piege(i);
	                	   Piege piege = pieges.getCurent_piege();
	                	   
					    	/*affichage des �l�ments dans leurs champs respectifs*/
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
							
							SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //r�cup�re les param�tres de l'application
							
							// stock l'identifiant du pi�ge
				    		SharedPreferences.Editor editor = preferences.edit();
				    		editor.putLong("PIEGE_ID", pieges.getCurent_piege().getId()); 
				    		editor.commit();
				    		
				    		break;
	                   }
				}
	        }
		});
		
		/*S�lection du premier pi�ge lors de l'initialisation de la vue*/
		pieges = new PiegesButton(bdd.getPieges(parcelle_id));
        if(pieges.count() != 0)
        	pieges.setCheck(0);
        
        /** phrase de s�lection du pi�ge **/
		LinearLayout layout_liste = (LinearLayout)activity.findViewById( R.id.linearLayout4 );
        TextView tv = new TextView(activity);
		tv.setText(R.string.selectionnerPiege);
		layout_liste.addView(tv);
		
		/**date picker**/
		//date de d�but
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
		//r�cup�ration de la position & stockage dans le champ curent_location
		final Button localiserGPS = (Button) activity.findViewById(R.id.localiserGPS);
		localiserGPS.setOnClickListener(new View.OnClickListener() {
		    public void onClick(View v) {
		        if(curent_location != null){
		        	EditText gpsPiege = (EditText)activity.findViewById( R.id.gpsPiege);
		        	gpsPiege.setText(curent_location.getLatitude() + " ; " + curent_location.getLongitude());
		        }
		        else
		        	alertbox("Attention !", "Pas de signal GPS");
		    }

		});
		/**gestion du bouton s�lectionner**/
		final Button buttonselectionner = (Button) activity.findViewById(R.id.selectionner);
		buttonselectionner.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
            	if(pieges.count() != 0){
					SharedPreferences preferences = activity.getPreferences(Context.MODE_PRIVATE); //r�cup�re les param�tres de l'application
	
					// stock l'identifiant du pi�ge
		    		SharedPreferences.Editor editor = preferences.edit();
		    		editor.putLong("PIEGE_ID", pieges.getCurent_piege().getId()); 
		    		editor.commit();
		    		
		    		//changement de fragment
		    		FragmentManager manager = activity.getFragmentManager();  
		    		
		        	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
		    		
		    		if( fragmentEnCours != null )
		    		{
		    			FragmentTransaction transaction = manager.beginTransaction();
		    				transaction.remove( fragmentEnCours );
		    			transaction.commit();
		    		}
		    		QuestionFragment questionView = new QuestionFragment();
		    		questionView.getId();
					
					FragmentTransaction transaction = manager.beginTransaction();
						transaction.add( R.id.linearLayout2, questionView, "enCours" );
					transaction.commit();
            	}else
            		alertbox("Attention !", "Cr�ez un pi�ge pour pouvoir le s�lectionner");

            }
        });
		
		/**gestion du bouton modifier**/
		final Button buttonmodifier = (Button) activity.findViewById(R.id.modifier);
		buttonmodifier.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	if(pieges.count() != 0){
            		EditText nomPiege = (EditText)activity.findViewById( R.id.nomPiege );
            		EditText finPiege = (EditText)activity.findViewById( R.id.finPiege );
            		
            		if(nomPiege.getText().toString().compareTo("") == 0){
    	                alertbox("Attention !", "Donner un nom au pi�ge.");
            		}
            		else
            		{
                		if(finPiege.getText().toString().compareTo("") == 0)
                		{
        	                alertbox("Attention !", "Donner une date de fin.");
                		}
                		else{
        	                Piege piege = pieges.getCurent_piege();
        	            	
        		        	piege.setNom(nomPiege.getText().toString());
        		    		
        		    		EditText descriptionPiege = (EditText)activity.findViewById( R.id.descriptionPiege );
        		    		piege.setDescription(descriptionPiege.getText().toString());
        		    		
        		    		EditText debutPiege = (EditText)activity.findViewById( R.id.debutPiege );
        		    		piege.setDate_debut(debutPiege.getText().toString());
        		    		
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
        				    		
        		    		EditText adressePiege = (EditText)activity.findViewById( R.id.adressePiege );
        		    		piege.setAdresse(adressePiege.getText().toString());	
        		    		
        		    		pieges.updatePiege(piege);
                		}
            		} 
            	}
            }
        });
		
		/**gestion du bouton cr�er**/
		final Button buttoncreer = (Button) activity.findViewById(R.id.creer);
		buttoncreer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
	        	EditText nomPiege = (EditText)activity.findViewById( R.id.nomPiege );
	        	EditText finPiege = (EditText)activity.findViewById( R.id.finPiege );
	        	
            	if(nomPiege.getText().toString().compareTo("") == 0){
	                alertbox("Attention !", "Donner un nom au pi�ge.");
        		}
        		else
        		{
            		if(finPiege.getText().toString() == "")
            		{
    	                alertbox("Attention !", "Donner une date de fin.");
            		}
	            		else{
			            	Piege piege = new Piege();
			            
				        	piege.setNom(nomPiege.getText().toString());
				    		
				    		EditText descriptionPiege = (EditText)activity.findViewById( R.id.descriptionPiege );
				    		piege.setDescription(descriptionPiege.getText().toString());
				    		
				    		EditText debutPiege = (EditText)activity.findViewById( R.id.debutPiege );
				    		piege.setDate_debut(debutPiege.getText().toString());
				    		
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
				    		
				    		piege.setParcelle_id(parcelle_id);
				    		
				    		pieges.insertPiege(piege);
	            		}
        		}
            }
        });
		
		/**gestion du bouton supprimer**/
		final Button buttonsupprimer= (Button) activity.findViewById(R.id.supprimer);
		buttonsupprimer.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
            	if(pieges.count() != 0){
               	
		    		/** cr�ation d'une alerte boxe avant la suppression*/
		    		AlertDialog deleteAlert = new AlertDialog.Builder(activity).create();
		    		deleteAlert.setTitle(R.string.attention);
		    		//deleteAlert.setMessage(R.string.supprimerPiege);
		    		deleteAlert.setMessage("Voulez-vous supprimer ce pi�ge ?"); //On ne met pas le texte ainsi, mais la forme pr�c�dente rencontre un probl�me de type qui n'est pas encore r�solu
		    		/**si oui**/
		    		deleteAlert.setButton(DialogInterface.BUTTON_POSITIVE,"Oui", new DialogInterface.OnClickListener(){
		
		    			public void onClick(DialogInterface dialog, int which) {  
		                	pieges.removePiege(pieges.getCurent_piege());	    				
		    			}
		    		});
		    		
	        		deleteAlert.setButton(DialogInterface.BUTTON_NEGATIVE,"Non", new DialogInterface.OnClickListener(){
	        			public void onClick(DialogInterface dialog, int which) { 
	        				//rien � faire
	        			}
	        		});
	        		
	        		deleteAlert.show();
            	}
            	else
                	alertbox("Attention !", "Cr�ez un pi�ge pour pouvoir le supprimer");
            	
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
    	if(bdd != null)
    		bdd.close();
    }
}
