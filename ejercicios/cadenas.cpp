#include <iostream>

using namespace std;

int len(char* cad){

    int res = 0;
    char aux = cad[0];

    while(aux != '\0'){
        aux = cad[res];
        res++;
    }

    return res;
}

int main(){

    char cadena[] = "hola";
    cout << len(cadena);

    return 0;

}
