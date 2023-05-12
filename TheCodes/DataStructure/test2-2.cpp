#include <iostream>
using namespace std;
template <class T, int N>
class SeqList{
	public:
		SeqList();  
        SeqList(T a[], int n){
        	length=n>N?N:n;
			for (int i=0;i<length;i++)
        		data[i]=a[i];        	
		}
		int 	GetLength(){
			return length;
		};
		T 	Get(int i)  
		{
			sprintf(sss,"get pos error: %d", i);
			//cout <<sss<< endl;
			if (i<1 || i>length) throw sss;
			return data[i-1];
		}                //获取
        int 	Locate(T x, int pos=1);                 //定位
		void 	Insert(int  i, T x);      //插入
		T 	Delete(int i);             //删除
        void     PrintList()
		{
			for(int i=0;i<length;i++)
				cout << data[i]<<" ";
			cout << endl;
		}               //打印
	private:
		T 	data[N];   //存储结构
		int 	length;
		char sss[100];
};
template <class T, int N>
SeqList<T, N>::SeqList()
{ length=0;
}
template <class T, int N>
void SeqList<T, N>::Insert(int  i, T x)
{
	if (i<1||i>length+1) throw "insert pos error.";
	if (length>=N) throw "overflow";
	for (int j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1] = x;
	length++;
}

template <class T, int N>
T SeqList<T, N>::Delete(int  i)
{
	
	sprintf(sss,"delete pos error: %d", i);
	//cout <<sss<< endl;
	if (i<1 || i>length) throw sss;
	T x = data[i-1];
	for (int j=i-1;j<=length-2;j++)
		data[j] = data[j+1];
	length--;
	return x;
}

template <class T, int N>
int SeqList<T,N>:: Locate(T x, int pos)
// not found: return 0
{
	for (int i=pos-1;i<length;i++)
		if (data[i]==x)
			return i+1;
	return 0;
}

template <class T, int N>
void Insert(SeqList<T,N> & a, int i, T x)
{
	a.Insert(i, x);
}

int main()
{
	try{
		char s[]="ABCDDSFSDF#W$SFEDSFDSF";
		SeqList <char, 100> c1(s, strlen(s));
		c1.PrintList();
		
		SeqList <int, 100> list;
		list.Insert(1,1);
		list.Insert(1,10);
		list.Insert(1,1);
		list.Insert(2,10);
		list.Insert(3,1);
		list.Insert(4,10);
		list.PrintList();
		
		int pos = 0;
		cout <<" print locations of 10:";
		do{
			pos = list.Locate(10, pos+1);
			if (pos==0) break;
			cout << pos << " ";
		}while (pos);
		cout << endl;
		
		int x = list.Delete(1);
		cout << "delete no. 1:"<< x << endl;	
		list.PrintList();
		
		SeqList <char, 100> list1;
		Insert(list1, 1, 'x');
		list1.Insert(1,'1');
		list1.Insert(1,'A');
		list1.PrintList();
		
		char c = list1.Delete(2);
		cout << "delete no. 2:"<< c << endl;	
		list1.PrintList();
		
		SeqList <int,100> a1;
		a1.Delete(1);
		
	}catch(const char * s)
	{
		cout << s << endl;
	}
	
	return 0;
}