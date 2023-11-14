#include "Peliculas.h"
#include <iostream>
#include <string>
using namespace std;

Peliculas::Peliculas(int _id,string _nombre, string _duracion, string _genero, double _calificacion, string _sp, string _na, int _np):Videos(_id, _nombre, _duracion, _genero, _calificacion, _sp, _np){
  na = _na;
  np = _np;
}

void Peliculas::print(){
  
  cout << "Película:" << endl;
  Videos::print();
  cout << "Personas que han votado antes que tú: " << np << endl;
  cout << endl;
	
}

string Peliculas::getGen(){
  return Videos::getGen();
}

string Peliculas::getSp(){
  return Videos::getSp();
}

double Peliculas::getCal(){
 return Videos::getCal();
}

int Peliculas::getNp(){
  return Videos::getNp();
}
