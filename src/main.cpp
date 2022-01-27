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

    map<string, int> zonas = i1.getZonas();
    map<int, string> dictZonas;

    for(auto it: zonas){
        dictZonas[it.second] = it.first;
        cout <<it.first<<" ";
    }


    Graph g2(zonas.size(), false);

    string s1 = "TRD1", s2 = "AML1";
    i1.addAllEdges(g1,paragens,diurno,g2);
    i1.addAllEdges(g1,paragens,noturna,g2);

    // se o grafo n liga duas zonas que estao conectadas geograficamente,
    // é porque nao ha linhas coincidentes entre as duas zonas e portanto nao importa que nao haja edge

    vector<int> ferro = i1.cheapestRoute(g1,g2,paragens,i1.findMapIndex(s1),i1.findMapIndex(s2),dictZonas);
    vector<int> mano = g1.dijkstra(i1.findMapIndex(s1),i1.findMapIndex(s2));
    cout<<endl<<endl;

    for(auto it: ferro){
        cout << paragens[it].getCode() << " ";
    }

    cout<<endl<<endl;

    for(auto it: mano){
        cout << paragens[it].getCode() << " ";
    }
}
