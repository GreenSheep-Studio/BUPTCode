#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char* arr[5];
    char str[5][22] = { 0 };
    int num = 5;
    int n = 0;
    while (num--) {
        cin >> str[n];
        n++;
    }
    for (int i = 0; i < 5; i++) {
        arr[i] = (char*)str[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (*arr[j] > *arr[j + 1]) {
                char* t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; *arr[i] != '\000'; j++){
            cout << *arr[i];
            arr[i]++;
        }
        cout <<'\n';
    }
    return 0;
}