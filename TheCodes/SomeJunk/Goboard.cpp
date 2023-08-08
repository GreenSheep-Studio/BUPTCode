#include <iostream>
#include <cstring>
using namespace std;

char MAP[21][21];
int Map_I[21][21];

void SetGame() {
    for (int i = 0; i < 21; i++){
        for (int j = 0; j < 21; j++){
            MAP[i][j] = 0;
            Map_I[i][j] = 0;
        }
    }
    Map_I[10][10] = 2;
}

void ShowGame() {
    for (int i = 1; i <= 19; i++){
        for (int j = 1; j <= 19; j++){
            if (Map_I[i][j] == 0) MAP[i][j] = '. ';
            else if (Map_I[i][j] == -1) MAP[i][j] = 'O ';
            else if (Map_I[i][j] == 1) MAP[i][j] = '@ ';
            else if (Map_I[i][j] == 2) MAP[i][j] = '+ ';
            cout << MAP[i][j];
        }
        cout << endl;
    }
}

int main (){
    SetGame();
    ShowGame();
    system("PAUSE");
    return 0;
}
