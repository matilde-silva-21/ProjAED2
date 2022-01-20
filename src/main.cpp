#include <iostream>
#include "FileHandler.h"
#include <cmath>
#include <algorithm>

static double haversine(double lat1, double lon1, double lat2, double lon2)
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

void addAllEdges(Graph& g1, const map<int,Stop>& paragens, const BST<Line>& linhas){
    for (auto it1 = linhas.begin() ; it1!=linhas.end() ; it1++){
        auto percurso0 = (*it1).getPercurso0(), percurso1 = (*it1).getPercurso1();
        for(auto code : percurso0){
            auto result = std::find_if(paragens.begin(),paragens.end(),[code](const auto& it3) {return it3.second == code;});
            if(result!=paragens.end()){

            }
        }
    }

}



int main() {
    FileHandler f;
    BST<Line> diurno = f.readLines(false), noturna=f.readLines(true);

    map<int,Stop> paragens = f.readStops();

    Graph g1(paragens.size(),true);

    //como é que defino as edges todas?
    //funcao que le todas as forwards list dos autocarros, cross search as stops no mapa e depois adiciona as edges de acordo?


}
