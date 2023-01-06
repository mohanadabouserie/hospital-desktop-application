#include "graph.h"

Graph::Graph()
{
    addEdge(1, 2, 4);
    addEdge(1, 3, 5);
    addEdge(1, 4, 2);
    addEdge(2,7,3);
    addEdge(2, 4, 3);
    addEdge(2,8,5);
    addEdge(3, 4, 1);
    addEdge(3, 5, 2);
    addEdge(3, 6, 10);
    addEdge(4, 8, 4);
    addEdge(4,6,1);
    addEdge(4, 9, 2);
    addEdge(5, 6, 2);
    addEdge(6,8,1);
    addEdge(6, 9, 6);
    addEdge(7,8,1);
    addEdge(7, 10, 8);
    addEdge(7,11,4);
    addEdge(8, 11, 1);
    addEdge(8,12,6);
    addEdge(8, 9, 3);
    addEdge(8, 10, 6);
    addEdge(9,12,2);
    addEdge(10, 13, 1);
    addEdge(10,11,1);
    addEdge(10,14,3);
    addEdge(11, 14, 1);
    addEdge(11,12,2);
    addEdge(12, 15, 9);
    addEdge(13,16,1);
    addEdge(13, 14, 5);
    addEdge(13,17,5);
    addEdge(14,17, 2);
    addEdge(14,15,4);
    addEdge(14,16,5);
    addEdge(15, 18, 5);
    addEdge(15,17,6);
    addEdge(16, 19, 5);
    addEdge(16,20,1);
    addEdge(16, 17, 4);
    addEdge(17,18,2);
    addEdge(17, 20, 4);
    addEdge(18, 20, 2);
    addEdge(19,20,4);
}

void Graph::addEdge(int u, int w, int weight){
    graph[u].push_back(qMakePair(w, weight));
    graph[w].push_back(qMakePair(u,weight));
}
int Graph:: Dijkestra(int w){
    // finding the shortest path from node w to node 8
    QVector<int> distance(V, INT_MAX);
    QSet<QPair<int, int>> s;
    s.insert(qMakePair(w, 0));
    distance[w] = 0;
    while (!s.empty()) {
        QPair<int,int> a = *s.begin();
        int node = a.first;
        s.remove(a);
        for (int i = 0; i < graph[node].size(); i++) {
            int v = graph[node][i].first;
            int w = graph[node][i].second;
            if (distance[v] > distance[node] + w) {
                distance[v] = distance[node] + w;
                s.insert(qMakePair(v, distance[v]));
                parent[v] = node;
              }
          }
      }
     return distance[8];
}
