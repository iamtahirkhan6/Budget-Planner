#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BudgetPlanner.h"
#include "Month.h"

char *months[5] = {"JAN", "FEB", "MAR", "APR", "MAY"};
float balance[5] = {23.45, 231.45, 234.45, 33.45, 33.45};

void PrintMonthList(char **monthName, float* balance)
{
   for (int i = 0; i<sizeof(monthName)/sizeof(monthName[0]); ++i)
   {
      printf("\t%s \tBalance: \t%f\n", monthName[i], balance[i]);
      printf("===================================================== \n");
   }
}

void GoToMonth()
{
   char monthToView[10];
   printf("What month do you want to view? (Input name): ");
   scanf("%s",monthToView);

   MonthMenu(monthToView);
}

void DisplayMainMenu()
{
   printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
   printf("===================================================== \n");
   printf(" \tWelcome to the Budget Planner\t \n ");
   printf(" \t\tTeam 1\t \n ");
   printf("===================================================== \n");
   
   PrintMonthList(months, balance);
   
   printf("\tTotal balance: \tAmount\n"); //The sum of all months' balances
   printf("===================================================== \n");

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
         case 2: exit(0); break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<3));
}