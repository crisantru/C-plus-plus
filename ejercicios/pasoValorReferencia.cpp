#include <iostream>
using namespace std;

int pasoValor(int x);
void pasoreferencia(int &z);

int main()
{
    int x = 2;
    int z = 4;

    cout << "x: " << x << endl;
    cout << "valor devuelto por paso valor: " << endl;
    pasoValor(x);
    cout << "x: " << x << endl;
    cout << "z: " << z << endl;
    cout << "valor devuelto por paso referencia: " << endl;
    pasoreferencia(z);
    cout << "z: " << z << endl;


    return 0;

}

int pasoValor(int x)
{
    return x *= x;
}

void pasoreferencia(int &z)
{
    z *= z;

}
