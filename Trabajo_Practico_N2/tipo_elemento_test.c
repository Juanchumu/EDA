#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tipo_elemento.c"
bool comparaTE (TipoElemento te1, TipoElemento te2);

void main(){
	TipoElemento TE;
	TipoElemento TE2;
	TE = te_crear(1000);
	printf("Clave del Tipo Elemento Creado < %d > \n", TE->clave);
	TE->clave = TE->clave + 1001;
	printf("Clave con 1000 sumados < %d > \n", TE->clave);
	TE2 = te_crear(2000);
	printf("Clave del Tipo2 Elemento Creado < %d > \n", TE2->clave);
	if (comparaTE(TE, TE2)) {
		printf("Las claves de los tipos elementos son iguales \n");
	}else{
		printf("Las claves de los tipos elementos son DISTINTAS \n");
	}
}

bool comparaTE (TipoElemento te1, TipoElemento te2){
	return (te1->clave == te2->clave);
}

