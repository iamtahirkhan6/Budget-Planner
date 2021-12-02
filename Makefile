all:
	planner

planner:
	gcc -Wall -g main.c Month.c Utilities.c BudgetPlanner.c -o BudgetPlanner