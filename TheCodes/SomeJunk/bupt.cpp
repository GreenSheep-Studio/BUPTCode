#include <iostream>
using namespace std;
int main()
{
    char c[20];
    int n;
    int x = 0;
    cin >> n;
    cin >> c;
    for (int  i = 0;; i++){ 
        if (c[i] >= 'A' && c[i] <= 'Z'){
            c[i] += n;
            if (c[i] > 'Z'){
                c[i] -= 26;
            }
            
            x++;
        }
        else if(c[i] == 0) break;
        else{
            c[i] += 0;
            x++;
        }
    }
    for (int  i = 0; i < x; i++){
        cout << c[i];
    }
    return 0;
}