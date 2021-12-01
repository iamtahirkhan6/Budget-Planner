#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "InOut.h"
#include "Month.h"

struct inOut
{
   char *source;
   bool isExpense;
   float value;
   struct inOut *next;
};

bool currentType;

void ModifyInOutSource()
{
    printf("You have selected modify src!\n");
    //Update the current InOut src
    InOutMenu(currentType);
}

void ModifyInOutType()
{
    printf("You have selected modify type(income/expense)!\n");
    //Update the current InOut type
    InOutMenu(currentType);
}

void ModifyInOutAmount()
{
   printf("You have selected modify amt!\n");
   //Update the current InOut amount
   InOutMenu(currentType);
}

void DeleteInOut()
{
   printf("You have selected to delete this Income!\n");
   InOutMenu(currentType);
}

void GoBackToMonth()
{
    MonthMenu();
}

void DisplayInOutMenu(bool inOutType)
{ 
    currentType = inOutType;

    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
    printf("===================================================== \n");
    printf(" \t\tMonth whatever \t \n ");
    if(inOutType)
        printf(" \t\tIncome \t \n");
    else
        printf(" \t\tExpense \t \n");
    printf(" Source\n");
    printf(" Amount\n");
    printf("===================================================== \n");
    printf(" 1.Modify Source\n");
    printf(" 2.Modify Amount\n");
    if(inOutType)
        printf(" 3.Delete Expense \n");
    else
        printf(" 3.Delete Expense \n");
    printf(" 4.Back to month \n");
    printf(" 5.Exit Program \n");
}

void InOutMenu(bool inOutType) //to add month as argument
{
   DisplayInOutMenu(inOutType);

   int yourChoice;

   do
   { 
      printf("Enter your choice(1-5):");
      scanf("%d",&yourChoice);

      switch (yourChoice)
      {
         case 1: ModifyInOutSource(); break;
         case 2: ModifyInOutAmount();break;
         case 3: DeleteInOut(); break;
         case 4: GoBackToMonth(); break;
         case 5: exit(0); break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<6));
}