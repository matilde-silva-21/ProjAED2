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

    string p = "TRD1", q = "AML1", r ="CPSF1";

    int index = i1.findMapIndex(r);
    list<int> adj = g1.getAdjNodes(index);

    for(int & it : adj){
        cout << paragens[it].getCode() << " ";
    }


    float d;

    vector<int> viagem = g1.Dijkstra(i1.findMapIndex(p),i1.findMapIndex(q), d);
    cout << viagem.size()<<" percurso desde TRD1 ate AML1 "<<d<<endl;

    for(int i=0; i<viagem.size() ; i++){
        cout << i<<" "<<paragens[viagem[i]].getCode() << " ";
    }
    /*cout << "paragens adjacentes a TRD1\n";

    list<int> l = g1.getAdjNodes(index);
    for(auto i: l){
        cout << paragens[i].getCode() << " ";
    }

     cout << "\n\nLinhas que passam em TRD1:\n";

    for(auto& i: paragens[index].getLines()){
        cout << i.getCode() << " ";
    }*/

}
