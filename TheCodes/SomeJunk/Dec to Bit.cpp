#include<iostream>
using namespace std;
int main ()
{
    int n;
    int i;
    int bit[100];
    cin >> n;
    for (i = 0;;i++){
        int x = 0;
        x = n / 2;
        bit[i] = n % 2;
        n = x;
        if (x == 1){
            bit[i + 1] = x;
            i++;
            break;
        }
    }
    for (int j = i; j >= 0; j--){
        cout << bit[j];
    }
    system("PAUSE");
    return 0;
}