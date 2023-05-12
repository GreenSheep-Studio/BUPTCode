#include<bits/stdc++.h>
using namespace std;
int main ()
{
    double s = 0;
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        s = sqrt(s + i);
    }
    cout << s <<endl;
    system ("PAUSE");
    return 0;
}