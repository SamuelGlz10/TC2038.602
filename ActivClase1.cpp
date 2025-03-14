/*
Samuel Gonzalez Vazquez A01412958
Algoritmos Avanzados
21/02/2025
*/
#include <iostream>
#include <vector>

using namespace std;

// Función para calcular Fibonacci usando recursividad
int fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

// Función para calcular Fibonacci usando memorización
int fibonacciMemo(int n, vector<int>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

// Función para calcular Fibonacci usando ciclos
int fibonacciCiclos(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Escribe el valor de n: ";
    cin >> n;

    // Calcula Fibonacci usando recursividad
    int resultadoRecursivo = fibonacciRecursivo(n);
    cout << "1.- Recursividad: " << resultadoRecursivo << endl;

    // Calcula Fibonacci usando memorización
    vector<int> memo(n + 1, -1);
    int resultadoMemo = fibonacciMemo(n, memo);
    cout << "2.- Memorizacion: " << resultadoMemo << endl;

    // Calcula Fibonacci usando ciclos
    int resultadoCiclos = fibonacciCiclos(n);
    cout << "3.- Ciclos: " << resultadoCiclos << endl;

    return 0;
}