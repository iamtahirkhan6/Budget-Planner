/*
    main: main of this program, where the reading and initializing happen
    @file main.c
    @author Alejandro García, Ruthra Bellen, Smruthi Ravichandran, Tahir Uddin Khan
    @version 1.0 2/12/21 
    
   <copyright file="«BudgetPlanner»" company="«SRH»">
      Author: Alejandro García, Ruthra Bellen, Smruthi Ravichandran, Tahir Uddin Khan
      Copyright (c). All rights reserved.
   </copyright>
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BudgetPlanner.h"
#include "Utilities.h"

//Reads the file budget.txt and inserts into our program
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
