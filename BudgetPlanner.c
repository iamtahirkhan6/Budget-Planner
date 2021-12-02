#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BudgetPlanner.h"
#include "Month.h"
#include "Utilities.h"

void PrintMonthList()
{
   summaryPrint();
}

void GoToMonth()
{
   char monthToView[10];
   printf("What month do you want to view? (Input name): ");
   scanf("%s",monthToView);

   //TODO function searches linked list check if monthToView is in it

   MonthMenu(monthToView);
}

void DisplayMainMenu()
{
   printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
   printf("===================================================== \n");
   printf(" \tWelcome to the Budget Planner\t \n ");
   printf(" \t\tTeam 1\t \n ");
   printf("===================================================== \n");
   
   PrintMonthList();

   printf("1.Open month\n");
   printf("2.Exit\n");
}

void MainMenu()
{
   DisplayMainMenu();

   int yourChoice;

   do
   { 
      printf("Enter your choice(1-2):");
      scanf("%d",&yourChoice);

      switch (yourChoice)
      {
         case 1: GoToMonth(); break;
         case 2: ExitProgram(); break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<3));
}