#include<stdio.h>
//int sum(int*,int);
int minimum(int *, int);
int min(int*,int,int);
int sum(int *,int,int);
int main()
{
  int result,m;
  int a[]={2,3,1,5,6};
  
  //result=sum(a,4);
   result=sum(a,0,4);
  printf("\nsum=%d\n",result);
  //m=minimum(a,4);
  m=min(a,0,4);
  printf("\nmin=%d\n",m);

}

  int sum(int *a,int l,int h)
  {
    if(l==h)//if only one element
      return a[l];
    int mid=(l+h)/2;//find mid of the array

    int left=sum(a,l,mid);//find sum of the left part
    int right=sum(a,mid+1,h);//find sum of right part
    return (left+right);
  }
    

  int min(int *a, int l, int h)
  {
    //if only one element
     if(l==h)
       return a[l];
     int mid=(l+h)/2;
     int left=min(a,l,mid);//find smallest in left half
     int right=min(a,mid+1,h);//find smallest in right half
     if(left <right)
          return left;
     return right;
   }
     
















  int minimum(int *a,int n)
  {
    int m;
    if(n==0)
      return a[0];
    m=minimum(a,n-1);//find the solution for the reduced problem size
    if(m < a[n])
      return m;
    else
      return a[n];
  }









  /*int sum(int *p,int n)
  {
      int s=0;
     if(n==0)  
        return p[0];//answer for the smallest problem size
     s=sum(p,n-1)+p[n];//find solution for reduced problem size
     return s;
   }*/







