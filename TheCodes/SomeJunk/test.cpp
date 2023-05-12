#include <bits/stdc++.h>
using namespace std;

void Swap(int * p1, int * p2){
    int *p;
    p = p1;
    p1 = p2; 
    p2 = p;
}

int main()
{
    int a, b;
    int *p1;
    int *p2;
    cin >> a >> b;
    p1 = &a;
    p2 = &b;
    Swap(p1, p2);
    cout << a << " " << b << endl;
    system("pause");
    return 0;
}