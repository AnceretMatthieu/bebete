package polytechTours.DI4.GesionIdentification;

import java.io.File;

import polytechTours.DI4.BebeteActivity;
import polytechTours.DI4.R;
import polytechTours.DI4.gestion_projet.GestionCampagne;
import polytechTours.DI4.gestion_projet.GestionParcelle;
import polytechTours.DI4.gestion_projet.GestionPiege;
import polytechTours.DI4.gestion_projet.GestionUtilisateur;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.View.OnClickListener;
import android.widget.CheckBox;
import android.widget.Gallery;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.AdapterView.OnItemLongClickListener;

public class MenuGPSFragment extends Fragment implements OnClickListener 
{
	private Activity activity;
	private FragmentManager manager;
	
	private ImageButton button1;
	private ImageButton button2;
	private ImageButton button3;
	private ImageButton button4;
	private ImageButton button5;
	private ImageButton button6;
	
	public MenuGPSFragment( Activity act )
	{
		activity = act;
		manager = activity.getFragmentManager();
	}
	
	@Override
    public void onAttach(Activity activity)  
	{
        super.onAttach(activity);
	}
	
	@Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {		
		//Le fragment prend la forme du fichier layout XML passer en parametre, ici reponse.xml
        return inflater.inflate( R.layout.menugps, container, false); 
    }
	
	@Override
	public void onActivityCreated (Bundle savedInstanceState)
	{
		super.onActivityCreated(savedInstanceState);
		
		button1 = (ImageButton)this.getView().findViewById( R.id.imageButton1 );
		button2 = (ImageButton)this.getView().findViewById( R.id.imageButton2 );
		button3 = (ImageButton)this.getView().findViewById( R.id.imageButton3 );
		button4 = (ImageButton)this.getView().findViewById( R.id.imageButton4 );
		button5 = (ImageButton)this.getView().findViewById( R.id.imageButton5 );
		button6 = (ImageButton)this.getView().findViewById( R.id.imageButton6 );
		
		button1.setOnClickListener( this );
		button2.setOnClickListener( this );
		button3.setOnClickListener( this );
		button4.setOnClickListener( this );
		button5.setOnClickListener( this );
		button6.setOnClickListener( this );
	}
	
	public void onClick(View arg0) 
	{
		if( arg0.getId() == button1.getId() )
    	{
    		GestionUtilisateur gestionutilisateur = new GestionUtilisateur();
    		
    		miseAjourAffichage();
    		
    		FragmentTransaction transaction = manager.beginTransaction();
    			transaction.add( R.id.linearLayout2, gestionutilisateur, "enCours" );
    		transaction.commit();
    	}
    	else if( arg0.getId() == button2.getId() )
    	{
    		GestionCampagne gestionCampagne = new GestionCampagne();
			
			miseAjourAffichage();
			
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionCampagne, "enCours" );
			transaction.commit();
    	}
    	else if( arg0.getId() == button4.getId() )
    	{
			GestionPiege gestionPiege = new GestionPiege();
			
			miseAjourAffichage();

			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionPiege, "enCours" );
			transaction.commit();
    	}
    	else if( arg0.getId() == button3.getId() )
    	{
			GestionParcelle gestionParcelle = new GestionParcelle();
			
			miseAjourAffichage();

			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, gestionParcelle, "enCours" );
			transaction.commit();
    	}
    	else if( arg0.getId() == button5.getId() )
    	{
    		QuestionFragment questionView = new QuestionFragment();
    		questionView.getId();
			
    		miseAjourAffichage();
			
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.add( R.id.linearLayout2, questionView, "enCours" );
			transaction.commit();
    	}
	}	
	
	public void miseAjourAffichage()
    {
    	Fragment fragmentEnCours = manager.findFragmentByTag("enCours");
		
		if( fragmentEnCours != null )
		{
			FragmentTransaction transaction = manager.beginTransaction();
				transaction.remove( fragmentEnCours );
			transaction.commit();
		}
    }
}
