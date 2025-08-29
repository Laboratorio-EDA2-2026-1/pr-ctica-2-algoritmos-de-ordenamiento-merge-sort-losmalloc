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
    scanf("%d", &n);  // Leer el número de arreglos

    int total = n * n;  
    int *arr = (int *)malloc(total * sizeof(int));

    // Leer n arreglos de tamaño n
    for (int i = 0; i < total; i++) {
        scanf("%d", &arr[i]);
    }

    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);

    // Imprimir el arreglo ordenado
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

// ---- Implementa aquí tu función mergeSort ----
void mergeSort(int arr[], int left, int right) {
    int n = sizeof(arr);
    if (n = 1){
        return arr;
    }
    int mid = ((left + right)/2);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// ---- Implementa aquí tu función merge ----
void merge(int arr[], int left, int mid, int right) {
    int Nl = (mid - left) + 1;
    int Nr = (right - mid);
    int L[Nl - 1];
    int R[Nr - 1];
    for (int i = 0; i = (Nl -1); i++){
        L[i] = arr[left + i];
    }
    for (int j = 0; j = (Nr -1); j++){
        R[j] = arr[mid + j + 1];
    }
    i = 0;
    j = 0;
    int k = left;
    while (i < Nl){
        if (L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < Nl){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < Nr){
        arr[k] = R[j];
        j++;
        k++;
    }
    return arr;
}
