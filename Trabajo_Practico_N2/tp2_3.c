#include <stdio.h>
#include "tipo_elemento.c"
#include "listas_punteros.c"
#include "tp_2_listas.h"


Lista l_desde_array(int arr[4], int largo );

int main(void){
	int vec1[4] = {2,5,7,3};
	int vec2[4] = {8,20,28,12};
	int vec3[4] = {8,20,28,12};
	Lista l1 = l_desde_array(vec1, 4);
	Lista l2 = l_desde_array(vec2, 4);
	l_mostrar(l1);
	l_mostrar(l2);
	ResultadosMul a = multiplo(l1, l2);
	if(a.esMultiplo){
		printf("l2 es multiplo de l1 ");
		if(a.escalar){
			printf("por un escalar %d \n", a.numEscalar);
		}
	}
	return 0;
}

Lista l_desde_array(int arr[], int largo ){
	Lista arrays = l_crear();
	for(int i = 0; i < largo; i++){
		TipoElemento te = te_crear(arr[i]);
		l_agregar(arrays, te);
	}
	return arrays;
}

ResultadosMul multiplo(Lista l1, Lista l2){
	ResultadosMul r;
	Iterador ite1, ite2;
	ite1 = iterador(l1);
	ite2 = iterador(l2);
	TipoElemento te1, te2;
	int multiplo, escalar, resto, operacion, guardar, largo;
	resto = 0;
	multiplo = 0;
	escalar = 0;
	guardar = 0;
	largo = 0;
	while(hay_siguiente(ite1)&& hay_siguiente(ite2) ){
		largo++;
		te1 = siguiente(ite1);
		te2 = siguiente(ite2);
		operacion = te2->clave % te1->clave; 
		resto = te2->clave / te1->clave;
		if (operacion == 0){
			multiplo++;
			if(guardar == 0){// primer guardado
				guardar = resto;
			}
			if(guardar == resto){
				escalar++;
			}
		}
	}
	//chequeo de que tenemos
	if(multiplo == largo){
		//printf("l2 es multiplo de l1");
		r.esMultiplo = true; 
	}else{
		r.esMultiplo = false;
	}
	if(escalar == largo){
		//printf("l2 es multiplo de l1, por un escalar %d", guardar);
		r.escalar = true;
		r.numEscalar = guardar;
	}else{
		r.escalar = false;
	}
	return r;
}



