#include <iostream>

using namespace std;

int cuentaArreglo(int arreglo[], int tam, int numero, int veces);

int main()
{
    int arreglo[8] = {1,1,1,1,1,1,1,1};
    int numero, res, veces = 0;

    cout << "\nDame el numero para ver cuantas veces se repite: ";
    cin >> numero;
    res = cuentaArreglo(arreglo, 8, numero, veces);
    cout << endl << res;

    return 0;
}

int cuentaArreglo(int arreglo[], int tam, int numero, int veces)
{
    cout << "entra\n";


    if(arreglo[tam] == numero)
    {
        cout << "\nentra a if para evaluar";
        veces++;
        cout << veces;
    }


    if(tam  == 0)
    {
        cout << "\nentra a if para terminar";
        return veces;
    }





    cuentaArreglo(arreglo, tam-1, numero, veces);

}
