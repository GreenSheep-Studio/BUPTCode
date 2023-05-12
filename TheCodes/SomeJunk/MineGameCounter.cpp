#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    int n = 0;
    int m = 0;
    char a[103][103] = {0};
    char b[100][100] = {0};
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[i][j] = '0';
        }
    }
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            if (a[i][j] != '*'){
                for (int p = i - 1; p <= i + 1; p++){ 
                    for(int q = j - 1; q <= j + 1; q++){
                        if(a[p][q] == '*') b[i - 1][j - 1]++;
                    }
                }
            }
            else if(a[i][j] == '*') b[i - 1][j - 1] = '*';
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << b[i][j];
        }
        cout << endl;
    }
    system("PAUSE");
    return 0;
}