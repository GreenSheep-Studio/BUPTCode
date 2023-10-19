#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    //定义变量n，m
    int n = 0;
    int m = 0;
    //定义变量a，b
    char a[103][103] = {0};
    char b[100][100] = {0};
    //输入变量n，m
    cin >> n >> m;
    //输入变量a
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    //输入变量b
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[i][j] = '0';
        }
    }
    //遍历变量a
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            //如果变量a中的字符不为*
            if (a[i][j]!= '*'){
                //遍历变量a中的每一个字符
                for (int p = i - 1; p <= i + 1; p++){ 
                    for(int q = j - 1; q <= j + 1; q++){
                        //如果变量a中的字符为*
                        if(a[p][q] == '*') b[i - 1][j - 1]++;
                    }
                }
            }
            //如果变量a中的字符为*，则将变量b中的字符设置为*
            else if(a[i][j] == '*') b[i - 1][j - 1] = '*';
        }
    }
    //输出变量b
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << b[i][j];
        }
        cout << endl;
    }
    //结束程序
    system("PAUSE");
    return 0;
}