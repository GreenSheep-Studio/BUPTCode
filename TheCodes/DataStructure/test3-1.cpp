#include <iostream>
using namespace std;

template <class T>
struct Node {
	T data;
	Node <T> * next;
};

template <class T>
class LinkList{
public:	
	LinkList(){
		front = new Node <T>;
		front->next = 0;
	}
	LinkList(T a[], int n, char tag )
	{
		if (tag=='h') LinkList1(a, n);
		else LinkList2(a,n);
	}
	LinkList1(T a[], int n );
	LinkList2(T a[], int n );
	PrintList()
	{
		cout <<"list info:"<< endl;
		Node <T> *p = front->next;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	int GetLength(){
		int i=0;
		Node <T> *p = front->next;
		while (p)
		{
			i++;
			p = p->next;
		}
		return i;
	}
	~LinkList()
	{			
		while (front){
			Node <T> * p = front;
			front = front->next;
			delete p;			
		}
	}
	Node <T> * Locate(T x)
	{
		Node <T> * p = front->next;
		while (p)
		{
			if (p->data==x) break;
			p = p->next;
		}
		return p;
	}
	int Locate1(T x)
	{//返回序号
		Node <T> * p = front->next;
		int i=1;
		while (p)
		{
			if (p->data==x) return i;
			p = p->next;
			i++;
		}
		return 0;
	}
	Node <T> * Get(int k)
	{
		Node <T> * p = front->next;
		int i=1;
		while (p)
		{
			if (i==k) return p;
			p = p->next;
			i++;
		}
		return 0;
	}
	void InsertAfter(Node <T> * p, T x)
	{
		Node <T> * s = new Node <T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	
	void InsertBefore(Node <T> * p, T x)
	{
		Node <T> * s = new Node <T>;
		//s->data = p->data;
		//s->next = p->next;
		*s = *p;
		p->next = s;
		p->data = x;
	}
	
	T DeleteAfter(Node <T> * p)
	{
		Node <T> * s = p->next;
		p->next = s->next;
		T x = s->data;
		return x;
	}
	
	T Delete(Node <T> * p)
	{
		Node <T> * s = p->next;
		if (s){
			T x = p->data;
			*p = *s;//p->data = s->data; p->next=s->next;
			delete s;
			return x;	
		}
		s = GetPreNode(p);
		s->next = 0;
		T x= p->data;
		delete p;
		return x;
	}
	Node <T> * GetPreNode(Node <T> *p)
	{
		Node <T> * q= front;
		while (q)
		{
			if (q->next == p) return q;
			q = q->next;
		}
		return q;
	}
	
	Node <T> * GetPreNode1(Node <T> *p)
	{
		Node <T> * q= front;
		while (q&&q->next != p)
		{
			q = q->next;
		}
		return q;
	}
private:
	Node <T> * front;
	//int length;
};
template <class T>
LinkList<T>:: LinkList1(T a[], int n )
{
	front = new Node <T>;
	front->next = 0;
	for (int i=0;i<n;i++){
		Node <T> * s = new Node <T>;
		s->data = a[n-1-i];
		s->next = front->next;
		front->next = s;
	}
}

template <class T>
LinkList<T>:: LinkList2(T a[], int n )
{//尾插法
	front = new Node <T>;
	Node <T> * r = front;
	for (int i=0;i<n;i++){
		r->next = new Node <T>;
		r = r->next;
		r->data = a[i];
	}
	r->next = 0;
}

int main()
{
	int a[]={3,234,56,4,3,435,34,1,3,5,35,3,5,3,51};
	LinkList <int> ab (a, sizeof(a)/sizeof(int),'h');
	ab.PrintList();
	LinkList <int> b (a, sizeof(a)/sizeof(int),'x');
	b.PrintList();
	cout << "b list length: ";
	cout << b.GetLength() << endl;
	Node <int> * p = b.Locate(435);
	cout << p << " "<< p->data <<" " << p-> next << endl;
	p = b.Locate(12);
	cout << p << endl;
	p = b.Get(10);
	cout << p << " "<< p->data <<" " << p-> next << endl;
	b.InsertAfter(p, 111);
	b.PrintList();
	b.Delete(p);
	b.PrintList();
	p=b.Get(5);
	p=b.GetPreNode(p);
	cout << p->data << endl;
	p=b.Locate(51);
	b.Delete(p);
	b.PrintList();
	system("PAUSE");
	return 0;
}