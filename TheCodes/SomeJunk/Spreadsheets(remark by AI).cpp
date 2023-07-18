#include <iostream>
#include <cstring>
using namespace std;

struct Position{
    string Pos;
};

int ExpN(int x, int n){
    int Ep = 1;
    for (int i = 0; i < n; i++)
        Ep *= x;
    return Ep;
}

void Translate(string Poss){
    bool Sign = 0;
    if(Poss[0] == 'R'){
        for(int i = 1; Poss[i]; i++){
            if (Poss[i] == 'C' && Poss[i - 1] >= '0' && Poss[i - 1] <= '9'){
                Sign = 1;
                break;
            }
        }
    }

    if (Sign == 0) {
        int Y[10000] = {0};
        int l = 0;
        int y = 0;
        int x = 0;
        int k = 0;
        cout << "R";
        for (int i = 0; Poss[i] ; i++){
            if (Poss[i] >= 'A' && Poss[i] <= 'Z'){
                Y[i] = Poss[i] - 'A' + 1;
                l = i;
            }
            else if (Poss[i] >= '0' && Poss[i] <= '9'){
                cout << Poss[i];
            }
        }
        cout << "C";
        for (int i = l; i >= 0; i--){
            y += Y[i] * ExpN(26, k);
            k++;
        }
        cout << y;
    }
    else if (Sign == 1){
        int X1 = 0;
        char y1[10000] = {0};
        int Y1 = 0;
        int k = 0;
        int s = 0;
        char pos[10000] = {0};
        int l = Poss.length(); // Use the length function instead of strlen for string objects
        for (int i = 0; i < l; i++){
            pos[i] = Poss[i];
        }
        for (int i = l - 1; pos[i] != 'C'; i--){ // This is the after number
            Y1 += (pos[i] - '0') * ExpN(10, k);
            k++;
            l = i - 1;
        }
        k = 0;
        for (int i = l - 1; pos[i] != 'R'; i--){ // This is the front number also the same number
            X1 += (pos[i] - '0') * ExpN(10, k);
            k++;
        }
        while (Y1){ // This is the letter number
            if (Y1 % 26 > 0) {
                y1[s] = (Y1 % 26) - 1 + 'A';
                Y1 = Y1 / 26;
            }
            else if (Y1 % 26 == 0){
                 y1[s] = 'Z';
                 Y1 = (Y1 / 26) - 1;
            }
            s++;
        }
        for (int i = s - 1; i >= 0; i--){
            cout << y1[i];
        }
        cout << X1; // This is the same number
    }
}

int main(){
    int n;
    Position Pos[10000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> Pos[i].Pos;
    }
    for (int i = 0; i < n; i++){
        Translate(Pos[i].Pos);
        cout << endl;
    }
    system("PAUSE");
    return 0;
}
