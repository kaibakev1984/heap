#include "heap.h"
#include <stdlib.h>
#define TAM_INICIAL 13

struct heap{
	void **datos;
	size_t cantidad;
	size_t capacidad;
	cmp_func_t cmp;
};

/* Funciones auxiliares */
void swap(void *elem_a, void *elem_b){
	void *aux = elem_a;
	elem_a = elem_b;
	elem_b = aux;
}

bool redimensionar(void **datos, size_t capacidad){
	void **datos_nuevos = realloc(datos, capacidad*sizeof(void *));
	if(!datos_nuevos) return false;
	datos = datos_nuevos;
	return true;
}

void upheap(void **vector, size_t pos, cmp_func_t cmp){
	if(pos == 0) return;
	size_t pos_padre = (pos - 1) / 2;
	if(cmp(vector[pos], vector[pos_padre]) < 0) return;
	swap(vector[pos], vector[pos - pos_padre]);
	upheap(vector, pos - pos_padre, cmp);
}

heap_t *heap_crear(cmp_func_t cmp){
	heap_t *heap = malloc(sizeof(heap_t));
	if(!heap) return NULL;
	heap->datos = malloc(TAM_INICIAL*sizeof(void *));
	if(!heap->datos){
		free(heap);
		return NULL;
	}
	heap->cantidad = 0;
	heap->capacidad = TAM_INICIAL;
	heap->cmp = cmp;
	return heap;
}

bool heap_esta_vacio(const heap_t *heap){
	return heap->cantidad == 0;
}

size_t heap_cantidad(const heap_t *heap){
	return heap->cantidad;
}

void *heap_ver_max(const heap_t *heap){
	if(heap_esta_vacio(heap)) return NULL;
	return heap->datos[0];
}

bool heap_encolar(heap_t *heap, void *elem){
	heap->datos[heap->cantidad] = elem;
	heap->cantidad++;
	if(heap->cantidad > heap->capacidad / 2){
		if(!redimensionar(heap, 2*heap->capacidad)) return false;
	}
	upheap(heap->datos, heap->cantidad - 1, heap->cmp)
	return true;
}

void *heap_desencolar(heap_t *heap){
	if(heap_esta_vacio(heap)) return NULL;
	swap(heap->datos[0], heap->datos[heap->cantidad - 1]);
	heap->cantidad--;
	downheap(heap, )
}