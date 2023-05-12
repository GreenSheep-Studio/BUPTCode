#include <iostream>
using namespace std;
template <class T>
T Inc(T n)
{
    return 1 + n;
}
int main()
{
    cout << Inc<double>(4) / 2;
    cout << Inc<int>(4) / 2;
    system("PAUSE");
    return 0;
}
