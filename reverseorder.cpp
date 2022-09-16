#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"
#include <string>
#include <sstream>
#include <iomanip>

void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dData;
    double EastSt, EastEl, WestSt, WestEl;

    int month1 = std::stoi(date1.substr(0,2));
    int day1 = std::stoi(date1.substr(3,5));
    int month2 = std::stoi(date2.substr(0,2));
    int day2 = std::stoi(date2.substr(3,5));

    int num = 1;
    //to find out how many moves we have to make 
    int tempmonth = month2;
    int tempday = day2;

    while(!(tempmonth == month1) && !(tempday == day1)){
        if(tempday == 0){
            tempmonth--;
        } 
        if (tempmonth == 4 || tempmonth == 6 || tempmonth == 9 || tempmonth == 11) {
                tempday = 30;
        } else {
            tempday = 31;   
        }
        num++;
        tempday--;
    }
    double WestElArray [num];
    std::string dateArray[num];
    int i = 0;
    int temp = 0;

    while(!(month2 == month1) || !(day2 == day1)) {
        if(day2 == 0) {
            month2--;
            if (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) {
                day2 = 30;
            } else {
                day2 = 31;        
        }
        if(month2 == 2) {
            day2 = 28;
        }
        }
        if(day2 == 0) {
            temp = 0;
        } else {
        std::ostringstream oss;
        
        auto cout_buff = std::cout.rdbuf(oss.rdbuf());
        
        std::cout << std::setw(2) << std::setfill('0') << std::to_string(month2);
        std::cout << "/";
        std::cout << std::setw(2) << std::setfill('0') << std::to_string(day2) << "/2018";
            
        std::cout.rdbuf(cout_buff);
        
        std::string dayTemp = oss.str();

        dateArray[i] = dayTemp;
        i++;
        day2--;
        }
    }
        dateArray[num-1] = date1;

    int check = 0;
    int check2 = num - 1;
    while(fin >> dData >> EastSt >> EastEl >> WestSt >> WestEl) {
    fin.ignore(INT_MAX, '\n');

    if(dData == dateArray[check]) {
        WestElArray[check2] = WestEl;
        check--;
        check2++;
    }
}
    for(int i = 0; i < num; i++) {
        std::cout << dateArray[i] << " " << WestElArray[num-i-1] << "\n";
    }
}
