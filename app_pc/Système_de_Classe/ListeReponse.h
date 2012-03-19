#ifndef ListeReponse_h
#define ListeReponse_h

#include <vector>
#include "Reponse.h"


class ListeReponse : public std::vector {

 public:

    Reponse getElementById(int id);
};

#endif // ListeReponse_h
