// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#include <queue>
#include <map>
#include "graph.h"
#include "algorithm"
#include "minHeap.h"


// Constructor: nr nodes and direction
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, float weight){
    if (src<1 || src>n || dest<1 || dest>n) return;


    if(noDuplicates(src,dest,weight)){
            nodes[src].adj.push_back({dest, weight});
            if(!hasDir)nodes[dest].adj.push_back({src, weight});
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

bool Graph::noDuplicates(int src, int dest, double weight) {
    for(auto e: nodes[src].adj){
        if(e.dest == dest) return false;
    }
    return true;
}



vector<int> Graph::bfs(int v, int b, float& d){
    vector<int> course;
    if (v == b) return course;
    //distance representa a distancia de qualquer node ao node 1
    int predecessor[nodes.size() + 1];
    float distance[nodes.size() + 1];
    for (int i = 1; i <= n; i++) {
        distance[i] = FLOAT_MAX;
        predecessor[i] = -1;
        nodes[i].visited = false;
    }
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    distance[v] = 0;
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        for (auto e: nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                distance[w] = distance[u] + e.weight;
                predecessor[w] = u;
                q.push(w);
                nodes[w].visited = true;

                if (w == b) {
                    d = distance[b];
                    int one = b, two;

                    course.push_back(b);

                    while(one!=v){
                        two = predecessor[one];
                        course.emplace(course.begin(),two);
                        one = two;
                    }
                    return course;
                }
            }
        }
    }

    return course;
}

vector<int> Graph::dijkstra(int start, int finish) {

    float distance[n+1];
    MinHeap<int, float> heap(n,0);
    int predecessor[n+1];
    vector<int> course;

    for(int i=1;i<=nodes.size(); i++){
        distance[i] = FLOAT_MAX;
        nodes[i].visited = false;
    }

    heap.insert(start, 0.0);

    while(heap.getSize()!=0){
        pair<int,float> p = heap.removeMin();
        int min = p.first;
        nodes[min].visited = true;
        if(min == finish) {
            int one = finish, two;

            course.push_back(finish);

            while(one!=start){
                two = predecessor[one];
                course.emplace(course.begin(),two);
                one = two;
            }
            return course;
        }
        for(auto& e: nodes[min].adj){
            if(nodes[e.dest].visited) continue;

            else{
                int destine = e.dest;
                float weight = e.weight + p.second;
                predecessor[destine]=min;
                if(!heap.hasKey(destine)) heap.insert(destine,weight);
                else heap.decreaseKey(destine,weight);
            }
        }

    }
    return course;
}

vector<int> Graph::dijkstra2(int start, int finish, map<string,bool>& zonasPermitidas, map<int, Stop>& paragens) {

    float distance[n+1];
    MinHeap<int, float> heap(n,0);
    int predecessor[n+1];
    vector<int> course;

    for(int i=1;i<=nodes.size(); i++){
        distance[i] = FLOAT_MAX;
        nodes[i].visited = false;
    }

    heap.insert(start, 0.0);

    while(heap.getSize()!=0){
        pair<int,float> p = heap.removeMin();
        int min = p.first;
        nodes[min].visited = true;
        if(min == finish) {
            int one = finish, two;

            course.push_back(finish);

            while(one!=start){
                two = predecessor[one];
                course.emplace(course.begin(),two);
                one = two;
            }
            return course;
        }
        for(auto& e: nodes[min].adj){
            if(nodes[e.dest].visited || !zonasPermitidas[paragens[e.dest].getZona()]) continue;

            else{
                int destine = e.dest;
                float weight = e.weight + p.second;
                predecessor[destine]=min;
                if(!heap.hasKey(destine)) heap.insert(destine,weight);
                else heap.decreaseKey(destine,weight);
            }
        }

    }
    return course;
}

