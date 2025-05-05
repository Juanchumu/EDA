#include <stdio.h>
#include "tipo_elemento.c"
#include "listas_punteros.c"
#include "tp2_lista_array.c"
#include "tp_2_listas.h"



float potencia(float x, int cantidad);

int main(){
	Lista test = l_crear();
	hacerPolinomio(test);
	float segundo_test = evaluarPoliomio(test, 5);
	printf("para l1, f(5): %f\n", segundo_test);
	Lista test2 = calcularRango(test, 0.5, 5.5, 0.5);
	
}

// P5
/*Función que recibe una lista vacía y la carga con los términos del polinomio; los 
mismos tendrán el exponente o grado del término (entero mayor o igual a 0) en "clave" y el coeficiente real  apuntado por "valor". */
void hacerPolinomio(Lista list){
	int largo = 4;
	int exponentes[] = {0,1,2,3};
	float coeficientes[] = {2,5,7,3};
	for(int i = 0; i < largo; i++){
		TipoElemento te = te_crear(exponentes[i]);
		float * puntero = malloc(sizeof(float));
		*puntero = coeficientes[i];
		te->valor = puntero;
		//printf("%f\n", *((float*)te->valor) );
		l_agregar(list, te);
	}
}

/*Función que recibe el polinomio y un número real y devuelve el valor del polinomio 
evaluado en ese valor de x.*/
float evaluarPoliomio(Lista list, float x){
	Iterador ite = iterador(list);
	TipoElemento te;
	float suma = 0;
	while(hay_siguiente(ite)){
		te = siguiente(ite);
		suma = suma + ( *((float*)te->valor ) * potencia(x, te->clave) );
		//printf("suma %f\n", suma);
	}
	//Devuelve lo que tiene 
	return suma;
}
float potencia(float x, int cantidad){
	float suma = 1;
	for(int i = 0; i < cantidad; i++){
		suma = (suma * x);
	}
	//printf("retornando %f\n", suma);
	return suma;
}

/*Función que calcula el polinomio en un rango de valores de x.
Recibe: el polinomio, los valores mínimo y máximo del intervalo y la diferencia entre cada valor 
tomado del intervalo.
Devuelve: una lista de valores reales apuntados por "valor", y que representan los 
valores del polinomio en los sucesivos puntos del intervalo.*/
Lista calcularRango(Lista list, double x, double y, double sumando){
	Lista no_se_muestra = l_crear();
	Iterador ite = iterador(list);
	TipoElemento te;
	int contador = 0; 
	for(x; x<y; x = x + sumando){
		te = te_crear(contador);

		float * puntero = malloc(sizeof(float));
		*puntero = evaluarPoliomio(list, x);
		te->valor = puntero;
		printf("%f\n", *(float*)te->valor );
		l_agregar(no_se_muestra, te);
	}
	return no_se_muestra;
}


