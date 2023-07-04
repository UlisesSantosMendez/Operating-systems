#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void crearArbol ( );
void primerHijo ( int nNiveles );
void segundoHijo ( int nNiveles );

int main ( ) { crearArbol ( ); } /* fin del main. */

void crearArbol ( ) { /* Construye los dos hijos principales. */

  int idProceso; /* Esta variable almacena lo que retorna fork. */
  int estado = 0; /* estado del proceso. */
  int nNiveles; /* Almacena el numero de niveles del arbol. */
  int escojerNiveles = 0; /* Esta variable nos ayuda a que el usuario solo seleccione un numero de nivel. */
  int contador = 0;

  if ( escojerNiveles == 0 ) {
    printf ( "\n\n\t\t Arbol de procesos." );
    printf ( "\n\n\t   Digite la cantidad de niveles para el arbol de procesos: " );
    scanf ( "%d", &nNiveles );
    escojerNiveles++;
  } /* Final del if */

  for ( contador = 0 ; contador < 2 ; contador++ ) { /* El proceso principal solo necesita dos hijos */
    idProceso = fork ( ); /* Crea hijos del proceso principal solo creara dos */
    switch ( idProceso ) {
      case 0:
        if ( contador == 0 ) { /* Primer hijo del proceso principal ejecutandose. */
          printf ( "\n\tPrimer hijo del proceso principal: %d.", getpid ( ) );
          printf ( "\tEl padre es: %d.\n", getppid ( ) );
          primerHijo ( nNiveles );
        } /* Fin del if.*/
        if ( contador == 1 ) { /* Segundo hijo del proceso principal ejecutandose. */
          printf ( "\n\n\tSegundo hijo del proceso principal: %d.", getpid ( ) );
          printf ( "\tEl padre es: %d.\n", getppid ( ) );
          segundoHijo ( nNiveles );
        } /* Final del if. */
        exit ( 0 );
      case -1:
        printf ( "\n\tError creando el nuevo proceso." );
        exit ( 0 );
      default:
        if ( contador == 0 ) { /* Para el id del Proceso padre principal. */
          printf ( "\n\tProceso padre principal: %d.\n", getpid ( ) ); /* Usamos la funcion getpid() para para obtener el id */
        } /* Fin del if. */
        wait ( &estado ); /* con la funcion wait esperamos que el proceso hijo termine. */
    } /* Final del switch. */
  } /* final del for. */

  printf ( "\n\n" );

} /* final de la funcion crearArbol. */

void primerHijo ( int nNiveles ) { /* Va contruyendo los nimeles del primer hijo. */

  int contadorProcesos = 0;
  int estado = 0;
  int idProceso; /* Almacena el valor que devuelve fork () */

  for ( contadorProcesos = 0 ; contadorProcesos < 2 ; contadorProcesos++ ) { /* Controla el numero de hijos por nivel */
    idProceso = fork ( );
    switch ( idProceso ) {
      case 0:
        printf ( "\n\tProceso hijo id: %d.", getpid ( ) );
        printf ( "\tPadre id: %d.", getppid ( ) );
        if ( nNiveles > 1 ) {
          primerHijo ( nNiveles - 1 ); /* Función recursiva que controla los niveles del árbol. */
        } /* final del if */
        exit ( 0 );
      case -1:
        printf ( "\n\n\tError creando el nuevo proceso." );
        exit ( 0 );
      default:
        wait ( &estado );
    } /* final del switch. */
  } /* final del for. */

} /* Fin de la funcion primerHijo. */

void segundoHijo ( int nNiveles ) { /*  Va contruyendo los niveles del segundo hijo. */

  int contadorProcesos = 0;
  int estado = 0;
  int idProceso; /* Almacena el valor que devuelve fork () */

  for ( contadorProcesos = 0 ; contadorProcesos < 3 ; contadorProcesos++ ) { /* Controla el numero de hijos por nivel */
    idProceso = fork ( );
    switch ( idProceso ) {
      case 0:
        printf ( "\n\tProceso hijo id: %d.", getpid ( ) );
        printf ( "\tPadre id: %d.", getppid ( ) );
        if ( nNiveles > 1 ) {
          segundoHijo ( nNiveles - 1 ); /* Función recursiva que controla los niveles del árbol. */
        } /* Final del if. */
        exit ( 0 );
      case -1:
        printf ( "\n\n\tError creando el nuevo proceso." );
        exit ( 0 );
      default:
        wait ( &estado );
        break;
    } /* Final del switch. */
  } /* Final del for. */

} /* Fin de la funcion segundoHijo. */
