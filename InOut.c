#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "InOut.h"
#include "Month.h"

char* currentMonth;
bool currentType;
char* sampleSource = "Rent"; 

void ModifyInOutAmount()
{
   printf("You have selected modify amt!\n");
   //Update the current InOut amount
   InOutMenu(currentMonth, sampleSource, currentType);
}

void DeleteInOut()
{
   printf("You have selected to delete this Income!\n");
   InOutMenu(currentMonth, sampleSource, currentType);
}

void GoBackToMonth()
{
    MonthMenu(currentMonth);
}

void DisplayInOutMenu(bool inOutType)
{ 
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
    printf("===================================================== \n");
    printf(" \t\t%s \t \n", currentMonth);
    if(inOutType)
        printf(" \t\tIncome \t \n");
    else
        printf(" \t\tExpense \t \n");
    printf(" Source\n");
    printf(" Amount\n");
    printf("===================================================== \n");
    printf(" 1.Modify Amount\n");
    if(inOutType)
        printf(" 2.Delete Expense \n");
    else
        printf(" 2.Delete Expense \n");
    printf(" 3.Back to month \n");
    printf(" 4.Exit Program \n");
}

void InOutMenu(char* monthName, char* source, bool inOutType) //to add month as argument
{
   currentType = inOutType;
   currentMonth = monthName;

   DisplayInOutMenu(currentType);

   int yourChoice;

   do
   { 
      printf("Enter your choice(1-5):");
      scanf("%d",&yourChoice);

      switch (yourChoice)
      {
         case 1: ModifyInOutAmount();break;
         case 2: DeleteInOut(); break;
         case 3: GoBackToMonth(); break;
         case 4: exit(0); break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<5));
}