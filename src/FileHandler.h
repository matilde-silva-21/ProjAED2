//
// Created by Matilde on 18/01/2022.
//

#ifndef PROJAED2_FILEHANDLER_H
#define PROJAED2_FILEHANDLER_H

#include "fstream"
#include "sstream"
#include "iostream"
#include "Line.h"
#include "Stop.h"
#include "set"
#include "bst.h"
#include "graph.h"
#include "map"

class FileHandler {

public:

    BST<Line> readLines(bool night); //se for true retorna so as linhas noturnas, caso contrario só as diurnas
    map<int, Stop> readStops();

};


#endif //PROJAED2_FILEHANDLER_H
