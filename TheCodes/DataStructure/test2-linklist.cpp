#include <iostream>
#include <cstring>
using namespace std;
template <class T>
struct Node{
	T data;
	Node <T> * next;	
};
template <class T>
class LinkList{
public:
	LinkList(T a[], int n)
	{
		first=new Node<T>;
		first->next = NULL;
		for (int i=0;i<n;i++)
		{
			Node <T> *s = new Node <T>;
			s->data = a[n-1-i];
			s->next = first->next;
			first->next = s;
		}
	}
private:
	Node <T> * first;	
};



class A
{
public:
	queue<B> q;
};
A a;
a.q.push(10);