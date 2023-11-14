#include "Series.h"

Series::Series(int _id, string _nombre, string _duracion, string genero,
               double _calificacion, string _sp, string _tm, int _np)
    : Videos(_id, _nombre, _duracion, genero, _calificacion, _sp, _np) {

  tm = _tm;
  np = _np;
}

void Series::print() {
  cout << "Serie: " << endl;
  Videos::print();
  cout << "Temporada: " << tm << endl;
  cout << "Personas que han votado antes que tú: " << np << endl;
  cout << endl;
}

string Series::getGen() { 
	return Videos::getGen(); 
}

string Series::getNom() {
	return Videos::getNom(); 
}

string Series::getSp() { 
	return Videos::getSp(); 
}

double Series::getCal() { 
	return Videos::getCal(); 
}

int Series::getNp() {
  return Videos::getNp();
}