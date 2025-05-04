#include "tp_2_listas.h"
#include "listas_punteros.c"
#include "tipo_elemento.c"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
Lista generar_lista_aleatoria();
float promediosListaAux(Iterador i, int suma, int cantidad);
int minimo(Lista l1);
int minimoAux(Iterador i, int min_contender);
int buscar_pos(Lista l1, int clave );

int main(){
	Lista listita = generar_lista_aleatoria();
	l_mostrar(listita);
	Lista listota = generar_lista_aleatoria();
	l_mostrar(listota);
	Lista no_repetidos = verElementosQueNoSeRepiten(listita, listota);
	l_mostrar(no_repetidos);
	Lista repetidos = verElementosRepetidos(listita, listota);
	l_mostrar(repetidos);
	float p1, p2;
	p1 = promedio(listita);
	p2 = promedio(listota);
	printf("Promedio de la l1 %f, promedio l2: %f \n",p1,p2 );
	ResultadoValorMinimo hola = valorMinimo(listita, listota);
	printf("min l1 %d, pos: %d, minl2 %d, pos: %d \n", hola.valor, hola.pos, hola.valor_2, hola.pos_2 );

}

Lista generar_lista_aleatoria(){
	Lista lista_aleatoria = l_crear();
	for(int i = 0; i < 100; i++){
		TipoElemento te = te_crear( (rand()%100) );
		l_agregar(lista_aleatoria, te);
	}
	return lista_aleatoria;
}
/*
// P2
typedef struct
{
    float resultado1;
    float resultado2;
} Resultados;

typedef struct resultadoStruct
{
    int pos;
    int valor;
    int pos_2;
    int valor_2;
} ResultadoValorMinimo;
*/



//Punto 2a y 2b 
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
	TipoElemento x_l1, x_l2, x;
	Lista lnrp = l_crear();
	Iterador itel1 = iterador(l1);
	//Primero recorro la l1
	//busco el elemento en la l2 
	while(hay_siguiente(itel1)){
		x_l1 = siguiente(itel1);
		x = l_buscar(l2, x_l1->clave);
		if(x == NULL){
			//Si ya esta en la lista, no se agrega
			x_l2 = l_buscar(lnrp, x_l1->clave);
			if(x_l2 == NULL){
				l_agregar(lnrp, x_l1);
			}
		}
	}
	return lnrp;
}


// Punto 2 C
Lista verElementosRepetidos(Lista l1, Lista l2){
	TipoElemento x_l1, x_l2, x;
	Lista lrp = l_crear();
	Iterador itel1 = iterador(l1);
	//Primero recorro la l1
	//busco el elemento en la l2 
	while(hay_siguiente(itel1)){
		x_l1 = siguiente(itel1);
		x = l_buscar(l2, x_l1->clave);
		if(x != NULL){
			//buscar que no este en la lista, para agregarlo
			x_l2 = l_buscar(lrp, x_l1->clave);
			if(x_l2 == NULL){ //sinoesta, lo agregamos
				l_agregar(lrp, x_l1);
			}
		}
	}
	//Ahora recorro la l2
	Iterador itel2 = iterador(l2);
	//busco el elemento en la l1 
	while(hay_siguiente(itel2)){
		x_l1 = siguiente(itel2);
		x = l_buscar(l1, x_l1->clave);
		if(x != NULL){
			//buscar que no este en la lista, para agregarlo
			x_l2 = l_buscar(lrp, x_l1->clave);
			if(x_l2 == NULL){ //sinoesta, lo agregamos
				l_agregar(lrp, x_l1);
			}
		}
	}
	return lrp;
}

// Punto 2 D
float promedio(Lista l1){
	Iterador ite = iterador(l1);
	float promedio_l1 = promediosListaAux(ite, 0 ,0);
	return promedio_l1;
}

float promediosListaAux(Iterador i, int suma, int cantidad){
	TipoElemento x = siguiente(i);
	if(hay_siguiente(i) == false ){//Si no hay siguiente 
		if(cantidad == 0){
			return -1;
		}else{
			float resultado = (float) suma / cantidad;
			return resultado;
		}
	}else{
		return promediosListaAux(i, (suma + x->clave), (cantidad +1) );
	}
}
// Punto 2 E
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
	ResultadoValorMinimo resultados;
	resultados.valor = minimo(l1);
	resultados.valor_2 = minimo(l2);
	resultados.pos = buscar_pos(l1, resultados.valor);
	resultados.pos_2 = buscar_pos(l2, resultados.valor_2);
	return resultados;
/*
	typedef struct resultadoStruct
{
    int pos;
    int valor;
    int pos_2;
    int valor_2;
} ResultadoValorMinimo;
*/

}
int minimo(Lista l1){
	Iterador ite = iterador(l1);
	TipoElemento x = siguiente(ite);
	int minimo_l1 = minimoAux(ite, x->clave);
	return minimo_l1;
}

int minimoAux(Iterador i, int min_contender){
	TipoElemento x = siguiente(i);
	if(hay_siguiente(i) == false ){//Si no hay siguiente
			if(x->clave < min_contender){
				return x->clave;
			}else{
				return min_contender;
			}
	}else{
		if(x->clave < min_contender){
			return minimoAux(i, x->clave);
		}else{
			return minimoAux(i, min_contender);
		}
	}
}

int buscar_pos(Lista l1, int clave ){
	Iterador ite = iterador(l1);
	TipoElemento contender;
	int pos = 0;
	while(hay_siguiente(ite)){
		contender = siguiente(ite);
		if(clave == contender->clave ){
			return pos;
		}else{
			pos++;
		}
	}
}




