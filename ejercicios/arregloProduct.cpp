#include<iostream>
using namespace std;

int producto(int arreglo[], int tam);

int main()
{
    int arreglo[5]={1,4,0,5,1}, res;
    res = producto(arreglo, 5);

    cout << res << endl;
    return 0;
}


int producto(int arreglo[], int tam)
{

    int i, valor = 1;

    for(i = 1; i<tam; i++)
    {
        if(arreglo[i] == 0)
            return valor;

        valor *= arreglo[i];

    }

    return valor;


}
