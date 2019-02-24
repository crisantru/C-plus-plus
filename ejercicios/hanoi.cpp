#include <iostream>
using namespace std;

void hanoi(int n, char torreInicial, char torreFinal, char torreAux);

int main()
{
    char torreInicial, torreAux, torreFinal;
    int n;

    cout << "Dame el numero de discos ";
    cin >> n;
    hanoi(n, 'A', 'C', 'B');

    return 0;
}

void hanoi(int n, char torreInicial, char torreFinal, char torreAux)
{
    //cout << "Discos: " << n << "  Torre Inicial: " << torreInicial
//         << "  Torre Aux: " << torreAux << "  Torre Final: " << torreFinal << endl;
    if(n == 1)
    {
        //cout<<"Mueva el bloque "<<n<<" desde "<<torreInicial<<" hasta  "<<torreFinal<<endl;
        cout << torreInicial << " -> " << torreFinal << endl;
    }
    else
    {
        hanoi(n - 1, torreInicial, torreAux, torreFinal);
        //cout << "Mueva el bloque " << n <<" desde " << torreInicial << " hasta  " << torreFinal << endl;
        cout << torreInicial << " -> " << torreFinal << endl;
        hanoi(n - 1, torreAux, torreFinal, torreInicial);
    }

}
