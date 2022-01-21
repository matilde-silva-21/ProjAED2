// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#include <queue>
#include "graph.h"
#include "algorithm"

// Constructor: nr nodes and direction
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, double weight){
    if (src<1 || src>n || dest<1 || dest>n) return;

    if(noDuplicates(src,dest,weight)){
        nodes[src].adj.push_back({dest, weight});
        if (!hasDir) nodes[dest].adj.push_back({src, weight});
    }
}

bool inQueue(queue<int> q, int a){
    while(!q.empty()){
        if (q.front()==a) return true;
        else q.pop();
    }
    return false;
}

int Graph::prim(int r) {
    int distance[nodes.size()+1], parent[nodes.size()+1], min, index;
    queue<int> q;

    for(int i=1; i<=nodes.size(); i++){
        distance[i]=INT16_MAX;
        parent[i]=NULL;
        q.push(i);
    }

    min = distance[1];

    while(!q.empty()){
        for (int i=1; i<=nodes.size(); i++){
            if(distance[i]<min){index=i;}
        }
        for(auto e: nodes[index].adj){
            int v = e.dest;
            if(inQueue(q,v) && e.weight<distance[v]){
                parent[v]=index;
                distance[v]=e.weight;
            }
        }
        q.pop();
    }

    min=0;

    for(int i=1; i<=nodes.size(); i++){
        min+=distance[i];
    }
    return min;
}


// ----------------------------------------------------------
// Exercicio 5: Algoritmo de Kruskal
// ----------------------------------------------------------
// TODO
int Graph::kruskal() {
    return 0;
}

bool Graph::noDuplicates(int src, int dest, double weight) {
    for(auto e: nodes[src].adj){
        if(e.dest == dest) return false;
    }
    return true;
}
