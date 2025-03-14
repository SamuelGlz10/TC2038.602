/**
 * Samuel Gonzalez Vazquez
 * A01412958
 * Algoritmos Avanzados
 * **/
#include <iostream>
#include <vector>
using namespace std;

// Función para intercambiar dos elementos en un arreglo
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función recursiva para generar permutaciones usando backtracking
void permute(vector<int> &arr, int start, int end) {
    if (start == end) {
        // Cuando se alcanza una permutación completa, se imprime
        cout << "[ ";
        for (int i = 0; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << "] ";
    } else {
        for (int i = start; i <= end; i++) {
            // Intercambiar el elemento actual con el elemento en la posición 'start'
            swap(arr[start], arr[i]);
            // Llamar recursivamente para el siguiente índice
            permute(arr, start + 1, end);
            // Deshacer el intercambio (backtracking)
            swap(arr[start], arr[i]);
        }
    }
}

int main() {
    // Arreglo de entrada
    vector<int> arr = {1, 2, 3};

    // Calcular y mostrar todas las permutaciones
    permute(arr, 0, arr.size() - 1);
    cout << endl;

    return 0;
}