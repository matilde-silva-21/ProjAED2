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

void Initialize::addAllEdges(Graph& g1, map<int, Stop> &paragens, const BST<Line>& linhas, Graph& g2) {
    for (auto it1 = linhas.begin() ; it1!=linhas.end() ; it1++){
        auto percurso0 = (*it1).getPercurso0(), percurso1 = (*it1).getPercurso1();

        for(auto it2 = percurso0.begin(); it2!=percurso0.end(); ){
            int index1 = dictionary[*(it2++)];
            if(it2==percurso0.end()) break;
            int index2 = dictionary[*(it2)];
            Stop s1 = paragens[index1], s2 = paragens[index2];
            g1.addEdge(index1,index2, peso(s1,s2));

            if(s1.getZona()!=s2.getZona()) g2.addEdge(zonas[s1.getZona()], zonas[s2.getZona()], 1.0);

            paragens[index1].addLine(*it1);
            paragens[index2].addLine(*it1);
        }

        for(auto it3 = percurso1.begin(); it3!=percurso1.end(); ){
            int index1 = dictionary[*(it3++)];
            if(it3==percurso0.end()) break;
            int index2 = dictionary[*(it3)];
            Stop s1 = paragens[index1], s2 = paragens[index2];
            g1.addEdge(index1,index2, peso(s1,s2));

            if(s1.getZona()!=s2.getZona()) g2.addEdge(zonas[s1.getZona()], zonas[s2.getZona()], 1.0);

            paragens[index1].addLine(*it1);
            paragens[index2].addLine(*it1);
        }
    }
}

void Initialize::fillDictionary(const map<int, Stop> &paragens) {
    for(auto & paragen : paragens){
        dictionary.emplace((paragen.second).getCode(), paragen.first);
        if(zonas.find(paragen.second.getZona())==zonas.end()){
            zonas[paragen.second.getZona()] = zonas.size()+1;
        }
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



map<Line, list<Stop>> Initialize::stopsToLine(const vector<Stop> &s1) {

    auto lastToWork = s1.begin();
    vector<Line> final;
    map<Line, list<Stop>> counter, greg, ret; //para cada linha as stops no percurso
    map<Line, list<Line>> aux;

    for(const Stop & it : s1){
        set<Line> linhas1 = it.getLines();
        for(const Line& l1: linhas1){
            //se a linha nao existir no set
            if(counter.find(l1)==counter.end()) {
                list<Stop> v1;
                v1.push_back(it);
                counter[l1] = v1;
            }
            //se a linha existir
            else{
                counter[l1].push_back(it);
            }

        }
    }

    //ate agora isto so funciona para viagens com uma linha, sem troca, mesmo que seja na mesma paragem

    //se o fim da liata coincidir com o inicio da lista entao estao juntas!!!!!!!!!!

    for(auto it = counter.begin(); it!=counter.end(); ){
        if(it->second.size() == s1.size()) {ret[it->first] = counter[it->first]; return ret;}
        if(it->second.size()<2) it=counter.erase(it);
        else{it++;}
    }

    //esta parte compara a parte do percurso coincidente com cada linha, o ideal era que para cada linha nao houvesse mais que 1 paragem repetida
    for(auto it = counter.begin(); it!=counter.end(); it++){
        cout <<endl<< "linha "<<it->first.getCode() <<endl;
        for(auto it3: it->second){cout << it3.getCode() << " ";}
        for(auto it2 = it; it2!=counter.end(); it2++){
            if(it2->second.front() == it->second.back() && it2->first.getCode()!=it->first.getCode()){
                cout << it2->first.getCode()<<" ";
                aux[it->first].push_back(it2->first);
            }
        }
    }


    for(auto it = aux.begin(); it!=aux.end(); it++){
        if(!(counter[it->first].front()==s1.front())) continue;
        //se for uma route de 1 so troca com 1 unica paragem coincidente
        for(auto it2 = it->second.begin() ; it2!=it->second.end(); it2++){
            if(counter[*it2].back() == s1.back()){
                cout << "linha "<<it->first.getCode() << " ligada a linha "<<it2->getCode()<<" na paragem "<<counter[*it2].front().getCode()<<endl;
                ret[it->first] = counter[it->first];
                ret[*it2] = counter[*it2];
            }
            else{

            }
        }

    }

    return ret;

}

map<string, int> Initialize::getZonas() {
    return zonas;
}

vector<int> Initialize::cheapestRoute(Graph& g1, Graph& g2, int a, int b, map<int, Stop>& paragens, map<int, string>& dictZonas) {
    if(paragens[a].getZona()==paragens[b].getZona()) return g1.dijkstra(a,b);

    map<string,bool> zonasPermitidas;
    int zonaS1 = zonas[paragens[a].getZona()] , zonaS2 = zonas[paragens[b].getZona()];
    for(const auto& it: zonas){
        zonasPermitidas[it.first] = true;
    }

    vector<int> zuzu = g2.bfs(zonaS1, zonaS2);

    for(const auto& it: zonas){
        zonasPermitidas[it.first] = false;
    }
    for(auto it: zuzu){
        zonasPermitidas[dictZonas[it]] = true;
    }

    vector<int> result = g1.dijkstra2(a,b,zonasPermitidas, paragens);
    //se nao houver rota fiavel pelas zonas escolhidas entao usar o algoritmo normal
    if(result.empty()) return g1.dijkstra(a,b);
    else return result;

}


