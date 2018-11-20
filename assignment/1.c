// DS ASSIGNMENT-1
// Single linked list
#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef int boolean;
typedef struct node
{
    struct node * next;
    int data;
}node;
typedef struct list
{
     node * header;
     int count;
}list;
list * initializehead()
{
  list * l = (list *) malloc(sizeof(list));
  l->header = NULL;
  l->count = 0;
  return header;
}
void insert(list * list,int data)
{
  node * temp = (node *)malloc(sizeof(node));
  temp->data = data;
  temp->next = list->list;
  list->header = temp;
  ++(list->count);
}
void delete(list * list)
{
    if(list->header == NULL)
    {
      printf("Empty List\n");
      return;
    }
    node* temp = list->header;
    list->header = temp->next;
    --(list->count);
    free(temp);
}
void display(list * list)
{
    printf("\n");
    node * temp = list->header;
    if(temp == NULL)
    {
      printf("Empty List\n");
      return;
    }
    while(temp!=NULL)
    {
      printf("%d -> ",temp->data);
      temp = temp->next;
    }
}
void addafter(list * list,int b,int data)
{
    node * temp1 = (node *)malloc(sizeof(node));
    temp1->data = data;
    node * temp = list->header;
    while(temp != NULL && temp->data !=b )
    {
        temp = temp->next;
    }
    if(temp!=NULL)  // node found
    {
      temp1->next = temp->next;
      temp->next = temp1;
    }
    else
    {
      printf("b %d Not found in the list\n",b);
      free(temp1);
    }
  }
void replace(list * list,int b,int data)
{
  node * tempnode = (node *)malloc(sizeof(node));
  tempnode->data = data;
  node * temp = list->header;
  node * prev = NULL;
  while(temp != NULL && temp->data != b)
  {
    prev = temp;
    temp = temp->next;
  }
  if(temp==NULL)
  {
    printf("not found in list\n");
    free(tempnode);// no elements in list get replaced
  }
  else //node is found
  {
   if(prev!=NULL)
    {
      prev->next = tempnode;
      tempnode->next = temp->next;
      free(temp);
    }
   else //found at first node
   {
     tempnode->next = (list->header)->next;
     list->header = tempnode;
     free(temp);
   }
}}
boolean issorted_recursive1(node * temp)
{
 if(temp == NULL || temp->next == NULL)
      return True;
 if(temp->data > (temp->next)->data)
      return False;
 return issorted_recursive1(list->next);
}
boolean issorted_recursive(list * list)
{
  return issorted_recursive1(list->header);
}
boolean issorted_nonrecursive(list * list)
{
 node * temp = list->header;
 while(temp && temp->next)
 {
 if(temp->data > (temp->next)->data) return False;
 temp = temp->next;
 }
 return True;
}
void removeduplicates(list * list)
{
  node * temp = list->header;
  node * next = NULL;
  node * q = NULL;
  while(temp!=NULL && temp->next!=NULL)
  {
    if(temp->data == (temp->next)->data)
    {
      q = temp->next;
      temp->next = q->next;
      free(q);
    }
    else temp = temp->next;
 }
}
void insertrear(list * list,int data)
{
  node * temp = (node *)malloc(sizeof(node));
  temp->data = data;
  temp->next = NULL;
  ++(list->count);
  node * q = list->header;
  if(list->header == NULL)
  {
    list->header = temp;
  }
  else
  {
    while(q->next)
    {
      q = q->next;
    }
    q->next = temp;
  }
}
void alternatingsplit(list * head1,list * head2,list * head3)
{
 int i = 0;
 destroy(head3);
 destroy(head2);
 head3->header = NULL;
 head2->header = NULL;
 node * temp1 = head1->header; node * temp2 = head2->header; node * temp3 = head3->header;
 while(temp1)
 {
   if(i%2)
   {
     insertrear(head3,temp1->data);
   }
   else insertrear(head2,temp1->data);
   i++;
   temp1 = temp1->next;
 }
}
void destroy(list * list)
{
 node * temp = list->header;
 while(temp)
 {
   temp = temp->next;
   free(list->header);
   list->header = temp;
 }
 printf("\nSucessfully deleted the list\n");
}
