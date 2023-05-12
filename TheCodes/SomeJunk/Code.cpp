#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1){
        char a[10001];
        char b[10001];
        int c[10001];
        cin >> a >> b;
        int la = strlen(a);
        int lb = strlen(b);
        int x = 0;
        for (int i = lb - 1; i < la; i++){
            b[i] = b[i % lb];
        }
        for (int i = 0; i < la; i++){
        c[i] = b[i] - 'a';
        }
        for (int i = 0; i < la; i++){
            if (a[i] - c[i] >= 'a') a[i] = a[i] - c[i];
            else if (a[i] - c[i] < 'a') a[i] = a[i] - c[i] -6 + ('a'- 'A');
        }
        for (int  i = 0; i < la; i++){
            cout << a[i];
        }
        cout << endl;
    }
    system("PAUSE");
    return 0;
}