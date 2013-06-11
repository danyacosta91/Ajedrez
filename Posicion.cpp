#include <iostream>
#include "Posicion.h"
using namespace std;

//inicio constructor de la clase posicion
Posicion::Posicion(int x, int y)
{
   this -> x = x;//inicializa variable privada con parametros recibidos
   this -> y = y;//inicializa variable privada con parametros recibidos
}//fin constructor de la clase posicion

//inicio metodo getX
int Posicion::getX()
{
   return x;//retorna el valor de variable privada
}//fin metodo getX

//inicio metodo getY
int Posicion::getY()
{
   return y;//retorna el valor de variable privada
}//fin metodo getY
