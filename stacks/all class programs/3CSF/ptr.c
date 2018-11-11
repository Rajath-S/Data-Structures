#include<stdio.h>
int main()
{
   int x=10;
   int *y;
   int **z;
   printf("\nx=%d",x);
   printf("\nAddress of X =%p\n",&x);
   y=&x;
   printf("\nthe value of x = %d",*y);
   printf("\nthe address of x = %p\n",y);
   z=&y;
   printf("\nthe address of y= %p\n",z);
   printf("\nThe value of x = %d\n",**z);
   printf("\n The address of Z = %p\n",&z);
 }
