/*
    main: Main file, runs the whole program. Includes some tests.
    @file main.c
    @author Alejandro García, Ruthra Bellen, Smruthi Ravichandran, Tahir Uddin Khan
    @version 1.0 2/15/21

   <copyright file="«BudgetPlanner»" company="«SRH»">
      Author: Alejandro García, Ruthra Bellen, Smruthi Ravichandran, Tahir Uddin Khan
      Copyright (c). All rights reserved.
   </copyright>
*/
#include <iostream>
#include <string>
#include <vector>

#include "BudgetPlanner.hpp"
#include "BudgetPlannerMenu.hpp"

using namespace std;

//Sample Data for the tests
BudgetPlanner sampleData()
{
    BudgetPlanner myBudget;
    myBudget.AddMonth("January");
    myBudget.AddMonth("February");
    myBudget.AddMonth("March");
    myBudget.AddMonth("April");

    int testMonthPosition = myBudget.AccessMonth("January");
    myBudget.months.at(testMonthPosition).AddEntry("rent", false, 533.4f);
    myBudget.months.at(testMonthPosition).AddEntry("car", true, 23.4f);
    myBudget.months.at(testMonthPosition).AddEntry("shop", true, 53.4f);


    testMonthPosition = myBudget.AccessMonth("February");
    myBudget.months.at(testMonthPosition).AddEntry("rent", false, 333.4f);
    myBudget.months.at(testMonthPosition).AddEntry("car", true, 63.4f);
    myBudget.months.at(testMonthPosition).AddEntry("shop", true, 53.4f);

    testMonthPosition = myBudget.AccessMonth("March");
    myBudget.months.at(testMonthPosition).AddEntry("rent", false, 633.4f);
    myBudget.months.at(testMonthPosition).AddEntry("car", true, 13.4f);
    myBudget.months.at(testMonthPosition).AddEntry("shop", true, 53.4f);

    testMonthPosition = myBudget.AccessMonth("April");
    myBudget.months.at(testMonthPosition).AddEntry("rent", false, 133.4f);
    myBudget.months.at(testMonthPosition).AddEntry("car", true, 233.4f);
    myBudget.months.at(testMonthPosition).AddEntry("shop", true, 53.4f);

    return myBudget;
}

//Simple tests for the Budget Planner functionalities
void tests()
{
    //Tests BudgetPlanner:
    cout << "Start Budget: " << endl;
    BudgetPlanner myBudget;
    myBudget.AddMonth("January");
    myBudget.AddMonth("February");
    myBudget.AddMonth("March");
    myBudget.AddMonth("April");

    myBudget.PrintBudgetPlanner();

    cout << "Add existing month: " << endl;
    myBudget.AddMonth("February");

    myBudget.PrintBudgetPlanner();

    //Tests Month:
    //initialize a month and add some data
    cout << "Access January: " << endl;
    int testMonthPosition = myBudget.AccessMonth("January");

    myBudget.months.at(testMonthPosition).PrintMonth();

    //Use all the functions
    cout << "Add entries: " << endl;
    myBudget.months.at(testMonthPosition).AddEntry("rent", false, 833.4f);
    myBudget.months.at(testMonthPosition).AddEntry("car", true, 43.4f);
    myBudget.months.at(testMonthPosition).AddEntry("shop", true, 53.4f);

    myBudget.months.at(testMonthPosition).PrintMonth();

    cout << "Delete entry: " << endl;
    myBudget.months.at(testMonthPosition).DeleteEntry("shop");

    myBudget.months.at(testMonthPosition).PrintMonth();

    cout << "Modify entry: " << endl;
    myBudget.months.at(testMonthPosition).ModifyEntry("car", 200.3f);

    myBudget.months.at(testMonthPosition).PrintMonth();

    //Double test
    cout << "Show updated Budget: " << endl;
    myBudget.PrintBudgetPlanner();
}

int main () {
    BudgetPlanner budget;
    vector<string> rawVector;
    vector<string> splitVector;

    //If the file can't be opened, change the path to where your budget.txt location
    bool isRead = budget.ReadDocument("D://SRH//AdvProg//Task4//BudgetPlanner//BudgetPlanner//budget.txt", rawVector);

    if (!isRead)
        BudgetPlannerMenu::ExitProgram(budget);

    //Splits the data
    budget.SplitString(rawVector, splitVector);

    //Enter the data in the budget instance
    int counter = 0;
    string monthName, source;
    bool isExpense;
    float amount;

    for (int i = 0; i < splitVector.size(); i++) {
        switch (counter)
        {
            case 0: {
                monthName = splitVector.at(i);
                counter++;
                break;
            }
            case 1: {
                if (!(splitVector.at(i) == "expense"))
                    isExpense = false;
                else
                    isExpense = true;
                counter++;
                break;
            }
            case 2: {
                source = splitVector.at(i);
                counter++;
                break;
            }
            case 3: {
                amount = stof(splitVector.at(i));
                budget.AddMonth(monthName);
                int monthPosition = budget.AccessMonth(monthName);
                budget.months.at(monthPosition).AddEntry(source, isExpense, amount);
                counter=0;
                break;
            }
            default: cout << "Invalid! \n"; break;
        }
    }

    //Starts the program
    BudgetPlannerMenu::MainMenu(budget);
}