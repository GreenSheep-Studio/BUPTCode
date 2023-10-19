#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >>n;
	//cout << "您输入的是" << n << "阶行列式" << endl;
	int a[3][3];
	int b[4];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int y = 1; y < n-i; y++)
		{
			for (int x = i, b = a[i + y][i]; x < n; x++)
			{
				a[i + y][x]= (a[i + y][x] * a[i][i])- (a[i][x] * b);
			}
		}
		b[i] = pow(a[i][i], n-1-i);
	}
	int A=1;
	for (int i = 0; i < n; i++)
	{
		A *= a[i][i];
	}
	for (int i = 0; i < n-1; i++)
	{
		A /= b[i];
	}
	cout << A;
    system("PAUSE");
    return 0;
}