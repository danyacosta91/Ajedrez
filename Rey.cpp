#include <iostream>
#include <cmath>
#include "Rey.h"
using namespace std;

Rey::Rey(ENUM_COLOR color): Pieza(color)
{
   this->color = color;
   Pieza::setTipo(REY);
}

string Rey::toString()
{
    if( color == NEGRO )
      return "  K  ";
    if( color == BLANCA )
      return "  k  ";
}

bool Rey::esMovimientoValido(Posicion* origen, Posicion* destino)
{
    int x_origen = origen->getX();
    int y_origen = origen->getY();
    int x_destino = destino->getX();
    int y_destino = destino->getY();
    if( fabs(x_destino-x_origen) == 1 && fabs(y_destino-y_origen) <= 1 )
       return true;
    else if( fabs(y_destino-y_origen) == 1 && fabs(x_destino-x_origen) <= 1 )
       return true;
    else
       return false;
}
