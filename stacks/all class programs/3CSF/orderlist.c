#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next;
};

void display(struct node*);
void insert_order(struct node**,int);
int main()
{
  struct node *first;
  int x;
   first=NULL;

  while(1)
  {
    printf("\nEnter the number..\n");
    scanf("%d",&x);
     if(x==0)
       break;
    insert_order(&first,x);
    display(first);
  }
}

 void display(struct node *p)
 {
   printf("The list..\n");
   while(p!=NULL)
   {
     printf("%d->",p->data);
     p=p->next;
   }
}

  void insert_order(struct node **p, int x)
  {
    struct node *temp, *prev, *q;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
 
    q=*p;
    prev=NULL;;

    while((q!=NULL)&&(x>q->data))
    {
      prev=q;
      q=q->next;
     }
    if(q!=NULL)
    {
      if(prev==NULL)//inserting ther smallest number, insert first
      {
        temp->next=q;
        *p=temp;
       }
     else// insert somewhere in middle of the list
      {
        temp->next=q;
        prev->next=temp;
      }
    }
   else//q==NULL
   {
     if(prev==NULL)//empty list, first node inserted
          *p=temp;
    else
      prev->next=temp;//largest no, insert at end
   }
 }
























 
 /*void insert_order(struct node** p,int x)
 {
  struct node *temp,*prev,*q;

  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=NULL;

  q=*p;//copy address of the first node
  prev=NULL;

  while((q!=NULL)&&(x>q->data))
  {
    prev=q;
    q=q->next;
  }
  if(q!=NULL)//position found,x<q->data
  {
   if(prev==NULL)//first position, insert as the first node
    { temp->next=q;
    *p=temp;
    }
   else//insert somewhere in middle
   {
    prev->next=temp;
    temp->next=q;
   }
  }
  else//q==NULL,
  {
    if(prev==NULL)//empty list,insert the node as the first node 
      *p=temp;
    else
     prev->next=temp;//insert at the end of the list
 }
}*/
  
   



   



