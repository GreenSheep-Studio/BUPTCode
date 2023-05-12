#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a;
    int x = 0, y = 0, z =0;
    while(cin >> a)
    if (a > 0) x++;
    else if (a < 0) y++;
    else if (a == 0) z++;
    printf("%d, %d, %d", x ,y ,z);
    system ("PAUSE");
    return 0;
}