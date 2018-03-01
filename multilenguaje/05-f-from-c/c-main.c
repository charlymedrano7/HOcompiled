
#include <stdio.h>

#define NUM 200

extern void sum_abs_(int *inp, int *num, int *asum); //acá defino una función externa con 3 punteros que es la subrutina  
						     //de fortran que voy a usar después
int main(int argc, char **argv)
{
    int data[NUM], num, i;
    int res;

    num = NUM;
    for (i=0; i < num; i++) {
        data[i] = i - 100 + 1;  /* NOTE: difference in array numbering */  
    }
    sum_abs_(data, &num, &res);   //ACÁ OBTENGO RES A PARTIR DE LA SUB DE FORTRAN, como fortran solo lee punteros tengo que
    printf("sum=%d\n", res);	  //pasarlos correctamente: data es un array de enteros (definido más arriba), y los arrays en
    return 0;                     //C son definidos por la posición de memoria en al que está el primer elemento del array,
}				  //por lo tanto fortran no va a tener problema con esa variable, en el caso de num y res,
				  //fueron definidas como enteros dentro del main, y ahora "num" y "res" representan valores
				  //para que fortran las entienda tengo que pasarles la ubicación de memoria de "num" y "res"
				  //agregando un "&" adelante de cada variable.
