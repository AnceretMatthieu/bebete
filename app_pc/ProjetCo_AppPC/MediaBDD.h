#ifndef MediaBDD_h
#define MediaBDD_h

#include "Media.h"
#include "BDD.h"

class MediaBDD : public BDD {
public:
    static void enregistrerMedia(Media* med);
};

#endif // MediaBDD_h
