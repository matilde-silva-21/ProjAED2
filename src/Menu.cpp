//
// Created by ASUS on 22/01/2022.
//

#include "Menu.h"
#include <conio.h>

Menu::Menu(){}

void Menu::showMenu() {
    std::cout << "STCP APP" << std::endl;
    std::cout << "Selecting departure and destiny of your trip" << std::endl;
    //calculate the best path between two locations
    std::cout << "1 - Choose departure location (coordinates)" << std::endl;
    std::cout << "2 - Choose destiny location (coordinates)" << std::endl;
    //calculate the best path between two stops
    //need to verify if this path is valid (if it's in lines.csv)
    std::cout << "3 - Choose departure stop" << std::endl;
    std::cout << "4 - Choose destiny stop" << std::endl;
    std::cout << "Selecting the type of 'best trip' you want to do" << std::endl;
    std::cout << "5 - Pass through the minimum number of stops" << std::endl;
    std::cout << "6 - Minimum distance" << std::endl;
    std::cout << "7 - Minimum line changes" << std::endl;
    std::cout << "8 - Cheaper trip" << std::endl;
    //probably some more options, this is just a draft
}

void Menu::takeInput() {
    while (true){
        std::cout << "Please, given the above options, choose what you pretend to do: ";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice) {
            case '1':
                std::cout << "Departure location: ";
                std::cin >> departureLocation;
                std::cout << std::endl;
                if (!destinyLocation.empty()){
                    break;
                }
                //show nearby stops
            case '2':
                std::cout << "Destiny location: ";
                std::cin >> destinyLocation;
                std::cout << std::endl;
/*                std::cout << std::endl;
                std::cout << "Please, input choice: ";
                std::cin >> choice;*/
                //show nearby stops
                continue;
            case '3':
                std::cout << "Departure stop: ";
                std::cin >> departureStop;
                if (!destinyStop.empty()){
                    break;
                }
            case '4':
                std::cout << "Destiny stop: ";
                std::cin >> destinyStop;
                std::cout << std::endl;
/*                std::cout << std::endl;
                std::cout << "Please, input choice: ";
                std::cin >> choice;*/
                continue;
            case '5':
                if ((!departureLocation.empty() && !destinyLocation.empty())) {
                    //calculate the best path for all the stops nearby this location and give the user the best departure stop and the best destiny stop
                    std::cout << "Showing best path given the locations..." << std::endl;
                } else if ((!departureStop.empty() && !destinyStop.empty())) {
                    std::cout << "Showing best path given the paths..." << std::endl;
                    //provide user with this type of path
                } else {
                    std::cout << "You need to select both stops or both locations to know the best path" << std::endl;
                    continue;
                }
                break;
            case '6':
                if ((!departureLocation.empty() && !destinyLocation.empty())) {
                    //calculate the best path for all the stops nearby this location and give the user the best departure stop and the best destiny stop
                    std::cout << "Showing best path given the locations..." << std::endl;
                } else if ((!departureStop.empty() && !destinyStop.empty())) {
                    std::cout << "Showing best path given the paths..." << std::endl;
                    //provide user with this type of path
                } else {
                    std::cout << "You need to select both stops or both locations to know the best path" << std::endl;
                    std::cout << std::endl;
                    continue;
                }
                break;
            case '7':
                if ((!departureLocation.empty() && !destinyLocation.empty())) {
                    //calculate the best path for all the stops nearby this location and give the user the best departure stop and the best destiny stop
                    std::cout << "Showing best path given the locations..." << std::endl;
                } else if ((!departureStop.empty() && !destinyStop.empty())) {
                    std::cout << "Showing best path given the paths..." << std::endl;
                    //provide user with this type of path
                } else {
                    std::cout << "You need to select both stops or both locations to know the best path" << std::endl;
                    std::cout << std::endl;
                    continue;
                }
                break;
            case '8':
                if ((!departureLocation.empty() && !destinyLocation.empty())) {
                    //calculate the best path for all the stops nearby this location and give the user the best departure stop and the best destiny stop
                    std::cout << "Showing best path given the locations..." << std::endl;
                } else if ((!departureStop.empty() && !destinyStop.empty())) {
                    std::cout << "Showing best path given the paths..." << std::endl;
                    //provide user with this type of path
                } else {
                    std::cout << "You need to select both stops or both locations to know the best path" << std::endl;
                    std::cout << std::endl;
                    continue;
                }
                break;
        }
    }
}