#include <stdlib.h>
#include <stdio.h>

typedef struct heap {
    int capacity;
    int size;
    int *elements;
} heap;

heap* heap_construct(int initial_capacity);
void  heap_destruct(heap* heap);

int  heap_get_capacity(heap *heap);
int  heap_get_size(heap *heap);

/*
	insert data into heap
	return 1 if inserted.
	return 0 if size > capacity

*/
int heap_insert(heap *heap, int data);

/*return the min value without deleting it*/
int  heap_get_min(heap *heap);
/*delete the min value in the heap*/
void heap_remove(heap *heap);

/*Print the values(data) in ascending order by deleting the min value node from the heap each time*/
void heap_print(heap *heap);
void swap(heap*,int,int);
void heapifyUpAccordingToPriority(heap* heap);
void heapifyDown(heap* heap);
int getRightChild(heap*,int);
int getLeftChild(heap*,int);
/* Write suitable implementations for the function declarations */

int main() {
	int choice, loop = 1;
	int initial_size = 0;
	scanf("%d", &initial_size);
	heap *my_heap = heap_construct(initial_size);
	while(loop) {
		scanf("%d", &choice);
		switch(choice) {
			int number_of_elements, element, index;
			int data;
			case 1:
				/* Insert elements */
					scanf("%d", &element);
					if(!heap_insert(my_heap, element))
						printf("OVERFLOW\n");

				break;

			case 2:
				/* Print elements in sorted order, and empties the heap. */
				heap_print(my_heap);
				heap_destruct(my_heap);
				loop = 0;
				break;

			default:
				heap_destruct(my_heap);
				loop = 0;
                                break;
		}
	}
	return 0;
}
heap* heap_construct(int initial_capacity)
{

    heap * h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = initial_capacity;
    h->elements = (int *)malloc(sizeof(int)*initial_capacity);
    return h;
}
void  heap_destruct(heap* heap)
{
    free(heap->elements);
    free(heap);
}


int  heap_get_capacity(heap *heap)
{
    return heap->capacity;
}
int  heap_get_size(heap *heap)
{
    return heap->size;
}
int getParentIndex(int currIndex)
{
  return (currIndex-1)/2;
}
int getParent(heap* heap,int currIndex)
{
  return heap->elements[(currIndex-1)/2];
}
int getRightChild(heap* heap,int currIndex)
{
  return heap->elements[2*currIndex+2];
}
int getRightChildIndex(int currIndex)
{
  return (2*currIndex+2);
}
int getLeftChildIndex(int currIndex)
{
  return (2*currIndex+1);
}
int getLeftChild(heap* heap,int currIndex)
{
  return heap->elements[2*currIndex+1];
}



void heapifyUpAccordingToPriority(heap* heap)
{
  int currIndex=heap->size-1;
  while(getParentIndex(currIndex)>=0&& heap->elements[currIndex]<heap->elements[getParentIndex(currIndex)])
  {
    swap(heap,currIndex,getParentIndex(currIndex));
    currIndex=getParentIndex(currIndex);
  }
}
void swap(heap* h,int index1,int index2)
{
  int temp=(h->elements[index1]);
  h->elements[index1]=h->elements[index2];
  h->elements[index2]=temp;
}



int heap_insert(heap* heap,int data)

{
  if(heap->size>heap->capacity)
    return 0;
  else
  {
  heap->elements[heap->size]=data;
  heapifyUpAccordingToPriority(heap);
  heap->size++;
  return 1;
}

}
int heap_get_min(heap* heap)
{
  return heap->elements[0];
}

void heap_print(heap* heap)
{
  printf("Before we heapify");
  for(int i=0;i<heap->size;i++)
    {

      printf("-%d-",heap->elements[i]);
    }
  printf("---------------------\n");

  while(heap->size>0)
  {
    printf("--%d",heap_get_min(heap));
    heap_remove(heap);
  }
}
void heap_remove(heap* heap)
{
  if(heap->size==0)
    {
      printf("no heap");
      return;
    }
  heap->elements[0]=heap->elements[heap->size-1];
  heap->size--;
  heapifyDown(heap);
}
int LeftChildNodeExists(heap* heap,int currIndex)
{
  return getLeftChildIndex(currIndex)<heap->size;

}
int RightChildExists(heap* heap,int currIndex)
{
  return getRightChildIndex(currIndex)<heap->size;
}
void heapifyDown(heap* heap)
{
  int currIndex=0;
  while(LeftChildNodeExists(heap,currIndex))
  { int smallChildIndex=getLeftChild(heap,currIndex);
    if(RightChildExists(heap,currIndex) && getLeftChild(heap,currIndex)>getRightChild(heap,currIndex))
      smallChildIndex=getRightChildIndex(currIndex);
      if(heap->elements[smallChildIndex]>heap->elements[currIndex])
        break;
      else
        swap(heap,currIndex,smallChildIndex);
      currIndex=smallChildIndex;
    }



  }





















/*
int heap_insert(heap *heap, int data)
{
    if(heap->size >= heap->capacity )
        return 0;
    heap->elements[heap->size] = data;
    (heap->size)++;
    int j = heap->size -1;
    while(j>0)
    {
        int i = (j-1)/2;//parent node
        int temp;//swap variable
        if(heap->elements[i] <= heap->elements[j])
        {
            break;
        }
        else//we swap
        {
            temp = heap->elements[i];
            heap->elements[i] = heap->elements[j];
            heap->elements[j] = temp;
            j = i;
            i = (j-1)/2;

        }
    }
    return 1;
}
int  heap_get_min(heap *heap)
{
    return heap->elements[0];
}
void heap_remove(heap *heap)
{
     int n = heap->size;
     (heap->size)--;
     heap->elements[0] = heap->elements[n-1];//remove  element
     int i = 0;
     int rj,lj,t,t1;
     t = 1;
     while(i<n-1)
     {
         t = i;
         rj = 2*i +  2;
         lj = 2*i + 1;
         if(lj>n-1)
            break;
         if(lj<n-1)
         {
             if(heap->elements[t]>heap->elements[lj])
             {
                 t = lj;
             }
         }
         if(rj<n-1)
         {
             if(heap->elements[t]>heap->elements[rj])
             {
                 t = rj;
             }
         }
         if(t == i) break;
         t1 = heap->elements[t];
         heap->elements[t] = heap->elements[i];
         heap->elements[i] = t1;
         i = t;
}
}
void heap_print(heap *heap)
{
    if(heap->size ==0)
        return;
    int n = heap->size;
    int t;
    while(heap->size>0)
    {
        printf("%d\n",heap_get_min(heap));
        heap_remove(heap);
    }
}
*/
