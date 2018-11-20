#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *next,*prev;
};

struct dequeue
{
  struct node *front;
  struct node *rear;
};
void qdisplay(struct dequeue);
 void qinsert_head(int ,struct dequeue*);
void qinsert_tail(int ,struct dequeue*);
int qdelete_head(struct dequeue*);
int qdelete_tail(struct dequeue*);
int main()
{
  int k,x,ch;
  struct dequeue dq; 
  dq.front=dq.rear=NULL;
 
  while(1)
  {
    qdisplay(dq);
    printf("\n1..insert head");
    printf("\n2..insert Tail");
    printf("\n3..Delete Head");
    printf("\n4..Delete Tail");
    printf("\n5..display");
    printf("\n6..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              qinsert_head(x,&dq);
               break;
       case 2:printf("Enter the value..");
              scanf("%d",&x);
              qinsert_tail(x,&dq);      
              break;
       case 3:k=qdelete_head(&dq);
              printf("Element deleted = %d\n",k);
              break;
       case 4:k=qdelete_tail(&dq);
              printf("Element deleted = %d\n",k);
              break;
        case 5:qdisplay(dq); 
   }
  }
 }







    void qdisplay(struct dequeue dq)
    {
       struct node *p;
      if(dq.front==NULL)
        printf("Empty Queue...\n");
      else
      {
       for(p=dq.front;p!=dq.rear;p=p->next)
       {
          printf("%d ",p->data);
       }
       printf("%d ",p->data);   
      }
   }
   
 
    

        
          







 
    


   
     








