//
// Created by Matilde on 18/01/2022.
//

#include <fstream>
#include "Line.h"

Line::Line(std::string code, std::string name, std::string start, std::string end): code(code), name(name), start(start), end(end) {

    if(code[code.length()-1]=='M') this->night= true;
    else this->night = false;
}

void Line::readPercurso(char& direction) {
    std::ifstream file("line_"+code+"_"+direction+".csv");
    std::string nlines,code1;
    std::getline(file, nlines);
    int n = std::stoi(nlines);
    if(n!=0){
        while(n!=0){
            std::getline(file, code1);
            n--;
            if(direction=='0') {
                auto it = percurso0.before_begin();
                percurso0.emplace_after(it, code1);
            }
            else if(direction=='1'){
                auto it = percurso1.before_begin();
                percurso1.emplace_after(it, code1);
            }

        }
    }
}

bool Line::operator<(const Line &l2) const{
    return code<l2.code;
}

bool Line::operator==(const Line &l2) const{
    return code==l2.code;
}

std::string Line::getCode() {
    return code;
}

bool Line::getNight() {
    return night;
}
