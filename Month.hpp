#ifndef HEADER_MONTH
#define HEADER_MONTH
#include <iostream>
#include <string>
#include <vector>

#include "Entry.hpp"

using namespace std;

class Month
{
    string name;
    float balance;
    vector<Entry> entries;

    public:
        Month(string nameMonth);
        ~Month();
        string GetName(){return name;};
        void UpdateMonthlyBalance();
        float GetMonthlyBalance ();
        void AddEntry(string newEntryName, float newEntryBudget);
        void ModifyEntry(string entryToModify, float newAmount);
        void DeleteEntry(string entryToDelete);
        void SortEntries();
        void PrintMonth();
};
#endif