#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int s[100];
    int n = 0, x, m = 0;
    int s1[n];
    for (int i = 0; i <= 4; i++){
        for (int j = 0; j <= 3; j++){
            s[n] = 3 * i + 5 * j;
            n++;
        }  
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; i < j; j--){
            if(s[j] > s[j - 1]){
                x = s[j];
                s[j] = s[j - 1];
                s[j - 1] = x;
            }
        }
        
    }
    for (int i = 1, j = 0; i < n; i++){
        if(s1[m] != s[i]){
            s1[m + 1] = s[i];
            m++;
        }
    }
    cout << m;
    system("PAUSE");
    return 0;
}