#include <iostream>
#include <algorithm>
using namespace std;

void Bubble(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void Select(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void Insert(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void Quick(int a[], int L, int R) {
    if (L >= R) {
        return;
    }
    int pivot = a[L];
    int i = L, j = R;
    while (i < j) {
        while (i < j && a[j] >= pivot) {
            j--;
        }
        a[i] = a[j];
        while (i < j && a[i] <= pivot) {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = pivot;
    Quick(a, L, i - 1);
    Quick(a, i + 1, R);
}

int main() {
    int a[5] = {3, 5, 8, 1, 6};
    // Bubble(a, 5);
    // Select(a, 5);
    // Insert(a, 5);
    Quick(a, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    system("PAUSE");
    return 0;
}
