#include <bits/stdc++.h>
using namespace std;

void Bubble(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                int t;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }     
    }
}

void Select(int a[], int n) {
    int t;
    int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        t = a[min];
        a[min] = a[i];
        a[i] = t;   
    }
}

void Insert(int a[], int n) {
    int key, t;
    for (int i = 1; i < n; i++) {
        key = i;
        t = a[i];
        for (int j = i - 1; (j >= 0) && (a[j] > t); j--) {
            a[j + 1] = a[j];
            key = j;
        }
        a[key] = t;
    } 
}

void Quick(int a[], int n, int L, int R) {
    int p;
    p = L;
    int key = a[p];
    while (L != R) {
        if (a[R] < a[p]){ 
            a[L] = a[R];
            L++;
        }
        else if (a[R] > a[p]) R--;
        if (a[L] > a[p]) {
            a[R] = a[L];
            R--;
        }
        else if (a[L] < a[p]) L++;
    }
    a[L] = key;
    Quick(a, n, 0, L);
    Quick(a, n, L, n - 1);
}

int compare(const void *a, const void *b){
    return (*(int*)a -*(int*)b);
}

int main ()
{
    int a[5] = {3, 5, 8, 1, 6};
    Bubble(a, 5);
    //unique()
    //qsort(a, 5, sizeof(int), compare);
    //Select(a, 5);
    //Insert(a, 5);
    //Quick(a, 5, 0, 4);
    for (int i = 0; i < 5; i++) cout << a[i] << " ";
    cout << endl;
    system("PAUSE");
    return 0;
}