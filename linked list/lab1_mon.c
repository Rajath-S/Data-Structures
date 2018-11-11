//A program to perform the following operations using a Linked List.
#include<stdio.h>
#include<stdlib.h>

//Node of the linked list
typedef struct Node {
	int data;
	struct Node *link;
} Node;

//Handle of the list. Its head points to the first node in the list.
typedef struct List {
	Node* head;
	int length;
} List;

//Create an empty linked list
List* create_list();

//Insert a new Node at the beginning of the linked list
void insert_beginning(List* list, int data);

//Delete the first Node having the element "data".
//No operation if there is no such Node.
void delete_element(List* list, int data);

//Display the elements of the linked list seperated by spaces in a single line
void disp_list(List* list);

//Delete the linked list along with any nodes it has.
void delete_list(List* list);

int main()
{
	int choice = 1;
	int element;
	List* list = create_list();
	while(choice > 0 && choice < 4) {
  		//printf("1. Insert in the beginning \n");
		//printf("2. Delete specified element \n");
		//printf("3. Display \n");
		scanf("%d",&choice);
		switch(choice) {
   		case 1 : //printf("Enter the element\n");
			scanf("%d",&element);
			insert_beginning(list, element);
			break;
		case 2 : //printf("Enter the element to be deleted\n");
			scanf("%d", &element);
			delete_element(list, element);
			break;
		case 3 :
			disp_list(list);
			break;
		}
	}
	delete_list(list);
	return 0;
}
List* create_list()
{
    List* L=(List*)malloc(sizeof(List));
    L->head=NULL;
    L->length=0;


    return L;
}
void insert_beginning(List* list, int data)
{

    Node* temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->link=NULL;

    if(list->head==NULL)
        list->head=temp;

    else
    {
        temp->link=list->head;
        list->head=temp;
    }
}
void delete_element(List* list, int data)
{
    Node* pres=list->head;
    Node* to_delete;
	Node* prev=NULL;


    while(pres!=NULL&& pres->data!=data)
    {
		prev=pres;
        pres=pres->link;

    }
    if(pres==NULL)
    {
        printf("element not found\n");
    }
	else if(prev==NULL)
	{
		to_delete=pres;
		list->head=NULL;
		free(to_delete);
    printf("deleted the first node");
	}
    else
    {
       to_delete=pres;
       prev->link=pres->link;
       free(to_delete);
    }
}
void disp_list(List* list)
{
    Node* p=list->head;


    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
		printf("\n");
}
void delete_list(List* list)
{
    Node* temp;
    while(list->head != NULL)
    {
        temp = list->head;
        list->head = temp->link;
        free(temp);
    }
    printf("deleted all nodes");
    free(list);
    printf("deleted the list");
}
