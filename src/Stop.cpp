//
// Created by Matilde on 18/01/2022.
//

#include "Stop.h"

Stop::Stop(std::string& code, std::string& name, std::string& zona, float& latitude, float& longitude): code(code), name(name), zona(zona), latitude(latitude), longitude(longitude) {

}

std::string Stop::getCode() {
    return code;
}
