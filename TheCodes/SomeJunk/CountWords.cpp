#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
    char a[1001] = {0};
    int Cap = 0, Num = 0, Els = 0, Sum = 0, Wod = 0;
    cin.get(a,1001);
    for (int i = 0;a[i] != '\000';i++){
        if(a[i] >= 'A' && a[i] <= 'Z') Cap++;
        else if(a[i] >= 'a' && a[i] <= 'z') Wod++;
        else if(a[i] >= '0' && a[i] <= '9') Num++;
        else Els++;
        Sum++;
    }
    cout << Cap << '\n' << Wod << '\n' << Num << '\n' << Els << '\n' << Sum << endl;
    return 0;
}