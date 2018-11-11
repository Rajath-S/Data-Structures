#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n;
  int i, *p;

  printf("Enter the number of elements..\n");
  scanf("%d",&n);

  p=(int*)malloc(n*sizeof(int));

  printf("\nEnter the values..\n");

  for(i=0;i<n;i++)
    scanf("%d",&p[i]);
 

  printf("\nThe elements of the array\n");
  for(i=0;i<n;i++)
    printf("%d  ",*(p+i));

  printf("\n");
}
