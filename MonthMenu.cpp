#include "MonthMenu.hpp"

void MonthMenu::DisplayMonthMenu(string monthName, BudgetPlanner budget)
{
    int monthPosition = budget.AccessMonth(monthName);

    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n";
    cout << "===================================================== \n";
    cout << "\t\t" << monthName << "\t \n"; 
    cout << "\t\tBudget: " << budget.months.at(monthPosition).GetMonthlyBalance() << endl;
    cout << "=====================================================\n";
    
    budget.months.at(monthPosition).PrintMonth();

    cout << "-----------------------------------------------------\n";
}

void MonthMenu::LowerMenu(string monthName, BudgetPlanner budget)
{
    DisplayMonthMenu(monthName, budget);

    int choice;

    cout << " 1.Add entry\n";
    cout << " 2.Modify entry \n";
    cout << " 3.Delete entry \n";
    cout << " 4.Go Back \n";
    cout << " 5.Exit Program \n";

    do
    {
        cout << "Enter your choice(1-5): ";
        cin >> choice;

        switch (choice)
        {
            case 1: AddEntryDisplay(monthName, budget); break;
            case 2: ModifyEntryAmountDisplay(monthName, budget); break;
            case 3: DeleteEntryInOutDisplay(monthName, budget); break;
            case 4: GoBackToBudgetPlanner(budget); break;
            case 5: BudgetPlannerMenu::ExitProgram(budget); break;
            default: cout << "Invalid! \n"; break;
        }
    } while (!(choice > 0 && choice < 6));
}

void MonthMenu::AddEntryDisplay(string monthName, BudgetPlanner budget)
{
    string source;
    bool isExpense;
    float amount;

    int monthPosition = budget.AccessMonth(monthName);

    cout << "Enter the source: ";
    cin >> source;

    cout << "Enter the amount: ";
    cin >> amount;

    cout << "Is it income(0) or expense(1): ";
    cin >> isExpense;

    budget.months.at(monthPosition).AddEntry(source, isExpense, amount);

    LowerMenu(monthName, budget);
}

void MonthMenu::ModifyEntryAmountDisplay(string monthName, BudgetPlanner budget)
{
    string source;
    float newAmount;

    int monthPosition = budget.AccessMonth(monthName);

    cout << "Enter the source of the entry to modify its amount: ";
    cin >> source;

    cout << "Enter the new amount: ";
    cin >> newAmount;

    budget.months.at(monthPosition).ModifyEntry(source, newAmount);

    LowerMenu(monthName, budget);
}

void MonthMenu::DeleteEntryInOutDisplay(string monthName, BudgetPlanner budget)
{
    string source;

    int monthPosition = budget.AccessMonth(monthName);

    cout << "Enter the source of the entry to delete: ";
    cin >> source;

    budget.months.at(monthPosition).DeleteEntry(source);

    LowerMenu(monthName, budget);
}

void MonthMenu::GoBackToBudgetPlanner(BudgetPlanner budget)
{
    BudgetPlannerMenu::MainMenu(budget);
}