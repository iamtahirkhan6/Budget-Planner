#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BudgetPlanner.h"
#include "Month.h"
#include "InOut.h"

struct month 
{
   int monthName;
   struct inOut *money;
   float balance;
   struct month *next;
};

int currentMonth;

void AddInOutDisplay(bool inOutType)
{
   if(inOutType)
   {
      printf("You have selected add expense!\n");
      //TODO AddInOut(month, inOutType)
   }
   else
   {
      printf("You have selected add income!\n");
      //TODO AddInOut(month, inOutType)
   }
   
   //ReSort the InOuts
   MonthMenu();
}

void OpenInOutDisplay(bool inOutType)
{
   printf("Yes!\n");
   if(inOutType)
   {
      printf("You have selected open income [income whatever]!\n");
   }
   else
   {
      printf("You have selected open expense [expense whatever]!\n");
   }
   
   InOutMenu(inOutType);
   //InOutMenu(month, inOutType);
}

void ReSortInOuts(bool sortBySource)
{
   if(sortBySource)
   {
      printf("Sorted by source \n"); //TODO sortby source
   }
   else
   {
      printf("Sorted by amount \n"); //TODO sortby amount
   }

   MonthMenu();
}

void GoBackToBudgetPlanner()
{
   MainMenu();
}

void DisplayMonthMenu()
{ 
   printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
   printf("===================================================== \n");
   printf(" \t\tMonth whatever \t \n");
   //TODO Month name in place
   printf("===================================================== \n");
   printf(" \t\tIncome \t \n");
   printf(" 1. Source - amount\n");
   printf(" 2. Source - amount\n");
   printf(" \t\tExpenses \t \n");
   printf(" 3. Source - amount\n");
   printf(" 4. Source - amount\n");
   printf(" 5. Source - amount\n");
   printf(" \t\tBalance \t \n");
   printf("Amount\n");
   /*TODO 
   Change the name of the month to the current month, also save it in a var
   for each InOut, we have a source and amount, then we calculate the balance/show it
      printf(" \t\tIncome \t \n");
      printf(" i. SOURCE - AMOUNT\n");
      printf(" \t\tExpenses \t \n");
      printf(" i. SOURCE - AMOUNT\n");
   */

   printf("===================================================== \n");
   printf(" 1.Open income\n");
   printf(" 2.Open expense\n");
   printf(" 3.Add income \n");
   printf(" 4.Add expense \n");
   printf(" 5.Sort tables by source \n");
   printf(" 6.Sort tables by amount \n");
   printf(" 7.Go Back \n");
   printf(" 8.Exit Program \n");
}

void MonthMenu()
{
   DisplayMonthMenu();

   int yourChoice;

   do
   { 
      printf("Enter your choice(1-5):");
      scanf("%d",&yourChoice);

      switch (yourChoice)
      {
         case 1: OpenInOutDisplay(0); break;
         case 2: OpenInOutDisplay(1);break;
         case 3: AddInOutDisplay(0); break;
         case 4: AddInOutDisplay(1); break;
         case 5: ReSortInOuts(0); break;
         case 6: ReSortInOuts(1); break;
         case 7: GoBackToBudgetPlanner(); break;
         case 8: exit(0); break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<7));
}
