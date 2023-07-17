#include <iostream>
#include <cstring>
using namespace std;

struct Arr {
    int n;
    int a[10001];
    bool Good;
};

bool Goodif(Arr x) {
    int sum = 0;
    int mut = 1;
    for (int i = 0; i < x.n; i++){
        sum += x.a[i];
        mut *= x.a[i]; 
    }
    if (sum >= 0 && mut == 1) return true;
    else return false;
}

int Count(Arr x) {
    int sum = 0;
    int mut = 1;
    for (int i = 0; i < x.n; i++){
        sum += x.a[i]; 
        mut *= x.a[i];     
    }
    if (x.Good == true) return 0;
    else {
        if (sum >= 0 && mut == -1) return 1;
        else if (sum < 0 && mut == 1) {
            if (-sum == 1) return 2;
            else if ((-sum / 2) % 2 == 0) return -sum / 2;
            else if ((-sum / 2) % 2 == 1) {
                if ((-sum) < x.n) return -sum / 2 + 1;
                else if ((-sum) == x.n) return -sum;
            } 
        }
        else if (sum < 0 && mut == -1) {
            if ((-sum) == )  
            else if ((-sum / 2) % 2 == 0) return -sum / 2 + 1;
            else if ((-sum / 2) % 2 == 1) {
                if ((-sum) < x.n) return -sum / 2;
                else if ((-sum) == x.n) return -sum;
            }  
        }
    }
}

int main()
{
    int t;
    cin >> t;
    Arr T[t];
    for (int i = 0; i < t; i++){
        cin >> T[i].n;
        for (int j = 0; j < T[i].n; j++){
            cin >> T[i].a[j];
        }
        T[i].Good = Goodif(T[i]);
    }
    for (int i = 0; i < t; i++){
        cout << Count(T[i]) << endl;
    }
    system("PASUE");
    return 0;
}