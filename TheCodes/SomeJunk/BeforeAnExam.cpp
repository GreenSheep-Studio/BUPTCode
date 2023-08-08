#include <iostream>
using namespace std;

struct Schedule {
    int MinTime;
    int MaxTime;
};

bool CompareIf(Schedule A[], int n, int sum) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += A[i].MaxTime;
    if (s >= sum) {
        cout << "YES" << endl;
        return 1;
    }
    else {
        cout << "NO" << endl;
        return 0;
    }   
}

void PrintTab(Schedule A[], int n, int sum) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += A[i].MaxTime;
        if (s <= sum) cout << A[i].MaxTime << " ";
        else if (s > sum) {
            for (int j = A[i].MaxTime - 1; j >= A[i].MinTime; j--) {
                s--;
                if (s == sum) 
                    cout << j << endl;
                    break;
            }
        }
    }
}

int main ()
{
    Schedule TimeTab[50];
    int day;
    int sum;
    bool P;
    cin >> day >> sum;
    for (int i = 0; i < day; i++)
        cin >> TimeTab[i].MinTime >> TimeTab[i].MaxTime;
    if (day == 1) {
        for (int i = TimeTab[0].MinTime; i <= TimeTab[0].MaxTime; i++) {
            if (i == sum) {
                cout << "YES" << endl;
                cout << i;
                return 0;
            }
        }
        cout << "NO";
        return 0;
    }
    else if (day > 1) {
        bool T = CompareIf(TimeTab, day, sum);
        if(T) {
            PrintTab(TimeTab, day, sum);
        }
    }
    return 0;
}