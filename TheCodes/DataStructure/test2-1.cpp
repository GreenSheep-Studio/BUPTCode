#include <iostream>
using namespace std;
template <class T, int N>
class A
{
	T x[N];
public:
	void input ();//声明
	void output();	
};
template <class T, int N>
void A<T,N>::input()
{cin >> x[0];}

template <class T, int N> void A<T, N>::output()
{cout << x[0] << endl;}

template <class T> T max1(T a, T b)
{ return a>b?a:b;}

int main1()
{
	A<int,5> a;
	a.input();
	a.output();
	A<double,6> b;
	b.input();
	b.output();
	cout << max1(1,2)<< endl;
	cout << max1(1.3f,4.2f)<< endl;

	cout << max1(1.3,4.2)<< endl;
	cout << max1('1','4')<< endl;
	return 0;
}

void f()
{
	double a=1;
	double b=0;
	if (b==0)
		throw 12;
	a=a/b;
}
int main2()
{
	try{
		//.....
		f();
		int x=5;
		//.....
	}catch(int a){
		cout << a << endl;
	}
	return 0;
}
void ff( int & a)
{a++;
}
void fff(int * a)
{
(*a)++;
}
int main()
{
	int x=5;
	ff(x);
	fff(&x);
	cout << x << endl;
	char s[] = "ABCDEDF";
	cout << s << endl;
	s[1]='b';
	cout << s << endl;
}

