/*
	BudgetPlannerMenu: This class handles the Main Menu of the BP, and its actions.
	@file BudgetPlannerMenu.hpp
	@author Alejandro García
	@version 1.0 2/15/21
*/
#ifndef HEADER_BUDGETMENU
#define HEADER_BUDGETMENU

#include <iostream>

using namespace std;

#include "BudgetPlanner.hpp"
#include "MonthMenu.hpp"

class BudgetPlannerMenu
{
public:
	static void DisplayMainMenu(BudgetPlanner budget);
	static void MainMenu(BudgetPlanner budget);
	static void OpenMonth(BudgetPlanner budget);
	static void ExitProgram(BudgetPlanner budget);
};
#endif