#include <iostream>
#include <cmath>
#include "Reina.h"
using namespace std;

Reina::Reina(ENUM_COLOR color): Pieza(color)
{
   this->color = color;
   Pieza::setTipo(REINA);
}

string Reina::toString()
{
    if( color == NEGRO )
      return "  Q  ";
    if( color == BLANCA )
      return "  q  ";
}

bool Reina::esMovimientoValido(Posicion* origen, Posicion* destino)
{
    int x_origen = origen->getX();
    int y_origen = origen->getY();
    int x_destino = destino->getX();
    int y_destino = destino->getY();
    if( fabs(x_origen-x_destino) == fabs(y_origen-y_destino) )
       return true;
    if( x_origen != x_destino )
    {
       if( y_destino == y_origen )
           return true;
    }
    else if( y_origen != y_destino )
    {
       if( x_destino == x_origen )
           return true;
    }
    else
       return false;
}
