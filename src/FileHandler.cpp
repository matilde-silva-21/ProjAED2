//
// Created by Matilde on 18/01/2022.
//


#include "FileHandler.h"

BST<Line> FileHandler::readLines(bool night) {
    std::ifstream file("lines.csv");
    std::string line, word1, word2, start,end, code, name, composite;

    BST<Line> final(Line("","","",""));

    getline(file, line);

    if(file.is_open()){
        while(!file.eof()) {
            int count = 0, count2 = 0;
            getline(file, line);
            std::stringstream ss1(line);

            while (std::getline(ss1, word1, ',')) {
                if (!count) {
                    code = word1;
                    count++;
                }
                else {
                    composite = word1;
                    std::stringstream ss2(composite);

                    while (std::getline(ss2, word2, '-')) {
                        if (count2 == 0) {
                            name = word2;
                            count2++;
                        }
                        else if (count2 == 1) {
                            start = word2;
                            count2++;
                        }
                        else if (count2 == 2) { end = word2; }
                    }

                }
            }

            Line l1(code, name, start, end);

            l1.readPercurso('1');
            l1.readPercurso('0');

            if(night && l1.getNight()){final.insert(l1);}
            else if(!night && !l1.getNight()){final.insert(l1);}

        }
    }

    file.close();

    return final;

}

map<int, Stop> FileHandler::readStops() {

    std::ifstream file("stops.csv");
    std::string word, name, code, line, zone;
    float latitude, longitude;
    map<int, Stop> final;
    int nstops=0;


    getline(file, line);

    if(file.is_open()){
        while(!file.eof()){
            int count=0;

            std::getline(file, line);
            std::stringstream ss(line);

            while(std::getline(ss,word, ',')){
                if(count==0){ code = word; count++;}
                else if(count==1){name = word; count++;}
                else if(count==2){zone = word; count++;}
                else if(count==3){latitude = std::stof(word); count++;}
                else if(count==4){longitude = std::stof(word); count++;}
            }

            nstops++;
            Stop s1(code,name,zone,latitude,longitude);
            final.emplace(nstops, s1);
        }
    }

    file.close();

    return final;
}
