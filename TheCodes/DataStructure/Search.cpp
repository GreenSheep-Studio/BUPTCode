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
    return -2;
}

int BinarySearch(int arr[], int key, int left, int right) {
    int middle;
    if (left > right) return -2;
    else {
        middle = (left + right) / 2;
        if (arr[middle] == key) return middle;
        else if (arr[middle] > key) return BinarySearch (arr, key, left, middle - 1);
        else if (arr[middle] < key) return BinarySearch (arr, key, middle + 1, right);
    }
}

int main ()
{
    int x;
    cin >> x;
    SortAndShow(arr, 10);
    cout << OrderSearch(arr, 10, x) + 1 << endl;
    cout << BinarySearch(arr, x, 0, 9) + 1 <<endl;
    system("PAUSE");
    return 0;
}