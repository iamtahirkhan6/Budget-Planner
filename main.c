#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BudgetPlanner.h"
#include "Utilities.h"

void ReadFile()
{
   FILE *fp;
   char name[10];
   char type[10];
   char source[10];
   int value;
   char check = 'y';
   char buff[10];

   fp = fopen("budget.txt", "r");
   char test[10];
   while (!feof(fp))
   {
      fscanf(fp, "%s", name);
      fscanf(fp, "%s", type);
      fscanf(fp, "%s", source);
      fscanf(fp, "%s", buff);
      value = atoi(buff);
      
      insert(name, type, source, value);
   }
}

int main(void)
{
   ReadFile();

   MainMenu();

   return 0;
}
