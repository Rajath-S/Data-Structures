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
void delete_all_elements(List* list,int data);
void reverse(List* list);
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
	printf("before create list\n");
	List* list = create_list();
	printf("after creation of list\n");
	while(choice > 0 && choice <=4) {
  		printf("1. Insert in the beginning \n");
			printf("2. Delete specified element \n");
			printf("3. Display \n");
			printf("4 reverse the list\n");
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
		case 4 :
				reverse(list);
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
		printf("created a list");
    return L;
}
void insert_beginning(List* list, int data)
{

    Node* temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=data;

    if(list->head==NULL)
    {
				printf("This is the first node inserted in the beginning\n");
        list->head=temp;
        temp->link=NULL;

    }
    else
    {
				printf("existing nodes found, insert in the beginning");
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
			list->head=pres->link;
			free(to_delete);
		}
    else
    {
       to_delete=prev->link;
       prev->link=pres->link;
       free(to_delete);
    }
}
/*
void delete_all_elements(List* list,int data)
{
	Node* pres=list->head;
	Node* to_delete;
	Node* prev=NULL;


	while(pres!=NULL)
	{
		if(pres->data==data)
		{
			prev->link=
		}

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
		list->head=pres->link;
		free(to_delete);
	}
	else
	{
		 to_delete=prev->link;
		 prev->link=pres->link;
		 free(to_delete);
	}

}
	*/
void disp_list(List* list)
{
    Node* p=list->head;
    printf("showing the list \n");

    while(p!=NULL)
    {
        printf("%d =>",p->data);
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
        list->head = list->head->link;

        free(temp);

    }
		free(list);
    printf("finished deletion of all elements");
	}
	void reverse(List* list)
	{
		Node * curr,*prev,*temp;
		prev=NULL;
		curr=list->head;
		while(curr!=NULL)
		{
			temp=curr->link;
			curr->link=prev;
			prev=curr;
			curr=temp;


		}
		list->head=prev;
	}
