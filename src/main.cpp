#include <iostream>
#include "FileHandler.h"

int main() {
    FileHandler f;
    BST<Line> diurno = f.readLines(false), noturna=f.readLines(true);

    map<int,Stop> paragens = f.readStops();

    for(auto it = paragens.begin(); it!=paragens.end() ; it++){
        cout << it->first <<" "<<it->second.getCode()<<endl;
    }

}
