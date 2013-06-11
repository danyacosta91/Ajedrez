#include <iostream>
#include "Ajedrez.h"
#include "Enumeracion.h"
#include <cmath>
using namespace std;

//inicio del constructor de la clase ajedrez
Ajedrez::Ajedrez()
{
  //inicializa cada cuadro del tablero
  //ya sea pieza o este vacia
  inicializarTablero();
  leerArchivo();
}//fin constructor clase ajedrez

void Ajedrez::inicializarTablero()
{
   tablero[0][0] = new Torre(NEGRO);tablero[0][1] = new Caballo(NEGRO);//inicializa piezas: torre, caballo
   tablero[0][2] = new Alfil(NEGRO);tablero[0][3] = new Reina(NEGRO);//inicializa piezas: alfil, reina
   tablero[0][4] = new Rey(NEGRO);tablero[0][5] = new Alfil(NEGRO);//inicializa piezas: rey, alfl
   tablero[0][6] = new Caballo(NEGRO);tablero[0][7] = new Torre(NEGRO);//inicializa piezas: caballo, torre
   tablero[1][0] = new Peon(NEGRO);tablero[1][1] = new Peon(NEGRO);//inicializa piezas: peon, peon
   tablero[1][2] = new Peon(NEGRO);tablero[1][3] = new Peon(NEGRO);//inicializa piezas: peon, peon
   tablero[1][4] = new Peon(NEGRO);tablero[1][5] = new Peon(NEGRO);//inicializa piezas: peon, peon
   tablero[1][6] = new Peon(NEGRO);tablero[1][7] = new Peon(NEGRO);//inicializa piezas: peon, peon
   tablero[6][0] = new Peon(BLANCA);tablero[6][1] = new Peon(BLANCA);//inicializa piezas: peon, peon
   tablero[6][2] = new Peon(BLANCA);tablero[6][3] = new Peon(BLANCA);//inicializa piezas: peon, peon
   tablero[6][4] = new Peon(BLANCA);tablero[6][5] = new Peon(BLANCA);//inicializa piezas: peon, peon
   tablero[6][6] = new Peon(BLANCA);tablero[6][7] = new Peon(BLANCA);//inicializa piezas: peon, peon
   tablero[7][0] = new Torre(BLANCA);tablero[7][1] = new Caballo(BLANCA);//inicializa piezas: torre, caballo
   tablero[7][2] = new Alfil(BLANCA);tablero[7][3] = new Reina(BLANCA);//inicializa piezas: alfil, reina
   tablero[7][4] = new Rey(BLANCA);tablero[7][5] = new Alfil(BLANCA);//inicializa piezas: rey, alfil
   tablero[7][6] = new Caballo(BLANCA);tablero[7][7] = new Torre(BLANCA);//inicializa piezas: caballo, torre
   //empieza desde la linea 3 hasta linea 6
   for( int i = 2; i < 6; i++ )
   {
      for( int j = 0; j < 8; j++ )
      {
          tablero[i][j] = 0;//inicializa piezas vacias
      }//fin para interior
   }//fin para exterior
}//fin metodo inicializarTablero

//inicio metodo estaVacia
bool Ajedrez::estaVacia( Posicion* posicion )
{
    int x = posicion->getX();//guarda en variable local la "x" de la posicion
    int y = posicion->getY();//guarda en variable local la "y" de la posicion
    if( tablero[x][y] == 0 )        
       return true;//retorna verdadero si cuadrado del tablero esta vacia
    return false;
}//fin metodo estaVacia

bool Ajedrez::finJuego(){
  int cont = 0;
  for( int i = 0; i < 8; i++ ){
    for( int j = 0; j < 8; j++ ){
      if( tablero[i][j] != 0 && tablero[i][j]->getTipo() == REY ){
        cont++;
      }
    }
  }

  if( cont > 1 )
    return false;
  return true;
}

//inicio metodo imprimir
void Ajedrez::imprimir()
{
  int cont = 0;
  attron( COLOR_PAIR(3) | A_BOLD );
  printw("                  T A B L E R O\n\n");//imprime mensage de tablero
  printw("      1     2     3     4     5     6     7     8\n\n");//imprimir lista de 1 a 8
  for( int i = 0; i < 8; i++ )
  {
    attron( COLOR_PAIR(3) | A_BOLD );
    printw("%d  |",(i+1));
    for( int j = 0; j < 8; j++)
    {
      if( cont%2 == 0 )
        attron( COLOR_PAIR(2) | A_BOLD );
      else
        attron( COLOR_PAIR(1) | A_BOLD );
      cont++;
      if( tablero[i][j] == 0 )
        printw("     ");
      else
        printw("%s", tablero[i][j]->toString().c_str() );
      attron( COLOR_PAIR(3) | A_BOLD );
      printw("|");
    }//fin para interior
    attron( COLOR_PAIR(3) | A_BOLD );
    printw("\n   -------------------------------------------------\n");//imprime linea de rayas
    cont++;
  }//fin para exterior
}//fin metodo imprimir

void Ajedrez::imprimirBitacora(){
  string tmp = "";
  attron( COLOR_PAIR(6) | A_BOLD );
  printw("BITACORA DE MOVIEMIENTOS\n\n");
  attron( COLOR_PAIR(5) | A_BOLD );
  for(int i = 0; i < bitacora.size(); i++){
    bitacora.at(i)->imprimir();
  }
}

void Ajedrez::leerArchivo(){
  ifstream leer ("estadisticas.txt");
  char buffer[2];
  int x1,y1,x2,y2;
  Posicion* origen;
  Posicion* destino;

  //(2,2) PEON   NEGRA (4,2)
  if( !leer ){
    attron( COLOR_PAIR(4) | A_BOLD );
    printw("Archivo no se pudo leer...!");
    getch();
  }else {
    while ( !leer.eof() ){
      leer.getline(buffer, 2, ',');
      x1 = atoi(buffer);
      leer.getline(buffer, 2, ',');
      y1 = atoi(buffer);
      
      leer.getline(buffer, 2, ',');
      x2 = atoi(buffer);
      leer.getline(buffer, 2, ';');
      y2 = atoi(buffer);

      origen = new Posicion(x1-1,y1-1);
      destino = new Posicion(x2-1,y2-1);

      moverPieza(origen,destino);
    }
    leer.close();
    attron( COLOR_PAIR(4) | A_BOLD );
    printw("Archivo cargado exitosamente...!");
    getch();
  }
}

void Ajedrez::escribirArchivo(){
  ofstream archivo("estadisticas.txt");
  for(int i = 0; i < bitacora.size(); i++){
    archivo << bitacora.at(i)->toString();
  }
  archivo.close();
}

//inicio metodo moverPieza
bool Ajedrez::moverPieza(Posicion* origen,Posicion* destino)
{
   Pieza* tmp;//crea variable temporal de tipo pieza
   int x_origen = origen->getX();int y_destino = destino->getY();//variables locales para "x" y "y" del destino/origen
   int y_origen = origen->getY();int x_destino = destino->getX();//variables locales para "x" y "y" del destino/origen 
   if( estaVacia(origen) )//pregunta si pieza esta vacia
   {
      return false;//retorna falso si pieza esta vacia
   }//fin si pieza esta vacia

  if( tablero[x_origen][y_origen]->getTipo() == PEON )//pregunta si pieza es PEON
  {      
      if( !estaVacia(destino))//si destino no esta vacio
      {         
         if( fabs(x_origen-x_destino) != 1 || fabs(y_origen-y_destino) != 1 || (tablero[x_destino][y_destino]->getColor() == 
             tablero[x_origen][y_origen]->getColor() ))    
         {                        
              return false;//retorna falso si color de pieza contraria es igual a pieza original o si el destino esta vacio
         }
       }//fin si exterior
       if (tablero[x_destino][y_destino] == 0 && fabs(y_destino-y_origen) != 0)
	   return false;//retorna falso si 	
   }//fin si PEON

   if( tablero[x_origen][y_origen]->esMovimientoValido(origen, destino) && !(hayPiezasEnMedio(origen,destino)) & estaVacia(destino) )//pregunta si esMovimiento valdo, no ay piezas enmedio, y esta vacia la posicion de destino
   {
      bitacora.push_back(new Movimiento(tablero[x_origen][y_origen], origen, destino));//ingresa movimiento a bitacora de movimientos
      tmp = tablero[x_destino][y_destino];//al temporal le asignamos el destino
      tablero[x_destino][y_destino] = tablero[x_origen][y_origen];//al destino le asignamos el origen
      tablero[x_origen][y_origen] = tmp;//y origen le asignamos destino
      delete tmp;//borramos instancia de temporal
      return true;//retornamos verdadero se condicion se cumplio
   }//fin si esMovimientoValido, no ay pieza en medio y esta vacia
   if( tablero[x_origen][y_origen]->esMovimientoValido(origen, destino) && !(hayPiezasEnMedio(origen,destino)) & !(estaVacia(destino)) )//pregunta si esMovimiento valdo, no ay piezas enmedio, y no esta vacia la posicion de destino
   {
      if( tablero[x_origen][y_origen]->getColor() != tablero[x_destino][y_destino]->getColor() )//pregunta si color de origen es distinto del color de destino
      {
        bitacora.push_back(new Movimiento(tablero[x_origen][y_origen], origen, destino));//ingresa movimiento a bitacora de movimientos
        tmp = tablero[x_destino][y_destino];//al temporal le asignamos el destino
        tablero[x_destino][y_destino] = tablero[x_origen][y_origen];//al destino le asignamos el origen          
	      tablero[x_origen][y_origen] = 0;//al origen le asignamos 0
        return true;//retornamos verdadero se condicion se cumplio
      }//fin si colores son distintos
   }//fin si esMovimientoValido, no ay pieza en medio y no esta vacia
   
   return false;//si ninguna se cumplio retorna falso
}//fin si metodo moverPieza

//inicio metodo hayPiezaEnMedio
bool Ajedrez::hayPiezasEnMedio(Posicion* origen,Posicion* destino)
{ 
   int x_origen = origen->getX();int y_destino = destino->getY();//variables locales para "x" y "y" del destino/origen
   int y_origen = origen->getY();int x_destino = destino->getX();//variables locales para "x" y "y" del destino/origen 
   int tipo = tablero[x_origen][y_origen]->getTipo();//variable de tipo de pieza
   switch( tipo )//inicio bloque caso de tipo de pieza
   {
      //caso TORRE
      case TORRE:
       if( x_destino-x_origen > 0 )//pregunta si movimiento es a la derecha
       {
          for( int i = x_origen + 1; i < x_destino; i++ )//recorre cada cacia verificanco si esta vacia
          {
              if(tablero[i][y_origen]!= 0)//pregunta si tablero esta vacio
                 return true;//retorna verdadero si tablero esta vacio
          }
          return false;//retorna verdadero si no tablero no esta vacia
       }else if( y_destino-y_origen > 0 )//pregunta si movimiento es arriba
       {
          for( int i = y_origen + 1; i < y_destino; i++ )//recorre cada cacia verificanco si esta vacia
          {
              if(tablero[x_origen][i] != 0)//pregunta si tablero esta vacio
                 return true;//retorna verdadero si tablero esta vacio
          }
          return false;//retorna verdadero si no tablero no esta vacia
       }else if( x_destino-x_origen < 0 )//pregunta si movimiento es a la izquierda
       {
          for( int i = x_origen - 1; i > x_destino; i-- )//recorre cada cacia verificanco si esta vacia
          {
              if(tablero[i][y_origen] != 0)//pregunta si tablero esta vacio
                 return true;//retorna verdadero si tablero esta vacio
          }
          return false;//retorna verdadero si no tablero no esta vacia
       }else if( y_destino-y_origen < 0 )//pregunta si movimiento es abajo
       {
          for( int i = y_origen - 1; i > y_destino; i-- )//recorre cada cacia verificanco si esta vacia
          {
              if(tablero[x_origen][i] != 0)//pregunta si tablero esta vacio
                 return true;//retorna verdadero si tablero esta vacio
          }
          return false;//retorna verdadero si no tablero no esta vacia
       }
        break;//fin caso TORRE
      //caso CABALLO
      case CABALLO:
          return false;//retorna falso, porque caballo puede saltar piezas
        break;//fin caso CABALLO
      //caso ALFIL
      case ALFIL:
        if(x_destino-x_origen > 0 & y_destino-y_origen > 0)//pregunta si movimiento es derecha/arriba
       {
          for(int i = x_origen + 1; i < x_destino; i++)//recorre cada cacia verificanco si esta vacia
          {
             y_origen++;//crece posicion en "Y"
             if(tablero[i][y_origen] != 0)//pregunta si tablero esta vacio
                  return true;//retorna verdadero si tablero esta vacio
          }
          return false;
       }
       else if(x_destino-x_origen < 0 & y_destino-y_origen > 0)//pregunta si movimiento es izquierda/arriba
       {
          for(int i = x_origen - 1; i < x_destino; i--)//recorre cada cacia verificanco si esta vacia
          {
             y_origen++;//crece posicion en "Y"
             if(tablero[i][y_origen]!= 0)//pregunta si tablero esta vacio
                  return true;//retorna verdadero si tablero esta vacio
          }
          return false;//retorna verdadero si no tablero no esta vacia
       }else if(x_destino-x_origen < 0 & y_destino-y_origen < 0)//pregunta si movimiento es izquierda/abajo
       {
          for(int i = x_origen - 1; i < x_destino; i--)//recorre cada cacia verificanco si esta vacia
          {
             y_origen--;//decrece posicion en "Y"
             if(tablero[i][y_origen]!= 0)//pregunta si tablero esta vacio
                  return true;//retorna verdadero si tablero esta vacio
          }
          return false;//retorna verdadero si no tablero no esta vacia
       }else if(x_destino-x_origen > 0 & y_destino-y_origen < 0)//pregunta si movimiento es derecha/abajo
       {
          for(int i = x_origen + 1; i < x_destino; i++)//recorre cada cacia verificanco si esta vacia
          {
             y_origen--;//decrece posicion en "Y"
             if(tablero[i][y_origen] != 0)//pregunta si tablero esta vacio
                  return true;//retorna verdadero si tablero esta vacio
          }
          return false;//retorna verdadero si no tablero no esta vacia
       }
        break;//fin caso ALFIL
      //caso REINA
      case REINA:
        if( fabs(x_origen-x_destino) == fabs(y_origen-y_destino) )//pregunta si movimiento es de tipo alfil
        {
           if(x_destino-x_origen > 0 & y_destino-y_origen > 0)//pregunta si movimiento es derecha/arriba
           {
             for(int i = x_origen + 1; i < x_destino; i++)//recorre cada cacia verificanco si esta vacia
             {
                y_origen++;//crece posicion en "Y"
                if(tablero[i][y_origen]!= 0)//pregunta si tablero esta vacio
                  return true;//retorna verdadero si tablero esta vacio
             }
             return false;//retorna verdadero si no tablero no esta vacia
          }
          else if(x_destino-x_origen < 0 & y_destino-y_origen > 0)//pregunta si movimiento es izquierda/arriba
          {
             for(int i = x_origen - 1; i < x_destino; i--)//recorre cada cacia verificanco si esta vacia
             {
                y_origen++;//crece posicion en "Y"
                if(tablero[i][y_origen] != 0)//pregunta si tablero esta vacio
                    return true;//retorna verdadero si tablero esta vacio
             }
             return false;//retorna verdadero si no tablero no esta vacia
          }else if(x_destino-x_origen < 0 & y_destino-y_origen < 0)//pregunta si movimiento es izquierda/abajo
          {
             for(int i = x_origen - 1; i < x_destino; i--)//recorre cada cacia verificanco si esta vacia
             {
                y_origen--;//decrece posicion en "Y"
                if(tablero[i][y_origen] != 0)//pregunta si tablero esta vacio
                  return true;//retorna verdadero si tablero esta vacio
             }
             return false;//retorna verdadero si no tablero no esta vacia
          }else if(x_destino-x_origen > 0 & y_destino-y_origen < 0)//pregunta si movimiento es derecha/abajo
          {
             for(int i = x_origen + 1; i < x_destino; i++)//recorre cada cacia verificanco si esta vacia
             {
                y_origen--;//decrece posicion en "Y"
                if(tablero[i][y_origen] != 0)//pregunta si tablero esta vacio
                  return true;//retorna verdadero si tablero esta vacio
             }
             return false;//retorna verdadero si no tablero no esta vacia
           }
        }//fin si movimiento caballo
        if( x_origen != x_destino )//pregunta si origen en "X" es distino del destino
        {
           if( y_destino == y_origen )//pregunta si origen en "Y" es igual del destino
           {
               if( x_destino-x_origen > 0 )//pregunta si "X" esta creciendo
               {
                 for( int i = x_origen + 1; i < x_destino; i++ )//recorre cada cacia verificanco si esta vacia
                 {
                    if(tablero[i][y_origen] != 0)//pregunta si tablero esta vacio
                       return true;//retorna verdadero si tablero esta vacio
                 }
                 return false;//retorna verdadero si no tablero no esta vacia
               }else if( x_destino-x_origen < 0 )//pregunta si "X" esta decreciendo
               {
                  for( int i = x_origen - 1; i > x_destino; i-- )//recorre cada cacia verificanco si esta vacia
                  {
                     if(tablero[i][y_origen] != 0)//pregunta si tablero esta vacio
                         return true;//retorna verdadero si tablero esta vacio
               }
               return false;//retorna verdadero si no tablero no esta vacia
              }
           }
        }
        else if( y_origen != y_destino )//pregunta si origen en "Y" es distino del destino
        {
           if( x_destino == x_origen )//pregunta si origen en "X" es igual del destino
           {
               if( y_destino-y_origen > 0 )//pregunta si "Y" esta creciendo
               {
                  for( int i = y_origen + 1; i < y_destino; i++ )//recorre cada cacia verificanco si esta vacia
                  {
                      if(tablero[x_origen][i] != 0)//pregunta si tablero esta vacio
                          return true;//retorna verdadero si tablero esta vacio
                  }
                  return false;//retorna verdadero si no tablero no esta vacia
               }
               else if( y_destino-y_origen < 0 )//pregunta si "Y" esta decreciendo
               {
                  for( int i = y_origen - 1; i > y_destino; i-- )//recorre cada cacia verificanco si esta vacia
                  {
                     if(tablero[x_origen][i] != 0)//pregunta si tablero esta vacio
                         return true;//retorna verdadero si tablero esta vacio
                   }
                   return false;//retorna verdadero si no tablero no esta vacia
               }
           }
        }
        break;//fin caso REINA
      //caso REY
      case REY:
        return false;//retorna falso porque rey solo se puede mover 1 posicion
        break;//fin caso REY
      //caso PEON
      case PEON: 
        return false;//retorna falso porque peon solo se puede mover 1 posicion
        break;//fin caso PEON
   }//fin bloque caso tipo pieza
}//fin metodo hayPiezaEnMedio

//inicio del destructor de la clase ajedrez
Ajedrez::~Ajedrez()
{
  escribirArchivo();
   //inicio ciclos para recorrer todo el tablero
   for( int i = 0; i < 8; i++ )
   {
      for( int j = 0; j < 8; j++)
          delete tablero[i][j];//borra la pieza en esa posicion
   }//fin para exterior
}//fin del destructor de la clase ajedrez
