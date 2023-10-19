#include <bits/stdc++.h>
using namespace std;
int main ()
{
    float a[18][2] = {0};
    float b[18] = {0};

    for (int i = 0; i < 18; i++)
    {
        cin >> a[i][0] >> a[i][1];  
        b[i] = a[i][0] * a[i][1] * a[i][1] / 1000 / 1000;
    }
    
    for (int i = 0; i < 18; i++)
    {
        cout << b[i] << endl; 
    }
    system("pause");
    return 0;
}