#include <iostream>

using namespace std;

void imprimeRec(int i);

int main()
{
    imprimeRec(90);

    return 0;
}

void imprimeRec(int i)
{
    if(i < 100)
        imprimeRec(i+1);

    cout << i << "\n";
}
