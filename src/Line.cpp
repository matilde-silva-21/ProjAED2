//
// Created by Matilde on 18/01/2022.
//

#include "Line.h"

Line::Line(std::string code, std::string name, std::string start, std::string end): code(code), name(name), start(start), end(end) {

    if(code[code.length()-1]=='M') this->night= true;
    else this->night = false;
}
