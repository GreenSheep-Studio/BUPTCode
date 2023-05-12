#include <bits/stdc++.h>
#include <cstring>
using namespace std;

char a[12][12] = {"*"};

void move(int x, int y, int *turn){
    if ((turn % 4) == 0){
        if (a[x + 2][y + 1] != "*"){
            char T;
            T = a[x + 2][y + 1];
            a[x + 2][y + 1] = a[x + 1][y + 1];
            a[x + 1][y + 1] = T;
        }
        else if (a[x + 2][y + 1] == "*"){
            turn++;
        }
    }
    else if ((turn % 4) == 1){
        if (a[x + 1][y + 2] != "*"){
            char T;
            T = a[x + 1][y + 2];
            a[x + 1][y + 2] = a[x + 1][y + 1];
            a[x + 1][y + 1] = T;
        }
        else if (a[x + 1][y + 2] == "*"){
            turn++;
        }
    }
    else if ((turn % 4) == 2){
        if (a[x][y + 1] != "*"){
            char T;
            T = a[x][y + 1];
            a[x][y + 1] = a[x + 1][y + 1];
            a[x + 1][y + 1] = T;
        }
        else if (a[x][y + 1] == "*"){
            turn++;
        }
    }
    else if ((turn % 4) == 3){
        if (a[x + 1][y] != "*"){
            char T;
            T = a[x+ 1][y];
            a[x + 1][y] = a[x + 1][y + 1];
            a[x + 1][y + 1] = T;
        }
        else if (a[x + 1][y] == "*"){
            turn++;
        }
    }
}

int main()
{
    for (int i = 1; i < 11; i++){
        for (int j = 1; j < 11; j++){
            cin >> a[i][j];
        }
    }
    int Cx, Cy;
    int Fx, Fy;

    for(int i = 1; i < 11, i++){
        for(int j = 1,j < 11, j++){
            if (a[i][j] == "C"){
                Cx = i;
                Cy = j;
            }
            else if (a[i][j] == "F"){
                Fx = i;
                Fy = j;
            }
        }
    }
    int Time = 0;
    int turn = 0;
    do
    {
        move(Cx, Cy, turn)
    } while (/* condition */);
    
    system("PAUSE");
    return 0;
}