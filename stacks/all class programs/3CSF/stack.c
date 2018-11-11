#include<stdio.h>
#include<stdlib.h>
int push(int*,int*,int,int);
int pop(int*,int*);
void display(int*,int);
int main()
{
  int top,size,ch,k,x;
  int *s;
  printf("Enter the size of the stack..\n");
  scanf("%d",&size);
  s=(int*)malloc(sizeof(int)*size);
  top=-1;
  while(1)
  {
    display(s,top);
    printf("\n1..push\n");
    printf("2..pop\n");
    printf("3..display\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the data\n");
             scanf("%d",&x);
             k=push(s,&top,size,x);
             if(k>0)
               printf("Element pushed successfully\n");
             break;
     case 2:k=pop(s,&top);
            if(k>0)
               printf("\nElement popped=%d\n",k);
            break;
     case 3:display(s,top);
            break;
     case 4:exit(0);
   }
 }
}

  int push(int *s,int *t, int size, int x)
  {
    //if stack overflow
    if(*t==size-1)
    {
      printf("Stack overflow..\n");
      return 0;
    }
     //increment top
     (*t)++;//or ++*t or *t=*t+1
     s[*t]=x;
     return 1;
   }

   int pop(int *s, int *t)
   {
     int x;
     //check for underflow
     if(*t==-1)
     {
       printf("Stack underflow..\n");
       return -1;
     }
     x=s[*t];
     (*t)--;//or --*t
     return x;
   }
  
  void display(int *s, int t)
  {
    int i;

    if(t==-1)
      printf("empty stack..\n");
    else
     for(i=t;i>=0;--i)
       printf("%d ",s[i]);
     printf("\n");
   }






































/* int push(int *s,int *t,int sz,int x)
 {
   //checking for overflow

   if(*t==sz-1)
   {
    printf("stack overflow..\n");
    return -1;
   }
   ++*t;//*t=*t+1, or (*t)++//increment top
   s[*t]=x;
   return 1;
  }

  int pop(int *s, int *t)
  {
    int x;
    //check for empty stack
    if(*t==-1)
    {
      printf("stack underflow..\n");
      return -1;
    }
    x=s[*t];
    --*t;//decrement top
    return x;
  }
  
  ;
  }*/












   
 


  



   

    






   

   
