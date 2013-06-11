#include <iostream>
#include "Ajedrez.h"
#include "Posicion.h"
#include <ncurses.h>
using namespace std;

//inicio del metodo main
int main()
{
  initscr();
  start_color();
  init_pair(2, COLOR_WHITE, COLOR_BLACK );
  init_pair(1, COLOR_BLACK, COLOR_WHITE );
  init_pair(3, COLOR_BLUE, COLOR_BLACK );
  init_pair(4, COLOR_RED, COLOR_WHITE );
  init_pair(5, COLOR_GREEN, COLOR_BLACK );
  init_pair(6, COLOR_YELLOW, COLOR_RED );
  
  Ajedrez* ajedrez = new Ajedrez();//crea variable de tipo Ajedrez* e inicializa el tablero
  int x1,y1,x2,y2;//crea 4 variables para almacenar origenes y destinos en "X" y "Y"
  Posicion* origen, *destino;//crea 2 variables de tipo Posicion*
  int control = 0;//crea variable para controlar ciclo repetitivo
  bool turnoA = true;

  do 
  {
    clear();
    ajedrez->imprimir();//imprime el tablero inicialmente
    
    attron( COLOR_PAIR(6) | A_BOLD );
    if( turnoA )
      printw("\n\nTURNO PIEZAS DE COLOR NEGRO (LETRAS MAYUSCULAS)!\n\n");
    else
      printw("\n\nTURNO PIEZAS DE COLOR BLANCO (LETRAS minusculas)!\n\n");

    attron( COLOR_PAIR(5) | A_BOLD );
    printw("\n        MENU\n\n1. Salir\n2. Mover Pieza\n3. Imprimir Bitacora\nINGRESE OPCION: ");
    control = getch();
    control -= 48;//asigna valor ingresado
    switch( control )//inicio del bloque caso de lectura
    {
      case 1:
        control = 0;//sale del programa
      break;
      case 2:
      //inicio ciclo para controlar variables
      do
      {
        printw("\nINGRESE PIEZA A BUSCAR (EN COLUMNA): ");
        y1 = getch();
        printw("\nINGRESE PIEZA A BUSCAR (EN FILA): ");
        x1 = getch();

        y1 -= 48;x1 -= 48;
      }while( (y1 < 1) || (y1 > 8) || (x1 < 1) || (x1 > 8) );//repite ciclo mientras variables no se pasen de lo establecido
      //inicio ciclo para controlar variables
      do
      {
        printw("\nINGRESE PIEZA A BUSCAR (EN COLUMNA): ");
        y2 = getch();
        printw("\nINGRESE PIEZA A BUSCAR (EN FILA): ");
        x2 = getch();

        y2 -= 48;x2 -= 48;
      }while( (y2 < 1) || (y2 > 8) || (x2 < 1) || (x2 > 8) );//repite ciclo mientras variables no se pasen de lo establecido
      x1 = x1 - 1;y1 = y1 - 1;x2 = x2 - 1;y2 = y2 - 1;//resta 1 a cada dato ingresado
      origen = new Posicion(x1,y1);//crea una nueva instancia con los valores dados
      destino = new Posicion(x2,y2);//crea una nueva instancia con los valores dados
      if( ajedrez->moverPieza(origen,destino) )//pregunta si se puede mover pieza
        ajedrez->imprimir();//imprime el tablero si pieza se pudo mover
      else{
        attron( COLOR_PAIR(4) | A_BOLD );
        printw("\n\nMOVIMIENTO INVALIDO!!!\n\n");
        getch();
      }
      break;
      case 3:
        clear();
        ajedrez->imprimirBitacora();
        getch();
      break;
      default:
        attron( COLOR_PAIR(4) | A_BOLD );
        printw("\n\nERROR DE DATOS!!!\n");//mensage de error por si datos del menu estan incorrectos
        getch();
    }
    turnoA = !turnoA;
  }while ( control != 0 && !ajedrez->finJuego() );//sale del ciclo si variable es 0

  endwin();
  delete ajedrez; //llama al destructor de ajedrez 
  return 0;//retorna 0 para cerrar aplicacion
}//fin main
