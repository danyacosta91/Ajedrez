#ifndef ALFIL_H
#define ALFIL_H
#include "Pieza.h"
#include "Posicion.h"
#include <string.h>
using namespace std;

//inicio clase alfil que deriva de la clase pieza
class Alfil: public Pieza
{
   private:
     ENUM_COLOR color;//variable privada de tipo enum
   public:
     Alfil( ENUM_COLOR );//constructor de la clase alfil
     string toString();//metodo que imprime la pieza
     bool esMovimientoValido( Posicion*, Posicion* );//metodo que devuelve si es un movimiento valido
};//fin clase alfil

#endif
