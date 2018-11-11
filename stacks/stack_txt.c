#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAXSTACK 10
typedef char StackEntry;
typedef struct stack
{
  int top;
  StackEntry entry[MAXSTACK];
}Stack;
void Push(StackEntry item,Stack* s)
{
  if(StackFull(s))
    printf("error stack full\n");
  else
    s->entry[s->top++]=item;
}
void Pop(StackEntry* item,Stack* s)
{
  if(StackEmpty(s))
    printf("error stack empty\n");
  else
    *item=s->entry[--s->top];
}
int StackEmpty(Stack* s)
{
  return s->top<=0;
}
int StackFull(Stack* s)
{
  return s->top>=MAXSTACK;
}
void CreateStack(Stack* s)
{
  s->top=0;
}
void ReverseRead()
{
  StackEntry item;
  Stack stack;

  CreateStack(&stack);
  while(!StackFull(&stack)&&(item=getchar())!='\n')
  {
    Push(item,&stack);
  }
  while(!StackEmpty(&stack))
  {
    Pop(&item,&stack);
    putchar(item);
  }
  putchar('\n');
}

int main()
{
  ReverseRead();
}
