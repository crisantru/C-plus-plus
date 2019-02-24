/*
 * File:   main.cpp
 * Author: Vivie
 *
 * Created on 17 de mayo de 2016, 14:30
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;
/*Las siguientes funciones son el corazón del programa. La primera inserta los elementos de un array
de tal modo que queden como un montículo. La segunda elimina sucesivamente la raíz del montículo,
que ser el elemento más pesado*/

void insertamonticulo(int *A, int N) {
    /*Esta función inserta los elementos en un mont°culo representado como
    arreglo.*/
    int i, k, aux, band; /*Esta última variable es una bandera que se considera de tipo booleano*/
    for (i = 2; i <= N; i++) {
        k = i;
        band = 1; /*1 se considera como verdadero*/
        while (k > 1 && band == 1) {
            band = 0;
            if (A[k] > A[k / 2]) {
                aux = A[k / 2];
                A[k / 2] = A[k];
                A[k] = aux;
                k = k / 2; /*El propio lenguaje se encarga de adaptar la parte entera de este
    tipo de divisiones entre enteros*/
                band = 1;
            }
        }
    }
}

void eliminamonticulo(int *A, int N) {
    /*Esta función elimina la raíz del montículo en forma repetida.*/
    int i, aux, izq, der, k, ap, bandera, mayor;
    for (i = N; i > 1; i--) {
        aux = A[i];
        A[i] = A[1];
        izq = 2;
        der = 3;
        k = 1;
        bandera = 1; /*Si bandera es 1,  es  verdadero*/
        while (izq < i && bandera == 1) {
            mayor = A[izq];
            ap = izq;
            if (mayor < A[der] && der != i) {
                mayor = A[der];
                ap = der;
            }
            if (aux < mayor) {
                A[k] = A[ap];
                k = ap;
            } else
                bandera = 0;
            izq = k * 2;
            der = izq + 1;
        }
        A[k] = aux;
    }
}

int main() {
    int *array; /*Un vector dinámico*/
    int N;
    cout << "Introduce el número de datos enteros a ordenar: ";
    cin>>N;
    array = new int[N + 1]; /*El N+1 es por comodidad. Con eso de que en C++
	todos los arreglos empiezan desde 0 y el heapsort presupone que em-
	piezan desde 1, pues ignoro el elemento 0 del array y le aumento un
	elemento para dar cabida a un °ndice igual al n£mero de elementos*/
    int i;

    /*El siguiente ciclo pide al usuario los números de 1 a N*/
    for (i = 1; i <= N; i++) {
        cout << "Introduce el valor " << i << ": ";
        cin >> array[i];
    }

    /*Imprimo los números en el orden que dio el usuario*/
    printf("\nAntes de la funcion:\n");
    for (i = 1; i <= N; i++) {
        cout << array[i] << "\n";
    }

    /*A continuación llamo a la función que acomoda los números de tal
    manera que se respeten las condiciones de un montículo lineal*/
    insertamonticulo(array, N);

    printf("\nDespues de la funcion que inserta en el monticulo:\n");
    for (i = 1; i <= N; i++) {
        cout << array[i] << "\n";
    }

    /*Y finalmente, se acomodan los números luego de quitárseles sucesivamente la raiz del
    montículo*/
    eliminamonticulo(array, N);

    printf("\nDespues de la función que elimina el monticulo:\n");
    for (i = 1; i <= N; i++) {
        cout << array[i] << "\n";
    }

}

