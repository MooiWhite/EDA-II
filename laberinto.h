#ifndef LABERINTO_H_INCLUDED
#define LABERINTO_H_INCLUDED



#endif // LABERINTO_H_INCLUDED
/*Copyright (C)
 * 2016 - eda1 dot fiunam at yahoo.com.mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

// Modificado el 2018-05-31


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <stdbool.h>
// para usar bool, true y false

#define FILAS 4
#define COLS 4



//----------------------------------------------------------------------
//  Tablero ADT
//----------------------------------------------------------------------

enum TIPO_CELDAS
{
	PARED = 0,
	LIBRE,
	INICIO,
	SALIDA,
	VISITADA,
	CANCELADA
};



struct Tablero_T
{
	int tablero[FILAS][COLS];
	int filas;
	int cols;
};

typedef struct Tablero_T Tablero;



Tablero* Tablero_Ctor (int filas, int cols, int tablero_copia[][COLS]);
void Tablero_Dtor (Tablero* this);
void Tablero_Dibujar (Tablero* this);
void Tablero_SetCelda (Tablero* this, int x, int y, int tipo);
int Tablero_GetCelda (Tablero* this, int x, int y);
bool aceptable(Tablero* this, int x, int y);
bool EsSolucion(Tablero* this, int x, int y, int xs, int ys);
bool LaberintoBT( Tablero* this, int xi, int yi, int xs, int ys);
bool Laberinto( Tablero* this,int xi,
               int yi, int xs, int ys);
