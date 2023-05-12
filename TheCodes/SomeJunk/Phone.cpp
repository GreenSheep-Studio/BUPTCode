#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int phone (char a){
    if(a == 'a' || a == 'd' || a == 'g' || a == 'j' || a == 'm' || a == 'p' || a == 't' || a == 'w') return 1;
    else if(a == 'b' || a == 'e' || a == 'h' || a == 'k' || a == 'n' || a == 'q' || a == 'u' || a == 'x') return 2;
    else if(a == 'c' || a == 'f' || a == 'i' || a == 'l' || a == 'o' || a == 'r' || a == 'v' || a == 'y') return 3;
    else if(a == 's' || a == 'z') return 4;
    else if(a == ' ') return 1;
}
int main ()
{
    int sum = 0;
    char str[201];
    char x;
    int y;
    int l = 0;
    while (1){
        str[l] = getchar();
        l++; 
        if(str[l] == '\n') break;
    }
    for (int i = 0; i < l; i++)
    {
        y = phone(str[i]);
        sum += y;
    }
    cout << sum <<endl;
    system("PAUSE");
    return 0;
}