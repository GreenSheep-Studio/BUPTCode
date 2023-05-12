#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    char Ltr;
    int Frq;
    int Pare;
    int Lch;
    int Rch;
}Node, *HuffmanTree;

void CreateTree(HuffmanTree a, int n){
    int m = 2 * n - 1;
    a = new Node[m + 1];
    for (int i = 1; i <= m; ++i){
        a[i].Rch = 0; a[i].Lch = 0; a[i].Pare = 0;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i].Frq;
    int s1, s2;
    for (int i = n + 1, i <= m, i++){
        Select(a, i - 1, s1, s2);
        a[s1].Pare = a[s2].Pare = i;
        a[i].Lch = s1;
        a[i].Rch = s2;
        a[i].Frq = a[s1].Frq + a[s2].Frq;
    }
}

void Select(HuffmanTree a, int n, int &s1, int &s2){
    for (int i = 0; i < n; i++){
        if(a[i].Pare == 0){
            s1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i].Pare == 0 && a[s1].Frq > a[i].Frq) s1 =i;
    }
    for (int j = 0; j < n; j++){
        if(a[j].Pare == 0){
            s2 = j;
            break;
        }
    }
    for (int j = 0; j < n; j++){
        if (a[j].Pare == 0 && a[s2].Frq > a[j].Frq && j != s1) s2 =j;
    }
}

void Count(char a[], int &n, int b[]){
    for (int i = 1; a[i] != '0'; i++)
    {
        
    }
    
}

int main()
{
    char Stn[1001] ={0};
    cin.get(a,1001);

}