#include "Sobrecarga.h"

Sobrecarga::Sobrecarga(){
  
}

ostream& operator<<(ostream & menu, const Sobrecarga& obj){
  menu << "1. Cargar archivo de datos" << endl << "2. Mostrar los videos en general con una cierta calificación\no de un cierto género"<< endl << "3. Mostrar los episodios de una\ndeterminada serie con una calificacion determinada" << endl << "4. Mostrar las películas con cierta calificacion" << endl << "5. Calificar un video" << endl << "0. Salir" << endl;

  return menu;
}; 