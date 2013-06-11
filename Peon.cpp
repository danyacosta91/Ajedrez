#include <iostream>
#include <cmath>
#include "Peon.h"
#include "Ajedrez.h"
using namespace std;

Peon::Peon(ENUM_COLOR color): Pieza(color)
{
   this->color = color;
   Pieza::setTipo(PEON);   
}

string Peon::toString()
{
    if( color == NEGRO )
      return "  P  ";
    if( color == BLANCA )
      return "  p  ";
}

bool Peon::esMovimientoValido(Posicion* origen,Posicion* destino)
{
	
    int x_origen = origen->getX();int y_origen = origen->getY();    
    int x_destino = destino->getX();int y_destino = destino->getY();
    
    if( color == NEGRO && (x_origen == 1 && (x_destino-x_origen == 2 || x_destino-x_origen == 1)) )
       return true;
    else if( color == NEGRO && (x_origen != 1 && x_destino-x_origen == 1) )
       return true;
    else if( color == BLANCA && (x_origen == 6 && (x_origen-x_destino == 2 || x_origen-x_destino == 1)) )
       return true;
    else if( color == BLANCA && (x_origen != 6 && x_origen-x_destino == 1) )
       return true;
    else
       return false;
}
