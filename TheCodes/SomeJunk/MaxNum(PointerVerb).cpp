#include<iostream>
using namespace std;
void search(int *pa,int n,int *pmax){
    int pflag;
    for (int i = 0; i < n; i++){
        if(*pa > *pmax) *pmax = *pa, pflag = i + 1;
        ++pa;
    }
    cout << *pmax <<endl;
    cout << pflag <<endl;
}
int main ()
{
    int a[1001] = {0};
    //int num = 0;
    //cin >> num;
    for (int  i = 0; i< 10; i++){
        cin >> a[i];
    }
    search(a, 10, a);
    system("PAUSE");
    return 0;
}