#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    char cadena1[6] = "hola";       //declaracion string en c++
    char cadena2[16];

    strcpy(cadena2, cadena1);

    cout << cadena2 << endl;

    return 0;

}
