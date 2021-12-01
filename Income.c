#include <stdio.h>
#include <string.h>

void ModifyIncomeSource()
{
   printf("You have selected modify src!\n");
}

void ModifyIncomeAmount()
{
   printf("You have selected modify amt!\n");
}

void ModifyIncomeDescription()
{
   printf("You have selected modify desc!\n");
}

void DeleteIncome()
{
   printf("You have selected to delete this Income!\n");
}

void GoBack()
{
   printf("Go Back to Month View!\n");
}

void DisplayIncomeMenu()
{ 
   printf("===================================================== \n");
   printf(" \t\tMonth whatever \t \n ");
   printf(" \t\tIncomes \t \n");
   printf(" Source\n");
   printf(" Amount\n");
   printf(" Description\n");
   printf("===================================================== \n");
   printf(" 1.Modify Source\n");
   printf(" 2.Modify Amount\n");
   printf(" 3.Modify Description \n");
   printf(" 4.Delete Income \n");
   printf(" 5.Back \n");
}

void IncomeMenu()
{
   DisplayIncomeMenu();

   int yourChoice;

   do
   { 
      printf("Enter your choice(1-5):");
      scanf("%d",&yourChoice);

      switch (yourChoice)
      {
         case 1: ModifyIncomeSource(); break;
         case 2: ModifyIncomeAmount();break;
         case 3: ModifyIncomeDescription(); break;
         case 4: DeleteIncome(); break;
         case 5: GoBack();break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<6));
}

int main()
{
   IncomeMenu();

   return 0;
}
