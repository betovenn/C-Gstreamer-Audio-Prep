#include <limits.h>
#include <stddef.h>
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

int minmax(const int *arr, size_t n, int *min, int *max) {
    if (arr == NULL || n == 0 || min == NULL || max == NULL) 
        return -1;

    int mini = *arr;
    int maxi = *arr;

    for (size_t i = 0; i < n; i++) {
        if (*(arr + i) < mini) 
            mini = *(arr + i);
        if ( *(arr + i) > maxi ) {
            maxi = *(arr + i);
        }
    }

    *min = mini;
    *max = maxi;
    return 0;
}

int main() {

    int a = 10;
    int b = 5;

    printf("a:%d\n", a);
    printf("b:%d\n", b);
    printf("After swap\n");
    swap(&a, &b);
    printf("a:%d\n", a);
    printf("b:%d\n", b);

    const int array[] = {22, 14, 8, 17, 35, 3};
    size_t n = sizeof(array) / sizeof(array[0]);
    int min = 0;
    int max = 0;

    minmax(array, n, &min, &max);

    printf("min:%d\n", min);
    printf("max:%d\n", max);



    return EXIT_SUCCESS;
}
