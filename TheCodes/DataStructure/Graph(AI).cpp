#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {
private:
    int vertices;
    std::vector<std::list<int>> adjList;

public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int v, int w);
    void DFS(int v);
    void BFS(int v);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
}

Graph::~Graph() {
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
}

void Graph::DFS(int v) {
    std::vector<bool> visited(vertices, false);
    
    std::function<void(int)> dfsHelper = [&](int vertex) {
        visited[vertex] = true;
        std::cout << vertex << " ";
        
        for (int adj : adjList[vertex]) {
            if (!visited[adj]) {
                dfsHelper(adj);
            }
        }
    };

    dfsHelper(v);
}

void Graph::BFS(int v) {
    std::vector<bool> visited(vertices, false);
    std::queue<int> q;
    
    visited[v] = true;
    q.push(v);
    
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        
        std::cout << vertex << " ";
        
        for (int adj : adjList[vertex]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2);

    std::cout << std::endl;
    std::cout << "Breadth First Traversal (starting from vertex 2): ";
    g.BFS(2);

    return 0;
}