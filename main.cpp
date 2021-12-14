#include <iostream>
#include <string>
#include <vector>

#include "Month.hpp"

using namespace std;

int main () {
  //Tests Month:
  //initialize a month and add some data
  Month testMonth("January");

  testMonth.PrintMonth();
  
  //Use all the functions
  cout << "Add entries: " << endl;
  testMonth.AddEntry("rent", 33.4f);
  testMonth.AddEntry("car", 43.4f);
  testMonth.AddEntry("shop", 53.4f);

  testMonth.PrintMonth();
  
  cout << "Delete entry: " << endl;
  testMonth.DeleteEntry("rent");

  testMonth.PrintMonth();
  
  cout << "Modify entry: " << endl;
  testMonth.ModifyEntry("car", 200.3f);

  testMonth.PrintMonth();

  return 0;
}