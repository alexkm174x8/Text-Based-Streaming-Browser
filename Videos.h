#ifndef VIDEOS_H_INCLUDED
#define VIDEOS_H_INCLUDED
#include <iostream>
using namespace std;

class Videos {
public:
  int id;
  string nombre;
  string duracion;
  string genero;
  double calificacion;
  string sp;
  int np;

public:
  Videos();
  Videos(int, string, string, string, double, string, int);

  string getGen();
  string getNom();
  string getSp();
  double getCal();
  void setCalif(double);
  int getNp();
  void setNp(int);

  virtual void print() = 0;

};

#endif