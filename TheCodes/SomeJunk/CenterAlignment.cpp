#include <iostream>
#include <cstring>
using namespace std;

struct Sentence {
    string S;
    int L;
};

int main ()
{
    Sentence Snts[1000];
    string T;
    bool Stick = 0; // 0 = left; 1 = right;
    int MaxL = 0;
    int n = 0;
    while (getline(cin, T)){
        Snts[n].L = T.length();
        if(T.length() > MaxL) MaxL = T.length();
        Snts[n].S = T;
        n++;
    }
    for (int i = 0; i < MaxL + 2; i++) cout << "*";
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "*";
        int Head = (MaxL - Snts[i].L) / 2;
        if ((MaxL - Snts[i].L) % 2 == 0) {
            for (int j = 0; j < Head; j++) cout << " ";
            cout << Snts[i].S;
            for (int j = (Head + Snts[i].L) - 1; j < MaxL - 1; j++) cout <<" ";
            cout << "*" << endl; 
        }
        else if ((MaxL - Snts[i].L) % 2 != 0) {
            if (!Stick) {
                for (int j = 0; j < Head; j++) cout << " ";
                cout << Snts[i].S;
                for (int j = (Head + Snts[i].L) - 1; j < MaxL - 1; j++) cout <<" ";
                cout << "*" << endl;
                Stick = 1;
            }
            else if (Stick) {
                Head += 1;
                for (int j = 0; j < Head; j++) cout << " ";
                cout << Snts[i].S;
                for (int j = (Head + Snts[i].L) - 1; j < MaxL - 1; j++) cout <<" ";
                cout << "*" << endl;
                Stick = 0;
            }
        }
    }
    for (int i = 0; i < MaxL + 2; i++) cout << "*";
    system("PAUSE");
    return 0;
}