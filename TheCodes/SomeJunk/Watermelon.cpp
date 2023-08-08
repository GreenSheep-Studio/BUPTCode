#include <iostream>
using namespace std;

bool IFen(int x){
    if (x <= 2) return 0;
    else if (x > 2) {
        if (x % 2 == 0) return 1;
        else return 0;
    }
}

int main (){
    int x;
    cin >> x;
    if (IFen(x)) cout << "YES";
    else cout << "NO";
    system("PAUSE");
    return 0;
}