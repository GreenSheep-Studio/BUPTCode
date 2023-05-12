#include <bits/stdc++.h>
using namespace std;
const int QueueSize = 5;
template <class T>
class Queue
{
private:
    T date[QueueSize];
    int front;
    int rear;
public:
    Queue();
    void InQueue(T);
    T OutQueue();
};

template <class T>
Queue<T>::Queue(){
    front = rear = 0;
}

template <class T>
void Queue<T>::InQueue(T x){
    if (front == (rear + 1) % QueueSize) cout << "FULL" << endl;
    else {
        rear = (rear + 1) % QueueSize;
        date[rear] = x;
    }
}

template <class T>
T Queue<T>::OutQueue(){
    if (rear == front) {
        cout << "Empty" << endl;
        return -1;
    }
    else {
        front = (front + 1) % QueueSize;
        return date[front];
    }
}

int main ()
{
    Queue<int> queue;
    int a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        queue.InQueue(a);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << queue.OutQueue() << endl;
    }
    system("PAUSE");
    return 0;
}