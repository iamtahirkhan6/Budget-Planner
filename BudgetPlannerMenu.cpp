#include "BudgetPlannerMenu.hpp"

void BudgetPlannerMenu::DisplayMainMenu(BudgetPlanner budget)
{
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "=====================================================\n";
    cout << " \tWelcome to the Budget Planner\t \n ";
    cout << " \t\tTeam 1\t \n";
    cout << "=====================================================\n";

    budget.PrintBudgetPlanner();

    cout << "-----------------------------------------------------\n";
}

void BudgetPlannerMenu::MainMenu(BudgetPlanner budget)
{
    DisplayMainMenu(budget);

    int choice;
    //Choices:
    printf("1.Open month\n");
    printf("2.Exit\n");

    do
    {
        cout << "Enter your choice(1-2): ";
        cin >> choice;

        switch (choice)
        {
            case 1: OpenMonth(budget); break;
            case 2: ExitProgram(budget); break;
            default: cout << "Invalid! \n"; break;
        }
    } while (!(choice > 0 && choice < 3));
}

void BudgetPlannerMenu::OpenMonth(BudgetPlanner budget)
{
    string monthToCheck;
    cout << "Enter the month name: ";
    cin >> monthToCheck;

    if (budget.IsMonthInBudgetPlanner(monthToCheck))
    {
        MonthMenu::LowerMenu(monthToCheck, budget);
    }
    else
    {
        cout << "\nError: Month not in Budget Planner!\n";
        MainMenu(budget);
    }
}

void BudgetPlannerMenu::ExitProgram(BudgetPlanner budget)
{
    vector<string> vecOfStr;
    string dataEntry, currentMonth;

    //Go through the month list
    for (decltype(budget.months.size()) i = 0; i < budget.months.size(); i++)
    {
        dataEntry = "";
        currentMonth = "";
        currentMonth = budget.months.at(i).GetName();
        for (decltype(budget.months.at(i).GetSize()) j = 0; j < budget.months.at(i).GetSize(); j++)
        {
            //If Income
            if (budget.months.at(i).entries.at(j).BudgetImpact()>0)
                dataEntry = currentMonth + " income " + budget.months.at(i).entries.at(j).GetSource() + " " + to_string(abs(budget.months.at(i).entries.at(j).BudgetImpact()));
            else
                dataEntry = currentMonth + " expense " + budget.months.at(i).entries.at(j).GetSource() + " " + to_string(abs(budget.months.at(i).entries.at(j).BudgetImpact()));

            vecOfStr.push_back(dataEntry);
        }
    }
    // for each month, go through the entries
    // format each entry as a line in the vecofStr

    BudgetPlanner::WriteDocument(vecOfStr);
    exit(0);
}