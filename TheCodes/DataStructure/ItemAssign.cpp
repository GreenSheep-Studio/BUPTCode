#include <bits/stdc++.h>
#define MAXSIZE    100
using namespace std;

// 建立边表
struct EdgeNode{
    int Edge;
    EdgeNode * next;
};

// 建立顶点表
struct VexNode{
    int date;
    int Number;
    EdgeNode * First;
};

// 建立邻接表
struct GAdjNode{
    VexNode Vex[MAXSIZE];
    int VexNum;
    int EdgeNum;
};

// 项目名称
struct Itme{
    string Name;
};

//创建邻接表
void Create(GAdjNode & G){
    int i;
    int j;
    cout << "VexNum EdgeNum" << endl;
    cin >> G.VexNum >> G.EdgeNum;
    cout << "Vex Infor" <<endl;
    for (int k = 0; k < G.VexNum; k++) {
        cin >> G.Vex[k].Number;
        G.Vex[k].First = NULL;
        G.Vex[k].date = 0;
    }
    cout << "Edge Infor" << endl;
    for (int k = 0; k <G.EdgeNum; k++)
    {
        cin >> i >> j;
        EdgeNode *p = new EdgeNode;
        p ->Edge = j;
        p ->next = G.Vex[i].First;
        G.Vex[i].First = p;
        EdgeNode *q = new EdgeNode;
        q ->Edge = i;
        q ->next = G.Vex[j].First;
        G.Vex[j].First = q;
    }
}

bool Visit[MAXSIZE];
int OrdMax = 0; // 最多安排数

// 安排项目顺序函数
void Assign(GAdjNode &G, int v){
    int N;
    N = G.EdgeNum;
    int Order[N];
    int Ord;
    for (int i = 0; i < N; i++) 
        Order[i] = 0;
    bool T = 1;
    EdgeNode *p = new EdgeNode;
    p = G.Vex[v].First;
    int k = 0;
    while (p){ 
        Order[k] = G.Vex[p ->Edge].date;
        k++;
        p = p ->next;
    }
    for (Ord = 0; T; Ord++){
        T = 0;
        for (int i = 0; i < N; i++){
            if (Ord == Order[i]) T = 1;
        }
    }
    Ord--;
    if (Ord > OrdMax) OrdMax = Ord;
    G.Vex[v].date = Ord;
    Visit[v] = 1;
    EdgeNode *s = new EdgeNode;
    s = G.Vex[v].First;
    while (s){
        int i = s ->Edge;
        if (Visit[i] != 1) Assign(G, i);
        else s = s ->next;
    }
}

// 打印输出项目安排
void Print(GAdjNode & G){
    Itme x[7] = {"100m_Run", "200m_Run" , "High_Jump", "Long_Jump", "Shot_Put", "Discus", "Javelin"};
    for (int i = 1; i <= OrdMax; i++){
        cout << "Time " << i << ": ";
        for (int j = 0; j < G.VexNum; j++) {
            if (G.Vex[j].date == i)  cout << x[G.Vex[j].Number].Name << ", ";
        }
        cout << endl;
    }
}

//主函数，用于调试上述功能
int main ()
{
    GAdjNode assign;
    Create (assign);
    for (int i = 0; i < MAXSIZE; i++) Visit[i] = 0;// 初始化访问列表
    Assign (assign, 0);
    Print (assign);
    system("PAUSE");
    return 0;
}