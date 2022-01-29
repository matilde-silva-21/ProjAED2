//
// Created by Matilde on 18/01/2022.
//

#include "Stop.h"

Stop::Stop(std::string& code, std::string& name, std::string& zona, float& latitude, float& longitude): code(code), name(name), zona(zona), latitude(latitude), longitude(longitude) {

}

std::string Stop::getCode() const {
    return code;
}

float Stop::getLatitude() const{
    return latitude;
}

float Stop::getLongitude() const{
    return longitude;
}

bool Stop::operator<(const Stop& s1) const {
    return code<s1.code;
}

bool Stop::operator==(const Stop &s1) const {
    return s1.code==code;
}

void Stop::addLine(Line l1) {
    linhas.insert(l1);
}

std::set<Line> Stop::getLines() const {
    return linhas;
}

std::string Stop::getZona() const {
    return zona;
}

bool Stop::operator!=(const Stop &s1) const {
    return s1.code!=code;
}

