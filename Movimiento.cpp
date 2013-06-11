#include <iostream>
#include <string>
#include <ncurses.h>

#include "Movimiento.h"

using namespace std;

//inicio constructor de la clase movimiento
Movimiento::Movimiento(Pieza* pieza, Posicion* origen, Posicion* destino)
{
   this->pieza = pieza;//inicializa variable privada con parametros recibidos
   this->origen = origen;//inicializa variable privada con parametros recibidos
   this->destino = destino;//inicializa variable privada con parametros recibidos
}//fin constructor de la clase movimiento

//inicio destructor de la clase movimiento
Movimiento::~Movimiento()
{
   delete pieza;
   delete origen;
   delete destino;//borra las instancias de las variables privadas
}//fin destructor de la clase movimiento

Posicion* Movimiento::getOrigen()
{
    return origen;
}

Posicion* Movimiento::getDestino()
{
    return destino;
}

Pieza* Movimiento::getPieza()
{
    return pieza;
}

//inicio metodo imprimir
void Movimiento::imprimir()
{
   string tipo_pieza;//crea variable de tipo string para almacenar
   string tipo_color;//crea variable de tipo string para almacenar

   if( pieza->getTipo() == TORRE )
      tipo_pieza = " TORRE ";//guarda si tipo es TORRE

   else if( pieza->getTipo() == CABALLO )
      tipo_pieza = " CABALLO ";//guarda si tipo es CABALLO

   else if( pieza->getTipo() == ALFIL )
      tipo_pieza = " ALFIL ";//guarda si tipo es ALFIL

   else if( pieza->getTipo() == REINA )
      tipo_pieza = " REINA ";//guarda si tipo es REINA

   else if( pieza->getTipo() == REY )
      tipo_pieza = " REY ";//guarda si tipo es REY

   else if( pieza->getTipo() == PEON )
      tipo_pieza = " PEON ";//guarda si tipo es PEON


   if( pieza->getColor() == BLANCA )
      tipo_color = " BLANCA ";//guarda si color es BLANCO

   else if( pieza->getColor() == NEGRO )
      tipo_color = " NEGRA ";//guarda si color es NEGRO

   stringstream ss;
   //imprime coordenada de origen + tipo de pieza + color de pieza + coordenada de destino
   ss << "("<<(origen->getX()+1)<<","<<(origen->getY()+1)<<")"<<tipo_pieza<<" "<<tipo_color<<"("<<(destino->getX()+1)<<","<<(destino->getY()+1)<<")"<<"\n";
   printw("%s", ss.str().c_str() );
}//fin metodo imprimir

string Movimiento::toString(){
   stringstream ss;
   ss << (origen->getX()+1)<<","<<(origen->getY()+1)<<","<<(destino->getX()+1)<<","<<(destino->getY()+1)<<";";
   return ss.str();
}