#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;



//第三次//
bool Visited[MAXSIZE];// 全局变量，用于表示涂色状态（0代表上色，1代表已经上色过）
int ColorMax = 0;// 全局变量，表示使用的颜色数

// 边表节点
struct EdgeNode{
    int edge; // 边的指向
    EdgeNode * next;// 下一节点指针
};

// 顶点表节点
struct VexNode{
    int node;// 存储节点的序号
    int date; // 节点中存储的数据
    EdgeNode * first; // 该节点的第一条边
};

// 邻接表
struct GAdjListNode{
    VexNode AdjList[MAXSIZE];// 顶点数组
    int VexNum;// 顶点数
    int EdgeNum;// 边数
};

struct ColorSize{
    string Colors;
};

// 创建邻接表
void Creat(GAdjListNode &G){
    int i, j, k;
    EdgeNode *p = NULL;
    EdgeNode *q = NULL;
    cout << "输入节点数和边数: " << endl;
    cin >> G.VexNum >> G.EdgeNum;
    cout << "输入节点序号";
    for (k = 0; k < G.VexNum; k++){
        cin >> G.AdjList[k].node; // 输入节点信息
        G.AdjList[k].first = NULL;
        G.AdjList[k].date = 0;
    }

    cout << "输入各条边两端的节点序号i、j(i, j与j, i为同一条边, 无需重复注入): ";
    for (k = 0; k < G.EdgeNum; k++){
        cin >> i >> j;
        // 构建无向图
        p = new EdgeNode;
        p ->edge = j;
        p ->next = G.AdjList[i].first;
        G.AdjList[i].first = p;
        q = new EdgeNode;
        q ->edge = i;
        q ->next = G.AdjList[j].first;
        G.AdjList[j].first = q;
    }
}

// 上色函数
// 基本思路：利用深度优先遍历的思想，对每个节点进行涂色，每次涂色都从第零号颜色开始涂，并且对相邻节点进行冲突判定
void DrawColor(GAdjListNode &G, int v){
    int i;
    int s;
    int k;
    bool T = 1;
    int Color = 1;// 初始颜色为 1
    int ColorBox[G.VexNum];// 颜色集合，用于存储与某顶点相邻的所有顶点的上色情况
    for (k = 0; k < G.VexNum; k++)
        ColorBox[k] = 0;// 将颜色集合初始化为 0（未上色）
    EdgeNode *q = G.AdjList[v].first;
    k = 0;
    while (q){ // 遍历与 v号节点相邻的所有节点上的 date值，并将其存入颜色集合中
        s = q ->edge;
        ColorBox[k] = G.AdjList[q ->edge].date;
        q = q ->next;
        k++;
    }
    for (Color = 1; T; Color++){
        T = 0;// 用于判断是否冲突
        for (k = 0; k < G.VexNum; k++){
            if (Color == ColorBox[k]){
                T = 1;// 集合中存在与当前预上色相同的颜色，直接判定冲突
                break;// 冲突结束循环，节省时间（虽然节省不了多少 doge）
            } 
        }
    }
    Color--;// 可能是因为 for循环的问题，会出现自动加一的情况，所以做一个小调整
    if (Color > ColorMax) ColorMax = Color;
    G.AdjList[v].date = Color;// 上色
    Visited[v] = 1;// 将该节点更新为已涂色
    EdgeNode *p = G.AdjList[v].first;
    while (p){
        i = p ->edge;
        if (Visited[p ->edge] == 0) DrawColor(G, i);// 递归遍历剩下的节点，并且上色
        else p = p ->next;
    }
}

// 输出涂色结果
void ColorResult(GAdjListNode &G){
    ColorSize x[4] = {"Red", "Yellow", "Blue", "Green"};
    for (int i = 0; i < G.VexNum; i++)
        cout << "节点" << G.AdjList[i].node << "上的颜色为" << x[G.AdjList[i].date - 1].Colors << endl; 
}

// 主函数，用于调试程序各功能是否正常执行
int main ()
{
    GAdjListNode G;
    Creat(G);// 生成一张图
    for (int i = 0; i < G.VexNum; i++)
        Visited[i] = 0;// 初始化标记集合的信息，使所有节点处于未上色的状态
    DrawColor(G, 0);// 执行上色函数
    ColorResult(G);// 打印上色结果
    system("PAUSE");
    return 0;
}