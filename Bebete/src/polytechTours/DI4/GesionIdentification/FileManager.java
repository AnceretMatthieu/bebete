package polytechTours.DI4.GesionIdentification;

import java.io.File;

import android.app.Activity;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.os.Environment;
import android.util.Log;

/**
 * @author Julien Teruel
 * Classe pour g�rer l'enregistrement des fichiers sur le DD de la tablette
 * Deux dossier sont g�r�s Innophyt la racine de l'application et Innophyt/Incident pour les rapports
 * Attention pour que le syst�me affiche dans l'explorateur de fichier un fichier nouvellement cr�er, comme pour les rapports d'erreur,
 * il faut indiquer au mediaFile scanner qu'un nouveau fichier existe via la fonction updateFileSystem
 */
public class FileManager 
{
	/**
	 * Fonction statique retournant le chemin du dossier incident de la tablette
	 * @return un string contenant le chemin absolue vers le dossier incident
	 */
	public static String getSaveIncidentPath()
	{
		File rapport = new File(Environment.getExternalStorageDirectory(), "Innophyt" + File.separator + "Incident");
		if (!rapport.exists()) 
		{
            if (!rapport.mkdirs()) 
            {
                    Log.d("FileManager", "Cannot create directory: " + rapport.toString());
            }
		}

		return rapport.getPath();
	}
	
	/**
	 * Fonction statique retournant le chemin du dossier Innophyt de la tablette
	 * @return un string contenant le chemin absolue vers le dossier Innophyt
	 */
	public static String getSavePath()
	{
		File rapport = new File(Environment.getExternalStorageDirectory(), "Innophyt");
		if (!rapport.exists()) 
		{
            if (!rapport.mkdirs()) 
            {
                    Log.d("FileManager", "Cannot create directory: " + rapport.toString());
            }
		}

		return rapport.getPath();
	}
	
	/**
	 * Fonction statique permettant de faire connaitre un fichier nouvellement cr�e au syst�me de fichier Android
	 * @param file le fichier nouvellement cr�e � faire conna�tre au syst�me
	 * @param activity l'activity responsable de la cr�ation du fichier
	 */
	public static void updateFileSystem( File file, Activity activity )
	{
		MediaScannerConnection.scanFile(activity, new String[] { file.toString() }, null, new MediaScannerConnection.OnScanCompletedListener() 
        {
            public void onScanCompleted(String path, Uri uri) 
            {
                Log.d("ExternalStorage", "Scanned " + path + ":");
                Log.d("ExternalStorage", "-> uri=" + uri);
            }
        }
        );
	}
}
