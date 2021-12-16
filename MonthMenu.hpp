/*
	MonthMenu: This class handles the month menu and actions
	@file MonthMenu.hpp
	@author Alejandro García
	@version 1.0 2/15/21
*/
#ifndef HEADER_MONTHMENU
#define HEADER_MONTHMENU

#include <iostream>

#include "BudgetPlanner.hpp"
#include "BudgetPlannerMenu.hpp"

using namespace std;
class MonthMenu
{
public:
	static void DisplayMonthMenu(string monthName, BudgetPlanner budget);
	static void LowerMenu(string monthName, BudgetPlanner budget);
	static void AddEntryDisplay(string monthName, BudgetPlanner budget);
	static void ModifyEntryAmountDisplay(string monthName, BudgetPlanner budget);
	static void DeleteEntryInOutDisplay(string monthName, BudgetPlanner budget);
	static void GoBackToBudgetPlanner(BudgetPlanner budget);
};
#endif