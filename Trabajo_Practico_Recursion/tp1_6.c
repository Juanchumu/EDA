#include <stdio.h>
#include <string.h>

void ondaDigital(char * cadena);


int main(void){
	//ondaDigital (“HHHHLLLLHHHHHLLHH”) => ****|____|*****|__|**
	ondaDigital("HHHHLLLLHHHHHLLHH");
	return 0;
}

void ondaDigital(char * cadena){
	if(cadena[0] != '\0'){
		//printf("f %c", cadena[0]);
		if(cadena[0] == 'H' || cadena[0]=='L'){
			if(cadena[0]=='H'){
				//si el siguiente es el final, si el siguiente es cambio 
				if( (cadena[1] == 'L')){
					printf("*|");
				}else{
					printf("*");
				}
			}else{
				if( (cadena[1] == 'H')){
					printf("_|");
				}else{
					printf("_");
				}
			}
				}else{
			printf("Error en la cadena");
		}
		//llamar denuevo a la funcion:
		//nota: No modifica la cadena original, solo cambia el puntero
		ondaDigital(cadena + 1);
	}else{
		printf("\n");
		//printf("Fin");
	}

}
