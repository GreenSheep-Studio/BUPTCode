#include <bits/stdc++.h>
using namespace std;

void change(char A[100000000], int a[100000000])
{
    int l = strlen(A);
    for (int i = 0; i < l; i++){
        a[l - i - 1] = A[i] - '0';
    }
}

int main()
{
    int a[100000000] = {0};
    int b[100000000] = {0};
    char A[100000000] = {0};
    char B[100000000] = {0};
    cin >> A >> B;
    change(A, a);
    change(B, b);
    int c[1000000] = {0};
    int L, la, lb;
    L = max(la, lb);
    int k = 0;
    for (int i = 0; i < la; i++)
    {
        for (int j = 0; j < lb; j++)
        {
            c[k] = 
        }
        
    }
    
}