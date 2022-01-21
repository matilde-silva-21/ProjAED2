//
// Created by Matilde on 18/01/2022.
//

#ifndef PROJAED2_LINE_H
#define PROJAED2_LINE_H
#include "string"
#include "iostream"
#include "forward_list"


class Line {
private:
    //o code é unico por isso as funcoes de comparacao usam apenas esse valor
    std::string code, name, start, end;
    bool night; //true se for um autocarro M, falso caso contrario
    std::forward_list<std::string> percurso0, percurso1;

public:
    Line(std::string code, std::string name, std::string start, std::string end);
    std::forward_list<std::string> readPercurso(char direction);
    bool operator<(const Line& l2) const;
    bool operator==(const Line& l2) const;
    std::string getCode() const;
    bool getNight();
    std::forward_list<std::string> getPercurso0() const;
    std::forward_list<std::string> getPercurso1() const;
};


#endif //PROJAED2_LINE_H
