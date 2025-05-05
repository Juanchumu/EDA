/*
#include <stdio.h>
#include "tp_2_listas.h"
#include "tipo_elemento.c"
#include "listas_punteros.c"
#include "tp2_lista_array.c"

//Main de pruebas 
int main(){
	int vec1[4] = {2,5,7,3};
	int vec2[4] = {8,20,28,12};
	int vec3[4] = {2,5,7,3};
	Lista l1 = l_desde_array(vec1, 4);
	Lista l2 = l_desde_array(vec2, 4);
	Lista l3 = l_desde_array(vec3, 4);
	l_mostrar(l1);
	l_mostrar(l2);
	printf("Resultado l1 l2 %d \n", CompararListas(l1, l2));
	printf("Resultado l2 l1 %d \n", CompararListas(l2, l1));
	printf("Resultado l1 l3 %d \n", CompararListas(l1, l3));
	return 0;
}
*/
// P4 Retorna 1 si L1 > L2, 2 si L2 > 1, 0 si son iguales
int CompararListas(Lista l1, Lista L2){
	Iterador ite1, ite2;
	ite1 = iterador(l1);
	ite2 = iterador(L2);
	TipoElemento te1, te2;
	int local, visitante, resultado;
	local = 0;
	visitante = 0;
	while(hay_siguiente(ite1) && hay_siguiente(ite2) ){
		te1 = siguiente(ite1); 
		te2 = siguiente(ite2);
		if(te1->clave > te2->clave){
			local++;
		}else{
			if(te1->clave < te2->clave){
				visitante++;
			}
		}
	}
	//verificamos que tenemos 
	if(local > visitante){
		resultado = 1;
	}else{
		if(visitante > local){
			resultado = 2 ;
		}else{
			resultado = 0; 
		}
	}
	return resultado;
}
