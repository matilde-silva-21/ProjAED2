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

class FileHandler {

public:

    //nao tenho a certeza se a funcao deve retornar um vetor ou assim
    void readLines();
    void readStops();

};


#endif //PROJAED2_FILEHANDLER_H
