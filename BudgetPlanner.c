/*
    BudgetPlanner: main screen of the program, it handles the month list and its actions
    @file BudgetPlanner.c
    @author Alejandro García
    @version 1.0 2/12/21 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BudgetPlanner.h"
#include "Month.h"
#include "Utilities.h"

//Prints the month list in the program
void PrintMonthList()
{
   summaryPrint();
}

//Navigates to the month view, specified by the user
void GoToMonth()
{
   char monthToView[10];
   printf("What month do you want to view? (Input name): ");
   scanf("%s",monthToView);

   //TODO function searches linked list check if monthToView is in it

   MonthMenu(monthToView);
}

//Displays the information of the Month List
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

//Handles the actions of the Month list
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