#ifndef REY_H
#define REY_H
#include "Pieza.h"
#include "Posicion.h"
#include <string.h>
using namespace std;

//inicio de la clase rey que deriva de pieza
class Rey: public Pieza
{
   private:
     ENUM_COLOR color;//variable privada de tipo enum
   public:
     Rey( ENUM_COLOR );//constructor de la clase rey
     string toString();//metodo que imprime la pieza
     bool esMovimientoValido( Posicion*, Posicion* );//metodo que devuelve si es un movimiento valido
};//fin clase rey

#endif
