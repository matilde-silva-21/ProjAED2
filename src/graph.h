// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_
#define  FLOAT_MAX 1000000000000000.1

#include "minHeap.h"
#include "disjointSets.h"
#include <vector>
#include <list>
#include <iostream>
#include "Stop.h"
#include "queue"
#include "stack"
#include "map"
using namespace std;

/*criar um mapa que tenha indice igual ao node e depois da origem as stops?*/

class Graph {
    struct Edge {
        int dest;   // Destination node
        float weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction
    Graph(int nodes, bool dir);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, float weight);

    // ----- Functions to implement in this class -----
    int prim(int v);

    //algoritmo que pesquisa a menor distancia
    vector<int> bfs(int a, int b, float& d);

    vector<int> dijkstra(int start, int finish);

    list<int> getAdjNodes(int n) {
        list<int> final;
        for(auto e: nodes[n].adj){
            final.push_back(e.dest);
        }
        return final;
    }

    bool noDuplicates(int src, int dest, double weight);
};

#endif
