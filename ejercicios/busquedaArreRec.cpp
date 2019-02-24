#include <iostream>
using namespace std;

int numElemento(int arreglo[], int tam, int num, int res);
void imprimirArreglo(int arreglo[], int tam);

int main()
{
    int tam, i, num, res = 0;

    cout << "Dame el tamaño de tu arreglo: ";
    cin >> tam;
    int arreglo[tam];

    for(i = 0; i < tam; i++)
    {
        cout << "Dame el numero a insertar en la posicion " << i << ": ";
        cin >> arreglo[i];
    }

    imprimirArreglo(arreglo, tam);
    cout << "\nQue elemento deseas a buscar: ";
    cin >> num;
    res = numElemento(arreglo, tam, num, res);

    if(res == 0)
    cout << "No se encuentra el valor solicitado en tu arreglo";
    cout << "\nEl valor se repite en tu arreglo " << res << " veces";

    return 0;
}

int numElemento(int arreglo[], int tam, int num, int res)
{

    if(arreglo[tam - 1] == num)
        res++;

    if(tam == 0)
        return res;

    return numElemento(arreglo, tam-1, num, res);
}

void imprimirArreglo(int arreglo[], int tam)
{
    int i;

    cout << "\nArreglo" << endl;

    for(i = 0; i < tam; i++)
        cout << arreglo[i] << " ";
}
