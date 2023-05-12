#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, m;
    int S[1000][1000];
    int s[1000][1000];
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < 4; j++){
            cin >> s[i][j];
        }
    }
    int x = 1;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            S[i][j] = x;
            x++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        /* code */
    }
    
}