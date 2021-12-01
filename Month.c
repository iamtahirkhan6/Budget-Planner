#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BudgetPlanner.h"
#include "Month.h"
#include "InOut.h"

char* currentMonth;
char** typeMonth;
char** sourceMonth;
float* amountMonth;

void AddInOutDisplay()
{
   bool inOutType=0;
   char* newSource;
   float newAmount;
   
   printf("Is it an expense (1) or an income (0): ");
   scanf("%d",&inOutType);

   /*if(inOutType==1 || inOutType==0)
   {
      printf("Enter the source: ");
      scanf("%s",&newSource);

      printf("How much is the amount: ");
      scanf("%d",&newAmount);

      TODO AddInOut(currentMonth, newSource, newAmount, inOutType)
      printf("\nEntry added!\n")
   }
   */
   
   MonthMenu(currentMonth);
}

void OpenInOutDisplay()
{
   bool inOutType=0;
   char* source;

   printf("What entry do you want to view? (Input name): ");
   scanf("%s",source);
   
   //TODO bool SearchInOut(char* monthName, char* source)
   //if (found)
   InOutMenu(currentMonth, source, inOutType);
   //else MonthMenu(currentMonth);
}

void GoBackToBudgetPlanner()
{
   MainMenu();
}

void DisplayMonthMenu(char* monthName)
{ 
   //TODO char** typeMonth, char** sourceMonth, float* amountMonth extractFinances(char* monthName) 
   //-> returns 3 arrays: types, sources, and amounts

   //ReadEntries(currentMonth);

   printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
   printf("===================================================== \n");
   printf(" \t\t%s \t \n", monthName);
   printf("===================================================== \n");
   
   /* int size = sizeof(sourceMonth) / sizeof(*sourceMonth);

   printf(" \t\tIncome \t \n");
   for (int i = 0; i < size; i++)
   {
      if(typeMonth[i] == "INCOME")
         printf(" %s - %d\n", sourceMonth[i], amountMonth[i]);
   }
   
   printf(" \t\tExpenses \t \n");
   for (int i = 0; i < size; i++)
   {
      if(typeMonth[i] == "EXPENSE")
         printf(" %s - %d\n", sourceMonth[i], amountMonth[i]);
   } */
   
   printf(" \t\tBalance \t \n");
   printf("Amount\n");

   printf("===================================================== \n");
   printf(" 1.Open entry\n");
   printf(" 2.Add entry \n");
   printf(" 3.Go Back \n");
   printf(" 4.Exit Program \n");
}

void MonthMenu(char* monthName)
{
   currentMonth = monthName;
   DisplayMonthMenu(currentMonth);

   int yourChoice;

   do
   { 
      printf("Enter your choice(1-6):");
      scanf("%d",&yourChoice);

      switch (yourChoice)
      {
         case 1: OpenInOutDisplay(); break;
         case 2: AddInOutDisplay(); break;
         case 3: GoBackToBudgetPlanner(); break;
         case 4: exit(0); break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<5));
}
