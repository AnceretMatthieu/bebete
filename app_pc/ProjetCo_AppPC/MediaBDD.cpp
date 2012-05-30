#include "MediaBDD.h"

void MediaBDD::enregistrerMedia(Media* med) {

    if(med->getType() == MEDIA_TYPE_IMAGE)   {
        QDomElement img = doc.createElement("img");
        img.setAttribute("id", "img"+QString::number(med->getIdentifiant()));
        img.setAttribute("src", med->getPath());
        currentNode.appendChild(img);
    }
    else if(med->getType() == MEDIA_TYPE_TEXT)  {
        QDomElement type = doc.createElement("legende");
        QDomText txtlegende = doc.createTextNode(med->getPath());
        type.appendChild(txtlegende);
        currentNode.appendChild(type);
    }
    else if(med->getType() == MEDIA_TYPE_VIDEO) {
        QDomElement video = doc.createElement("img");
        video.setAttribute("id", "video"+QString::number(med->getIdentifiant()));
        video.setAttribute("src", med->getPath());
        currentNode.appendChild(video);
    }
}
