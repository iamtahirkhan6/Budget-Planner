#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Utilities.h"

struct inOut
{
   char *name;
   char *type;
   char *source;
   float value;
   struct inOut *next;
};

struct inOut *head = NULL;
struct inOut *current = NULL;

struct balance
{
  char *mname;
  float balance;
};

void summary()
{
   int x,i;
   struct balance bc[12];
   
   bc[0].mname = "january";
   bc[1].mname = "february";
   bc[2].mname = "march";
   bc[3].mname = "april";
   bc[4].mname = "may";
   bc[5].mname = "june";
   bc[6].mname = "july";
   bc[7].mname = "august";
   bc[8].mname = "september";
   bc[9].mname = "october";
   bc[10].mname = "november";
   bc[11].mname = "december";

   for (x = 0; x < 12; x++)
   {
      bc[x].balance = 0;
   }
   struct inOut *ptr = head;
   for (i = 0; i < 12; i++)
   {
      struct inOut *ptr = head;
      while (ptr != NULL)
      {
         if((strcmp(ptr->name,bc[i].mname)==0)){
               if ((strcmp(ptr->type,"income") == 0))
               {
                  bc[i].balance = bc[i].balance + ptr->value;
               }
               else
               {
                  bc[i].balance = bc[i].balance - ptr->value;
               }
         }ptr = ptr->next;
      } 
   }
}

void summaryPrint()
{
   int x,i;
   struct balance bc[12];
   
   bc[0].mname = "january";
   bc[1].mname = "february";
   bc[2].mname = "march";
   bc[3].mname = "april";
   bc[4].mname = "may";
   bc[5].mname = "june";
   bc[6].mname = "july";
   bc[7].mname = "august";
   bc[8].mname = "september";
   bc[9].mname = "october";
   bc[10].mname = "november";
   bc[11].mname = "december";

   for (x = 0; x < 12; x++)
   {
      bc[x].balance = 0;
   }
   struct inOut *ptr = head;
   for (i = 0; i < 12; i++)
   {
      struct inOut *ptr = head;
      while (ptr != NULL)
      {
         if((strcmp(ptr->name,bc[i].mname)==0)){
               if ((strcmp(ptr->type,"income") == 0))
               {
                  bc[i].balance = bc[i].balance + ptr->value;
               }
               else
               {
                  bc[i].balance = bc[i].balance - ptr->value;
               }
         }ptr = ptr->next;
      } 
   }
   
   for(i=0;i<12;i++){
      if(strlen(bc[i].mname)<7)
         printf("\t%s \t\tBalance: \t%.2f\n", bc[i].mname, bc[i].balance);
      else
         printf("\t%s \tBalance: \t%.2f\n", bc[i].mname, bc[i].balance);
      printf("===================================================== \n");
   }

   printf("\tTotal balance: \t%.2f\n", bc[0].balance); //The sum of all months' balances
   printf("===================================================== \n");
}

//insert link at the first location
void insert(char *name, char *type, char *source, float value)
{
   struct inOut *link = (struct inOut *)malloc(sizeof(struct inOut));
   
   link->name = malloc(strlen(name) + 1);
   strcpy(link->name, name);

   link->type = malloc(strlen(type) + 1);
   strcpy(link->type, type);
   
   link->source = malloc(strlen(source) + 1);
   
   strcpy(link->source, source);

   link->value = value;

   link->next = head;

   head = link; 
}

void delete (char *name, char *type, char *source)
{
   struct inOut *current = head;
   struct inOut *previous = NULL;

   if (head == NULL)
   {
      printf("Head is null");
   }

   while (strcmp(current->name, name) || strcmp(current->type, type) || strcmp(current->source, source))
   {
      if (current->next == NULL)
      {
         break;
      }
      else
      {
         previous = current;
         current = current->next;
      }
   }
   
   if (current == head)
   {
      head = head->next;
   }
   else
   {
      previous->next = current->next;
   }
}

void update(char *name, char *type, char *source, float value)
{
   struct inOut *current = head;
   struct inOut *previous = NULL;
   
   if (head == NULL)
   {
      printf("Head is null");
   }
   while ((strcmp(current->name,name)||strcmp(current->type,type)||strcmp(current->source,source))){
      if(current->next == NULL) {
         break;
      }else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }
   current->value=value;
}

void monthList(char *key)
{
   float balance = 0;
   //start from the beginning
   struct inOut *ptr = head;
   printf("\tIncome\n");
   while (ptr != NULL)
   {      
      if ((strcmp(ptr->name,key) == 0)) {
          if((strcmp(ptr->type,"income")) == 0){
              printf("%s \t\t%.2f",ptr->source, ptr->value);
              printf("\n");
              balance += ptr->value;
         }
      }
      ptr = ptr->next;
   }
   
   struct inOut *ptr1 = head;

   printf("----------------------------------------------------- \n");

   printf("\tExpense\n");
   while (ptr1 != NULL)
   {      
      if ((strcmp(ptr1->name,key)) == 0) {
         if((strcmp(ptr1->type,"expense")) == 0)
            {
               printf("%s \t\t%.2f",ptr1->source, ptr1->value);
               printf("\n");
               balance -= ptr1->value;
            }
      }
   ptr1 = ptr1->next; 
   }
   printf("===================================================== \n");
   printf("\tBalance: %.2f\n",balance);
}

bool checking(char *name, char *type, char *source)
{
   bool check=false;

   struct inOut *ptr = head;
   while (ptr != NULL)
   {      
      if ((strcmp(ptr->name,name) == 0)) {
          if((strcmp(ptr->type,type)) == 0){
              if((strcmp(ptr->source,source)) == 0){
                  check =true;
              }
          }  
      }      
      ptr = ptr->next;        
   }
   return check;     
}

/* 
void WriteFile()
{
   while (!feof(fp))
   {
      fprintf(fp, "%s", name);
      fprintf(fp, "%s", type);
      fprintf(fp, "%s", source);
      fprintf(fp, "%s", buff);
      value = atoi(buff);
      
      insert(name, type, source, value);
   }
} */

void ExitProgram()
{
   //WriteFile();
   exit(0);
}