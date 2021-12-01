all:
	planner

planner:
	gcc main.c Month.c Expense.c Income.c BudgetPlanner.c -o BudgetPlanner