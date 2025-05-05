/*
#include "listas_punteros.c"
#include "tp_2_listas.h"
#include "tp2_lista_array.c"
#include "tipo_elemento.c"

#include <stdio.h>

int main(){
	int vec1[] = {7,3,4,5,9,2};
	int vec2[] = {4,7,2};
	Lista l1 = l_desde_array(vec1, 6);
	Lista l2 = l_desde_array(vec2, 3);
	l_mostrar(l1);
	l_mostrar(l2);
	if(esSublista(l1, l2)){
		printf("l2 es sub de l1");
	}else{
		printf("no");
	}
	return 0;
}
*/

// P6
bool esSublista(Lista l1, Lista l2){
	Iterador ite = iterador(l2);
	TipoElemento te, buscado;
	bool respuesta = false;
	int contador = 0;
	int presentes = 0;
	while(hay_siguiente(ite)){
		te = siguiente(ite);
		buscado = l_buscar(l1, te->clave);
		if(buscado != NULL ){
			presentes++;
		}
		contador++;
	}
	if(contador == presentes){
		respuesta = true;
	}
	return respuesta;
}


