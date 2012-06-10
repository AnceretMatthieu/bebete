#include "MediaBDD.h"

void MediaBDD::enregistrerMedia(Media* med)
{
    if(med->getType() == MEDIA_TYPE_IMAGE)
    {
        QDomElement img = doc.createElement("img");
        img.setAttribute("id", QString::number(med->getIdentifiant()));
        img.setAttribute("src", med->getPath());
        currentNodeWrite->appendChild(img);
    }
    else if(med->getType() == MEDIA_TYPE_TEXT)
    {
        QDomElement text = doc.createElement("legende");
        QDomText legende = doc.createTextNode(med->getPath());
        text.appendChild(legende);
        currentNodeWrite->appendChild(text);
    }
    else if(med->getType() == MEDIA_TYPE_VIDEO)
    {
        QDomElement video = doc.createElement("video");
        video.setAttribute("id", QString::number(med->getIdentifiant()));
        video.setAttribute("src", med->getPath());
        currentNodeWrite->appendChild(video);
    }
    else if(med->getType() == MEDIA_TYPE_AUDIO)
    {
        QDomElement audio = doc.createElement("audio");
        audio.setAttribute("id", QString::number(med->getIdentifiant()));
        audio.setAttribute("src", med->getPath());
        currentNodeWrite->appendChild(audio);
    }
}
