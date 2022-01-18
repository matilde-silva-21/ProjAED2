//
// Created by Matilde on 18/01/2022.
//

#ifndef PROJAED2_LINE_H
#define PROJAED2_LINE_H
#include "string"
#include "iostream"


class Line {
private:
    std::string code, name, start, end;
    bool night; //true se for um autocarro M, falso caso contrario

public:
    Line(std::string code, std::string name, std::string start, std::string end);
};


#endif //PROJAED2_LINE_H
