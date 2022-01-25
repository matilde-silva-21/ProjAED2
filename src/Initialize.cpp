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

Stop Initialize::closestStation(map<int, Stop> &paragens, float latitude, float longitude) {
    float min = FLOAT_MAX;
    auto final = paragens.end();
    for(auto it = paragens.begin(); it!=paragens.end() ; it++){
        float distance = haversine(it->second.getLatitude(), it->second.getLongitude(),latitude,longitude);
        if(min>distance){
            min = distance;
            final = it;
        }
    }
    return final->second;
}

vector<Line> Initialize::stopsToLine(const vector<Stop> &s1) {

    vector<Line> final;
    set<Line> matchingLines;
    map<Line, set<Stop>> counter; //para cada linha as stops no percurso
    int check = 1;

    for(const Stop & it : s1){
        set<Line> linhas1 = it.getLines();
        for(const Line& l1: linhas1){
            //se a linha nao existir no set
            if(matchingLines.insert(l1).second) {
                set<Stop> v1;
                v1.insert(it);
                counter[l1] = v1;
            }
            //se a linha existir
            else{
                counter[l1].insert(it);
            }
        }
    }

    //ate agora isto so funciona para viagens com uma linha, sem troca, mesmo que seja na mesma paragem

    for(auto it = counter.begin(); it!=counter.end(); it++){
        if(it->second.size() == s1.size()) final.push_back(it->first);
    }

    return final;
}
