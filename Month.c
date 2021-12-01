#include <stdio.h>
#include <string.h>

#include "Month.h"

void AddExpense()
{
   printf("You have selected add expense!\n");
}

void AddIncome()
{
   printf("You have selected add expense!\n");
}

void OpenExpense()
{
   printf("You have selected open expense [expense whatever]!\n");
}

void OpenIncome()
{
   printf("You have selected open income [income whatever]!\n");
}

void GoBack()
{
   printf("Go Back to Planner!\n");
}

void DisplayMonthMenu()
{ 
   printf("===================================================== \n");
   printf(" \t\tMonth whatever \t \n ");
   printf("===================================================== \n");
   printf(" \t\tIncome \t \n ");
   printf(" Source - amount\n");
   printf(" Source - amount\n");
   printf(" \t\tExpenses \t \n ");
   printf(" Source - amount\n");
   printf(" Source - amount\n");
   printf(" Source - amount\n");
   printf(" \t\tRemaining \t \n ");
   printf(" Amount\n");
   printf("===================================================== \n");
   printf(" 1.Open income\n");
   printf(" 2.Open expense\n");
   printf(" 3.Add income \n");
   printf(" 4.Add expense \n");
   printf(" 5.Back \n");
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
         case 1: OpenIncome(); break;
         case 2: OpenExpense();break;
         case 3: AddIncome(); break;
         case 4: AddExpense(); break;
         case 5: GoBack();break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<6));
}
