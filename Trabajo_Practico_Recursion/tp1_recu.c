#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"

//funcion auxiliar palindromo 
char *recortar_extremos(char *original);

void menu_intro();
void menu();

//prototivo funcion 8:
// Ejercicio 8
// Variables globales para poder acceder a tamaños desde fuera de subconjuntosQueSumanN
int returnSize = 0;
int *returnColumnSizes = NULL;

int medir(int * arr);
//int ** subconjuntosQueSumanN(int conjunto[], int n);

int main(void){
	menu();
	return 0; 
}
void menu_intro(){
	printf("Seleccione un punto del trabajo practico:\n");
	printf("(1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 ) \n ");
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
				char palabra_palin[100];
				scanf("%s", palabra_palin);
				if(palindromo(palabra_palin)){
					printf("%s es un palindromo\n", palabra_palin);
				}else{	
					printf("%s no es un palindromo\n", palabra_palin);
				}
				printf("Fin Ejercicio 1\n");
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
				printf("Fin Ejercicio 2\n");
				menu();
				break;
			case 3:
				printf("Ejercicio 3\n");
				printf("Se necesita ingresar el valor de K\n");
				int kesimo; 
				scanf("%d",&kesimo);
				printf("El resultado es: %d\n", terminoSeridFibonacci(kesimo));
				printf("Fin Ejercicio 3\n");
				menu();
				break;
			case 4:
				printf("Ejercicio 4\n");
				int m_div, n_div; 
				printf("Se necesita ingresar el valor de m\n");
				scanf("%d",&m_div);
				printf("Se necesita ingresar el valor de n\n");
				scanf("%d",&n_div);
				printf("El resultado es: %.4f \n", division(m_div, n_div));
				printf("Fin Ejercicio 4\n");
				menu();
				break;
			case 5:
				printf("Ejercicio 5\n");
				printf("Se necesita ingresar un valor numerico:\n");
				char palabra_sep[20]; 
				scanf("%s",palabra_sep);
				printf("El resultado es: %s\n", agregarSeparadorMiles(palabra_sep)  );
				printf("Fin Ejercicio 5\n");
				menu();
				break;
			case 6:
				printf("Ejercicio 6\n");
				printf("Se necesita ingresar el nivel de mafia\n");
				int mafiosos; 
				scanf("%d",&mafiosos);
				printf("El resultado es: %s\n", reunionMafia(mafiosos));
				printf("Fin Ejercicio 6\n");
				menu();
				break;
			case 7:
				printf("Ejercicio 7\n");
				printf("Se necesita ingresar la onda codificada:\n");
				printf("Nota: se requieren letras mayusculas\n");
				char onda[100]; 
				scanf("%s",onda);
				printf("El resultado es: %s\n", ondaDigital(onda));
				printf("Fin Ejercicio 7\n");
				menu();
				break;
			case 8:
				printf("Ejercicio 8\n");
				printf("Se necesita ingresar varias cosas, se utiliza\n");
				printf("la plantilla: {10,3,1,7,4,2,-1}, con N 7 \n");
				// Usamos -1 como terminador para saber el tamaño del arreglo
				// //int conjunto[] = {2, 3, 5, 7, -1};
				int conjunto[] = {10,3,1,7,4,2,-1};
				int N = 7;
				int **resultados = subconjuntosQueSumanN(conjunto, N);
				printf("R: [");
				for (int i = 0; i < returnSize; i++) {
					printf("{ ");
					for (int j = 0; j < returnColumnSizes[i]; j++) {
						printf("%d ", resultados[i][j]);
					}
					printf("}");
					if((i+1)<returnSize){
						printf(",");
					}
					free(resultados[i]);
				}
				printf("]\n");
				free(resultados);
				free(returnColumnSizes);
				//otra plantilla 
				printf("la plantilla: {10,3,1,7,4,2,-1}, con N 10 \n");
				// Usamos -1 como terminador para saber el tamaño del arreglo
				// //int conjunto[] = {2, 3, 5, 7, -1};
				int A_x = 10;
				int **resultados_A = subconjuntosQueSumanN(conjunto, A_x);
				printf("R: [");
				for (int i = 0; i < returnSize; i++) {
					printf("{ ");
					for (int j = 0; j < returnColumnSizes[i]; j++) {
						printf("%d ", resultados_A[i][j]);
					}
					printf("}");
					if((i+1)<returnSize){
						printf(",");
					}
					free(resultados_A[i]);
				}
				printf("]\n");
				free(resultados_A);
				free(returnColumnSizes);
				printf("Fin Ejercicio 8\n");
				menu();
				break;
			case 9:
				printf("Ejercicio 9\n");
				printf("Se necesita ingresar un numero:\n");
				int siete; 
				scanf("%d",&siete);
				if(divisiblePor7(siete)){
					printf("%d es divisible por 7\n", siete);
				}else{	
					printf("%d no es divisible por 7\n", siete);
				}
				printf("Fin Ejercicio 9\n");
				menu();
				break;
			case 10:
				printf("Ejercicio 10\n");
				printf("Se necesita ingresar el numero:\n");
				int numero, bomba; 
				scanf("%d",&numero);
				printf("Se necesita ingresar la bomba:\n");
				scanf("%d",&bomba);
				int * reventar = explosion(numero,bomba); 
				printf("El resultado es: [");
				int cantidad_fragmentos =  medir(reventar);
				for(int i = 0; i < cantidad_fragmentos; i++){
					printf("%d", reventar[i]);
					if((i+1)<cantidad_fragmentos){
						printf(",");
					}
				}
				printf("]\n");
				//reccorido del array reventar 
				printf("Fin Ejercicio 10\n");
				menu();
				break;




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
//Ejercicio 1:
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

//Ejercicio 4
float division(int m, int n){
	//m 64 n 5
	float estado; 
	int resta = m - n;
	if (resta > n ){
		//continua la resta
		estado = 1 + division(resta, n);
		//printf("if %f", estado);
	}else{
		//resta vale 4, n 5  
		//necesito un 0.8
		estado = 1 + ( (float) resta / n );
		//printf("else %f", estado);
	}
	return estado; 

}



// Ejercicio 5
char *agregarSeparadorMiles(char numero[])
{
	int len = strlen(numero);
	if (len <= 3)
	{
		char *result = malloc(len + 1);
		strcpy(result, numero);
		return result;
	}
	char *prefix = malloc(len - 2);
	strncpy(prefix, numero, len - 3);
	prefix[len - 3] = '\0';
	char *proccesedPref = agregarSeparadorMiles(prefix);
	free(prefix);
	char *suffix = numero + len - 3;
	char *result = malloc(strlen(proccesedPref) + 1 + 3 + 1);
	sprintf(result, "%s.%s", proccesedPref, suffix);
	free(proccesedPref);
	return result;
}

// Ejercicio 6
char *reunionMafia(int nivel)
{
	if (nivel < 1)
	{
		return strdup("0");
	}
	if (nivel == 1)
	{
		return strdup("(-.-)");
	}
	char *centro = reunionMafia(nivel - 1);
	char *completo = malloc(strlen(centro) + 7);
	sprintf(completo, "(-.%s.-)", centro);
	free(centro);
	return completo;
}

//aux7
char *unir_strings(const char *s1, const char *s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	// +1 para el carácter nulo '\0'
	char *resultado = malloc(len1 + len2 + 1);
	if (!resultado) return NULL;

	strcpy(resultado, s1);
	strcat(resultado, s2);

	return resultado;
}


//Ejercicio 7 
char * ondaDigital(char * cadena){
	//Cadena a devolver:
	char * devolver;
	if(cadena[0] != '\0'){
		//printf("f %c", cadena[0]);
		if(cadena[0] == 'H' || cadena[0]=='L'){
			if(cadena[0]=='H'){
				//si el siguiente es el final, si el siguiente es cambio 
				if( (cadena[1] == 'L')){ //printf("*|");
					devolver = unir_strings("*|", ondaDigital(cadena +1));
				}else{ //printf("*");
					devolver = unir_strings("*", ondaDigital(cadena +1));
				}
			}else{
				if( (cadena[1] == 'H')){ //printf("_|");
					devolver = unir_strings("_|", ondaDigital(cadena +1));
				}else{ //printf("_");
					devolver = unir_strings("_", ondaDigital(cadena +1));
				}
			}
		}else{
			printf("Error en la cadena");
		}
		//llamar denuevo a la funcion:
		//nota: No modifica la cadena original, solo cambia el puntero
		//      Termina en \0 
	}else{
		//printf("\n");
		devolver = "";
		//printf("Fin");
	}
	return devolver;

}
// Ejercicio 8

//Funcion auxiliar 8
void backtrack(int *nums, int n, int target, int idx,
               int *temp, int tempSize,
               int **res, int *resSize, int **colSizes) {
    if (target == 0) {
        res[*resSize] = malloc(tempSize * sizeof(int));
        colSizes[*resSize] = malloc(sizeof(int));
        for (int i = 0; i < tempSize; i++)
            res[*resSize][i] = temp[i];
        colSizes[*resSize][0] = tempSize;
        (*resSize)++;
        return;
    }

    if (target < 0 || idx >= n)
        return;

    // Incluir nums[idx]
    temp[tempSize] = nums[idx];
    backtrack(nums, n, target - nums[idx], idx + 1, temp, tempSize + 1, res, resSize, colSizes);

    // No incluir nums[idx]
    backtrack(nums, n, target, idx + 1, temp, tempSize, res, resSize, colSizes);
}

int **subconjuntosQueSumanN(int conjunto[], int N) {
    int n = 0;
    // Calcular longitud del conjunto
    while (conjunto[n] != -1) n++;

    int max = 1 << n; // como máximo 2^n subconjuntos
    int **res = malloc(max * sizeof(int *));
    int **colSizes = malloc(max * sizeof(int *));
    int *temp = malloc(n * sizeof(int));

    returnSize = 0;

    backtrack(conjunto, n, N, 0, temp, 0, res, &returnSize, colSizes);

    // Copiar tamaños a variable global para que el usuario pueda acceder
    returnColumnSizes = malloc(returnSize * sizeof(int));
    for (int i = 0; i < returnSize; i++) {
        returnColumnSizes[i] = colSizes[i][0];
        free(colSizes[i]);
    }

    free(colSizes);
    free(temp);

    return res;
}


// Ejercicio 9
bool divisiblePor7(int numero) {
	//32291
    if (numero < 70) { // no 
        return numero % 7 == 0;
    }
    int ultimaCifra = numero % 10;
    int resto = numero / 10; //ult 

    int nuevoNumero = resto - 2 * ultimaCifra; //resta 

    return divisiblePor7(nuevoNumero);
}
// //Ejercicio 10

//Funcion auxiliar ejercicio 10:
int medir(int * arr){
	//devuelve el indice, se detiene cuando arr[i] = 0
	//osea que termino el array
	int indice = 0;
	for(int i = 0; arr[i] != 0 ; i++){
		indice++;
	}
	return indice;
}
int printar(int * arr){
	int indice = 0;
	printf("[");
	for(int i = 0; arr[i] != 0 ; i++){
		printf("%d,",arr[i]);
		indice++;
	}
	printf("]\n");
	return indice;
}


int *explosion(int n, int b){
	int *devolver_fragmentos = NULL;
	int fragmentos = 0;
	//int * revento_n_veces = NULL;
	int N1, N2;
	if(n > b){
		N1 = n / b; //10/3 = 3, no continua 
		N2 = n - ( n / b ); // 6, continua
		//primero se agrega el arbol de fragmentos generado a partir de N1:
		if(N1 >b ){
			printf("N1: %d \n", N1);
			//recursion,fragmentos crece, ¿que tanto crece?
			int * revento_n_veces = explosion(N1, b);
			printf("hola");
			int crece = medir(revento_n_veces);
			fragmentos = fragmentos + crece; 
			devolver_fragmentos = realloc(devolver_fragmentos, fragmentos * sizeof(int));
			for(int i = 0; i < crece; i++){
				int posicion = fragmentos + i - crece;
				devolver_fragmentos[posicion] = revento_n_veces[i];
			}
			printf("hasta aca: ");
			printar(devolver_fragmentos);
			printar(revento_n_veces);
		}else{
			printf("N1f, se fija %d\n", N1);
			//no hay recursion, se fijan dos fragmentos, N1 y -1.
			fragmentos++; 
			devolver_fragmentos = realloc(devolver_fragmentos, fragmentos * sizeof(int));
			devolver_fragmentos[fragmentos-1] = N1;  
 
		}
		//despues se arranca con este arbol: 
		if(N2 > b){
			printf("N2: %d\n", N2);
			//recursion,fragmentos crece, ¿que tanto crece?
			int * revento_n_veces = explosion(N2, b);
			int crece = medir(revento_n_veces);
			printf("dv fragmentos antes:\n");
			printar(devolver_fragmentos);
			printf("el array crece %d \n", crece);
			printf("fragmentos ahora valia %d\n",fragmentos);
			fragmentos = fragmentos + crece;
			printf("fragmentos ahora vale %d\n",fragmentos);
			devolver_fragmentos = realloc(devolver_fragmentos, fragmentos * sizeof(int));
			for(int i = 0; i < crece; i++){
				int posicion = fragmentos + i - crece ;
				devolver_fragmentos[posicion] = revento_n_veces[i];
			}
			printf("dv fragmentos despues:\n");
			printar(devolver_fragmentos);
			printf("lo que vale revento_nVeces:\n");
			printar(revento_n_veces);
		}else{
			printf("N2f, se fija  %d\n", N2);
			fragmentos++; 
			devolver_fragmentos = realloc(devolver_fragmentos, fragmentos * sizeof(int));
			devolver_fragmentos[fragmentos-1] = N2;
			//printf("N2f, se fijo");
			//medir(devolver_fragmentos);
		}
	}/*
	else{
		printf("-1");
		//no es mayor a b, entonces se agrega -1 
		fragmentos++; 
		devolver_fragmentos = realloc(devolver_fragmentos, fragmentos * sizeof(int));
		devolver_fragmentos[fragmentos-1] = -1; 
	}
	*/
	printf("devolver\n");
	printar(devolver_fragmentos);
	return devolver_fragmentos;
	
}

