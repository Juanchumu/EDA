#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"

//funcion auxiliar palindromo 
char *recortar_extremos(char *original);

void menu_intro();
void menu();

int main(void){
	menu();
	return 0; 
}
void menu_intro(){
	printf("Seleccione un punto del trabajo practico:\n");
	printf("(0 - 1 - 2 - 3 - 4 - 5 - 6) \n ");
	printf("ingrese -1 para terminar la ejecucion \n");
}

void menu(){
	menu_intro();
	int opcion;
	scanf("%d", &opcion);
	while(opcion >10 || opcion < -1 ){
		printf("Ingreso erroneo\n");
		menu_intro();
		scanf("%d", &opcion);
	}
	if(opcion != -1){
		switch (opcion) {
			case 1:
				printf("Punto Palindromos\n");
				printf("Ingrese una palabra a comprobar  Palindromos\n");
				char palabra[100];
				scanf("%s", palabra);
				if(palindromo(palabra)){
					printf("%s es un palindromo\n", palabra);
				}else{	
					printf("%s no es un palindromo\n", palabra);
				}
				menu();
				break;
			case 2:
				printf("Ejercicio 2\n");
				printf("Se necesita ingresar n y m\n");
				int n,m; 
				printf("Ingrese n\n");
				scanf("%d",&n);
				printf("Ingrese m\n");
				scanf("%d",&m);
				printf("El resultado es: %d\n", producto(m,n));
				printf("fin Ej2\n");
				menu();
				break;
			case 3:
				printf("Ejercicio 3\n");
				printf("Se necesita ingresar el valor de K\n");
				int k; 
				scanf("%d",&k);
				printf("El resultado es: %d\n", terminoSeridFibonacci(k));
				printf("Fin Ejercicio 3\n");
				menu();
				
			default:
			// code block
			}
	}
}



//Funcion Auxiliar Palindromo
char *recortar_extremos(char *original) {
    int len = strlen(original);
    if (len <= 2) {
        // Si tiene 2 o menos caracteres, devolvemos cadena vacía
        char *vacio = malloc(1);
        vacio[0] = '\0';
        return vacio;
    }
    // Reservamos espacio para los caracteres del medio + '\0'
    char *recorte = malloc(len - 1); // len - 2 letras + 1 '\0'
    if (!recorte) return NULL;
    strncpy(recorte, original + 1, len - 2); // Copiamos del segundo al penúltimo
    recorte[len - 2] = '\0'; // Agregamos terminador
    return recorte;
}
//Punto 1:
bool palindromo (char * cadena){
	bool estado;
	int l = strlen(cadena); // obtiene el largo hasta el \0
	if(cadena[0] != '\0' && l != 0 ){
		if(cadena[0] !=  cadena[l-1]){
			//no es palindromo 
			//printf("%s no es palin", cadena);
			return false;
		}else{
			//printf("control");
			//recortar cadena solo si tiene mas de 3 elementos "NOA" "ANA"
			//si tiene 2 elementos y ambos son iguales, es palin "EE\0" 
			//si tiene 1 elemento es palin
			if(l >= 3){
				char * recortado = recortar_extremos(cadena);
				if(palindromo(recortado)){
					estado = true;
				}else{
					estado = false; 
				}
			}else{
				if(l == 2){
					if(cadena[0] == cadena[l-1]){
						estado = true;
					}else{
						estado = false;
					}
				}else{
					estado = true;
					//solo queda una opcion y es que sea 1
				}
			}
		}
	}else{
		estado = false;
	}
	return estado; 
}
// Ejercicio 2
int producto(int m, int n)
{
    if ((n == 0 || m == 0))
    {
        return 0;
    }
    if (n > 0)
    {
        n -= 1;
        return m + producto(m, n);
    }
    else
    {
        n += 1;
        return -m + producto(m, n);
    }
}
// Ejercicio 3
int terminoSeridFibonacci(int k) {
	// Caso base
    if (k == 1 || k == 2) {
		return 1;
    }
    // Recursividad 
    return terminoSeridFibonacci(k - 1) + terminoSeridFibonacci(k - 2);
}


