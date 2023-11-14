#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "Videos.h"

class Peliculas : public Videos {

private:
  string na;
  int np;

public:
  Peliculas(int _id, string _nombre, string _duracion, string genero,
            double _calificacion, string _sp, string na, int _np);

  void print();

  string getGen();
  double getCal();
  string getSp();
  int getNp();
  void setNp(int);
};

#endif