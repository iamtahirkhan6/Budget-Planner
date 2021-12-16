/*
    Month: This class handles a Month, with all the entries in it.
    @file Month.hpp
    @author Alejandro García
    @version 1.0 2/15/21
*/
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

    public:
    vector<Entry> entries;

    Month(string nameMonth);
    ~Month();
    string GetName(){return name;};
    void UpdateMonthlyBalance();
    float GetMonthlyBalance();
    int GetSize();
    void AddEntry(string newEntryName, bool isExpense, float newEntryBudget);
    void ModifyEntry(string entryToModify, float newAmount);
    void DeleteEntry(string entryToDelete);
    void SortEntries();
    void PrintMonth();
};
#endif