// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include <string>

double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1); // exit if failed to open the file
}
    std::string junk;
    getline(fin,junk);

    std::string dData;
    double eastSt;

    while(fin >> dData >> eastSt){
        fin.ignore(INT_MAX, '\n');
        if (dData == date){
            return eastSt;
        }
    }
    fin.close();
    return 0;
}

double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dData;
    double eastSt;
    double minimum = INT_MAX;

    while (fin >> dData >> eastSt){
        fin.ignore(INT_MAX,'\n');
        if (eastSt < minimum){
            minimum = eastSt;
        }
    }
    fin.close();
    return minimum;
}

double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dData;
    double eastSt;
    double maximum = INT_MIN;

    while (fin >> dData >> eastSt){
        fin.ignore(INT_MAX,'\n');
        if (eastSt > maximum){
            maximum = eastSt;
        }
    }
    fin.close();
    return maximum;
}

std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dData;
    double eastSt, eastEl, westSt, westEl;

    while(fin >> dData >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX,'\n');

        if (dData == date){
            return eastEl > westEl ? "East" : eastEl < westEl ? "West" : "Equal";
        }
    }
    fin.close();
    return 0;
}