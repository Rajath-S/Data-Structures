#include<stdio.h>
int main()
{
   void display(int *, int);
   int a[]={1,2,3,4};
   display(a,3);
   }

  void display(int *a, int n)
  {
    //PRINTING THE ADDRESS OF ELEMENTS OF The ARRAY
     int i;
    for(i=0;i<=n;i++)
    {
      printf("\nAdress of the %d element = %p\n",i,a);
       printf("\nthe value of the element=%d\n",*a);
       a++;
    }
  }



