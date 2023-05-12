#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    int x = 0;
    int a[100001];
    cin >> n;
    for (int i = 0; ; i++)
    {
        a[i] = n; 
        x++;
        if(n % 2 == 1 &&n != 1){
            n = n * 3 + 1;
        }
        else if(n % 2 == 0){
            n /= 2;
        }
        else if (n == 1) break;
    }
    for (int i = x - 1; i >= 0; i--)
    {
        cout <<a[i] <<" ";
    }
    system("PAUSE");
    return 0;
}