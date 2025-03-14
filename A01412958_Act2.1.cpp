/*
Samuel Gonzalez Vazquez
A01412958
Algoritmos Avanzados
 */
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

unsigned int hashString(string& str){
    unsigned hash = 5381;

    for (char c : str){
        hash = ((hash << 5) + hash) + c;
    }

    return hash;

}

int main(){
    string input;

    getline(cin, input);

    unsigned int hash = hashString(input);

    cout << hash << endl;
    return 0;
}   