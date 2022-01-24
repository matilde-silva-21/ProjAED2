//
// Created by ASUS on 22/01/2022.
//

#ifndef PROJAED2_MENU_H
#define PROJAED2_MENU_H

#include <string>
#include <iostream>

class Menu {
private:
    std::string departureStop, destinyStop, departureLocation, destinyLocation;
    char choice;

public:
    Menu();
    void showMenu();
    void takeInput();
};


#endif //PROJAED2_MENU_H
