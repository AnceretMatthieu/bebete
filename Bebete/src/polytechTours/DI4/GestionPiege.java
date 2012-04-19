package polytechTours.DI4;

import android.app.Activity;
import android.app.Fragment;
import android.content.Context;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;


public class GestionPiege extends Fragment
{
	private Activity activity;
	
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
		//gestion des reseaux gps et du delais de pull
		locationMgr = (LocationManager) activity.getSystemService(Context.LOCATION_SERVICE);
		locationMgr.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 10000, 0, onLocationChange);
		locationMgr.requestLocationUpdates(LocationManager.GPS_PROVIDER, 10000, 0,onLocationChange);
    	
		//recuperation de la position & stocage dans le champ curent_location
		final Button localiserGPS = (Button) activity.findViewById(R.id.localiserGPS);
		localiserGPS.setOnClickListener(new View.OnClickListener() {
		    public void onClick(View v) {
		        if(curent_location != null){
		        	EditText gpsPiege = (EditText)activity.findViewById( R.id.gpsPiege);
		        	gpsPiege.setText(curent_location.getLatitude() + " ; " + curent_location.getLongitude() );
		        }
		    }

		});
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
