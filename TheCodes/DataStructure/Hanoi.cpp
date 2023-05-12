#include <bits/stdc++.h>
using namespace std;

int Hanoi(int n)
{
    if (n == 1) return 1;
    else if (n > 1) return (1 + 2*Hanoi(n - 1));
}

int main ()
{
    int n;
    cin >> n;
    cout << Hanoi(n) << endl;
    system("PAUSE");
    return 0;
}