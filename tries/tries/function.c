#include "trie.h"
#include<stdio.h>
#include<stdlib.h>
Trienode* Triesearch(Trienode* root,Key target)
{
    int i;
    for(i=0;i<MAXLENGTH&&root!=NULL;i++)
    {
        if(target[i]=='\0')
            break;   //end of word to be search
        else
            root=root->branch[target[i]-'a'];
             //move down
    }
    if(root!=NULL&& root->ref==NULL)  //checking for flag
        return NULL;
    return root;
}


Trienode* InsertTrie(Trienode* root,Key newkey,Entry* newentry)
{
    int i;
    Trienode* saveroot;

    if(root==NULL)
        root=CreateNode();
    saveroot=root;
    printf("into insert\n");
    for(i=0;i<MAXLENGTH;i++)
    { printf("%d",i);
        if(newkey[i]=='\0')
            break;
        else
        {
            printf("into else\n");
            if(!root->branch[newkey[i]-'a'])
                    root->branch[newkey[i]-'a']=CreateNode();
            printf("no");
        }
        printf("out\n");

    }
    //now we are at the required position
    if(root->ref!=NULL)
        printf("Note: You are inserting a duplicate key\n");
    else{
        root->ref=newentry;printf("entered data successfully\n");}
    return saveroot;
}
Trienode* CreateNode()
{
    int ch;
    Trienode* newnode=(Trienode*)malloc(sizeof(Trienode));
    for(ch=0;ch<LETTERS;ch++)
        newnode->branch[ch]=NULL;
    newnode->ref=NULL;
    return newnode;
}
