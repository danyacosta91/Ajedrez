#include <iostream>
#include "Torre.h"
#include "Enumeracion.h"
using namespace std;

Torre::Torre(ENUM_COLOR color): Pieza(color)
{
   this->color = color;
   Pieza::setTipo(TORRE);
}

string Torre::toString()
{
  if( color == NEGRO )
    return "  T  ";
  if( color == BLANCA )
    return "  t  ";
}

bool Torre::esMovimientoValido(Posicion* origen,Posicion* destino)
{
    int x_origen = origen->getX();
    int y_origen = origen->getY();
    int x_destino = destino->getX();
    int y_destino = destino->getY();
    if( x_origen != x_destino )
    {
       if( y_destino == y_origen )
           return true;           
    }
    else if( y_origen != y_destino )
    {
       if( x_destino == x_origen )
           return true;           
    }else
       return false;
}
