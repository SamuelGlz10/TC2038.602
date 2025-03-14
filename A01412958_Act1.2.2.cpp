/**
 * Samuel Gonzalez Vazquez
 * A01412958
 * Algoritmos Avanzados
 * **/

 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <climits>
 
 using namespace std;
 
 /**
  * Función que resuelve el problema del cambio utilizando un enfoque greedy.
  * 
  * @param denominaciones Un vector de enteros que contiene las denominaciones de las monedas.
  * @param cambio Un entero que representa la cantidad de cambio que se debe dar.
  * @return Un vector de enteros que indica cuántas monedas de cada denominación se deben usar para dar el cambio.
  * 
  * Complejidad temporal: O(n), donde n es el número de denominaciones.
  * Esto se debe a que el algoritmo recorre el vector de denominaciones una vez.
  */
 vector<int> cambioGreedy(vector<int>& denominaciones, int cambio) {
     int n = denominaciones.size();
     vector<int> resultado(n, 0);
 
     for (int i = n - 1; i >= 0; i--) {
         if (cambio >= denominaciones[i]) {
             resultado[i] = cambio / denominaciones[i];
             cambio %= denominaciones[i];
         }
     }
 
     return resultado;
 }
 
 /**
  * Función principal que maneja la entrada del usuario y ejecuta el algoritmo greedy para el problema del cambio.
  * 
  * Complejidad temporal: O(n log n) debido a la operación de ordenación de las denominaciones.
  * La complejidad de la función cambioGreedy es O(n), por lo que la complejidad total del programa está dominada por la ordenación.
  */
 int main() {
     int N;
     cout << "Ingrese el numero de denominaciones de monedas: ";
     cin >> N;
 
     vector<int> denominaciones(N);
     cout << "Ingrese las denominaciones de las monedas, una por linea: " << endl;
     for (int i = 0; i < N; i++) {
         cin >> denominaciones[i];
     }
 
     // Ordenar las denominaciones de menor a mayor
     sort(denominaciones.begin(), denominaciones.end());
 
     int P, Q;
     cout << "Ingrese el precio del producto: ";
     cin >> P;
     cout << "Ingrese la cantidad pagada: ";
     cin >> Q;
 
     // Verificar si el pago es suficiente
     if (Q < P) {
         cout << "Falta dinero para pagar ese producto" << endl;
         return 0;
     }
 
     // Calcular el cambio
     int cambio = Q - P;
     if (cambio == 0) {
         cout << "No hay cambio por dar" << endl;
         return 0;
     }
 
     // Obtener la solución utilizando el algoritmo greedy
     vector<int> resultadoGreedy = cambioGreedy(denominaciones, cambio);
     cout << "Solución con algoritmo avaro:" << endl;
     for (int i = N - 1; i >= 0; i--) {
         cout << resultadoGreedy[i] << " moneda(s) de " << denominaciones[i] << endl;
     }
 
     return 0;
 }