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
//				case 2:
//					/* Delete element at specified position */
//					scanf("%d", &position);
//					dllist_delete_at(list, position);
//					break;

//				case 3:
				/* Delete element at the end of the list */
	//				dllist_delete_rear(list);
	//				break;

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
     printf("list empty,Create first node\n");
     list->head=temp;
     list->tail=temp;

   }
   else
   {
     printf("list present\n");
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
     printf("empty list,what do you expect me to display\n");
   }
   else
   {
     while(pres!=NULL)
     {
     printf(" %d ",pres->data);
     pres=pres->next;

     }
     printf("\n");
     printf("number of nodes in list: %d\n",list->number_of_nodes);

    }
 }
 void dllist_destroy(DLList **list)
 {
   Node* to_delete=NULL;
   Node* pres=(*list)->head;
    while(pres->next!=NULL)
    {
      to_delete=pres;
      pres=pres->next;
      free(to_delete);
    }
    free(*list);
 }
void dllist_insert_at(DLList* list, int data, int index)
{
  Node* pres=list->head;
  Node* temp=(Node*)malloc(sizeof(Node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=data;
  int i=0;
  while(pres->next!=NULL&&i<index)
  {
      pres=pres->next;
			i++;
  }
  if(pres->next!=NULL)//node found or list exists
 {
	 printf("node found\n");
	 if(pres->next==NULL) //only one node or last node
	 {
		 printf("only one node or last node\n");
		 if(pres->prev==NULL)
		 {
			 printf("only one node\n");                   //if there is only one node in the list
		 temp->next=pres;
		 pres->prev=temp;
		 list->head=temp;

	    }
	   else if(pres->prev!=NULL)     //if its last node in list
	   {
			 printf("last node in list or more\n");
			 if(i==index)                //insert before last node
			 {
				 printf("insert before last node\n");
				 temp->next=pres;
				 temp->prev=pres->prev;
				 pres->prev->next=temp;
		     pres->prev=temp;
		   }
	     else if(i==(index-1))//insert after last node
      {
				printf("insert after last node\n");
			 pres->next=temp;
			 temp->prev=pres;
		  }
			else
			{
				printf("invalid position\n");

			}
	   }
   }
	 else if(pres->prev==NULL)
	 {//first node
	 printf("at position 0");
		 temp->next=list->head;
		 list->head->prev=temp;
		 list->head=temp;
	 }


	 else
	 {
		 printf("somewhere in the middle\n");
		 temp->next=pres;
		 temp->prev=pres->prev;
		 pres->prev->next=temp;
		 pres->prev=temp;
	 }                                                            //somewhere in middle
	 list->number_of_nodes++;
  }

  else if(pres==NULL)//node not found
	{
		printf("pres is NULL\n");
		if(i==index)//add at first
		{printf("at first \n");
			list->head=temp;
			list->number_of_nodes++;
		}
		else
		{
			printf("invalid position\n");
		}
	}
}
/*
void dllist_delete_at(DLList* list, int index)
{
	Node* pres=list->head;
	Node* to_delete=NULL;



	int i=0;
	while(pres->next!=NULL&&i<index)
	{
			pres=pres->next;
			i++;
	}
	if(pres!=NULL)//node found or list exists
 {
	 printf("node found\n");
	 if(pres->next==NULL) //only one node or last node
	 {
		 printf("only one node or last node\n");
		 if(pres->prev==NULL)
		 {
			 printf("only one node\n");
			to_delete=pres;                    //if there is only one node in the list
		 list->head=NULL;

			}
		 else if(pres->prev!=NULL)     //if its last node in list
		 {
			 printf("last node in list\n");
			 if(i==index)                //insert before last node
			 {
				 printf("delete before last node\n");

				pres->prev->
			 }
			 else if(i==(index-1))//insert after last node
			{
				printf("insert after last node\n");
			 pres->next=temp;
			 temp->prev=pres;
			}
		 }
	 }
	 else if(pres->prev==NULL)
	 {//first node
	 printf("at position 0");
		 temp->next=list->head;
		 list->head->prev=temp;
		 list->head=temp;
	 }


	 else
	 {
		 printf("somewhere in the middle\n");
		 temp->next=pres;
		 temp->prev=pres->prev;
		 pres->prev->next=temp;
		 pres->prev=temp;
	 }                                                            //somewhere in middle
	 list->number_of_nodes++;
	}

	else if(pres==NULL)//node not found
	{
		if(i==index)//add at first
		{printf("at first \n");
			list->head=temp;
			list->number_of_nodes++;
		}
		else
		{
			printf("invalid position\n");
		}
	}

}
*/
