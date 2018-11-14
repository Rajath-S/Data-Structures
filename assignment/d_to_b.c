#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

typedef struct Stack
{
	int stack[SIZE];
	int top;
}stack;

int empty(stack *s);//returns 1 if stack is empty else returns 0
int full(stack *s);//returns 1 if stack is full else returns 0
int push(stack *s,int i);//returns 1 if successful else returns 0
int pop(stack *s);//returns 1 if successful else returns 0
void disp(stack *s);//displays all elements in stack from top till base
void convert(int x);// converts given Decimal to binary and prints it in a single line
int main(){
	int n,x,i;
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d",&x);
		convert(x);
		printf("\n");
	}
}
void convert(int x)
{
  stack s;
  s.top=-1;
	
  while(x!=0)
  {
    int rem=x%2;
    x=x/2;
    push(&s,rem);

  }
  while(s.top!=-1){
    printf("%d",pop(&s));
  }

}
int empty(stack* s)
{
  if(s->top==-1)
    return 1;
  else return 0;

}
int full(stack* s)
{
	if(s->top>=SIZE-1){
    printf("OVERFLOW");
    return 1;
	}
	return 0;

}
int push(stack* s,int data)
{
	if(!full(s)){
  s->top++;
  s->stack[s->top]=data;
	return 1;
}	return 0;
}
int pop(stack* s)
{
	if(!empty(s)){
  int x=s->stack[s->top];
  s->top--;
  return x;
}
}
