#include <iostream>

using namespace std;

void burbuja(int arreglo[], int tam);
void imprimir(int arreglo[], int tam);


int main()
{
    int tam, i;

    cout << "dame el tamaño de tu arreglo: ";
    cin >> tam;
    int arreglo[tam];

    for(i = 0; i < tam; i++)
    {
        cout << "introduce el valor del arreglo en la posicion " << i << " : ";
        cin >> arreglo[i];
    }

    burbuja(arreglo, tam);
    imprimir(arreglo, tam);


    return 0;
}

void burbuja(int arreglo[], int tam)
{
    int i, j, temporal;

    for(i = 1; i < tam; i++)
    {
        for(j = 0 ; j < tam - 1; j++)
        {
            if (arreglo[j] > arreglo[j+1])
            {
                temporal = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temporal;
            }
        }
    }


}

void imprimir(int arreglo[], int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        cout << arreglo[i] << " ";

    }
}
