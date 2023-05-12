#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
    char a[101] = {'0'}, b[101] = {'0'};
    cin >> a;
    int l = strlen(a);
    b[0] = a[1];
    b[l - 1] = a[0];
    for(int i = 1; i < l - 1 ;i++){
        b[i] = a[i + 1];
    }
    cout << b;
    return 0;
}