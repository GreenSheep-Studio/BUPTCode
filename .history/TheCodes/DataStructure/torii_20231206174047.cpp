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

struct SevenBriged
{
    VexNode Feng[MAXSIZE];
    int n; // Number of Mountenr
    int m; //Number of Brige
};

void CreateGraph(SevenBriged &G) {
    int i, j, k;
    EdgeNode *p = NULL;
    EdgeNode *q = NULL;
    cin >> G.n >> G.m;
    for (k = 1; k <= G.n; k++) {
        G.Feng[k].nodeNum = k;
        G.Feng[k].first = NULL;
        G.Feng[k].Data = 0;
    }
    for (k = 0; k < G.m; k++) {
        cin >> i >> j;
        p = new EdgeNode;
        p->edge = j;
        p->next = G.Feng[i].first;
        G.Feng[i].first = p;
        q = new EdgeNode;
        q->edge = i;
        q->next = G.Feng[j].first;
        G.Feng[j].first = q;
    }
}

void Count(SevenBriged &G) {
    for (int i = 1; i <= G.n; i++) {
        EdgeNode *p = G.Feng[i].first;
        while (p != NULL) {
            G.Feng[i].Data++;
            p = p->next;
        }
    }
}

int main()
{
    SevenBriged G;
    bool Can = 0;
    int Nodeey = 0;
    CreateGraph(G);
    Count(G);
    for (int i = 1; i <= G.n; i++) {
        if (G.Feng[i].Data % 2 == 1) Nodeey++;
    }
    if (Nodeey < 2) Can = 1;
    else if (Nodeey == 2) {
        if (G.Feng[1].Data % 2 == 1) Can = 1;
    }
    if (Can) cout << "YES" << endl;
    else cout << "NO" << endl;
    //system("pause");
    return 0;
}
