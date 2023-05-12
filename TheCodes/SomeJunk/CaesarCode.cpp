#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
    char a[1001]  ={ 0 };
    int n = 0;
    cin.get(a,1001);
    n = a[0] -'0';
    for (int i = 1; a[i] != '\000'; i++){
        if (a[i] >= 'A' && a[i] <='Z'){
            if ((a[i] - n) >= 'A' && (a[i] - n)  <='Z'){
                a[i] -= n;
            }
            else if ((a[i] - n ) < 'A'){
                a[i] = a[i] - n -'A' + 'Z' + 1;
            }
        }
        cout << a[i];
    }
    return 0;
}