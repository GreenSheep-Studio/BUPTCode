#include<iostream>
using namespace std;
int main()
{
    int n, m = 0, x;
    int s[1001];
    int s1[1001];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = n - 1; j > i; j--){
            if(s[j] < s[i]){
                x = s[i];
                s[i] = s[j];
                s[j] = x;
            }
        } 
    }
    s1[0] = s[0];
    for (int i = 1; i < n; i++){
        if(s[i] != s1[m]){
            s1[m + 1] = s[i];
            m++; 
        }
    }
    cout << m + 1 << endl;
    for (int i = 0; i < m + 1; i++){
        cout << s1[i] << " ";
    }
    return 0;
}