#include <iostream>
#include <cstring>
using namespace std;

int map_I[5][5] = {0};


bool WinIf(int x, int y) { 
    int Line, List, CrosX, CrosY;
    Line = List = CrosX = CrosY = 1;
    for (int i = x + 1; map_I[i][y] == map_I[x][y]; i++) 
        Line++;
    for (int i = x - 1; map_I[i][y] == map_I[x][y]; i--) 
        Line++;

    for (int i = y + 1; map_I[x][i] == map_I[x][y]; i++) 
        List++;
    for (int i = y - 1; map_I[x][i] == map_I[x][y]; i--) 
        List++;

    for (int i = x + 1, j = y + 1; map_I[i][j] == map_I[x][y]; i++, j++) 
        CrosX++;
    for (int i = x - 1, j = y - 1; map_I[i][j] == map_I[x][y]; i--, j--) 
        CrosX++;
    
    for (int i = x + 1, j = y - 1; map_I[i][j] == map_I[x][y]; i++, j--) 
        CrosY++;
    for (int i = x - 1, j = y + 1; map_I[i][j] == map_I[x][y]; i--, j++) 
        CrosY++;
    
    if (Line == 3 || List == 3 || CrosX == 3 || CrosY == 3) return 1;
    else return 0;
}


int main ()
{
    char map[5][5];
    for (int i = 0; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            map[i][j] = 0;
        }
    }
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            cin >> map[i][j];
        }
    }
    for (int i = 0; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            if (map[i][j] == 0 || map[i][j] == '.') map_I[i][j] = 0;
            else if (map[i][j] == 'X') map_I[i][j] = -1;
            else if (map[i][j] == '0') map_I[i][j] = 1;
        }
    }
    int A = 0;
    int B = 0;
    int Space = 0;
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            if (map_I[i][j] == -1) A++;
            else if (map_I[i][j] == 1) B++;
            else if (map_I[i][j] == 0) Space++;
        }
    }
    
    if (Space == 0) {
        if (abs(A - B) >= 2 || (B - A) == 1) {
            cout << "illegal";
            return 0;
        }
        else if (abs(A - B) == 0) {
            for (int i = 1; i <= 3; i++) {
                for (int j = 1; j <= 3; j++) {
                    if (map_I[i][j] == -1){
                        if (WinIf(i, j)) {
                            cout << "the first player won";
                            return 0;
                        }
                    } 
                    else if (map_I[i][j] == 1){
                        if (WinIf(i, j)) {
                            cout << "the second player won";
                            return 0;
                        }
                    }
                }
            }
            cout << "draw";
            return 0;
        }
        else if (A - B == 1) {
            for (int i = 1; i <= 3; i++)
            {
                for (int j = 1; j <= 3; j++) {
                    if (map_I[i][j] == -1) {
                        if (WinIf(i, j)) {
                            cout << "the first player won";
                            return 0;
                        }
                    }                    
                    else if (map_I[i][j] == 1) {
                        if (WinIf(i, j)) {
                            cout << "the second player won";
                            return 0;
                        }
                    }
                }
            }
            cout << "draw";
            return 0;
        }
    }

    else if (Space != 0) {
        if (abs(A - B) >= 2 || (B - A) == 1) {
            cout << "illegal";
            return 0;
        }
        else if (abs(A - B) == 0) {
            for (int i = 1; i <= 3; i++) {
                for (int j = 1; j <= 3; j++) {
                    if (map_I[i][j] == -1){
                        if (WinIf(i, j)) {
                            cout << "illegal";
                            return 0;
                        }
                    } 
                    else if (map_I[i][j] == 1){
                        if (WinIf(i, j)) {
                            for (int p = 1; p <= 3; p++){
                                for (int q = 1; q <= 3; q++){
                                    if (map_I[p][q] == -1 && WinIf(p, q)) {
                                        cout << "illegal";
                                        return 0;
                                    }
                                }
                            }
                            cout << "the second player won";
                            return 0;
                        }
                    }
                }
            }
            cout << "first";
            return 0;
        }
        else if (A - B == 1) {
            for (int i = 1; i <= 3; i++) {
                for (int j = 1; j <= 3; j++) {
                    if (map_I[i][j] == -1){
                        if (WinIf(i, j)) {
                            for (int p = 1; p <= 3; p++){
                                for (int q = 1; q <= 3; q++){
                                    if (map_I[p][q] == 1 && WinIf(p, q)) {
                                        cout << "illegal";
                                        return 0;
                                    }
                                }
                            }
                            cout << "the first player won";
                            return 0;
                        }
                    } 
                    else if (map_I[i][j] == 1){
                        if (WinIf(i, j)) {
                            cout << "illegal";
                            return 0;
                        }
                    }
                }
            }
            cout << "second";
            return 0;
        }
    }
}