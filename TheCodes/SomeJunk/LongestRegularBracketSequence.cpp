#include <iostream>
#include <cstring>
using namespace std;

int Count(string s) {
    int n = 0;
    char stack[1000];
    int top = 1;
    for(int i = 0; s[i] ;i++)
    {
        stack[top] = s[i];
        if(stack[top] == ')') {
            if(stack[top - 1] == '(') {
                stack[top--] = 0;
                stack[top] = 0;
                n++;
            }
            else if (stack[top] == ')') top++;
        }
        else if (stack[top] == '(') top++;
    }
    return n;
}

int LongestLength(string s) {
     
}

int main ()
{
    string s;
    cin >> s;
    cout << Count(s) << endl;
    system("PAUSE");
    return 0;
}