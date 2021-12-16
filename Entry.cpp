#include <iostream>
#include <string>

#include "Entry.hpp"

using namespace std;

float Entry::BudgetImpact()
{
	if (isExpense)
		return -amount;
	else
		return amount;
}
