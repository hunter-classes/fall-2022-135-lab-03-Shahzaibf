// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  

  //Test for part A
  std::string date = "05/20/2018";
  std::cout << "Enter date: " << date << "\n";
  std::cout << "East basin storage: " << get_east_storage(date) << " billion gallons \n";
  
  //Test for part B
  std::cout << "Minimum storage in East basin: " << get_min_east() << " billion gallons \n";
  std::cout << "Maximum storage in East basin " << get_max_east() << " billion gallons \n";

  //test for part C
  std::cout << "09/13/2018: " << compare_basins("09/13/2018") <<"\n";
  std::cout << "09/17/2018: " << compare_basins("09/17/2018") <<"\n";

  //test for part D
  reverse_order("01/17/2018", "01/20/2018");
  std::cout << "\n";
  reverse_order("05/30/2018", "06/02/2018");
  std::cout << "\n";
  
} 
