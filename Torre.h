#ifndef TORRE_H
#define TORRE_H
#include "Pieza.h"
#include "Posicion.h"
#include <string.h>
using namespace std;

//inicio de la clase torre que deriva de pieza
class Torre: public Pieza
{
   private:
     ENUM_COLOR color;//variable privada de tipo enum
   public:
     Torre( ENUM_COLOR );//constructor de la clase torre
     string toString();//metodo que imprime la pieza
     bool esMovimientoValido( Posicion*, Posicion* );//metodo que devuelve si es un movimiento valido
};//fin clase torre

#endif
