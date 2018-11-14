
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
  int top1;
  int top2;
  int size;
  int* Twostacks;
}stack;
void initialize(stack*,int);
void push(stack*,int,int);
int pop(stack*,int);
void printTwostack(stack*);
int empty(stack*,int);
int full(stack*);
void initialize(stack* stack,int n)
{
  stack->size=n;
  stack->Twostacks=(int*)malloc(n*sizeof(int));
  stack->top1=-1;
  stack->top2=n;
}
int empty(stack* stack,int whichStack)
{
  if(whichStack==1)
  {
    if(stack->top1<0)
      return 1;
    return 0;
  }
  else if(whichStack==2)
  {
    if(stack->top2>(stack->size-1))
      return 1;
    return 0;
  }
  else
    {
      if(stack->top1<0&& stack->top2>(stack->size-1))
        return 1;
      else
        return 0;
    }


}
int full(stack* stack)
{
  if(stack->top1<stack->top2-1)
    return 0;
  return 1;

}
void push(stack* stack,int element,int whichStack)
{
  if(whichStack==1)
  {
    stack->Twostacks[++stack->top1]=element;
  }
  else
    stack->Twostacks[--stack->top2]=element;
}
void printTwostack(stack* stack)
{
  for(int i=0;i<stack->size;i++)
  {
    printf(" %d ",stack->Twostacks[i]);
  }
  printf("\n");
  printf("top1 is at index %d\n",stack->top1);
  printf("top2 is at index %d\n",stack->top2);
}
int pop(stack* stack,int whichStack)
{int ele;
  if(whichStack==1)
    ele=stack->Twostacks[stack->top1--];
  else
    ele=stack->Twostacks[stack->top2++];
  return ele;
}

void destroy(stack* s)
{
  free(s->Twostacks);
}



int main()
{

  int size;
  printf("enter the size of the two stack array\n");
  scanf("%d",&size);
  int stackchoice;int loop=1;
  stack s;
  initialize(&s,size);
  while(loop){
    printf("Enter 1 to push to stack1,\n2 to pop from stack1,\n3 to push to stack2,\n4 to pop from stack2 \nenter 5 to print the elements in twostack \nenter 6 to destroy\n");
    scanf("%d",&stackchoice);
  switch(stackchoice)
  { int ToDealWith;int element;

    case 1:
    if(!full(&s)){
      printf("enter the value of the element to be pushed");
      scanf("%d",&element);
      push(&s,element,1);
    }
    else
      printf("OVeRFLOW\n");
    break;
    case 2:
    if(!empty(&s,1))
      printf("popped element is-%d",pop(&s,1));
    else
      printf("UNDERFLOW\n");
    break;
    case 3:
    if(!full(&s))
    {
      printf("enter the value of the element to be pushed");
      scanf("%d",&element);
      push(&s,element,2);
    }
      else
        printf("OVERFLOW\n");
      break;
    case 4:
        if(!empty(&s,2))
          printf("popped element is-%d",pop(&s,2));
        else
          printf("UNDERFLOW\n");
        break;
    case 5:
    if(!empty(&s,3))
        printTwostack(&s);
    else
      printf("stack empty cannot print\n");
    break;
    default:
            destroy(&s);
            loop=0;
            break;
  }

}
}
