#ifndef MERGESORT_H
#define MERGESORT_H
#include <stdbool.h>

/*Funciones para manipular el arreglo*/
void copy_array(int *vector, int *destino, int ini, int fin);
bool compare_array(int *vector1, int *vector2, int tam);

/*Funciones para el mergesort*/
void mergesort(int *vector, int tam);
void mergesort_recursivo(int *vector, int *vector_aux, int ini, int fin);
void join_sorted(int *vector, int *vector_aux, int ini, int medio, int fin);

#endif