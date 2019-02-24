#include<iostream>
#include<stdlib.h>
using namespace std;

int** matriz(int **pp);
void imprimirMatriz(int **pp);

int main()
{
    int i,j, number;
    int **pp = new int *[3];        //reservamos una direccion a enteros de tamaño 3
    srand (time(NULL));              //Inicializar semilla

    pp[0] = new int [3];            //filas
    pp[1] = new int [3];
    pp[2] = new int [3];

    number = rand() % 1000;

    cout << "Devuelve Matriz identidad" << endl;
    cout << "Matriz Inicial: " << endl;

    for(i = 0; i <= 2; i++)
    {

        for(j = 0; j <= 2; j++)
            pp[i][j] = number++;
    }

    imprimirMatriz(pp);
    matriz(pp);
    cout << "\nMatriz Identidad" << endl;
    imprimirMatriz(pp);
    return 0;
}

int** matriz(int **pp)
{
    int i, j;

    //cout << "entra funcion matriz ";

    for(i = 0; i <= 2; i++)
    {
        for(j = 0; j <= 2; j++)
        {
            pp[i][j] = 0;

            if(i == j)
            {
                pp[i][j] = 1;
            }

        }

    }

    return pp;

}


void imprimirMatriz(int **pp)
{
    int i, j;

    for(i = 0; i <= 2; i++)
    {
        for(j = 0; j <= 2; j++)
        {
            cout << pp[i][j] << " ";

        }

        cout << "\n";
    }

}
