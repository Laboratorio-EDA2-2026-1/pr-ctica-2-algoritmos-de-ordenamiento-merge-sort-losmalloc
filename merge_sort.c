#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio: Implementación de Merge Sort

    Descripción:
    Se reciben n arreglos lineales, cada uno de tamaño n.
    El programa debe combinarlos en un solo arreglo de tamaño n*n
    y ordenarlo en orden creciente usando Merge Sort.

    Entrada:
    - Un número entero n
    - n arreglos de tamaño n (n*n enteros en total)

    Salida:
    - Un solo arreglo de tamaño n*n con los elementos ordenados en orden creciente

    Ejemplo:

    Input:
    3
    3 1 5
    2 9 4
    8 7 6

    Output:
    1 2 3 4 5 6 7 8 9
*/

// ---- Prototipos ----
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n;
    printf("Dame el numero de arreglos\n");
    scanf("%d", &n);  // Leer el número de arreglos
    getchar();
    int total = n * n;  
    int *arr = (int *)malloc(total * sizeof(int));

    // Leer n arreglos de tamaño n
    for (int i = 0; i < total; i++) {
        printf("\nDame un numero \n");
        scanf("%d", &arr[i]);
    }

    printf("\n\nLos arreglos originales son:\n");
    for (int i = 0; i < n; i++) {
        printf("Arreglo %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i * n + j]);
        }
        printf("\n");
    }


    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);

    // Imprimir el arreglo ordenado
    printf("\n\nEl arreglo ordenado es: \n");
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    free(arr);
    return 0;
}

// ---- Implementa aquí tu función mergeSort ----
void mergeSort(int arr[], int left, int right) {
    if(left < right){
        int mid = (left + right)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid +1, right);

        merge(arr, left, mid, right);
    }
    // TODO
}

// ---- Implementa aquí tu función merge ----
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2= right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while ( i < n1 && j < n2){
        if(L[i]<=R[j]){
            arr[k++] = L[i++];
        }else {
            arr[k++] = R[j++];

        }

    }

    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
    free(L);
    free(R);
    // TODO
}
