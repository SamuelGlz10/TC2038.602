#include<stdio.h>
#include <iostream>
#include <vector>

template <typename T>
void mergeHalves(std::vector<T>& arr, int left, int mid, int right); // Declaración de la función

template <typename T>
void merge(std::vector<T>& arr, int left, int right) {
    // Complejidad temporal: O(n log n), donde n es el número de elementos en el arreglo.
    // Complejidad espacial: O(n) debido a los arreglos auxiliares en mergeHalves.
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Dividir el array en dos mitades
        merge(arr, left, mid);
        merge(arr, mid + 1, right);

        // Mezclar las dos mitades
        mergeHalves(arr, left, mid, right);
    }
}

template <typename T>
void mergeHalves(std::vector<T>& arr, int left, int mid, int right) {
    // Complejidad temporal: O(n), donde n es el número de elementos en el subarreglo (right - left + 1).
    // Complejidad espacial: O(n) debido a los arreglos auxiliares leftArr y rightArr.
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    // Merge las dos mitades en orden descendente
    while (i < n1 && j < n2) {
        if (leftArr[i] > rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de leftArr[], si los hay
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de rightArr[], si los hay
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

int main() {
    // Complejidad temporal: O(n log n) debido a la llamada a merge.
    // Complejidad espacial: O(n) debido al arreglo de entrada y los arreglos auxiliares en mergeHalves.
    int n;
    std::cout << "Ingrese el numero de valores a ordenar: ";
    std::cin >> n;

    std::vector<float> arr(n);
    std::cout << "Ingrese " << n << " valores(reales o enteros), uno por linea\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "\nArreglo original: ";
    for (auto num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    merge(arr, 0, arr.size() - 1);

    std::cout << "Arreglo ordenado de mayor a menor: ";
    for (auto num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}