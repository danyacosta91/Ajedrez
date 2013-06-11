#ifndef CABALLO_H
#define CABALLO_H
#include "Pieza.h"
#include "Posicion.h"
#include <string.h>
using namespace std;

//inicio clase caballo que deriva de pieza
class Caballo: public Pieza
{
   private:
     ENUM_COLOR color;//variable privada de tipo enum
   public:
     Caballo( ENUM_COLOR );//constructor de la clase caballo
     string toString();//metodo que imprime la pieza
     bool esMovimientoValido( Posicion*, Posicion* );//metodo que devuelve si es un movimiento valido
};//fin clase caballo

#endif
