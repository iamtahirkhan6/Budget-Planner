#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*struct inOut
{
   char *type;
   char *source;
   float value;

};*/

struct inOut
{
   char *name;
   char *type;
   char *source;
   float value;
   //float balance;
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
    //int number_of_keys = 12;
    int x,i;
    struct balance bc[12];
    //struct balance *bc= malloc(sizeof(struct balance) * number_of_keys);
    
    //bc[0].mname = "January";bc[1].mname = "Feb";bc[0].mname = "Jan";bc[1].mname = "Feb";
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
    printf("\n[ ");
    for (i = 0; i < 12; i++)
    {
        struct inOut *ptr = head;
        while (ptr != NULL)
        {
          //printf("\n %s,%s,%.2f,%s,%s",ptr->name, bc[i].mname,ptr->value,ptr->type,ptr->source);
          //printf("\n%.2f",(strcmp(ptr->name,bc[i].mname)));
          if((strcmp(ptr->name,bc[i].mname)==0)){
                if ((strcmp(ptr->type,"income") == 0))
                {
                    bc[i].balance = bc[i].balance + ptr->value;
                }
                else
                {
                    bc[i].balance = bc[i].balance - ptr->value;
                }
              // printf("(%s,%.2f) ", bc[i].mname, bc[i].balance);
            }ptr = ptr->next;
        //printf("%s,%.2f", bc[i].mname, bc[i].balance);
        //printf("\n");
        
        } 
        
    }
    for(i=0;i<12;i++){
           printf("%s,%.2f", bc[i].mname, bc[i].balance);
           printf("\n");

        }
}



void printList()
{
   struct inOut *ptr = head;
   printf("\n[ ");

   //start from the beginning
   while (ptr != NULL)
   {
      printf("(%s,%s,%s,%.2f) ", ptr->name, ptr->type, ptr->source, ptr->value);
      printf("\n");
      ptr = ptr->next;
   }

   printf(" ]");
}

//insert link at the first location
void insert(char *name, char *type, char *source, float value)
{
   
   struct inOut *link = (struct inOut *)malloc(sizeof(struct inOut));
   
    
   link->name = malloc(strlen(name) + 1);
   strcpy(link->name, name);
   //printf("%s",link->name);

   link->type = malloc(strlen(type) + 1);
   strcpy(link->type, type);
   //printf("%s",link->type);

   //link->type = type;
   //printf("%s",link->type);
   //strcpy(link->in->type, type);

   
   link->source = malloc(strlen(source) + 1);
   strcpy(link->source, source);
   //printf("%s",link->source);

   //link->source = source;
  // printf("%s",link->source);

   link->value = value;
   printf("%.2f",link->value);
   
   //point it to old first node

   link->next = head;

   //point first to new first node
   head = link;  
}

void delete (char *name, char *type, char *source)
{

   //start from the first link
   struct inOut *current = head;
   struct inOut *previous = NULL;
   //struct inOut* temp;

   //if list is empty
   if (head == NULL)
   {
      printf("Head is null");
   }

   while (strcmp(current->name, name) || strcmp(current->type, type) || strcmp(current->source, source))
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
void update(char *name, char *type, char *source, float value)
{

   //start from the first link
   struct inOut *current = head;
   struct inOut *previous = NULL;
   //struct inOut* temp;

   //if list is empty
   if (head == NULL)
   {
      printf("Head is null");
   }

   while ((strcmp(current->name,name)||strcmp(current->type,type)||strcmp(current->source,source))){
     
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
   
   current->value=value;
   //printf("\n %.2f,\t %.2f",current->value ,value);


}  
bool isEmpty()
{
   return head == NULL;
}

void main()
{
      FILE *fp;
      char action[10];
      char name[10];
      char type[10];
      char source[10];
      int value;
      char check = 'y';
      char buff[10];

      fp = fopen("C://Users//Ruthra//Desktop//budget.txt", "r");
      char test[10];
      while (!feof(fp))
      {

         fscanf(fp, "%s", action);
         printf("\n\n%s ", action);
         fscanf(fp, "%s", name);
         printf("%s ", name);
         fscanf(fp, "%s", type);
         printf("%s ", type);
         fscanf(fp, "%s", source);
         printf("%s ", source);
         fscanf(fp, "%s", buff);
         value = atoi(buff);
         printf("%.2f \n", value);
         //if (feof(fp))
           // break;
         //fscanf(fp, "%s", test);
         if (strcmp(action, "ADD") == 0)
         {
            insert(name, type, source, value);
            printf("\n%s,%s,%s,%.2f",name, type, source, value);
         }
         else if (strcmp(action, "DEL") == 0)
         {

            //struct inOut *temp =
            delete (name, type, source);
            printf("\n entry Deleted :");
            //printf("(%s,%s,%s,%.2f) ",temp->name,temp->type,temp->source,temp->value);
            //"(%s,%s,%s,%.2f) ",temp->name,temp->type,temp->source,temp->value
            //printf("Deletion code comes here\n");
         }
         else
         {
            update(name, type, source, value);
            printf("\n Entry updated :");
            //printf("Action code comes here\n");
         }
          
         //switch(action){
         //  case "ADD":
         //    insertFirst(name,type,source,value);
         //    break;
         //default :
         //    break;}

         //while(fscanf(fp, "%.2f", &test) == 1);
         //while(fgetc(fp) != EOF);
      }

      summary();
      //printf("Total list: ");

      //print list
      
      printList();
      fclose(fp);
   
}