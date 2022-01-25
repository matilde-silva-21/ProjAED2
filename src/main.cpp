#include <iostream>
#include "FileHandler.h"
#include <cmath>
#include <algorithm>
#include "Initialize.h"
#include "graph.h"
#include "Menu.h"


int main() {

    /*Menu menu;
        menu.showMenu(); //needs a while true so we can return to the menu
        menu.takeInput();*/

    FileHandler f;
    BST<Line> diurno = f.readLines(false), noturna=f.readLines(true);

    map<int, Stop> paragens = f.readStops();

    //um grafo noturno e outro diurno?

    Graph g1(paragens.size()+1,true);

    Initialize i1;
    i1.fillDictionary(paragens);

    i1.addAllEdges(g1,paragens,diurno);
    i1.addAllEdges(g1,paragens,noturna);

    string p = "TRD1", q = "AML1";

    float d;

    vector<int> viagem = g1.dijkstra(i1.findMapIndex(p),i1.findMapIndex(q));
    vector<Stop> r;
    r.reserve(viagem.size());

    for(auto e: viagem){
        r.push_back(paragens[e]);
    }

    vector<Line> v = i1.stopsToLine(r);

    cout << viagem.size()<<" percurso desde TRD1 ate AML1 "<<endl;

    for(int i=0; i<v.size() ; i++){
        cout <<" "<<v[i].getCode() << " ";
    }

}
