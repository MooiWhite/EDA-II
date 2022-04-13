#include <stdio.h>
#include "laberinto.h"


//----------------------------------------------------------------------
//  Driver program
//----------------------------------------------------------------------
int main(void)
{

	int tablero_prueba[FILAS][COLS] =
	{
		{1,1,0,1},
		{0,1,1,1},
		{0,1,0,1},
		{1,1,0,1}
	};

	Tablero* tablero = Tablero_Ctor (FILAS, COLS, tablero_prueba);
    Tablero_SetCelda(tablero, 3,0,INICIO);
    //Tablero_SetCelda(tablero, 3,0,VISITADA);
    Tablero_SetCelda(tablero, 3,3,SALIDA);
    Tablero_Dibujar(tablero);
    LaberintoBT(tablero,3,0,3,3);
    Tablero_Dibujar(tablero);
	//bool res = Laberinto( tablero, 3, 0, 3, 3 );



	//if( res == true ){
		// Imprime el tablero resuelto
	//}
	//else{
		// Imprime "No se encontró una solución"
	//}

	//Tablero_Dtor (tablero);

	return 0;
}

