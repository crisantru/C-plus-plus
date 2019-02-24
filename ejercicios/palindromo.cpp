#include <iostream>
#include <cstring>
using namespace std;

bool esPalindromo(char* palindromo);

int main(){

    char cadena[] = "anitalavalatina";

    cout << esPalindromo(cadena);

    return 0;
}

bool esPalindromo(char* palindromo){

    int i, j;

    for(i = 0, j = strlen(palindromo) - 1; j >= 0; i++, j--){
        if(palindromo[i] != palindromo[j])
        {
            return false;
        }

    }

    return true;
}
