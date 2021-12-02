all:
	planner

planner:
	gcc main.c Month.c Utilities.c BudgetPlanner.c -o BudgetPlanner