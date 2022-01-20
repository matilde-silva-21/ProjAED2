//
// Created by Matilde on 18/01/2022.
//

#ifndef PROJAED2_STOP_H
#define PROJAED2_STOP_H


#include <string>

class Stop {
private:
    std::string code, name, zona;
    float latitude, longitude;

public:
    Stop(std::string& code,std::string& name, std::string& zona, float& latitude, float& longitude);
    std::string getCode();


};


#endif //PROJAED2_STOP_H
