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
    Node <T> * first;
public:
    LinkList();
    LinkList(T a[], int n);
    ~LinkList();
    void PrintList(){
        Node <T> * s = first ->next;
        while (s)
        {
            cout << s ->date << " " ;
            s = s ->next;
        }
        cout << endl;
    }

    Node <T> * Get(int k){
        Node <T> * s = first ->next;
        int i = 1; 
        while (s)
        {
            if(i == k) break;
            s  = s ->next;
            i++;
        }
        return s;
    }

    T Locad(T p)
    {
        Node <T> * s = first -> next;
        int i = 1;
        while (s)
        {
            if (s ->date == p) break;
            s = s ->next;
            i++;
        }
        return i;
    }

    void Into(T t, Node <T> * p)
    {
        Node <T> * s = new Node <T>;
        s ->date = t;
        s ->next = p ->next;
        p ->next = s;
    }

    void DeleteA(Node <T> * p)
    {
        Node <T> * s = new Node <T>;
        s = p ->next;
        p ->next = s ->next;
        delete s;
    }

    void DeleteI(Node <T> * p)
    {
        Node <T> * s = GetPre(p);
        DeleteA(s);
    }

    Node <T> * GetPre(Node <T> * p)
    {
        Node <T> * s = first;
        while (s)
        {
            if (s ->next == p) break;
            s = s->next;
        }
        return s;
    }
};

template <class T>
LinkList<T>::LinkList(T a[], int n)
{
    first = new Node <T>;
    first ->next = NULL;
    for (int i = 0; i < n; i++)
    {
        Node <T> * s = new Node <T>;
        s ->date = a[n- i -1];
        s ->next = first -> next;
        first ->next = s;
    }
}

template <class T>
LinkList<T>::~LinkList()
{
    while (first)
    {
        Node <T> * p = first;
        first = first -> next;
        delete p;
    }
}


    

int main  ()
{
    int a[] = {12,32,76,89,29,279,24};
    LinkList <int> ListA(a, sizeof(a)/sizeof(int));
    ListA.PrintList();
    Node <int> * p = ListA.Get(3);
    cout << p ->date << endl;
    int i = ListA.Locad(89);
    cout << i << endl;
    ListA.Into(9, ListA.Get(3));
    ListA.PrintList();
    ListA.DeleteA(ListA.Get(3));
    ListA.PrintList();
    Node <int> * k = ListA.GetPre(ListA.Get(3));
    cout << k ->date << endl;   
    ListA.DeleteI(ListA.Get(3));
    ListA.PrintList();
    system("PAUSE");
    return 0;
}