#ifndef REINA_H
#define REINA_H
#include "Pieza.h"
#include "Posicion.h"
#include <string.h>
using namespace std;

//inicio de la clase reina que deriva de pieza
class Reina: public Pieza
{
   private: 
     ENUM_COLOR color;//variable privada de tipo enum
   public:
     Reina( ENUM_COLOR );//constructor de la clase reina
     string toString();//metodo que imprime la pieza
     bool esMovimientoValido( Posicion*, Posicion* );//metodo que devuelve si es un movimiento valido
};//fin clase reina

#endif
