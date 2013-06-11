#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include "Posicion.h"
#include "Pieza.h"
#include <string.h>
#include <sstream>
#include "Enumeracion.h"
#include <ncurses.h>
using namespace std;

//inicio clase Movimiento
class Movimiento
{
    public:
     Movimiento(Pieza*,Posicion*,Posicion*);//constructor de la clase Movimiento
     ~Movimiento();//destructor de la clase Movimiento
     string toString();//metodo que devuelve cadena
     void imprimir();//metodo que imprime el movimiento
     Posicion* getOrigen();
     Posicion* getDestino();
     Pieza* getPieza();

   private:
     Posicion* origen;//variable privada de tipo posicion
     Posicion* destino;//variable privada de tipo posicion
     Pieza* pieza;//variable privada de tipo pieza   
};//fin clase Movimiento

#endif
