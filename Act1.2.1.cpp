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
 * Función: coinChange
 * Descripción: Calcula el número mínimo de monedas necesarias para dar un cambio específico utilizando programación dinámica.
 * Parámetros:
 *   - coins: vector<int> que contiene las denominaciones de las monedas.
 *   - amount: int que representa la cantidad de cambio a dar.
 * Retorna:
 *   - vector<int>: Un vector donde dp[i] contiene el número mínimo de monedas necesarias para dar un cambio de i.
 * Complejidad:
 *   - Tiempo: O(N * M), donde N es el número de denominaciones de monedas y M es la cantidad de cambio.
 *   - Espacio: O(M), donde M es la cantidad de cambio.
 */
vector<int> coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp;
}

/**
 * Función: getChange
 * Descripción: Determina cuántas monedas de cada denominación se necesitan para dar el cambio.
 * Parámetros:
 *   - coins: vector<int> que contiene las denominaciones de las monedas.
 *   - amount: int que representa la cantidad de cambio a dar.
 * Retorna:
 *   - vector<int>: Un vector donde result[i] contiene el número de monedas de la denominación coins[i].
 * Complejidad:
 *   - Tiempo: O(N), donde N es el número de denominaciones de monedas.
 *   - Espacio: O(N), donde N es el número de denominaciones de monedas.
 */
vector<int> getChange(vector<int>& coins, int amount) {
    vector<int> result(coins.size(), 0);
    for (int i = coins.size() - 1; i >= 0; --i) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result[i]++;
        }
    }
    return result;
}

int main() {
    int N;
    cout << "Ingrese el número de denominaciones de monedas: ";
    cin >> N;

    vector<int> coins(N);
    cout << "Ingrese las denominaciones de las monedas, una por línea:\n";
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    int P, Q;
    cout << "Ingrese el precio del producto: ";
    cin >> P;
    cout << "Ingrese la cantidad pagada: ";
    cin >> Q;

    int change = Q - P;

    if (change < 0) {
        cout << "Falta dinero para pagar ese producto\n";
    } else if (change == 0) {
        cout << "No hay cambio por dar\n";
    } else {
        vector<int> dp = coinChange(coins, change);
        if (dp[change] == INT_MAX) {
            cout << "No es posible dar el cambio exacto con las denominaciones dadas\n";
        } else {
            vector<int> result = getChange(coins, change);
            for (int i = coins.size() - 1; i >= 0; --i) {
                cout << result[i] << " moneda(s) de " << coins[i] << "\n";
            }
        }
    }

    return 0;
}