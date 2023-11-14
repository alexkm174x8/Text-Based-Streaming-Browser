#ifndef SERIES_H_INCLUDED
#define SERIES_H_INCLUDED
#include "Videos.h"

class Series : public Videos {

private:
  string tm;
  int np;

public:
  Series(int _id, string _nombre, string _duracion, string genero,
         double _calificacion, string _sp, string _tm, int _np);

  void print();

  string getGen();
  string getNom();
  double getCal();
  string getSp();
  int getNp();
void setNp(int);
};

#endif // SERIES_H_INCLUDED