#include <bits/stdc++.h>
using namespace std;
int arr[10] = {1, 11, 85, 64, 12, 7, 45, 31, 21, 50};

int cmp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}

void SortAndShow(int arr[], int n){
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int OrderSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++){
        if (arr[i] == key) return i;
    }
    return -1;
}

int main ()
{
    int x;
    cin >> x;
    SortAndShow(arr, 10);
    cout << OrderSearch(arr, 10, x) << endl;
    system("PAUSE");
    return 0;
}