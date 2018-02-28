#include <stdlib.h>
#include "c-sum.h"

void sum_abs_(int *in, int *num, int *sum) { //Cambio int por void para sacarme de encima el return (fortran no permite que
					    //le devuelvan nada, solo puede cambiar el valor de las variables que le pasan
		     			    //también le tengo que decir a C que las variables que vienen de fortran son
					    //punteros, porque fortran trabaja todo con punteros. Para eso son los * de las
					    //variables. También necesito "enmascarar" la función de C con el sufijo "_"
					    //para que fortran la vea como una subrutina.
   int i;				    //ya no necesito declarar sum

   for (i=0,*sum=0; i < *num; ++i) {        //vuelvo a usar el * para obtener el valor asignado al puntero, porque acá
       *sum += abs(in[i]);                  //necesito operar con el valor correspondiente al puntero.
   }
//   return &asum;                          //El return lo puedo (y debo, por culpa de fortran) porque puse el void arriba
}
 
