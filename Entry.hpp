/*
	BudgetPlanner: This class handles the list of months and the reading/writing of files.
	@file Entry.hpp
	@author Alejandro García
	@version 1.0 2/15/21
*/
#ifndef HEADER_ENTRY
#define HEADER_ENTRY

#include <string>
using namespace std;

class Entry
{
  string source;
  bool isExpense;
  float amount;

public:
  Entry(string s, bool b, float n) : source(s),isExpense(b), amount(n) {};
  string GetSource(){return source;};
  void SetAmount(float newAmount) { amount = newAmount;};
  float BudgetImpact();
};
#endif