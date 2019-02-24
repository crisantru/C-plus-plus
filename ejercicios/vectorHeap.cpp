#include<iostream>
using namespace std;

class Vector
{
    int tam;

    public:
        int *arreglo ;
        Vector(int tam2);


};

Vector::Vector(int tam2)    //Constructor
{
    tam = tam2;
    arreglo = new int[tam2];

}

int main()
{
    int i;
    Vector vectorPadre(5);

    for(inti = 0; i < vectorPadre.tam; i++)
    {
        vectorPadre.arreglo[i] = 5;

    }

    for(i = 0; i < Vector.tam; i++)
    {
        cout << "vector " << Vector.arreglo[i];

    }




}
