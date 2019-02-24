#include<iostream>
using namespace std;

int** marcoMatriz(int* columnas, int* filas);
void imprimirMatriz(int **pp, int* columnas, int* filas);

int main()
{
    int* columnas;
    int* filas;
    int tam1, tam2;

    cout << "Dimension de la matriz" << "\n";
    cout << "Dame el numero de columnas: ";
    cin >> tam2;
    cout << "Dame el numero de filas: ";
    cin >> tam1;

    columnas = &tam1;
    filas = &tam2;

    marcoMatriz(columnas, filas);

    return 0;
}

int** marcoMatriz(int* columnas, int* filas)
{
    int i,j;

    int **pp = new int* [*columnas];

    for(i = 0; i <= *columnas; i++)
    {
        pp[i] = new int [*filas];

    }

    for(i = 0; i <= *columnas; i++)
    {
        for(j = 0; j<= *filas; j++)
        {
            pp[i][j] = 1;

            /*if(i == 0 || j == 0 || i == (*columnas - 1) || j == (*columnas -1))
                pp[i][j] = 0;
            else
                pp[i][j] = 1;*/

            if((i == 0 || j == 0) || (i == (*columnas - 1) || j == (*columnas -1)))
                pp[i][j] = 0;
        }

    }

    imprimirMatriz(pp, columnas, filas);

    return pp;
}

void imprimirMatriz(int **pp, int* columnas, int* filas)
{
    int i, j;

    for(i = 0; i < *columnas; i++)
    {
        for(j = 0; j < *filas; j++)
        {
            cout << pp[i][j] << " ";
        }
        cout << "\n";
    }

}
