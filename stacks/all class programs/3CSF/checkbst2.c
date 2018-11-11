
//program to ckeck if a binary tree
//is a BST
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};

void preorder(struct tnode*);
int checkbst(struct tnode *);
struct tnode* newnode(int);
int main()
{
 int num,r;
 struct tnode *root;
 //creating a sample tree
 root=newnode(4);
 root->left=newnode(2);
 root->right=newnode(6);
 root->left->left=newnode(1);
 root->left->right=newnode(3);
 printf("\npreorder traversal of tree..\n");
 preorder(root);
 printf("Checking for BST..\n");
 r=checkbst(root);
 if(r)
   printf("BST..\n");
 else
   printf("Not BST..\n");
}

 struct tnode *newnode(int x)
 {
   struct tnode *temp;
   temp=(struct tnode*)malloc(sizeof(struct tnode));
   temp->data=x;
   temp->left=temp->right=NULL;
   return temp;
 }



void preorder(struct tnode*t)
   {
     if(t!=NULL)
      {
         printf("%d   ",t->data);
         preorder(t->left);
         preorder(t->right);
      }
    }



 int checkbst(struct tnode *t)
 {
   if(t==NULL)
     return 1;
   if(t->left!=NULL)
   {
      if(t->left->data > t->data)
        return 0;
   }
   if(t->right!=NULL)
   {
     if(t->right->data < t->data)
        return 0;
   }
   if((checkbst(t->left))&& (checkbst(t->right)))
     return 1;
   return 0;
 }







