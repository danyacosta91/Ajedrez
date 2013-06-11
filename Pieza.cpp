#include <iostream>
#include "Pieza.h"
using namespace std;

//inicio del contstructor de la clase pieza
Pieza::Pieza(ENUM_COLOR color)
{
   this->color = color;//inicializa variable privada con parametro recibido
   Pieza::setTipo(VACIA);//establece el tipo de pieza
}//fin constructor de la clase pieza
 
//inicio metodo getTipo
ENUM_PIEZA Pieza::getTipo()
{
   return tipo;//retorna el tipo de pieza
}//fin metodo getTipo

//inicio metodo getColor
ENUM_COLOR Pieza::getColor()
{
   return color;//devuelve el color de la pieza
}//fin metodo getColor

//inicio metodo imprimir
string Pieza::toString()
{
	return "     ";//imprime posicion vacia o manda a llamar al metodo de las piezas hijas
}//fin metodo imprimir

//inicio metodo esMovimientoValido
bool Pieza::esMovimientoValido(Posicion* origen, Posicion* destino)
{
   //llama al metodo esMovimientoValido de cada una de las piezas
}//fin metodo esMovimientoValido

//inicio metodo setTipo
void Pieza::setTipo(ENUM_PIEZA tipo)
{
   this->tipo = tipo;//inicializa la varible privada con parametros recibido
}//fin metodo setTipo
