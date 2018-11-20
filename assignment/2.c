
1) Decimal to binary using stack
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
typedef struct Stack
{
  int stack[SIZE];
  int top;
}stack;
int push(stack *s,int i)
{
  ++(s->top);
  if(s->top == SIZE) return 0;
  s->stack[(s->top)] = i;
  return 1;
}
int pop(stack *s)
{
  --(s->top);
  return s->stack[(s->top)+1];
}
void convert(int x)
{
  stack * binary = (stack *)malloc(sizeof(stack));
  binary->top = -1;
  while(x)
  {
    push(binary,x%2);
    x/=2;
  }
  while(binary->top != -1)
  {
    printf("%d",pop(binary));
  }
  }

2) TWO STACKS
#include <stdio.h>
#include <stdlib.h>
typedef struct stack2
{
  int* twostacks;
  int top1,top2;
  int size;
}stack2;
stack2 * intializestack(int size)
{
  stack2 * stacktwo = (stack2 *)malloc(sizeof(stack2));
  stacktwo->top1 = -1;
  stacktwo->top2 = size;
  stacktwo->size = size;
  stacktwo->twostacks = (int *)malloc(sizeof(int)*size);
  stacktwo;
}
void push1(stack2 * stack2,int data)
{
  if(stack2->top2 == stack2->top1 + 1)
  {
  printf("\nSTACK ONE OVERFLOW\n");
  return;
  }
  stack2->twostacks[(stack2->top1)+1] = data;
  ++(stack2->top1);
}
void push2(stack2 * stack2,int data)
{
  if(stack2->top1 == stack2->top2-1)
  {
  printf("\nSTACK TWO OVERFLOW\n");
  return;
  }
  stack2->twostacks[(stack2->top2)-1] = data;
  --(stack2->top2);
}
int pop1(stack2 * stack2)
{
  if(stack2->top1 == -1)
  {
  printf("\nSTACK ONE EMPTY\n");
  return -1;
  }
  --(stack2->top1);
  return stack2->twostacks[stack2->top1 + 1];
}
int pop2(stack2 * stack2)
{
  if(stack2->top2 == stack2->size)
  {
  printf("\nSTACK TWO EMPTY\n");
  return -1;
  }
  ++(stack2->top2);
  return stack2->twostacks[stack2->top2 - 1];
}
void display1(stack2 * stack2)
{
  if(stack2->top1 == -1)
  {
  printf("\nSTACK ONE IS EMPTY\n");
  return;
  }
  int i = 0;
  while(i <= stack2->top1)
  {
  printf("%d \n",stack2->twostacks[i]);
  i++;
  }
}
void display2(stack2 * stack2)
{
  if(stack2->top2 == stack2->size)
  {
  printf("\nSTACK TWO IS EMPTY\n");
  return;
  }
  int i = stack2->size - 1;
  while(i >= stack2->top2)
  {
  printf("%d \n",stack2->twostacks[i]);
  i--;
  }
}
void destroy(stack2 * stack2)
{
  free(stack2->twostacks);
  free(stack2);
}
