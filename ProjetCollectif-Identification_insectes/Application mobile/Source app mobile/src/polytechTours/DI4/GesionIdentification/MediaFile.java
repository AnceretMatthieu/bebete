package polytechTours.DI4.GesionIdentification;

import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;


import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.net.Uri;
import android.os.Environment;
import android.util.Log;

/**
 * Classe servant à l'enregistrement de la capture d'écran de la caméra, similaire à FileManager,
 * avec l'option de pouvoir gérer l'utilisation future de vidéo
 * Voir : http://developer.android.com/guide/topics/media/camera.html
 */
public class MediaFile 
{
	public static final int MEDIA_TYPE_IMAGE = 1;
	public static final int MEDIA_TYPE_VIDEO = 2;


	/** Create a file Uri for saving an image or video */
	public static Uri getOutputMediaFileUri(int type)
	{
	      return Uri.fromFile(getOutputMediaFile(type));
	}

	/** Create a File for saving an image or video */
	public static File getOutputMediaFile(int type)
	{
	    // Create a media file name
	    String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
	    
	    File mediaFile;
	    
	    if (type == MEDIA_TYPE_IMAGE)
	    {
	        mediaFile = new File( FileManager.getSavePath() + File.separator + "temp.jpg");
	    } 
	    else if(type == MEDIA_TYPE_VIDEO) 
	    {
	        mediaFile = new File(FileManager.getSavePath() + File.separator + "VID_"+ timeStamp + ".mp4");
	    }
	    else 
	    {
	        return null;
	    }

	    return mediaFile;
	}
}
