#include <stdio.h>
#include <stdlib.h>

int minmax(const int *arr, size_t n, int *min, int *max); /* 0 = ok, -1 = error */
long suma_indices(const int *arr, size_t n);
long suma_punteros(const int *arr, size_t n);


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minmax(const int *arr, size_t n, int *min, int *max);

int main() {

    int a = 10;
    int b = 5;

    printf("a:%d\n", a);
    printf("b:%d\n", b);
    printf("After swap\n");
    swap(&a, &b);
    printf("a:%d\n", a);
    printf("b:%d\n", b);


    return EXIT_SUCCESS;
}
