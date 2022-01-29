//
// Created by Matilde on 21/01/2022.
//

#ifndef PROJAED2_INITIALIZE_H
#define PROJAED2_INITIALIZE_H

#include "Stop.h"
#include "graph.h"
#include "map"
#include "Line.h"
#include "cmath"
#include "bst.h"
#include "algorithm"

class Initialize {

private:
    map<string,int> dictionary, zonas;

public:
    void fillDictionary(const map<int, Stop>& paragens);
    static double haversine(double lat1, double lon1, double lat2, double lon2);
    double peso(const Stop& s1, const Stop& s2);
    //esta funcao adiciona as edges e atualiza a informacao das linhas em cada stop
    void addAllEdges(Graph& g1, map<int, Stop> &paragens, const BST<Line>& linhas, Graph& g2);
    map<string,int> getDictionary();
    map<string,int> getZonas();
    int findMapIndex(string& paragem);

    static Stop closestStation(map<int,Stop>& paragens, float latitude, float longitude);

    list<pair<Line, list<Stop>>> stopsToLine(const vector<Stop>& s1);

    vector<int> cheapestRoute(Graph& g1, Graph& g2, int a, int b, map<int, Stop>& paragens, map<int, string>& dictZonas);


};


#endif //PROJAED2_INITIALIZE_H
