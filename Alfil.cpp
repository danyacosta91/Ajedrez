#include <iostream>
#include <cmath>
#include "Alfil.h"
#include "Enumeracion.h"
using namespace std;

//inicio del constructor de alfil e inicializa el constructor de pieza
Alfil::Alfil(ENUM_COLOR color): Pieza(color)
{
    this->color = color;//inicializa variable privada con parametros recibidos
    Pieza::setTipo(ALFIL);//establece el tipo de pieza
}//fin constructor de alfil

//inicio metodo imprimir
string Alfil::toString()
{
    if( color == NEGRO )
      return "  A  ";
    if( color == BLANCA )
      return "  a  ";
}//fin metodo imprimir

//inicio metodo esMovimientoValido
bool Alfil::esMovimientoValido(Posicion* origen, Posicion* destino)
{
    int x_origen = origen->getX();int y_origen = origen->getY();//crea variable local del parametro origen
    int x_destino = destino->getX();int y_destino = destino->getY();//crea variable local del parametro origen

    if( fabs(x_destino-x_origen) == fabs(y_destino-y_origen) )//condicion si origen y destino son iguales
       return true;//retorna verdadero si condicion se cumple
    else
       return false;//retorna verdadero si condicion no se cumple
}//fin metodo esMovimientoValido
