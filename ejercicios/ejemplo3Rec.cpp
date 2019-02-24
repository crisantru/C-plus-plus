#include <iostream>

using namespace std;

int contar(int x);

int main()
{
    cout << contar(511) << "\n";

    return 0;
}

int contar(int x)
{
    if(x == 0)
    {
        return 0;
    }

    int div = x / 10;
    return 1 + contar(div);

}
