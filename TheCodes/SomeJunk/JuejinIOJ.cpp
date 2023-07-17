#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int nums[], int l = 0) {
        int SumF = 0;
        int SuMaxF = -10000000;
        int SumB = 0;
        int SuMaxB = -10000000;
        int Sum = 0;
        int B = 0;
        int F = 0;
        for (int  i = 0; i < l; i++){
            SumF += nums[i];
            if (SumF > SuMaxF) {
                SuMaxF = SumF;
                B = i;
            }
        }
        for (int  i = l - 1; i >= 0; i--){
            SumB += nums[i];
            if (SumB > SuMaxB) {
                SuMaxB = SumB;
                F = i;
            }
        }
        for (int i = F; i <= B; i++){
            Sum += nums[i];
        }
        return Sum;
    }
};

int main ()
{
    int num[] = {4,-3,5,-2,-1,2,6,-2};
    Solution a;
    cout << a.maxSubArray(num, sizeof(num)/sizeof(int));
    cout << endl;
    system("PAUSE");
    return 0;
}