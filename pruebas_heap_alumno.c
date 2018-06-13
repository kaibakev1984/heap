#include "testing.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>


int cmp(const void*n1, const void* n2){
    if ((int*)n1 == (int*)n2) return 0;
	else if ((int*)n1 > (int*)n2) return 1;
	else return -1;
}

void prueba_1(){
		heap_t *heap = heap_crear(cmp);
	
	int* x1 = malloc(sizeof(int));
	*x1 = 1;
	int* x2 = malloc(sizeof(int));
	*x2 = 2;
	int* x3 = malloc(sizeof(int));
	*x3 = 4;
	int* x4 = malloc(sizeof(int));
	*x4 = 3;

	print_test("heap esta vacio", heap_esta_vacio(heap));
	print_test("heap cantidad es 0", heap_cantidad(heap) == 0);
	print_test("heap maximo es NULL", heap_ver_max(heap) == NULL);

	print_test("Se encolo un 1", heap_encolar(heap,x1));
	print_test("heap cantidad es 1", heap_cantidad(heap) == *x1);
	print_test("heap maximo es 1", heap_ver_max(heap) == x1);

	print_test("Se encolo un 2", heap_encolar(heap,x2));
	print_test("heap cantidad es 2", heap_cantidad(heap) == *x2);
	print_test("heap maximo es 2", heap_ver_max(heap) == x2);

	print_test("Se encolo un 4", heap_encolar(heap,x3));
	print_test("heap cantidad es 3", heap_cantidad(heap) == *x4);
	print_test("heap maximo es 4", heap_ver_max(heap) == x3);

	print_test("Se encolo un 3", heap_encolar(heap,x4));
	print_test("heap cantidad es 4", heap_cantidad(heap) == *x3);
	print_test("heap maximo es 4", heap_ver_max(heap) == x3);

	free(x1);
	free(x2);
	free(x3);
	free(x4);

	heap_destruir(heap,NULL);
}

void prueba_2(){
	heap_t *heap = heap_crear(cmp);

	int x1 = 1;
	int x2 = 2;
	int x3 = 4;
	int x4 = 3;

	print_test("heap esta vacio", heap_esta_vacio(heap));
	print_test("heap cantidad es 0", heap_cantidad(heap) == 0);
	print_test("heap maximo es NULL", heap_ver_max(heap) == NULL);

	print_test("Se encolo un 1", heap_encolar(heap,&x1));
	print_test("heap cantidad es 1", heap_cantidad(heap) == x1);
	print_test("heap maximo es 1", heap_ver_max(heap) == &x1);

	print_test("Se encolo un 2", heap_encolar(heap,&x2));
	print_test("heap cantidad es 2", heap_cantidad(heap) == x2);
	print_test("heap maximo es 2", heap_ver_max(heap) == &x2);

	print_test("Se encolo un 4", heap_encolar(heap,&x3));
	print_test("heap cantidad es 3", heap_cantidad(heap) == x4);
	print_test("heap maximo es 4", heap_ver_max(heap) == &x3);

	print_test("Se encolo un 3", heap_encolar(heap,&x4));
	print_test("heap cantidad es 4", heap_cantidad(heap) == x3);
	print_test("heap maximo es 4", heap_ver_max(heap) == &x3);

	heap_destruir(heap,NULL);
}

static void prueba_heap_vacio(){
	printf("INICIO DE PRUEBAS CON HEAP VACIO\n");

	heap_t *heap = heap_crear(cmp);

	print_test("Prueba heap cantidad es 0", !heap_cantidad(heap));
	print_test("Prueba heap esta vacio", heap_esta_vacio(heap));
	print_test("Prueba heap desencolar es NULL, es invalido", !heap_desencolar(heap));
	print_test("Prueba heap ver maximo es NULL, no existe", !heap_ver_max(heap));

	heap_destruir(heap, NULL);
}

static void prueba_heap_guardar(){
	printf("INICIO DE PRUEBAS HEAP GUARDAR\n");

	/* Declaro las variables a utilizar */
	heap_t *heap = heap_crear(cmp);
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4;

	/* Pruebo que encolar num1 en heap vacío es válido, y que es máximo */
	print_test("Prueba heap encolar num1 es true", heap_encolar(heap, &num1));
	print_test("Prueba heap num1 es maximo", heap_ver_max(heap) == &num1);
	print_test("Prueba heap la cantidad de elementos es 1", heap_cantidad(heap) == 1);

	/* Pruebo que encolar num2 es válido; num2 es el nuevo máximo */
	print_test("Prueba heap encolar num2 es true", heap_encolar(heap, &num2));
	print_test("Prueba heap num2 es maximo", heap_ver_max(heap) == &num2);
	print_test("Prueba heap la cantidad de elementos es 2", heap_cantidad(heap) == 2);

	/* Pruebo que encolar num3 es válio; num3 es el nuevo máximo */
	print_test("Prueba heap encolar num3 es true", heap_encolar(heap, &num3));
	print_test("Prueba heap num3 es maximo", heap_ver_max(heap) == &num3);
	print_test("Prueba heap la cantidad de elementos es 3", heap_cantidad(heap) == 3);

	/* Pruebo que encolar num4 es válido; num4 es el nuevo máximo */
	print_test("Prueba heap encolar num4 es true", heap_encolar(heap, &num4));
	print_test("Prueba heap num4 es maximo", heap_ver_max(heap) == &num4);
	print_test("Prueba heap la cantidad de elementos es 4", heap_cantidad(heap) == 4);
	print_test("Prueba heap esta vacio es false", !heap_esta_vacio(heap));

	heap_destruir(heap, NULL);
}

static void prueba_heap_borrar(){
	printf("INICIO DE PRUEBAS DE HEAP BORRAR\n");

	/* Declaro las variables a utilizar */
	heap_t *heap = heap_crear(cmp);
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4;
	
	/* Guardo todos los elementos en el heap */
	print_test("Prueba heap insertar num1 es true", heap_encolar(heap, &num1));
	print_test("Prueba heap insertar num2 es true", heap_encolar(heap, &num2));
	print_test("Prueba heap insertar num3 es true", heap_encolar(heap, &num3));
	print_test("Prueba heap insertar num4 es true", heap_encolar(heap, &num4));

	/* Pruebo que al borrar num4, el nuevo máximo es num3 */
	print_test("Prueba heap desencolar es num4", heap_desencolar(heap) == &num4);
	print_test("Prueba heap el maximo es num3", heap_ver_max(heap) == &num3);
	print_test("Prueba heap la cantidad de elementos es 3", heap_cantidad(heap) == 3);

	/* Pruebo que al borrar num3, el nuevo máximo es num2 */
	print_test("Prueba heap desencolar es num3", heap_desencolar(heap) == &num3);
	print_test("Prueba heap el maximo es num2", heap_ver_max(heap) == &num2);
	print_test("Prueba heap la cantidad de elementos es 2", heap_cantidad(heap) == 2);

	/* Pruebo que al borrar num2, el nuevo máximo es num1 */
	print_test("Prueba heap desencolar es num2", heap_desencolar(heap) == &num2);
	print_test("Prueba heap el maximo es num1", heap_ver_max(heap) == &num1);
	print_test("Prueba heap la cantidad de elementos es 1", heap_cantidad(heap) == 1);

	/* Pruebo que al borrar num1, el heap está vacío */
	print_test("Prueba heap desencolar es num1", heap_desencolar(heap) == &num1);
	print_test("Prueba heap ver maximo es NULL, no existe", !heap_ver_max(heap));
	print_test("Prueba heap la cantidad de elementos es 0", !heap_cantidad(heap));

	heap_destruir(heap, NULL);
}

static void prueba_heap_reemplazar_con_destruir(){
	printf("INICIO DE PRUEBAS REEMPLAZAR CON DESTRUIR\n");

	heap_t *heap = heap_crear(cmp);

	int *valor1 = malloc(sizeof(int));
	int *valor2 = malloc(sizeof(int));
	int *valor3 = malloc(sizeof(int));

	*valor1 = 1;
	*valor2 = 2;
	*valor3 = 3;

	/* Pruebo que guardar valor1 funciona correctamente */
	print_test("Prueba heap guardar valor1 es true", heap_encolar(heap, valor1));
	print_test("Prueba heap ver maximo igual a valor1", heap_ver_max(heap) == valor1);
	print_test("Prueba heap la cantidad de elementos es 1", heap_cantidad(heap) == 1);

	/* Pruebo que guardar valor2 funciona correctamente */
	print_test("Prueba heap guardar valor2 es true", heap_encolar(heap, valor2));
	print_test("Prueba heap ver maximo igual a valor2", heap_ver_max(heap) == valor2);
	print_test("Prueba heap la cantidad de elementos es 2", heap_cantidad(heap) == 2);

	/* Pruebo que guardar valor3 funciona correctamente */
	print_test("Prueba heap guardar valor3 es true", heap_encolar(heap, valor3));
	print_test("Prueba heap ver maximo igual a valor3", heap_ver_max(heap) == valor3);
	print_test("Prueba heap la cantidad de elementos es 3", heap_cantidad(heap) == 3);

	heap_destruir(heap, free);
}

static void prueba_heap_volumen(){
	printf("INICIO DE PRUEBAS HEAP VOLUMEN\n");

	heap_t *heap = heap_crear(cmp);
	size_t n = 5000;
	size_t arreglo[n];

	for(size_t i = 0; i < n; i++){
		arreglo[i] = i;
	}

	/* Prueba se encolaron 5000 elementos correctamente */
	bool ok = true;
	for(size_t i = 0; i < n; i++){
		ok &= heap_encolar(heap, &arreglo[i]);
		ok &= &arreglo[i] == heap_ver_max(heap);
	}
	print_test("Prueba heap se encolaron todos los elementos", ok);
	print_test("Prueba heap la cantidad de elementos es correcta", heap_cantidad(heap) == n);

	/* Prueba se desencolaron todos los elementos */
	for(size_t i = 0; i < n; i++){
		ok &= &arreglo[n - i - 1] == heap_desencolar(heap);
	}
	print_test("Prueba heap desencolar funciona correctamente", ok);

	heap_destruir(heap, NULL);
}

void pruebas_heap_alumno(){
	prueba_heap_vacio();
	prueba_heap_guardar();
	prueba_heap_borrar();
 	prueba_heap_reemplazar_con_destruir();
 	prueba_heap_volumen();
}

