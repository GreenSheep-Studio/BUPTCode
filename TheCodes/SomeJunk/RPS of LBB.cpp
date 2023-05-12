#include <bits/stdc++.h>
using namespace std;

int WinIF(int a,int b){
    int c = a - b;
    if (c == 0) return 0;
    else if (c > 0){
        if (a != 4){
            if (c == 1) return -1;
            else if (c == 2 || c == 3) return 1;
        }
        else if (a == 4){
            if (c == 1 || c == 2) return 1;
            else if (c == 3 || c == 4) return -1; 
        }
    }
    else if (c < 0){
        if (b != 4){
            if (c == -1) return 1;
            else if (c == -2 || c == -3) return -1;
        }
        else if (b == 4){
            if (c == -1 || c == -2) return -1;
            else if (c == -3 || c == -4) return 1; 
        }
    }
}

int main ()
{
    int N, Nx[2];
    int A, B;
    int tab[2][200] = {0};
    int game[2][200] = {0};
    cin >> N >> Nx[0] >> Nx[1];   
    for (int i = 0; i < Nx[0]; i++){
        cin >> tab[0][i];
    }
    for (int i = 0; i < Nx[1]; i++){
        cin >> tab[1][i];
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0, p = 0; j < N;j++){
            game[i][j] = tab[i][p];
            p++;
            if (p == Nx[i]) p = 0;
        }
    }
    int key = 0;
    A = 0;
    B = 0;
    for (int i = 0; i < N; i++){
        key = WinIF(game[0][i], game[1][i]);
        if (key == -1) A++;
        else if (key == 1) B++;
    }
    cout << A << " " << B << endl;
    system("PAUSE");
    return 0;
}