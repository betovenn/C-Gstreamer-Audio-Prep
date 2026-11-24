#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minmax(const int *arr, size_t n, int *min, int *max); /* 0 = ok, -1 = error */
long suma_indices(const int *arr, size_t n);
long suma_punteros(const int *arr, size_t n);


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minmax(const int *arr, size_t n, int *min, int *max) {
    if (arr == NULL || n == 0 || min == NULL || max == NULL) 
        return -1;

    int mini = *arr;
    int maxi = *arr;

    for (size_t i = 0; i < n; i++) {
        if (arr[i] < mini) 
            mini = arr[i];
        if (arr[i] > maxi ) {
            maxi = arr[i];
        }
    }

    *min = mini;
    *max = maxi;
    return 0;
}

long suma_indices(const int *arr, size_t n) {
    long suma = 0;
    for (size_t i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma;
}

long suma_punteros(const int *arr, size_t n) {
    long suma = 0;
    for (const int *p = arr; p < arr + n; p++) {
        suma += *p;
    }
    return suma;
}

void print_array(const int * arr, size_t n) {
    printf("[");
    for(size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }  
    printf("]\n");
}

void print_address(const int * arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        const int *p = (arr + i);
        printf("%p\n", (void *)p);
    }
}

void verificar_suma(long sum1,long sum2) {
    if (sum1 == sum2)
        printf("Correct\n");
    else
        printf("sum1: %ld, sum2: %ld\n", sum1, sum2);
}

void verificar_minmax(int value) {
    if (value == -1) {
        printf(" !!!!!! minmax: error en los valores pasados a minmax\n");
    }
}

int main(void) {
    unsigned int semilla = (unsigned) time(NULL);
    printf("semilla: %u\n", semilla);
    srand(semilla);

    // Swap 
    // Valores distintos
    printf("Valores distintos\n");
    int a = 10;
    int b = 5;

    printf("a:%d\n", a);
    printf("b:%d\n", b);
    printf("After swap\n");
    swap(&a, &b);
    printf("a:%d\n", a);
    printf("b:%d\n", b);

    // Valores iguales
    printf("Valores iguales\n");
    a = 5;
    b = 5;

    printf("a:%d\n", a);
    printf("b:%d\n", b);
    printf("After swap\n");
    swap(&a, &b);
    printf("a:%d\n", a);
    printf("b:%d\n", b);

    // Valores negativos
    printf("Valores negativos\n");
    a = -5;
    b = -15;

    printf("a:%d\n", a);
    printf("b:%d\n", b);
    printf("After swap\n");
    swap(&a, &b);
    printf("a:%d\n", a);
    printf("b:%d\n", b);

    // MinMax

    const int array[] = {22, 14, 8, 17, 35, 3};
    size_t n = sizeof(array) / sizeof(array[0]);
    int min = 0;
    int max = 0;

    minmax(array, n, &min, &max);

    printf("min:%d\n", min);
    printf("max:%d\n", max);

    // Un solo elemento
    printf("Un solo elemento minmax\n");
    const int one[1] = {1};
    int valor1 = minmax(one, 1, &min, &max);
    verificar_minmax(valor1);
    printf("min:%d\n", min);
    printf("max:%d\n", max);

    // Todos iguales
    int same_value[10];
    size_t same_n = sizeof(same_value) / sizeof(same_value[0]);
    for (size_t i = 0; i < same_n; i++) {
        same_value[i] = 10;
    }

    int valor2 = minmax(same_value, same_n, &min, &max);
    verificar_minmax(valor2);
    printf("Todos iguales\n");
    printf("min:%d\n", min);
    printf("max:%d\n", max);

    // Valores Negativos
    int negative_values[20];
    size_t negative_values_n = sizeof(negative_values) / sizeof(negative_values[0]);

    for(size_t i = 0; i < negative_values_n; i++) {
        negative_values[i] = (rand() % 201) - 201;
    }

    int valor3 = minmax(negative_values, negative_values_n, &min, &max);
    verificar_minmax(valor3);
    printf("Valores negativos\n");
    printf("Direcciones\n");
    print_address(negative_values, negative_values_n);
    print_array(negative_values,negative_values_n);
    printf("min:%d\n", min);
    printf("max:%d\n", max);

    // NULL, 5, &a, &b
    printf("NULL, 5, &a, &b\n");
    int valor = minmax(NULL, 5, &a, &b);
    verificar_minmax(valor);

    long suma_arr = suma_indices(array, n);
    printf("suma indices: %ld\n", suma_arr);
    suma_arr = suma_punteros(array, n);
    printf("suma punteros: %ld\n", suma_arr);

    int numeros[1000];
    size_t n_num_arr = sizeof(numeros) / sizeof(numeros[0]);

    for(size_t i = 0; i < n_num_arr; i++) {
        numeros[i] = (rand() % 201) - 100;
    }

    //print_array(numeros,1000);
    long suma1 = suma_indices(numeros, n_num_arr);
    long suma2 = suma_punteros(numeros, n_num_arr);

    verificar_suma(suma1, suma2);

    return EXIT_SUCCESS;
}
