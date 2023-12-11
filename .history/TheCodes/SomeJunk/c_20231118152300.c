#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int a[100] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    system("pause");
    return 0;
}