#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int p = 0;
    int L = 0;
    string s;
    while (getline(cin, s))
    {
        if(s[0] == '+') p++;
        else{
            if (s[0] == '-') p--;
            else {
                L += p*(s.length() - s.find(':') - 1);
            }
        }
        
    }
    cout << L << endl;
    return 0;
}