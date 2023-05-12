#include <bits/stdc++.h>
using namespace std;

int a[1001] = {0};
int N = 0;
bool b[1001], c[2002], d[2002];

void Queen(int i,int n){
    for (int j = 0; j < n; j++){      //从第0个位置开始遍历
        if (b[j] && c [i + j] && d[i - j + n - 1]){     //判断该位置是否能放置皇后
            a[i] = j;
            b[j] = false;
            c[i + j] = false;
            d[i - j + n - 1] = false;       //放置皇后，将相关位置设置为不可放置
            if (i < n - 1) Queen(i + 1, n);    //判断是否将所有皇后放完，未放完放置下一个皇后
            else
                N++;              //所有皇后放完，解法加一
            b[j] = true;
            c[i + j] = true;
            d[i - j + n - 1] = true;     //将上一个节点回溯为未放置，进行下一个位置情况的放置
        }
    }
}

int main ()
{
    int n;
    cin >> n;              //输入要解决的问题的皇后数
    for (int i = 0; i < n; i++)
        b[i] = true;
    for (int i = 0; i < 2 * n; i++){
        c[i] = true;
        d[i] = true;
    }                      //对标记数组进行初始化
    Queen(0, n);
    cout << N <<endl;
    system("PAUSE");
    return 0;
}