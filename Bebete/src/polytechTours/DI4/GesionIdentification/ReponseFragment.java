package polytechTours.DI4.GesionIdentification;

import java.io.File;

import polytechTours.DI4.R;
import polytechTours.DI4.R.id;
import polytechTours.DI4.R.layout;

import android.app.Activity;
import android.app.Dialog;
import android.app.Fragment;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemLongClickListener;
import android.widget.CheckBox;
import android.widget.Gallery;
import android.widget.ImageView;
import android.widget.TextView;

/**
 * @author Julien Teruel
 * Fragment g�rant l'affichage d'une r�ponse avec sa galerie
 * En r�action � un clic long sur une imagette de la galerie, affichage du dialog de comparaison avec l'image temp.jpg de la tablette
 * Lors de l'affichage du dialog de comparaison un clic sur une des images ferme le dialog
 */
public class ReponseFragment extends Fragment implements OnItemLongClickListener, OnClickListener 
{	
	/**
	 * Sauvegarde de l'activity principale dans le fragment
	 */
	private Activity activity;
	
	/**
	 * Le dialog de comparaison
	 */
	private Dialog dialog;
	
	/**
	 * Le QuestionFragment parent de la r�ponse
	 */
	private QuestionFragment frag;
	
	/**
	 * L'objet r�ponse contenant toutes les infos sur lesquelles doit se baser le fragment
	 */
	private Reponse reponse;
	
	/**
	 * Bool�en directement li� � la notion d'historique, si il est vrai, cela indique au fragment qu'il doit coch� sa r�ponse avant affichage
	 * g�n�ralement li� � l'appuie d'un retour sur l'historique pour indiquer l'ancien choix effectu�
	 */
	private boolean select;
	
	/**
	 * Sauvegarde de l'id de la checkbox de ce fragent pour identification dans le QuestionFragment lors d'un clic dessus
	 */
	private int checkboxId;
	
	/**
	 * La premiere image afficher dans le dialog de comparaison
	 */
	private Bitmap resizedBitmap;
	
	/**
	 * La seconde image afficher dans le dialog de comparaison
	 */
	private Bitmap resizedBitmap2;
	
	/**
	 * Constructeur vide n�cessaire pour Android
	 */
	public ReponseFragment()
	{
	}
	
	/**
	 * Constructeur � utiliser dans le contexte de notre application
	 * @param frag le QuestionFragment p�re de la r�ponse
	 * @param rep l'objet r�ponse contenant les infos � afficher dans le framgent
	 * @param select indique si la r�ponse a d�j� �t� selectionn� dans le contexte d'un retour arri�re dans l'historique
	 */
	public ReponseFragment( QuestionFragment frag, Reponse rep, boolean select )
	{
		this.frag = frag;
		reponse = rep;
		this.select = select;
	}
	
	
	@Override
    public void onAttach(Activity activity)  
	{
        super.onAttach(activity);
        this.activity = activity; //Sauvegarde de l'activity
	}
	
	@Override
	public void onActivityCreated (Bundle savedInstanceState)
	{
		super.onActivityCreated(savedInstanceState);
		
		//On remplie l'UI du fragment, avec les infos de l'objet r�ponse 
		
		if( reponse != null )
		{
			// *********** Mise en place de la galerie *******************************
			Bitmap[] bitmaps = new Bitmap[reponse.getListeImage().size()];
			
			for( int i = 0; i < reponse.getListeImage().size(); i++ )
			{
				bitmaps[i] = BitmapFactory.decodeFile( FileManager.getSavePath() + File.separator + reponse.getListeImage().get(i) );
			}
			reponse.setmImageIds(bitmaps);
			
			//Installation du listener sur le click long d'une image de la galerie
			Gallery gallery = (Gallery)this.getView().findViewById(R.id.gallery1); // pour obtenir la gallerie relative a la question et pas toujours la memem commune connue de activity
			gallery.setOnItemLongClickListener(this);
			
			//Instanciation et setter de notre ImageAdapter sur la galerie
			ImageAdapter adapter = new ImageAdapter( activity );
			adapter.setmImageIds(reponse.getmImageIds() );
			gallery.setAdapter( adapter );
			//**************************************************************************
			
			//Mise en place de la checkbox de selection de la r�ponse
			CheckBox box = (CheckBox)this.getView().findViewById( R.id.checkBox1 );
			box.setOnClickListener(frag);
	        box.setText( reponse.getReponse() );
	        checkboxId = box.getId();
	        
	        // On coche la r�ponse au besoin (contexte d'historique)
	        if( select )
	        {
	        	box.setChecked(true);
	        }
	        
	        //Mise en place de la l�gende
	        TextView legende = (TextView)this.getView().findViewById( R.id.textView1 );
	        legende.setText( reponse.getLegende() );
		}
	}
	
	public int getCheckboxId()
	{
		return checkboxId;
	}
	
	public Reponse getReponse() {
		return reponse;
	}

	public void setReponse(Reponse reponse) {
		this.reponse = reponse;
	}

	@Override
    public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) 
    {		
		//Le fragment prend la forme du fichier layout XML passer en parametre, ici reponse.xml
        return inflater.inflate( R.layout.reponse, container, false); 
    }

	/**
	 * Lors du clic sur une image du dialog de comparaison on recycle les bitmap pour �viter les fuites m�moires, et on ferme le dialog
	 */
	public void onClick(View arg0) 
	{
		resizedBitmap.recycle();
		resizedBitmap2.recycle();
		dialog.dismiss();
	}

	/**
	 * Lors d'un clic long sur une image de la gallerie, cela ouvre une fenetre de comparaison,
	 * avec l'image cliqu� comparait avec la derniere image captur� par l'utilisateur sur la cam�ra 
	 */
	public boolean onItemLongClick(AdapterView<?> arg0, View arg1, int arg2, long id)
	{
		dialog = new Dialog( activity );
		dialog.setOwnerActivity(activity);
	       
		dialog.setContentView(R.layout.custom_dialog);
		dialog.setTitle("Comparaison");
		dialog.setCancelable(true);
		dialog.setCanceledOnTouchOutside(true);
		
		//N�cessaire pour r�duire l'utilisation m�moire des bitmaps et �viter les d�passements m�moire
		BitmapFactory.Options options = new BitmapFactory.Options();
		options.inSampleSize = 8;
		
		//Obtention de l'image de la cam�ra sauvegarder
		resizedBitmap = BitmapFactory.decodeFile( FileManager.getSavePath() + File.separator + "temp.jpg", options );
		
		ImageView image = (ImageView) dialog.findViewById(R.id.image44);
		image.setImageBitmap( resizedBitmap );
		image.setScaleType(ImageView.ScaleType.FIT_CENTER);
		image.setOnClickListener(this);
		
		//On r�cp�re l'image cliqu�
		ImageView image2 = (ImageView) dialog.findViewById(R.id.image45);
		ImageAdapter imA = (ImageAdapter)arg0.getAdapter();
		resizedBitmap2 = imA.getListImage()[(int)id];
		image2.setImageBitmap( resizedBitmap2 );
		image2.setScaleType(ImageView.ScaleType.FIT_CENTER);
		image2.setOnClickListener(this);
		
		//On affiche
		dialog.show();
	
		return true;
	}

}
