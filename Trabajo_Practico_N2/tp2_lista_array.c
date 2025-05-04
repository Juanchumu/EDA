
Lista l_desde_array(int arr[], int largo ){
	Lista arrays = l_crear();
	for(int i = 0; i < largo; i++){
		TipoElemento te = te_crear(arr[i]);
		l_agregar(arrays, te);
	}
	return arrays;
}


