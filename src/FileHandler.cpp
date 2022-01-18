//
// Created by Matilde on 18/01/2022.
//


#include "FileHandler.h"

void FileHandler::readLines() {
    std::ifstream file("lines.csv");
    std::string line, word1, word2, start,end, code, name, composite;
    char delim = '-';

    getline(file, line);

    if(file.is_open()){
        while(!file.eof())
        {
            int count=0, count2=0;
            getline(file, line);
            std::stringstream ss1(line);

            while (std::getline(ss1, word1, ',')){
                if(!count) {code = word1; count++;}
                else {
                    composite = word1;
                    std::stringstream ss2(composite);

                    while (std::getline(ss2, word2, '-')){
                        if(count2==0){ name = word2; count2++;}
                        else if(count2==1){start = word2; count2++;}
                        else if(count2==2){end = word2;}
                    }

                }
            }

            Line l1(code,name,start,end);

        }
    }


}
