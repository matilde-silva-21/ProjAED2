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


class Initialize {

private:
    map<string,int> dictionary;

public:
    void fillDictionary(const map<int, Stop>& paragens);
    static double haversine(double lat1, double lon1, double lat2, double lon2);
    double peso(const Stop& s1, const Stop& s2);
    //esta funcao adiciona as edges e atualiza a informacao das linhas em cada stop
    void addAllEdges(Graph& g1, map<int, Stop> &paragens, const BST<Line>& linhas);
    map<string,int> getDictionary();
    int findMapIndex(string& paragem);

};


#endif //PROJAED2_INITIALIZE_H
