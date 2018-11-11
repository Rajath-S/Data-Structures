#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
	Node* tail;
	unsigned int number_of_nodes;
} DLList;

/* Create a doubly linked list */
DLList* dllist_create();

/* Insert data at the beginning of the list */
void dllist_insert_beginning(DLList* list, int data);

/* Insert 'data' into the 'list', before object at 'index', where 0 <= 'index' < number_of_nodes, for a non-empty list */
void dllist_insert_at(DLList* list, int data, int index);

/* Removes last element of a non-empty list */
void dllist_delete_rear(DLList* list);

/* Removes an element at specified 'index', where 0 <= 'index' < number_of_nodes, for a non-empty list */
void dllist_delete_at(DLList* list, int index);

/* Print list contents */
void dllist_print(DLList* list);

/* Deallocate resources held by a list */
void dllist_destroy(DLList **list);

int main() {
	unsigned int choice = 0;
	int element;
	int position;
	DLList *list = dllist_create();
	while(choice < 5) {
    	scanf("%d", &choice);
		switch(choice) {
        	case 0:
				/* Insert in the beginning */
				scanf("%d", &element);
               	dllist_insert_beginning(list, element);
                break;


			case 1:
				/* Insert at specified position */
				scanf("%d", &element);
				scanf("%d", &position);
	               	dllist_insert_at(list, element, position);
	                break;
			case 2:
					/* Delete element at specified position */
					scanf("%d", &position);
					dllist_delete_at(list, position);
					break;

			case 3:
				/* Delete element at the end of the list */
				dllist_delete_rear(list);
				break;

			case 4:
				/* Print list contents */
				dllist_print(list);
                break;

		    default:
		    	dllist_destroy(&list);
		}
	}
	return 0;
}

/* TODO:
 * Provide suitable implementations for the above function declarations, describing operations on a doubly linked list.
 * Take care of the border cases.
 * Note: DO NOT delete or modify the preloaded code.
 */
 DLList* dllist_create()
 {

   DLList* dlist=(DLList*)malloc(sizeof(DLList));
   dlist->head=NULL;
   dlist->tail=NULL;
   dlist->number_of_nodes=0;
   return dlist;
 }
 void dllist_insert_beginning(DLList* list, int data)
 {
  Node* temp=(Node*)malloc(sizeof(Node));
  temp->data=data;
  temp->prev=NULL;
  temp->next=NULL;

   if(list->head==NULL)
   {
     list->head=temp;
     list->tail=temp;

   }
   else
   {
    temp->next=list->head;
	list->head->prev=temp;
    list->head=temp;
    }
     list->number_of_nodes++;
 }
 void dllist_print(DLList* list)
 {
   Node* pres=list->head;
   if(list->head==NULL)
   {

   }
   else
   {
     while(pres!=NULL)
     {
     printf("%d ",pres->data);
     pres=pres->next;

     }
     printf("\n");


    }
 }
 void dllist_destroy(DLList **list)
 {
   Node* to_delete=NULL;
   Node* pres=(*list)->head;
    while(pres!=NULL)
    {
      to_delete=pres;
      pres=pres->next;
      free(to_delete);
    }
    free(*list);
 }
 void dllist_insert_at(DLList* list, int data, int index)
{
  Node* temp;

 //create a node

     temp=(Node*)malloc(sizeof(Node));
     temp->data=data;
     temp->prev=temp->next=NULL;

    Node* q=list->head;
    int i=0;
    if(list->head!=NULL)
    {
      //go to the position

    while((q->next!=NULL)&&(i<index))
     {
       i++;
        q=q->next;
      }
    if(q->next!=NULL)//position found
    {
      //check if first position
       if(q->prev==NULL)
       {
          //insert in first position
          temp->next=q;
          q->prev=temp;
          list->head=temp;
        }
      else
      {
       //insert somewhere in the middle of list
       //but not the last but one position
       q->prev->next=temp;
       temp->prev=q->prev;
       temp->next=q;
        q->prev=temp;
      }
   }
   else//q->next==NULL
    {
        if(q->prev==NULL)//only one node
        {
            if(index==i)
            {
                temp->next=q;
                q->prev=temp;
                list->head=temp;
            }
            else if(index==i+1)
            {
                q->next=temp;
                temp->prev=q;
            }
        }
        else//last node
        {
      if(i==index)//insert at the last but one position
      {
        q->prev->next=temp;
       temp->prev=q->prev;
       temp->next=q;
        q->prev=temp;
     }
    else if(i==(index-1))//insert after the last node
     {
        q->next=temp;
         temp->prev=q;
     }
        }

    }

 }
 else
 {
   if(index==0)
   {
     list->head=temp;
   }
 }
 void dllist_delete_rear(DLList* list)
 {
   Node* pres=list->head;
   Node* to_delete=NULL;
   if(list->head==NULL)
   {
       return;
   }

   if(pres->prev==NULL&&pres->next==NULL)//only one node
   {
     to_delete=list->head;
     list->head=NULL;
   }
   else
   {
   while(pres->next!=NULL)
   {
     pres=pres->next;
   }
   to_delete=pres;
   pres->prev->next=NULL;
   free(to_delete);
 }
}
void dllist_delete_at(DLList* list, int index)
{
  Node* q=list->head;
    int i=0;
    if(list->head==NULL)
        return;

    //go to the position

    while((q!=NULL)&&(i<index))
     {
       i++;
        q=q->next;
      }
    if(q!=NULL)//position found
    {

       if(q->prev==NULL&&q->next==NULL)//only one node
       {
         list->head=NULL;
      }
      else if(q->prev==NULL)//first  position
      {
        list->head=q->next;
        list->head->prev=NULL;
      }
      else if(q->next==NULL)//last
      {
        q->prev->next=NULL;
      }
      else//somewhere in the middle
      {
        q->prev->next=q->next;
        q->next->prev=q->prev;
      }
      free(q);
    }
  }
