#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arreglo[5];
    cout << "arreglo = " << static_cast<void*>(arreglo) << endl;
    cout << "arreglo = " << &arreglo << endl;
    cout << "&arreglo[0] = " << &arreglo[0];


    return 0;


}
