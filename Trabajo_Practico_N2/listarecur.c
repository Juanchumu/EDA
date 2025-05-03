#include <stdio.h>
#include "listas_punteros.c"
#include "tipo_elemento.c"


Lista gencien();
Lista multiplosde(Lista l, int a);
float promediosListaAux(Iterador i, int suma, int cantidad);
float promedioLista(Lista l);


int main(){
	Lista cien1 = gencien();
	l_mostrar(cien1);
	Lista mp = multiplosde(cien1, 3);
	l_mostrar(mp);
	
}

Lista gencien(){
	Lista cien = l_crear();
	for(int i = 0; i < 100; i++){
		TipoElemento te = te_crear(i);
		l_agregar(cien, te);
	}
	return cien;
}

Lista multiplosde(Lista l, int a){
	TipoElemento x, x1;
	Lista lm = l_crear();
	Iterador ite = iterador(l);
	while(hay_siguiente(ite)){
		x = siguiente(ite);
		if(( x->clave % a) == 0 ){
			x1 = te_crear(x->clave);
			l_agregar(lm, x1);
		}
	}
	return lm;
}

float promediosListaAux(Iterador i, int suma, int cantidad){
	TipoElemento x = siguiente(i);
	if(x == NULL){
		if(cantidad == 0){ 
			return -1;
		}else{
			return (cantidad / suma);
		}
	}else{
		return promediosListaAux(i, suma + x->clave, cantidad +1);
	}
}

float promedioLista(Lista l){
	Iterador i = iterador(l);
	float promedio = promediosListaAux(i, 0 ,0);
	return promedio;
}
