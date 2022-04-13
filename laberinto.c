#include<stdio.h>
#include"laberinto.h"

Tablero* Tablero_Ctor (int filas, int cols, int tablero_copia[][COLS])
{
	Tablero* nuevo = (Tablero*) malloc (sizeof (Tablero));
	assert (nuevo);

	nuevo->filas = filas;
	nuevo->cols = cols;

	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < cols; ++j) {
			nuevo->tablero[i][j] = tablero_copia[i][j];
		}
	}

	return nuevo;
}

void Tablero_Dtor (Tablero* this)
{
	assert (this);
	free (this);
	this = NULL;
}

void Tablero_Dibujar (Tablero* this)
{
	printf ("\n");
	for (int i = 0; i < this->filas; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			int celda = this->tablero[i][j];
			switch (celda) {
				case PARED: printf ("#"); break;
				case LIBRE: printf ("."); break;
				case INICIO: printf ("I"); break;
				case SALIDA: printf ("S"); break;
				case VISITADA: printf ("V"); break;
				case CANCELADA: printf ("X"); break;
				default: break;
			}
		}
		printf ("\n");
	}
	printf ("\n");

}

void Tablero_SetCelda (Tablero* this, int x, int y, int tipo)
{
	this->tablero[x][y] = tipo;
}

int Tablero_GetCelda (Tablero* this, int x, int y)
{
	return this->tablero[x][y];
}

//----------------------------------------------------------------------
//  Fin -- Tablero ADT
//----------------------------------------------------------------------

bool aceptable(Tablero* this, int x, int y){
    //printf("%d", this->filas);
    if(x>this->filas-1 || x<0 ){

        return false;
    }
    if(y>this->cols-1 || y<0 ){
            return false;
    }
    if(this->tablero [x][y]==PARED || this->tablero[x][y]==CANCELADA){
        return false;
    }

    return true;
}
bool EsSolucion(Tablero* this, int x, int y, int xs, int ys ){
    if (this->tablero[x][y] == this->tablero[xs][ys]){
        return true;
    }
    else{
        return false;
    }

}

// Algoritmo recursivo con backtracking
bool LaberintoBT( Tablero* this, int xi, int yi, int xs, int ys)
{
bool exito=false;
    do{

            if(aceptable(this, xi, yi)){

                printf("\nes aceptable x,y: %d,%d\n", xi,yi);
                Tablero_SetCelda(this, xi, yi, VISITADA);
             }
             else{
                /*if (yi > ys){
                    printf("regresa a ");
                }*/
                printf("bajate");
                xi++;
                printf("mueve a la izquierda");
                yi--;
                if (aceptable(this, xi, yi)){
                        if (this->tablero[xi][yi]==VISITADA){
                                printf("mueve a la derecha");
                                yi++;
                                printf("mueve hacia abajo");
                                xi++;
                                if (aceptable(this, xi ,yi)){
                                    LaberintoBT(this, xi, yi, xs, ys);
                                }
                                else{
                                    printf("sube de nuevo");
                                    xi--;
                                    printf("ve a la derecha");
                                    yi++;
                                }
                            }
                    printf("\nes aceptable x,y: %d,%d\n", xi,yi);
                    Tablero_SetCelda(this, xi, yi, VISITADA);
                    printf("baja");
                    xi++;
                }
                else{
                    printf("regresa a la derecha");
                    yi++;
                    printf("Mueve hacia abajo");
                    xi++;
                    if (aceptable(this, xi, yi)){
                            if (this->tablero[xi][yi]==VISITADA){
                                printf("Mueve hacia arriba");
                                xi--;
                                printf("Ve a la derecha");
                                yi++;
                                if (!aceptable(this, xi, yi)){
                                    printf("Ir a la izquierda");
                                    //yi--;
                                    Tablero_SetCelda(this, xi, yi-1, CANCELADA);
                                    printf("cancelada %d", yi);
                                    printf("regresa a la derecha");
                                    yi++;
                                }
                            }
                        printf("\nes aceptable x,y: %d,%d\n", xi,yi);
                        Tablero_SetCelda(this, xi, yi, VISITADA);
                    }
                    else{
                        printf("regresa hacia arriba");
                        xi--;
                        Tablero_SetCelda(this, xi, yi, CANCELADA);
                        printf("muevete para la derecha");
                        yi++;

                        LaberintoBT(this, xi, yi ,xs, ys);
                        if (EsSolucion(this, xi, yi, xs, ys)== false){
                            printf("No es solucion: %d, %d", xi, yi);
                        }
                        else{
                            exito = true;
                        }
                    }
                }

             }
    xi=xi-1;
    if (this->tablero[xi][yi]==VISITADA){
        printf("baja");
        xi++;
        printf("mueve a la izquierda");
        xi--;
        if(!aceptable(this, xi, yi)){
            printf("muevete a la derecha");
            yi++;
            printf("bajate");
            xi++;

        }
    }
    printf("%d", xi);
    }while(xi!=xs && yi!=ys);
}


// Función de activación
bool Laberinto( Tablero* this,int xi,
               int yi, int xs, int ys)
{
	// órden de los movimientos:
	// arriba, izquierda, abajo, derecha
    //6e}bool res = LaberintoBT()
    bool res = LaberintoBT(this, xi, yi, xs, ys);
    if (res == true){
        return true;
    }
    else{
	return false;
    }
}

