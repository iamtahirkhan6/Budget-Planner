#include "Month.hpp"

Month::Month(string nameMonth)
{
  name = nameMonth;
  balance = 0;
}

Month::~Month()
{
  entries.clear();
}

void Month::UpdateMonthlyBalance()
{
  float newBalance = 0;
  //TODO->BudgetImpact to calculate Balance instead of direct access
  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    newBalance += entries.at(i).amount;
  }

  balance = newBalance;
}

float Month::GetMonthlyBalance () {
  UpdateMonthlyBalance();
  return balance;
}

void Month::AddEntry(string newEntryName, float newEntryBudget)
{
  Entry newEntry = Entry(newEntryName, newEntryBudget);
  entries.push_back(newEntry);
}

void Month::ModifyEntry(string entryToModify, float newAmount)
{
  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    if(entries.at(i).source==entryToModify)
    {
      //TODO->Call the modify amount function in Entry instead of direct assign
      entries.at(i).amount = newAmount; 
      break;
    }
  }
}

void Month::DeleteEntry(string entryToDelete)
{
  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    if(entries.at(i).source==entryToDelete)
    {
      entries.erase(entries.begin()+i);
      break;
    }
  }
}

//TODO
void Month::SortEntries()
{
    
}

void Month::PrintMonth()
{
  //TODO - remove these
  cout << "Month name: " << GetName() << endl;
  cout << "Budget: " << GetMonthlyBalance() << endl;;

  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    //TODO -> Used GetSource/Amount methods instead of direct access
    cout << entries.at(i).source << " (" << i << "): " << entries.at(i).amount << endl;
  }

  cout << endl;
}