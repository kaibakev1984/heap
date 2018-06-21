#include "mergesort.h"
#include <stdio.h>

/*Funciones adicionales para trabajar con el arreglo*/
void copy_array(int *vector, int *destino, int ini, int fin){
	for(int i = ini; i < fin; i++){
		destino[i] = vector[i];
	}
}

bool compare_array(int *vector1, int *vector2, int tam){
	bool ok = true;
	for(int i = 0; i < tam; i++){
		ok &= (vector1[i] == vector2[i]);
	}
	return ok;
}

/*Funciones para el mergesort*/
void mergesort(int *vector, int tam){
	int vector_aux[tam];
	copy_array(vector, vector_aux, 0, tam);
	mergesort_recursivo(vector_aux, vector, 0, tam);
}

void mergesort_recursivo(int *vector, int *vector_aux, int ini, int fin){
	if(fin - ini < 2) return;
	int medio = (ini + fin) / 2;
	mergesort_recursivo(vector, vector_aux, ini, medio);
	mergesort_recursivo(vector, vector_aux, medio, fin);
	join_sorted(vector, vector_aux, ini, medio, fin);
}

void join_sorted(int *vector, int *vector_aux, int ini, int medio, int fin){
	int i = ini, j = medio, k = ini;

	while(i < medio && j < fin){
		if(vector[i] < vector[j]){
			vector_aux[k++] = vector[i++];
		}else{
			vector_aux[k++] = vector[j++];
		}
	}

	while(i < medio){
		vector_aux[k++] = vector[i++];
	}

	while(j < fin){
		vector_aux[k++] = vector[j++];
	}

	copy_array(vector_aux, vector, ini, fin);
}