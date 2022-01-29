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



    string s1 = "MPL7", s2 = "FLOS1";

    i1.addAllEdges(g1,paragens,diurno,g2);
    //i1.addAllEdges(g1,paragens,noturna,g2);


    vector<int> ferro = i1.cheapestRoute(g1,g2, i1.findMapIndex(s1),i1.findMapIndex(s2),paragens, dictZonas);
    vector<int> mano = g1.dijkstra(i1.findMapIndex(s1),i1.findMapIndex(s2));

    vector<Stop> mana;
    for(auto it: ferro){
        cout << paragens[it].getCode() << " ";
        mana.push_back(paragens[it]);
    }

    cout << endl<<endl;
    for(auto it: i1.stopsToLine(mana)){
        cout << endl<<endl<<it.first.getCode();
    }
}
