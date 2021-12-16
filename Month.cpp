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

  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    newBalance += entries.at(i).BudgetImpact();
  }

  balance = newBalance;
}

float Month::GetMonthlyBalance () {
  UpdateMonthlyBalance();
  return balance;
}

void Month::AddEntry(string newEntryName, bool isExpense, float newEntryBudget)
{
    Entry newEntry = Entry(newEntryName, isExpense, newEntryBudget);
    entries.push_back(newEntry);
}

void Month::ModifyEntry(string entryToModify, float newAmount)
{
  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    if(entries.at(i).GetSource() == entryToModify)
    {
      entries.at(i).SetAmount(newAmount);
      break;
    }
  }
}

void Month::DeleteEntry(string entryToDelete)
{
  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    if(entries.at(i).GetSource() == entryToDelete)
    {
      entries.erase(entries.begin()+i);
      break;
    }
  }
}

int Month::GetSize() {
    return entries.size();
}

//TODO
void Month::SortEntries()
{

}

void Month::PrintMonth()
{
  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    cout << entries.at(i).GetSource() << " "  << entries.at(i).BudgetImpact() << endl;
  }
}