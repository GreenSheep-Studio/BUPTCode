#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

int Visited[MAXSIZE];
struct EdgeNode{
    int edge; 
    int weight; 
    EdgeNode * next;
};

struct VexNode{
    int node; 
    int date;  
    EdgeNode * first;  
};

 
struct GAdjListNode{
    VexNode AdjList[MAXSIZE];
    int vexnum;
    int edgenum;
};

void Creat(GAdjListNode &G){
    int i, j, k, w;
    EdgeNode *p = NULL;
    EdgeNode *q = NULL;
    cout << "Enter The VexNumber and EdgeNumbre" << endl;
    cin >> G.vexnum >> G.edgenum;
    for (k = 0; k < G.vexnum; k++){
        cin >> G.AdjList[k].node; 
        G.AdjList[k].first = NULL;
        G.AdjList[k].date = 0;
    }

    for (k = 0; k < G.edgenum; k++){
        cout << "Enter Edge(vi, vj) i, j & w: ";
        cin >> i >> j >> w;
        p = new EdgeNode;
        p ->edge = j;
        p ->weight = w;
        p ->next = G.AdjList[i].first;
        G.AdjList[i].first = p;
        q = new EdgeNode;
        q ->edge = i;
        q ->weight = w;
        q ->next = G.AdjList[j].first;
        G.AdjList[j].first = q;
    }
}

// 
void Print(GAdjListNode &G){
    EdgeNode * p;
    for (int i = 0; i < G.vexnum; i++){
        cout <<"Vex" << G.AdjList[i].node << ":" << "value" << ":" << G.AdjList[i].date << "--" ;
        for (p = G.AdjList[i].first; p; p = p->next){
            cout << p->edge << "(" << p ->weight << ")" << " ";
        }
        cout << endl;
    }
}


void DFS(GAdjListNode &G, int v){
    int j;
    cout << G.AdjList[v].node << " "; 
    Visited[v] = 1;
    EdgeNode *p = G.AdjList[v].first;
    while (p){
        j = p ->edge;
        if (Visited[j] == 0) DFS(G, j);
        else p = p ->next;
    }
}

void BFS(GAdjListNode &G, int v){
    int front;
    int rear;
    int queue[MAXSIZE];
    int j;
    front = rear = -1;
    EdgeNode *p;
    for (int i = 0; i < MAXSIZE; i++) queue[i] = 0;
    cout << G.AdjList[v].node << " ";
    Visited[v] = 1;
    queue[++rear] = v;
    while (front != rear){
        v = queue[++front];
        p = G.AdjList[v].first;
        while (p){
            j = p ->edge;
            if (Visited[j] == 0){
                cout << G.AdjList[j].node << " ";
                Visited[j] = 1;
                queue[++rear] = j;
            }
            p = p ->next;
        }
    }
}

int main ()
{
    GAdjListNode G;
    Creat(G);
    Print(G);
    for (int i = 0; i < G.vexnum; i++)
        Visited[i] = 0;
    DFS(G, 0);
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        Visited[i] = 0;
    BFS(G, 0);
    cout << endl;
    system("PAUSE");
    return 0;
}