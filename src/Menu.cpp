//
// Created by ASUS on 22/01/2022.
//

#include "Menu.h"
#include <conio.h>

void Menu::Menu(){}

void Menu::showMenu() {
    std::cout << "STCP APP" << endl;
    std::cout << "Press the indicated below numbers to select what you want to do" << std::endl;
    //calculate the best path between two locations
    std::cout << "1 - Choose departure location (coordinates)" << std::endl;
    std::cout << "2 - Choose destiny location (coordinates)" << std::endl;
    //calculate the best path between two stops
    //need to verify if this path is valid (if it's in lines.csv)
    std::cout << "3 - Choose departure stop" << std::endl;
    std::cout << "4 - Choose destiny stop" << std::endl;
    std::cout << "Now press the indicated below numbers to choose the type of path you want"
    std::cout << "5 - Pass through the minimum number of stops" << std::endl;
    std::cout << "6 - Minimum distance" << std::endl;
    std::cout << "7 - Minimum line changes" << std::endl;
    std::cout << "8 - Cheaper trip" << std::endl;
    //probably some more options, this is just a draft
    }
}

void Menu::takeInput() {
        switch (choice) {
            case '1':
                std::cin >>  departureLocation;
                //show nearby stops
                break;
            case '2':
                std::cin >> departureStop;
                //show nearby stops
                break;
            case '3':
                std::cin >> departureStop;
                break;
            case '4':
                std::cin >> destinyStop;
                break;
            case '5':
                if (departureStop.empty() || destinyStop.empty()) {
                    std::cout << "You can't choose the type of path before selecting both stops!" << std::endl;
                    showMenu():
                }
                else {
                    //provide user with this type of path
                }
                break;
            case '6':
                if (departureStop.empty() || destinyStop.empty()) {
                    std::cout << "You can't choose the type of path before selecting both stops!" << std::endl;
                    showMenu():
                }
                else {
                    //provide user with this type of path
                }
                break;
            case '7':
                if (departureStop.empty() || destinyStop.empty()) {
                    std::cout << "You can't choose the type of path before selecting both stops!" << std::endl;
                    showMenu():
                }
                else {
                    //provide user with this type of path
                }
                break;
            case '8':
                if (departureStop.empty() || destinyStop.empty()) {
                    std::cout << "You can't choose the type of path before selecting both stops!" << std::endl;
                    showMenu():
                }
                else {
                    //provide user with this type of path
                }
                break;
        }
    }

}