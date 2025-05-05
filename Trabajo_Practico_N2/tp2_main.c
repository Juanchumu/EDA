#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tp_2_listas.h"
//#include "listas_punteros.c"
#include "listas_cursores.c"
//#include "listas_arreglos.c"
#include "tipo_elemento.c"


#include "tp2_2.c"
#include "tp2_3.c"
#include "tp2_4.c"
#include "tp2_5.c"
#include "tp2_6.c"


//prototipos del menu
void menu_intro();
void menu();

//prototipo mostrar lista valores 
void mostrar_valores(Lista list, double x, double sumando);

//Prototipo para generar una lista a partir de un array
Lista l_desde_array(int arr[], int largo );
//Prototipo para generar una lista aleatoria
Lista generar_lista_aleatoria();


int main(void){
	menu();
	return 0; 
}
void menu_intro(){
	printf("Seleccione un punto del trabajo practico:\n");
	printf("(2 - 3 - 4 - 5 - 6 ) \n ");
	printf("ingrese -1 para terminar la ejecucion \n");
}

void menu(){
	menu_intro();
	int opcion;
	scanf("%d", &opcion);
	while(opcion >6 || opcion < -1 ){
		printf("Ingreso erroneo\n");
		menu_intro();
		scanf("%d", &opcion);
	}
	if(opcion != -1){
		switch (opcion) {
			case 2:
				printf("Punto 2\n");
				Lista listita = generar_lista_aleatoria();
				printf("Primer lista generada aleatoriamente: \n");
				l_mostrar(listita);
				Lista listota = generar_lista_aleatoria();
				printf("Segunda lista generada aleatoriamente: \n");
				l_mostrar(listota);
				Lista no_repetidos = verElementosQueNoSeRepiten(listita, listota);
				printf("Lista con valores no repetidos: \n");
				l_mostrar(no_repetidos);
				printf("Lista con valores repetidos: \n");
				Lista repetidos = verElementosRepetidos(listita, listota);
				l_mostrar(repetidos);
				float p1, p2;
				p1 = promedio(listita);
				p2 = promedio(listota);
				printf("Promedio de la Primer lista: %f \n",p1 );
				printf("Promedio de la Segunda lista: %f \n",p2 );
				ResultadoValorMinimo hola = valorMinimo(listita, listota);
				printf("Valor minimo de la primer lista: %d, posición: %d\n", hola.valor, hola.pos);
				printf("Valor minimo de la segunda lista: %d, posición: %d\n", hola.valor_2, hola.pos_2 );
				printf("Fin Ejercicio 2\n");
				menu();
				break;
			case 3:
				printf("Ejercicio 3\n");
				printf("Este ejercicio incluye listas generadas a partir de un array\n");
				printf("que se pueden modificar desde el codigo\n");
				printf("Siendo: L1 =[2,5,7,3] L2 = [8,20,28,12]\n");
				int vec1[4] = {2,5,7,3};
				int vec2[4] = {8,20,28,12};
				Lista l1 = l_desde_array(vec1, 4);
				Lista l2 = l_desde_array(vec2, 4);
				printf("Primer lista:\n");
				l_mostrar(l1);
				printf("Segunda lista:\n");
				l_mostrar(l2);
				ResultadosMul a = multiplo(l1, l2);
				if(a.esMultiplo){
					printf("L2 es multiplo de L1 ");
					if(a.escalar){
						printf("por un escalar %d \n", a.numEscalar);
					}else{
						printf("\n");
					}
				}
				printf("Fin Ejercicio 3\n");
				menu();
				break;
			case 4:
				printf("Ejercicio 4\n");
				printf("Este ejercicio incluye listas generadas a partir de un array\n");
				printf("que se pueden modificar desde el codigo\n");
				printf("Siendo: L1 =[2,5,7,3] L2 = [8,20,28,12] L3 =[2,5,7,3] \n");
				int vec1_4[4] = {2,5,7,3};
				int vec2_4[4] = {8,20,28,12};
				int vec3_4[4] = {2,5,7,3};
				Lista l1_4 = l_desde_array(vec1_4, 4);
				Lista l2_4 = l_desde_array(vec2_4, 4);
				Lista l3_4 = l_desde_array(vec3_4, 4);
				printf("Primer lista:\n");
				l_mostrar(l1_4);
				printf("Segunda lista:\n");
				l_mostrar(l2_4);
				printf("Resultado l1 vs l2: %d \n", CompararListas(l1_4, l2_4));
				printf("Resultado l2 vs l1: %d \n", CompararListas(l2_4, l1_4));
				printf("Resultado l1 vs l3: %d \n", CompararListas(l1_4, l3_4));
				printf("Fin Ejercicio 4\n");
				menu();
				break;
			case 5:
				printf("Ejercicio 5\n");
				printf("Este ejercicio incluye listas generadas a partir de una\n");
				printf("funcion interna del tp2_5.c que se pueden modificar desde el codigo\n");
				printf("Siendo: F(x) = 2 +5x +7x^2 + 3x^3 \n");
				Lista test = l_crear();
				hacerPolinomio(test);
				float segundo_test = evaluarPoliomio(test, 5);
				printf("Prueba de funcionalidad de la primer parte\n");
				printf("F(5): %f\n", segundo_test);
				printf("Prueba para x: 0.5, y: 5.5, sumando: 0.5 \n");
				Lista test2 = calcularRango(test, 0.5, 5.5, 0.5);
				mostrar_valores(test2, 0.5, 0.5);
				printf("Fin Ejercicio 5\n");
				menu();
				break;
			case 6:
				printf("Ejercicio 6\n");
				printf("Este ejercicio incluye listas generadas a partir de un array\n");
				printf("que se pueden modificar desde el codigo\n");
				printf("Siendo: L1 =[7,3,4,5,9,2] L2 = [4,7,2] \n");
				int vec1_6[] = {7,3,4,5,9,2};
				int vec2_6[] = {4,7,2};
				Lista l1_6 = l_desde_array(vec1_6, 6);
				Lista l2_6 = l_desde_array(vec2_6, 3);
				l_mostrar(l1_6);
				l_mostrar(l2_6);
				if(esSublista(l1_6, l2_6)){
					printf("La Lista 2 es sublista de la Lista 1\n");
				}else{
					printf("La lista 2 no es sublista de la Lista 1\n");
				}
				printf("Fin Ejercicio 6\n");
				menu();
				break;
			default:
				// code block
				printf("Hubo un error\n");
				break;
		}
	}
}



void mostrar_valores(Lista list, double x, double sumando){
	Iterador ite = iterador(list);
	TipoElemento te;
	while(hay_siguiente(ite)){
		te = siguiente(ite);
		printf("F(%f) = %f \n", x, *(float*)te->valor);
		x = x + sumando;
	}
}

Lista l_desde_array(int arr[], int largo ){
	Lista arrays = l_crear();
	for(int i = 0; i < largo; i++){
		TipoElemento te = te_crear(arr[i]);
		l_agregar(arrays, te);
	}
	return arrays;
}

Lista generar_lista_aleatoria(){
	Lista lista_aleatoria = l_crear();
	for(int i = 0; i < 100; i++){
		TipoElemento te = te_crear( (rand()%100) );
		l_agregar(lista_aleatoria, te);
	}
	return lista_aleatoria;
}



