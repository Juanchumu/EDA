#include <stdio.h>
#include "tipo_elemento.c"
#include "listas_punteros.c"
#include "tp2_lista_array.c"
#include "tp_2_listas.h"



float potencia(float x, int cantidad);

int main(){
	int vec1[4] = {2,5,7,3};
	int vec2[4] = {8,20,28,12};
	int vec3[4] = {2,5,7,3};
	Lista l1 = l_desde_array(vec1, 4);
	Lista l2 = l_desde_array(vec2, 4);
	Lista l3 = l_desde_array(vec3, 4);
	l_mostrar(l1);
	l_mostrar(l2);
	float primer_test = evaluarPoliomio(l1, 5);
	printf("para l1, f(5): %f\n", primer_test);
	Lista test = l_crear();
	hacerPolinomio(test);
	float segundo_test = evaluarPoliomio(l1, 5);
	
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
	TipoElemento te = siguiente(ite);
	float suma = te->clave; //sumo el primer termino del polinomio
	int grado = 1;
	//continuo con los siguientes terminos del polinomio
	//printf("suma %f\n", suma);
	while(hay_siguiente(ite)){
		te = siguiente(ite);
		suma = suma + ( te->clave * potencia(x, grado) );
		grado++;
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

}


