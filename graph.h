#ifndef GRAPH_H
#define GRAPH_H
#include <QVector>
#include <QPair>
#include <QSet>
#include <QDebug>

// one unit of weight is equivalent to 100m
class Graph
{
    static const int V = 21; // it is assumed the the maximum number of buildings in this hypothetical city is 20, including the hospital
    QVector<QPair<int,int>> graph[V];
    int position = 8; // the node of the hospital

public:
    Graph();
    int parent[V] = {0}; // array storing the information of the shortest path
    void addEdge(int u, int w, int weight); // w is the desination, as there is no point of adding the source because it is always the hospital
    int Dijkestra(int w); // w is the source
};

#endif // GRAPH_H
