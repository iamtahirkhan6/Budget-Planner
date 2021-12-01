#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct inOut
{
   char *in_out;
   char *type;
   float value;

};

struct budget
{
   char *month;
   struct inOut in;
   float balance;
   struct budget *next;
};


struct budget *head = NULL;
struct budget *current = NULL;

void printList()
{
   struct budget *ptr = head;
   printf("\n[ ");

   //start from the beginning
   while (ptr != NULL)
   {
      printf("(%s,%s,%s,%f) ", ptr->month, ptr->in.in_out, ptr->in.type, ptr->in.value);
      printf("\n");
      ptr = ptr->next;
   }

   printf(" ]");
}

//insert link at the first location
void insert(char *month, char *in_out, char *type, float value)
{
   
   struct budget *link = (struct budget *)malloc(sizeof(struct budget));
   //struct inOut *money = (struct inOut *)malloc(sizeof(struct inOut));
   //struct inOut money;
    
   link->month = malloc(strlen(month) + 1);
   strcpy(link->month, month);
   printf("%s",link->month);

   link->in.in_out = in_out;
   printf("%s",link->in.in_out);
   //strcpy(link->in->in_out, in_out);
   
   link->in.type = type;
   //strcpy(link->in->type, type);

   link->in.value = value;
   
   //point it to old first node

   link->next = head;

   //point first to new first node
   head = link;  
}

void delete (char *month, char *in_out, char *type)
{

   //start from the first link
   struct budget *current = head;
   struct budget *previous = NULL;
   //struct budget* temp;

   //if list is empty
   if (head == NULL)
   {
      printf("Head is null");
   }

   while (strcmp(current->month, month) || strcmp(current->in.in_out, in_out) || strcmp(current->in.type, type))
   {

      //if it is last node
      if (current->next == NULL)
      {
         printf("next is null \n");
         break;
      }
      else
      {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }
   //found a match, update the link
   if (current == head)
   {
      //change first to point to next link
      head = head->next;
   }
   else
   {
      //bypass the current link
      previous->next = current->next;
   }

   //return current;
}
void update(char *month, char *in_out, char *type, float value)
{

   //start from the first link
   struct budget *current = head;
   struct budget *previous = NULL;
   //struct budget* temp;

   //if list is empty
   if (head == NULL)
   {
      printf("Head is null");
   }

   while ((strcmp(current->month,month)||strcmp(current->in.in_out,in_out)||strcmp(current->in.type,type))){
     
      if(current->next == NULL) {
         printf("next is null \n");
         break;
      }else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }

   
   }
   
   current->in.value=value;
   //printf("\n %f,\t %f",current->in.value ,value);


}  
bool isEmpty()
{
   return head == NULL;
}

void main()
{
      FILE *fp;
      char action[10];
      char month[10];
      char in_out[10];
      char type[10];
      int value;
      char check = 'y';
      char buff[10];

      fp = fopen("C://Users//Ruthra//Desktop//budget.txt", "r");
      char test[10];
      while (1)
      {

         fscanf(fp, "%s", action);
         printf("\n\n%s ", action);
         fscanf(fp, "%s", month);
         printf("%s ", month);
         fscanf(fp, "%s", in_out);
         printf("%s ", in_out);
         fscanf(fp, "%s", type);
         printf("%s ", type);
         fscanf(fp, "%s", buff);
         value = atoi(buff);
         printf("%d \n", value);
         if (feof(fp))
            break;
         //fscanf(fp, "%s", test);
         if (strcmp(action, "ADD") == 0)
         {
            insert(month, in_out, type, value);
            printf("\n entry added ");
         }
         else if (strcmp(action, "DEL") == 0)
         {

            //struct budget *temp =
            delete (month, in_out, type);
            printf("\n entry Deleted :");
            //printf("(%s,%s,%s,%f) ",temp->month,temp->in_out,temp->type,temp->value);
            //"(%s,%s,%s,%f) ",temp->month,temp->in_out,temp->type,temp->value
            //printf("Deletion code comes here\n");
         }
         else
         {
            update(month, in_out, type, value);
            printf("\n Entry updated :");
            //printf("Action code comes here\n");
         }

         //switch(action){
         //  case "ADD":
         //    insertFirst(month,in_out,type,value);
         //    break;
         //default :
         //    break;}

         //while(fscanf(fp, "%d", &test) == 1);
         //while(fgetc(fp) != EOF);
      }

      printf("Total list: ");

      //print list
      printList();
      fclose(fp);
   
}