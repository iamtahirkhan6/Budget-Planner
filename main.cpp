#include <iostream>
#include <string>
#include <vector>

#include "Month.hpp"

using namespace std;

int main () 
{
  //Tests Month:
  //initialize a month and add some data
  Month testMonth(1);

  testMonth.PrintMonth();
  
  //Use all the functions
  cout << "Add entries: " << endl;
  testMonth.AddEntry("Rent", 33.4f);
  testMonth.AddEntry("Car", 43.4f);
  testMonth.AddEntry("Shop", 53.4f);

  testMonth.PrintMonth();
  
  cout << "Delete entry: " << endl;
  testMonth.DeleteEntry("Rent");

  testMonth.PrintMonth();
  
  cout << "Modify entry: " << endl;
  testMonth.ModifyEntry("Car", 200.3f);

  testMonth.PrintMonth();

  return 0;
}