#include <stdio.h>
#include <string.h>

int palindromo(char * cadena, int inicio, int fin){
	int palin = 0;
	if(inicio <= fin){ 
		//la primera y la ultima son iguales
		if(cadena[inicio] == cadena[fin]){
			if((inicio + 1) >= fin ){
				palin = 1 ;
			}else{
				palin = palindromo(cadena, inicio +1, fin -1);
			}
		}
	}
	return palin;
}
int main(void){

	char cadena[100];
	printf("Introduce una palabra:\n");
	fgets(cadena, sizeof(cadena), stdin);

	//eliminar el salto de la linea al final de la cadena 
	cadena[strcspn(cadena, "\n")] = '\0';

	// obtener la longitud de la cadena 
	int longitud = strlen(cadena);

	//llamada recursiva para verificar si la cadena es un palindromo
	if(palindromo(cadena, 0, longitud-1)== 1){
		printf("es un palindromo\n");
	}else{
		printf("la cadena no es un palindromo \n");
	}
	return 0;

}
