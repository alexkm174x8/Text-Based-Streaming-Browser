#include "Videos.h"
#include <iostream>

using namespace std;

Videos::Videos() {}

Videos::Videos(int _id, string _nombre, string _duracion, string _genero,
               double _calificacion, string _sp, int _np) {
  id = _id;
  nombre = _nombre;
  duracion = _duracion;
  calificacion = _calificacion;
  genero = _genero;
  sp = _sp;
  np = _np;
}

void Videos::print() {
  cout << "Id: " << id << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Duracion: " << duracion << endl;
  cout << "Género: " << genero << endl;
  cout << "Calificacion promedio: " << calificacion << endl;
}

string Videos::getGen() { 
	return genero; 
}

string Videos::getNom() { 
	return nombre; 
}
string Videos::getSp() {
	return sp; 
}
double Videos::getCal() { 
	return calificacion; 
}

void Videos::setCalif(double c) {
  calificacion = c;
}

int Videos::getNp() {
  return np;
}

void Videos::setNp(int np1) {
  np = np1;
}

