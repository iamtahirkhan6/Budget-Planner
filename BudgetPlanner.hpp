/*
	BudgetPlanner: This class handles the list of months and the reading/writing of files.
	@file BudgetPlanner.hpp
	@author Alejandro García, Ruthra Bellen
	@version 1.0 2/15/21
*/
#ifndef HEADER_BUDGETPLANNER
#define HEADER_BUDGETPLANNER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Month.hpp"

using namespace std;

class BudgetPlanner
{
public:
	vector<Month> months;

	bool IsMonthInBudgetPlanner(string monthName);
	void AddMonth(string monthName);
	int AccessMonth(string monthName);
	void PrintBudgetPlanner();
	bool ReadDocument(string fileName, vector<string>& vecOfStrs);
	static void WriteDocument(vector<string>& vecOfStrs);
	void SplitString(vector<string>& vecOfStr, vector<string>& v);
};
#endif