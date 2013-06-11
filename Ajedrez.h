#ifndef AJEDREZ_H
#define AJEDREZ_H
#include <list>
#include "Posicion.h"
#include "Pieza.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Reina.h"
#include "Rey.h"
#include "Peon.h"
#include <ncurses.h>
#include <vector>
#include "Movimiento.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//inicio clase ajedrez
class Ajedrez
{
   private:
      Pieza* tablero[8][8];//variable privada de tipo pieza
      void inicializarTablero();//metodo privado para inicializar tablero
      bool estaVacia(Posicion*);//metodo privado para ver si posicion esta vacia
      bool hayPiezasEnMedio(Posicion*,Posicion*);//metodo privado para ver si hay pieza en medio
      vector<Movimiento*> bitacora;
      void leerArchivo();
      void escribirArchivo();
   public:
   	  Ajedrez();
      void imprimir();//metodo que imprime el tablero
      bool moverPieza(Posicion*,Posicion*);//metodo publico mover la pieza de un origen a un destino
      void imprimirBitacora();
      ~Ajedrez();//destructor de la clase ajedrez
      bool finJuego();
};//fin clase ajedrez

#endif
