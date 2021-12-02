#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BudgetPlanner.h"
#include "Month.h"
#include "Utilities.h"

char* currentMonth;

void AddInOutDisplay()
{
   bool inOutType=0;
   char* type;
   char newSource[14];
   float newAmount;
   
   printf("Is it an expense (1) or an income (0): ");
   scanf("%d",&inOutType);

   if(inOutType==1 || inOutType==0)
   {
      if(inOutType)
         type = "expense";
      else
         type = "income";

      printf("Enter the source: ");
      scanf("%s",&newSource);

      if(checking(currentMonth, type, newSource))
      {
         printf("\nEntry already in the list!\n");
         MonthMenu(currentMonth);
      }

      printf("How much is the amount: ");
      scanf("%f",&newAmount);

      //TODO check function (if already exist, update amount)
      printf("%s %s %s %.2f", currentMonth, type, newSource, newAmount);
      insert(currentMonth, type, newSource, newAmount);
      printf("\nEntry added!\n");
   }
   
   summary();
   
   MonthMenu(currentMonth);
}

void DeleteInOut()
{
   bool inOutType=0;
   char* type;
   char newSource[14];
   
   printf("Deleting entry:\n");
   printf("Is it an expense (1) or an income (0): ");
   scanf("%d",&inOutType);

   if(inOutType)
      type = "expense";
   else
      type = "income";

   printf("Enter the source: ");
   scanf("%s",&newSource);


   if(!checking(currentMonth, type, newSource))
   {
      printf("\nEntry is not in the list!\n");
      MonthMenu(currentMonth);
   }

   delete (currentMonth, type, newSource);
   summary();
   MonthMenu(currentMonth);
}

void ModifyInOutAmount()
{
   bool inOutType=0;
   char* type;
   char newSource[14];
   float newAmount;
   
   printf("Is it an expense (1) or an income (0): ");
   scanf("%d",&inOutType);

   if(inOutType)
      type = "expense";
   else
      type = "income";

   printf("Enter the source: ");
   scanf("%s",&newSource);

   if(!checking(currentMonth, type, newSource))
   {
      printf("\nEntry not in the list!\n");
      MonthMenu(currentMonth);
   }

   printf("How much is the new amount: ");
   scanf("%f",&newAmount);

   update(currentMonth, type, newSource, newAmount);
   
   summary();

   MonthMenu(currentMonth);
}

void GoBackToBudgetPlanner()
{
   MainMenu();
}

void DisplayMonthMenu(char* monthName)
{
   summary();
   printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
   printf("===================================================== \n");
   printf(" \t\t%s \t \n", monthName);
   printf("===================================================== \n");
   
   monthList(currentMonth);

   printf("===================================================== \n");
   printf(" 1.Add entry\n");
   printf(" 2.Modify entry \n");
   printf(" 3.Delete entry \n");
   printf(" 4.Go Back \n");
   printf(" 5.Exit Program \n");
}

void MonthMenu(char* monthName)
{
   currentMonth = monthName;
   if (currentMonth == "january" || currentMonth == "february" || currentMonth == "march" || currentMonth == "april" || currentMonth == "may" || currentMonth == "june" || currentMonth == "july" || currentMonth == "august" || currentMonth == "september" || currentMonth == "october" || currentMonth == "november" || currentMonth == "december")
   {
      DisplayMonthMenu(currentMonth);

      int yourChoice;

      do
      {
         printf("Enter your choice(1-5): ");
         scanf("%d", &yourChoice);

         switch (yourChoice)
         {
         case 1:
            AddInOutDisplay();
            break;
         case 2:
            ModifyInOutAmount();
            break;
         case 3:
            DeleteInOut();
            break;
         case 4:
            GoBackToBudgetPlanner();
            break;
         case 5:
            ExitProgram();
            break;
         default:
            printf("Invalid \n");
            break;
         }
      } while (!(yourChoice > 0 && yourChoice < 6));
   } else {
      printf("Month does not exist! Please check the spelling of your input.\n");
   }
}
