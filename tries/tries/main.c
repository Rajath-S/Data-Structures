#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
int main()
{
    printf("This is going to be about tries\n");
    Trienode *head,*ptr;
    printf("enter 1 to insert and 2 to search if its present\n");
    int choice;
    scanf("%d",&choice);
    Key newkey;
    Entry newentry;
    while(1){
    switch(choice)
    {
    case 1:
        printf("Enter the new key and new entry\n");
        scanf("%s %s",newkey,newentry);
        printf("thanks for entry\n");
        printf("entered key and entry are %s-%s\n",newkey,newentry);
        head=InsertTrie(head,newkey,newentry);
        break;
    case 2:
        printf("enter the key to search\n");
        scanf("%s",newkey);
        ptr=Triesearch(head,newkey);
        if(ptr!=NULL)
            printf("Found!! Details about this entry is %s",ptr->ref);
        else
            printf("Sorry,Not Found!!");
        break;
    default:
        exit(0);
    }
    }
}
