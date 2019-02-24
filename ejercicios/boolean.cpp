#include <iostream>

using namespace std;

bool esPrimo(int n);

int main(){

    int n;

    cout << "Escribe un numero: ";
    cin >> n;

    cout << esPrimo(n);

    return 0;
}

bool esPrimo(int n){

    int i;

    for(i = 2; i < 2; i++)
    {
        if(n % i == 0)
        {

            return false;
        }
        else
        {
            return true;
        }

    }



}
