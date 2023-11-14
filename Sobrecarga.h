#ifndef SOBRECARGA_H_INCLUDES
#define SOBRECARGA_H_INCLUDES

#include <iostream>
using namespace std;

class Sobrecarga{

public:
Sobrecarga();
friend ostream& operator<<(ostream& menu, const Sobrecarga& obj);

};

#endif