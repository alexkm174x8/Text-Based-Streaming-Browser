/*
The following program shows different options for displaying data from streaming video services, including series and movies. 
Using inheritance and polymorphism, a parent class (Videos) and child classes (Series and Movies) will be created. 

The program will display a menu with the following options:

Load data file
Display all videos with a certain rating or of a certain genre
Display episodes of a specific series with a certain rating
Display movies with a certain rating
Rate a video
Enter title to rate
Enter rating value
Exit
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Peliculas.cpp"
#include "Series.cpp"
#include "Videos.cpp"
#include "Sobrecarga.cpp"

using namespace std;

int main() {

  Videos *arreglo[1005];

  int opcion = 0;
  int adder = 0;
  int i = 0;

  ifstream archivo("datos.txt");
  if (!archivo) {
    cerr << "No se pudo abrir el archivo." << endl;
  }
  do {
    Sobrecarga menu;
    cout << menu <<endl;
    cin >> opcion;

    if (opcion == 1) {
      for (int i = 0; i < 40; i++) {
        string linea;
        getline(archivo, linea);
        istringstream iss(linea);
        string idStr, nom, dur, gen, califStr, sp, a, nps;
        getline(iss, idStr, '\t');
        getline(iss, nom, '\t');
        getline(iss, dur, '\t');
        getline(iss, gen, '\t');
        getline(iss, califStr, '\t');
        getline(iss, sp, '\t');
        getline(iss, a, '\t');
        getline(iss, nps, '\t');
        int id = stoi(idStr);
        int np = stoi(nps);
        double calif = stod(califStr);
        if (sp == "P") {
          arreglo[adder] = new Peliculas(id, nom, dur, gen, calif, sp, a, np);
          arreglo[adder]->print();
        } else {
          arreglo[adder] = new Series(id, nom, dur, gen, calif, sp, a, np);
          arreglo[adder]->print();
        }
        adder++;
        cout << "¡Archivo cargado!" << endl;
        cout << endl;
      }
    }

    else if (opcion == 2) {
      cout << "Escoge si buscar por género (1) o por calificación (2)"
           << "\n"
           << "(Mostrará tanto películas como episodios bajo dicho parámetro)"
           << endl;

      int s_option;
      cin >> s_option;

      if (s_option == 1) {

        cout << "Géneros disponibles: \nDrama \nAcción \nMisterio \nTerror \nSci-Fi \nThriller \nBiografia \nCrimen \nComedia \nMusical \nRomantica \nEscribe el género tal cuál aparece mostrado:" << endl;

        string g_option;
        cin >> g_option;
        cout << endl;

        for (i = 0; i < adder; i++) {

          string gen = "";
          gen = arreglo[i]->getGen();
          if (gen == g_option) {
            arreglo[i]->print();
          }
        }
      }
      if (s_option == 2) {
        cout << "Inserte una calificación de 1 a 5:" << endl;

        double c_option;
        cin >> c_option;
        cout << endl;

        for (i = 0; i < adder; i++) {

          double cal = 0.0;
          cal = arreglo[i]->getCal();
          if (cal >= c_option and cal <= (c_option + 1))
            arreglo[i]->print();
        }
      }
    } else if (opcion == 3) {
      cout << "Escribe el nombre de la serie a buscar:" << endl;

      string sOption;
      cin.ignore(1);
      getline(cin, sOption);

      cout << "Escribe la calificación de la serie a buscar del 1 al 5:"
           << endl;

      double sCalif;
      cin >> sCalif;

      for (i = 0; i < adder; i++) {
        double cal = 0.0;
        string nSerie = "";
        cal = arreglo[i]->getCal();
        nSerie = arreglo[i]->getSp();
        if (nSerie == sOption) {
          if (cal == sCalif) {
            arreglo[i]->print();
          }
        }
      }
    } else if (opcion == 4) {
      cout << "Escribe la calificación de las peliculas a buscar del 1 al 5:"
           << endl;
      double pCalif;
      cin >> pCalif;
      for (i = 0; i < adder; i++) {
        double cal = 0.0;
        string spp = "";
        cal = arreglo[i]->getCal();
        spp = arreglo[i]->getSp();
        if ((cal >= pCalif) and ((cal < (pCalif + 1)) and (spp == "P"))) {
          arreglo[i]->print();
        }
      }
    } else if (opcion == 5) {
      cout << "Escribe el nombre del video a buscar:" << endl;
      string vOption;
      cin.ignore(1);
      getline(cin, vOption);

      cout << "Escribe la calificación del video a otorgar del 1 al 5:" << endl;

      double vCalif;
      cin >> vCalif;

      for (i = 0; i < adder; i++) {
        string nVideo = "";
				int nPersonas = 0;
				double calif = 0;
        int n_p = 0;
				string sp = "";
        nVideo = arreglo[i]->getNom();
        calif = arreglo[i]->getCal();
				sp = arreglo[i]->getSp();
        nPersonas = arreglo[i]->getNp();
        if (nVideo == vOption) {
					calif = (calif*nPersonas + vCalif)/(nPersonas+1);   
					nPersonas ++;
					arreglo[i]->setCalif(calif);
          arreglo[i]->print();
        }
      }
    }
  } while (opcion != 0);

  cout << "Gracias por utilizar el servicio" << endl;
  archivo.close(); // Cierra el archivo
  return 0;
}