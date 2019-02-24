#include <iostream>
#include <cstdlib>

using namespace std;

void invertir(int numero);

int main()
{
    int numero = 123;
    cout << "NUMERO " << numero << "\n";
    cout << "NUMERO INVERTIDO ";
    invertir(numero);



}

void invertir(int numero)
{
    cout << numero % 10;
    if(numero > 10)
        invertir(numero / 10);


}
