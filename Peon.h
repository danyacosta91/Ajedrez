#ifndef PEON_H
#define PEON_H
#include "Pieza.h"
#include "Posicion.h"
#include <string.h>
using namespace std;

//inicio de la clase peon que deriva de pieza
class Peon: public Pieza
{
   private:
     ENUM_COLOR color;//variable privada de tipo enum
   public:
     Peon( ENUM_COLOR );//constructor de la clase peon
     string toString();//metodo que imprime la pieza
     bool esMovimientoValido( Posicion*, Posicion* );//metodo que devuelve si es un movimiento valido
};//fin clase peon

#endif
