//
// Created by Matilde on 18/01/2022.
//

#ifndef PROJAED2_STOP_H
#define PROJAED2_STOP_H


#include <string>
#include "Line.h"
#include "set"

class Stop {
private:
    std::string code, name, zona;
    float latitude, longitude;
    std::set<Line> linhas;

public:
    Stop(std::string& code,std::string& name, std::string& zona, float& latitude, float& longitude);
    std::string getCode() const;
    float getLatitude() const;
    float getLongitude() const;
    Stop(){latitude=0.0; longitude = 0.0;}
    bool operator<(const Stop& s1) const;
    bool operator==(const Stop& s1) const;
    bool operator!=(const Stop& s1) const;
    void addLine(Line l1);
    std::set<Line> getLines() const;
    std::string getZona() const;
};


#endif //PROJAED2_STOP_H
