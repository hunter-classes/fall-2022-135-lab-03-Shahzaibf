// add your code as appropriate 
#include <iostream>
#include "reservoir.h"

int main()
{
  //Test for part A
  std::string date = "05/20/2018";
  std::cout << "Enter date: " << date << "\n";
  std::cout << "East basin storage: " << get_east_storage(date) << " billion gallons \n";
  
  return 0;
}
