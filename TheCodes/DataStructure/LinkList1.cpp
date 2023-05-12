#include <bits/stdc++.h>

using namespace std;

template <class T>
struct Node
{
    T date;
    Node <T> * next;
};

template <class T>
class LinkList
{
private:
    Node <T> * front;
public:     
    LinkList(){
        front = new Node <T>;
        front ->next = NULL;
    }
    LinkList(T a[], int n);
    ~LinkList();
    PrintList(){
        Node <T> * p = front ->next;
        while (p)
        {
            cout << p ->date << " ";
            p = p->next;
        } 
        cout << endl;
    }

    int Locad(T x)
    {
        Node <T> * s = front ->next;
        T i = 1;
        while (s)
        {
            if (s -> date == x) return i;
            s = s ->next;
            i++;
        }
        return 0;
    }

    Node <T> * Get(int n)
    {
        Node <T> * s = front -> next;
        int i = 1;
        while (s)
        {
            if(i == n) break;
            s = s->next;
            i++;
        }
        return s;
    }

    void Into(T x, Node <T> * p)
    {
        Node <T> * s = new Node <T>;
        s ->date = x;
        s ->next = p ->next;
        p ->next = s;
    }

    T DeleteA(Node <T> * p)
    {
        Node <T> * s = p->next;
		p->next = s->next;
		T x = s->date;
		return x;
    }

    void DeleteI(Node <T> * p)
    {
        Node <T> * s = GetPreNode(p);
        s ->next = p ->next;
        delete p;
    }

    Node <T> * GetPreNode(Node <T> * p)
    {
        Node <T> * q = front;
        while (q)
        {
            if(q ->next == p) return q;
            q = q ->next;
        }
        return q;
    }
};

template <class T> 
LinkList<T>::LinkList(T a[], int n)
{
    front = new Node <T>;
    front -> next = NULL;   
    for (int i = 0; i < n; i++)
    {
        Node <T> * s = new Node <T>;
        s -> date  = a[i];
        s -> next  = front -> next;
        front -> next = s;
    }
}

template <class T> 
LinkList<T>::~LinkList()
{
    while (front)
    {
        Node <T> * p = front;
        front = front -> next;
        delete p;
    }
    
}

int main ()
{
    int a[] = {0,1,2,3,4};
    LinkList <int> ListA(a, sizeof(a)/sizeof(int));
    ListA.PrintList();
    int L = ListA.Locad(3);
    cout << L << endl;
    Node <int> * p = ListA.Get(3);
    cout << p ->date << endl;
    Node <int> * q = ListA.Get(ListA.Locad(3));
    ListA.Into(6, q);
    ListA.PrintList();
    //Node <int> * k = ListA.Get(ListA.Locad(6));
    ListA.DeleteA(q);
    ListA.PrintList();
    Node <int> * x = ListA.GetPreNode(ListA.Get(ListA.Locad(3)));
    cout << x ->date << endl;
    system("PAUSE");
    return 0;
}