#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Node{
    T date;
    Node <T> * next;
};
template <class T>
class LinkStack{
private:
    Node <T> * top;
public:
    LinkStack();
    ~LinkStack();
    void Push(T x){
        Node <T> * s = new Node <T>;
        s ->date = x;
        s->next = top;
        top = s;
    }
    T Pop(){
        if (top == NULL){
            //cout << "throw" << endl;
            return -1;
        }
        else{
            Node <T> * s = top;
            T x = s ->date;
            top = top ->next;
            delete s;
            return x;
        }
    }
};
template <class T>
LinkStack<T>::LinkStack(){
    top = new Node <T>;
    top ->next = NULL;
}
template <class T>
LinkStack<T>::~LinkStack(){
}

int main ()
{
    int a[5];
    LinkStack <int> StackA;
    for (int i = 0; i < 5; i++){
        cin >> a[i];
        StackA.Push(a[i]);
    }
    for (int i = 0; i < 5; i++){
        cout << StackA.Pop();
    }
    system("PAUSE");
    return 0;
}