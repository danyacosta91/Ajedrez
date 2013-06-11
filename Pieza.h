#ifndef PIEZA_H
#define PIEZA_H
#include "Posicion.h"
#include "Enumeracion.h"
#include <string.h>
using namespace std;

//inicio clase pieza
class Pieza
{
   private:
      ENUM_PIEZA tipo;//variable privada de tipo enum
      ENUM_COLOR color;//variable privada de tipo enum
   public:
      Pieza(ENUM_COLOR);//constructor de la clase pieza, que recibe un color
      ENUM_PIEZA getTipo();//metodo que devuelve el tipo de la pieza
      ENUM_COLOR getColor();//metodo que devuelce el color de la pieza
      virtual string toString();//metodo que imprime la pieza
      virtual bool esMovimientoValido(Posicion*,Posicion*);//metodo que valida si es un movimiento valido
   protected:
      void setTipo(ENUM_PIEZA);//metodo protegido para establecer el tipo de la pieza
};//fin clase pieza

#endif
