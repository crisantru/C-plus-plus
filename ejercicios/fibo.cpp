#include <iostream>

using namespace std;

long fibo(int n);

int main()
{
    int n, res = 0;

    cout << "dame tu numero: ";
    cin >> n;

    res = fibo(n);
    cout << res;

    return 0;
}


long fibo(int n)
{
    //cout << "entra a funcion n: " << n << endl;
    if(n == 0 || n == 1)    //if(n < 2)
        return n;

    return fibo(n - 1) + fibo(n - 2);
}
