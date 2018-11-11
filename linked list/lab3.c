#include<stdio.h>
#include<stdlib.h>

//Node of the linked list
typedef struct Node{
	int data;
	struct Node *link;
}node;


//Handle of the list. Its head points to the first node in the list.
typedef struct List{
	node* head;
	int number_of_nodes;
}s_list;


/* initializes a linked list */
void list_initialize(s_list* list);

void list_insert_beginning(s_list* list, int data);

/* Inserts data at specified position 0 <= position < length(list).
 * Returns position if insertion is successful, else -1
 */
int list_insert_at(s_list* list, int data, int position);

/* Removes the last node of the linked list */
void list_delete_rear(s_list* list);

void list_reverse(s_list* list);

void list_print(s_list* list);

/* deallocates resources held by the list */
void list_destroy(s_list* list);

int main() {
	int choice, loop = 1;
	s_list list;
	list_initialize(&list);
	while(loop) {
		scanf("%d", &choice);
		switch(choice) {
			int element,index;
			case 0:
				/* Insert an element at beginning of the list */
					scanf("%d", &element);
					list_insert_beginning(&list, element);
					break;
			case 1:
				/* Insert elements at specified positions */
					scanf("%d%d", &element, &index);
					list_insert_at(&list, element, index);
					break;
			case 2:
				/* Remove rear elements */
					list_delete_rear(&list);
					break;
			case 3:
				/* Reverse elements */
				list_reverse(&list);
				break;
			case 4:
				/* Print list contents */
				list_print(&list);
				printf("\n");
				break;
			case 5:
				loop = 0;
		}
	}
	return 0;
}
/*
 * TODO:
 * -> Provide implementations for the above function prototypes. Take care of the border cases as well.
 */
 void list_initialize(s_list* list)
 {
    //list=(s_list*)malloc(sizeof(s_list))
    list->head=NULL;
    list->number_of_nodes=0;
 }
 void list_insert_beginning(s_list* list, int data)
 {
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->link=list->head;
    list->head=temp;

 }
 int list_insert_at(s_list* list, int data, int position)
 {
    node* prev,*pres,*temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->link=NULL;
    pres=list->head;
    int i=0;
    while(pres!=NULL&&i<position)
    {
        prev=pres;
        pres=pres->link;
        i++;
    }
    if(pres!=NULL)//position has been found
    {
        if(prev==NULL)//insert at first
        {
            temp->link=list->head;
            list->head=temp;
            return i;
        }
        else//insert between 2 nd to last
        {
            prev->link=temp;
            temp->link=pres;
            return i;
        }

    }
    else//pres is null
    {
        if(i==position)//its a valid position
        {
            if(prev==NULL)//there is no list insert at first
            {
                list->head=temp;
                return i;
            }
            else
            {
                prev->link=temp;
            }
        }
        else
           return -1;
    }
 }
 void list_delete_rear(s_list* list)
 {
    node* pres,*forward,*to_delete;

    pres=list->head;
    forward=pres->link;

    if(list->head->link==NULL)
    {
        pres=list->head;
        list->head=NULL;
        free(pres);
    }
    else
    {
    while(forward->link!=NULL)
    {
        pres=forward;
        forward=forward->link;
    }
    to_delete=forward;
    pres->link=NULL;
		free(to_delete);
 }

 }
 void list_reverse(s_list* list)
 {
     node*pres,*prev,*forward;
     pres=list->head;
     prev=NULL;
     while(pres!=NULL)
     {
        forward=pres->link;
		pres->link=prev;
        prev=pres;
        pres=forward;

     }
     list->head=prev;
 }

 void list_print(s_list* list)
{
  node* pres=list->head;
  while(pres!=NULL)
  {
    printf("%d ",pres->data);
    pres=pres->link;
  }

}
void list_destroy(s_list* list)
{

  node* to_delete;
  while(list->head!=NULL)
  {
    to_delete=list->head;
    list->head=to_delete->link;
    free(to_delete);

  }
  free(list);

}
