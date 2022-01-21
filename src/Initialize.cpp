//
// Created by Matilde on 21/01/2022.
//

#include "Initialize.h"

double Initialize::haversine(double lat1, double lon1, double lat2, double lon2)
{
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

double Initialize::peso(const Stop& s1, const Stop& s2){
    return haversine(s1.getLatitude(), s1.getLongitude(), s2.getLatitude(), s2.getLongitude());
}

void Initialize::addAllEdges(Graph& g1, map<int, Stop> &paragens, const BST<Line>& linhas) {
    for (auto it1 = linhas.begin() ; it1!=linhas.end() ; it1++){
        auto percurso0 = (*it1).getPercurso0(), percurso1 = (*it1).getPercurso1();

        for(auto it2 = percurso0.begin(); it2!=percurso0.end(); ){
            int index1 = dictionary[*(it2++)];
            if(it2==percurso0.end()) break;
            int index2 = dictionary[*(it2)];
            Stop s1 = paragens[index1], s2 = paragens[index2];
            g1.addEdge(index1,index2, peso(s1,s2));

            paragens[index1].addLine(*it1);
            paragens[index2].addLine(*it1);
        }

        for(auto it3 = percurso1.begin(); it3!=percurso1.end(); ){
            int index1 = dictionary[*(it3++)];
            if(it3==percurso0.end()) break;
            int index2 = dictionary[*(it3)];
            Stop s1 = paragens[index1], s2 = paragens[index2];
            g1.addEdge(index1,index2, peso(s1,s2));

            paragens[index1].addLine(*it1);
            paragens[index2].addLine(*it1);
        }
    }
}

void Initialize::fillDictionary(const map<int, Stop> &paragens) {
    for(auto & paragen : paragens){
        dictionary.emplace((paragen.second).getCode(), paragen.first);
    }
}

map<string, int> Initialize::getDictionary() {
    return dictionary;
}

int Initialize::findMapIndex(string& paragem) {
    return  dictionary[paragem];
}
