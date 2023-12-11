#include <bits/stdc++.h>
#define MAXSIZE 100001
using namespace std;

//边节点
struct EdgeNode{
    int edge;
    EdgeNode *next;
};

struct VexNode
{
    int nodeNum;
    int Data;
    EdgeNode *first;
};

struct Torii
{
    VexNode Zhu[MAXSIZE];
    int n; // Number of Mountenr
    int m; //Number of Brige
};

void CreateGraph(Torii &G) {
    int i, j, k;
    EdgeNode *p = NULL;
    EdgeNode *q = NULL;
    cin >> G.n >> G.m;
    for (k = 1; k <= G.n; k++) {
        G.Zhu[k].nodeNum = k;
        G.Zhu[k].first = NULL;
        G.Zhu[k].Data = 0;
    }
    for (k = 0; k < G.m; k++) {
        cin >> i >> j;
        p = new EdgeNode;
        p->edge = j;
        p->next = G.Zhu[i].first;
        G.Zhu[i].first = p;
        q = new EdgeNode;
        q->edge = i;
        q->next = G.Zhu[j].first;
        G.Zhu[j].first = q;
    }
}

bool SetNum(Torii &G) {
    G.Zhu[1].Data = 1;
    for (int i = 1; i <= G.n; i++) {
        EdgeNode *p = G.Zhu[i].first;
        while (p != NULL) {
            if (G.Zhu[p->edge].Data == 0) G.Zhu[p->edge].Data = G.Zhu[i].Data + 1;
            if (G.Zhu[p->edge].Data == G.Zhu[i].Data) return 0;
            p = p->next;
        }
    }
}

int main()
{
    Torii G;
    bool Can = 0;
    int Nodeey = 0;
    CreateGraph(G);
    SetNum(G);
    for(int i = 2; i <= G.n; i++){
        cout << G.Zhu[2].Data
    }
    system("pause");
    return 0;
}
