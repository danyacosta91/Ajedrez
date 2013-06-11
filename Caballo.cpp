#include <iostream>
#include <cmath>
#include "Caballo.h"
using namespace std;

//inicio del constructor de caballo e inicializa el constructor de 
Caballo::Caballo(ENUM_COLOR color): Pieza(color)
{
   this->color = color;//inicializa variables privadas con parametros recibidos
   Pieza::setTipo(CABALLO);//establece el tipo de pieza
}//fin construc

//inicio metodo imprimir
string Caballo::toString()
{
    if( color == NEGRO )
      return "  C  ";
    if( color == BLANCA )
      return "  c  ";
}//fin metodo imprimir

//inicio metodo esMovimientoValido
bool Caballo::esMovimientoValido(Posicion* origen, Posicion* destino)
{
    int x_origen = origen->getX();//asigna a variable local el origen en "X"
    int y_origen = origen->getY();//asigna a variable local el origen en "Y"
    int x_destino = destino->getX();//asigna a variable local el destino en "X"
    int y_destino = destino->getY();//asigna a variable local el destino en "Y"
    //pregunta si el destino es igual a 1 y 2
    if( (fabs(x_destino-x_origen) == 2 && fabs(y_destino-y_origen) == 1) || (fabs(x_destino-x_origen) == 1 && fabs(y_destino-y_origen) == 2) )
      return true;//retorna verdadero si destino es 1 Y 2
    else
      return false;//retorna falso si destino no es 1 Y 2
}//fin metodo esMovimientoValido
