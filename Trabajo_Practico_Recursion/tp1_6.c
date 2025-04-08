#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void auxiliar(const char *entrada, int i, char *salida_linea1, char *salida_linea2){
	if(entrada[i] == '\0'){
        salida_linea1[i] = '\0';
        salida_linea2[i] = '\0';
        return;
    }
	if(entrada[i] == 'H' || entrada[i] == 'L' ){
		if(entrada[i]=='H'){
			salida_linea1[i] = '_';
			salida_linea1[i+1] = ' ';
			if((i >0) && (entrada[i-1] == 'L') ){
				salida_linea2[i] = '|';
				salida_linea2[i+1] = ' ';
			}else{
				salida_linea2[i] = ' ';
				salida_linea2[i+1] = ' ';
			}
		}else{
			salida_linea1[i] = ' ';
			salida_linea1[i+1] = ' ';
			if((i >0) && (entrada[i-1] == 'H') ){
				salida_linea2[i] = '|';
				salida_linea2[i+1] = '_';
			}else{
				salida_linea2[i] = '_';
				salida_linea2[i+1] = ' ';
			}
		}
	}
    auxiliar(entrada, i + 1, salida_linea1, salida_linea2);
}

char *ondaDigital(char *cadena) {
    int n = (strlen(cadena)) * 2 ;
    char *salida_linea1 = malloc(n + 1);
    char *salida_linea2 = malloc(n + 1);
    if(!salida_linea1 || !salida_linea2){
		return NULL;
	}
    auxiliar(cadena, 0, salida_linea1, salida_linea2);
    // Resultado combinado en un solo string
    char *resultado = malloc((2 * n) + 2); // +1 para \n y +1 para \0
    if(!resultado){
		return NULL;
	}
    sprintf(resultado, "%s\n%s", salida_linea1, salida_linea2);
    free(salida_linea1);
    free(salida_linea2);
    return resultado;
}

int main() {
    char *entrada = "HHHHLLLLHHHHHLLHH";
    char *onda = ondaDigital(entrada);
    printf("%s\n", onda);
    free(onda);
    return 0;
}

//____    _____  __
//    |___|    |_|


