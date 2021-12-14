#include "Month.hpp"

Month::Month(int monthNumber)
{
  const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  name = months[monthNumber - 1];
  balance = 0;
}

Month::~Month()
{
  entries.clear();
}

// Update Monthly Balance
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

// Retrieve Monthly Balance
float Month::GetMonthlyBalance () {
  UpdateMonthlyBalance();
  return balance;
}

// Add an Entry to month
void Month::AddEntry(string newEntryName, float newEntryBudget)
{
  Entry newEntry = Entry(newEntryName, newEntryBudget);
  entries.push_back(newEntry);
}

// Modify an Entry to month
void Month::ModifyEntry(string entryToModify, float newAmount)
{
  for(decltype(entries.size()) i=0; i<entries.size(); i++)
  {
    if(entries.at(i).source == entryToModify)
    {
      //TODO->Call the modify amount function in Entry instead of direct assign
      entries.at(i).amount = newAmount; 
      break;
    }
  }
}

// Delete an Entry from month
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

// Sort Entries
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