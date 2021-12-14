#ifndef HEADER_ENTRY
#define HEADER_ENTRY

#include <string.h>
#include <iostream>

using namespace std;

class Entry
{
  public:
    string source;
    float amount;

    Entry(string entryName, float nAmount);
    float GetAmount();
    string GetSource();
    double BudgetImpact();
    void ModifyAmount();
};

#endif