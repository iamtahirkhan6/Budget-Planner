#include <stdio.h>
#include <string.h>

void ModifyExpenseSource()
{
   printf("You have selected modify src!\n");
}

void ModifyExpenseAmount()
{
   printf("You have selected modify amt!\n");
}

void ModifyExpenseDescription()
{
   printf("You have selected modify desc!\n");
}

void DeleteExpense()
{
   printf("You have selected to delete this expense!\n");
}

void GoBack()
{
   printf("Go Back to Month View!\n");
}

void DisplayExpenseMenu()
{ 
   printf("===================================================== \n");
   printf(" \t\tMonth whatever \t \n ");
   printf(" \t\tExpenses \t \n");
   printf(" Source\n");
   printf(" Amount\n");
   printf(" Description\n");
   printf("===================================================== \n");
   printf(" 1.Modify Source\n");
   printf(" 2.Modify Amount\n");
   printf(" 3.Modify Description \n");
   printf(" 4.Delete expense \n");
   printf(" 5.Back \n");
}

void ExpenseMenu()
{
   DisplayExpenseMenu();

   int yourChoice;

   do
   { 
      printf("Enter your choice(1-5):");
      scanf("%d",&yourChoice);

      switch (yourChoice)
      {
         case 1: ModifyExpenseSource(); break;
         case 2: ModifyExpenseAmount();break;
         case 3: ModifyExpenseDescription(); break;
         case 4: DeleteExpense(); break;
         case 5: GoBack();break;
         default: printf("Invalid \n"); break;
      }
   } while (!(yourChoice>0 && yourChoice<6));
}

int main()
{
   ExpenseMenu();

   return 0;
}
