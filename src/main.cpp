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
    map<string, bool> zonasPermitidas;

    for(auto it: zonas){
        dictZonas[it.second] = it.first;
    }


    Graph g2(zonas.size(), false);

    string s1 = "PP2", s2 = "IPO4";
    i1.addAllEdges(g1,paragens,diurno,g2);
    //i1.addAllEdges(g1,paragens,noturna,g2);

    //int zonaS1 = zonas[paragens[i1.findMapIndex(s1)].getZona()] , zonaS2 = zonas[paragens[i1.findMapIndex(s2)].getZona()];

    //vector<int> zuzu = g2.dijkstra(zonaS1, zonaS2);

    /*for(const auto& it: zonas){
        zonasPermitidas[it.first] = true;
    }
    for(auto it: zuzu){
        zonasPermitidas[dictZonas[it]] = true;
    }
    // se o grafo n liga duas zonas que estao conectadas geograficamente,
    // é porque nao ha linhas coincidentes entre as duas zonas e portanto nao importa que nao haja edge

    vector<int> ferro = i1.cheapestRoute(g1,zonasPermitidas, i1.findMapIndex(s1),i1.findMapIndex(s2));
    */
    vector<int> mano = g1.dijkstra(i1.findMapIndex(s1),i1.findMapIndex(s2));
    vector<Stop> mana;
    cout<<endl<<endl;

    for(auto it: mano){
        mana.push_back(paragens[it]);
    }

    i1.stopsToLine(mana);
}
