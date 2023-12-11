#include <bits/stdc++.h>
int main ()
{
    int List[1000000] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> List[i];
    sort(List, List + n);
    n = unique(List, n) - List;
    for (int i = 0; i < n; i++) cout << List[i] << " ";
}