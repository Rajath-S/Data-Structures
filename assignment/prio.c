
// A C program to demonstrate linked list based implementation of queue 
#include <stdlib.h> 
#include <stdio.h> 
#include<string.h>
  
// A linked list (LL) node to store a queue entry 
struct QNode 
{ 
    int key; 
    struct QNode *next;
    int priority; 
}; 
  
// The queue, front stores the front node of LL and rear stores ths 
// last node of LL 
struct Queue 
{ 
    struct QNode *front, *rear; 
}; 
  
// A utility function to create a new linked list node. 
struct QNode* newNode(int k,int priority) 
{ 
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->key = k; 
    temp->next = NULL;
    temp->priority; 
    return temp;  
} 
  
// A utility function to create an empty queue 
struct Queue *createQueue() 
{ 
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
// The function to add a key k to q 
void enQueue(struct Queue *q, int k,int priority) 
{ 
    // Create a new LL node 
    struct QNode *temp = newNode(k,priority); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) 
    { 
       q->front = q->rear = temp; 
       return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp; 
} 
  
// Function to remove a key from given queue q 
struct QNode *deQueue(struct Queue *q) 
{ 
    // If queue is empty, return NULL. 
    if (q->front == NULL) 
       return NULL; 
  
    // Store previous front and move front one node ahead 
    struct QNode *temp = q->front; 
    q->front = q->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) 
       q->rear = NULL; 
    return temp; 
} 
typedef struct QNode node;
typedef struct Queue queue;

 AddJob(queue* arr,int jobid, char* priority)
{
    if(strcmp(priority,"low"))
        enQueue(arr[2],key,priority);
    else if(strcmp(priority,"medium"))
        enQueue(arr[1],key,priority);
    else if(strcmp(priority,"high"))
        enQueue(arr[0],key,priority);
}
int RemoveMin()
{
    int removed;
    if(!empty(arr[0]))
        return deQueue(arr[0]);
    else if(!empty(arr[1]))
        return deQueue(arr[1]);
    else if(!empty(arr[2]))
        return deQueue(arr[2]);\
    else 
        printf("element couldn't be found");
}


int main()
{
    queue* arr[3];
    int choice;char priority[5],int removed;
    arr[0]=createQueue();
    arr[1]=createQueue();
    arr[2]=createQueue();
    switch(choice)
    {
        case 1:
                printf("enter key and priority ");
                scanf("%d %s",&key,&priority);
                AddJob(&arr,jobid,priority);
               
        case 2:
                 printf("Element Removed->%d",RemoveMin());



    }
}