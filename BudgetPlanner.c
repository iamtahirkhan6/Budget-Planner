#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BudgetPlanner.h"
#include "Month.h"

void DisplayMainMenu()
{
   printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
   printf("===================================================== \n");
   printf(" \tWelcome to the Budget Planner\t \n ");
   printf(" \t\tTeam 1\t \n ");
   printf("===================================================== \n");
   printf("\tMonth 1 \tBalance: \tAmount\n");
   printf("===================================================== \n");
   printf("\tMonth 2 \tBalance: \tAmount\n");
   printf("===================================================== \n");
   
   /*TODO for each month, print remaining and Amount
      printf("\tMONTHNAME \tBalance: \tBALANCE\n");
      printf("===================================================== \n");
   */
   
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
         case 1: MonthMenu(); break;
         case 2: exit(0); break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<3));
}