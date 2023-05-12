#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main ()
{
	int n = 0;
	char a[100001] = {0};
	int W = 0;
	int L = 0;
	for (int i = 0;;i++){
		a[i] = getchar();
		n++;
		if(a[i] == '\n') i--, n--;
		else if(a[i] == 'E') break;
	}
	for (int i = 0; i < n; i++)
	{
		if(a[i] == 'W') W++;
		else if(a[i] == 'L') L++;
		if(W == 11 || L == 11){
			if(abs(W - L) >= 2){
				cout << W << ":" << L <<endl;
				W = L = 0;
			}
		}
		else if((W > 11 || L > 11) && abs(W - L) >= 2){
			cout << W << ":" << L << endl;
			W = L =0;
		}
	}
	cout << W << ":" << L << endl;
	cout << endl;
	W = L = 0;
	for (int i = 0; i < n; i++)
	{
		if(a[i] == 'W') W++;
		else if(a[i] == 'L') L++;
		if(W == 21 || L == 21){
			if(abs(W - L) >= 2){
				cout << W << ":" << L <<endl;
				W = L = 0;
			}
		}
		else if((W > 21 || L > 21) && abs(W - L) >= 2){
			cout << W << ":" << L << endl;
			W = L = 0;
		}
	}
	cout << W << ":" << L << endl;
	system("PAUSE");
	return 0;	
}