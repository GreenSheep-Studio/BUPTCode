#include <bits/stdc++.h>
#include <cstring>
using namespace std;
void Change (char a[1000],int b[1000])
{
	int l;
	l = strlen (a);
	for(int i = 0;i < l;i++){
		b[l - i - 1] = a[i] - '0';
	}
}

int main ()
{
    int a[1000] = {0};
    int b[1000] = {0};
    char A[1000] = {0};
    char B[1000] = {0};
    int c[1002] = {0};
    cin >> A >> B;
    int la, lb;
    la = strlen(A);
    lb = strlen(B);
    int l;
    l = max(la, lb);
    Change(A, a);
    Change(B, b);
    for (int i = 0; i < l + 1; i++){
        c[i] += (a[i] + b[i]);
        if (c[i] >= 10){
            c[i] -= 10;
            c[i + 1]++;
        } 
    }
    if (c[l] == 0){
        for (int i = l - 1; i >= 0; i--){
            cout << c[i];
        }
    }
    else if (c[l] != 0){
        for (int i = l; i >= 0; i--){
            cout << c[i];
        }
    }
    system("PAUSE");
    return 0;    
}