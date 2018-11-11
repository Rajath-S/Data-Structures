#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

typedef struct tree {
	node* root;
} tree;


void tree_initialize(tree* tree);
void tree_insert(tree* tree, int data);

/* Print elements on successive lines */
void tree_print_inorder(tree* tree);
void tree_print_preorder(tree* tree);
void tree_print_postorder(tree* tree);

/* Advisory: While some guarded discernment could perhaps lead you to
 * more efficient implementations, you are requested to provide suitable recursive
 * solutions for the following function declarations.
 */

int tree_count_leaves(tree* tree);


node* tree_max(tree* tree);
node* tree_min(tree* tree);
int tree_count_nodes(tree* tree);
int tree_count_internal_nodes(tree* tree);
void tree_destruct(tree *tree);

int main() {
	int choice, loop = 1;
	tree my_tree;
	tree_initialize(&my_tree);
	while(loop) {
		scanf("%d", &choice);
		switch(choice) {
			int number_of_elements, element, index;
			int data;
			node *min_node, *max_node;
			case 1:
				/* Insert elements */
				scanf("%d", &element);
				tree_insert(&my_tree, element);
				break;
			case 2:
				/* Print elements in the inorder fashion */
				tree_print_inorder(&my_tree);
				printf("\n");
				break;
			case 3:
				/* Print elements in the preorder fashion */
				tree_print_preorder(&my_tree);
				printf("\n");
				break;
			case 4:
				/* Print elements in the postorder fashion */
				tree_print_postorder(&my_tree);
				printf("\n");
				break;
			case 5:
				/* Print the smallest and the largest element */
				min_node = tree_min(&my_tree);
				max_node = tree_max(&my_tree);
				if(min_node || max_node)
					printf("%d %d\n", min_node -> data, max_node -> data);
				else
					printf("None\n");
				break;
			case 6:
				/* Print the number of leaves, internal nodes and total number of nodes */
				printf("%d %d %d\n", tree_count_leaves(&my_tree), tree_count_internal_nodes(&my_tree), tree_count_nodes(&my_tree));
				break;

			case 8:
				tree_destruct(&my_tree);
				loop = 0;

		}
	}
	return 0;
}

void tree_initialize(tree* tree)
{
    tree->root=NULL;
}
void tree_insert(tree* tree, int data)
{
    node* ptr_to_newnode=(node*)malloc(sizeof(node));
    ptr_to_newnode->left=NULL;
    ptr_to_newnode->right=NULL;
    ptr_to_newnode->data=data;
    if(tree->root==NULL)
        tree->root=ptr_to_newnode;
    else
    {
        node* prev=NULL;
        node* pres=tree->root;
        while(pres!=NULL)
        {
        prev=pres
        if(data<pres->data)
            pres=pres->left;
        else
            pres=pres->right;
        }
        if(data<prev->data)
            prev->left=ptr_to_newnode;
        else
            prev->right=ptr_to_newnode;
    }

}
void tree_print_inorder(tree* tree)
{
    node* pres=tree->root;
    if(pres!=NULL)
    {
        tree_print_preorder(pres->left);
        print("%d",pres->data);
        tree_print_preorder(pres->right);
    }
}
void tree_print_preorder(tree* tree)
{
    node* pres=tree->root;
    if(pres!=NULL)
    {
        print("%d",pres->data);
        tree_print_preorder(pres->left);
        tree_print_preorder(pres->right);
    }
}

void tree_print_postorder(tree* tree)
{
    node* pres=tree->root;
    if(pres!=NULL)
    {
        tree_print_preorder(pres->left);
        tree_print_preorder(pres->right);
        print("%d",pres->data);
    }

}
int tree_count_leaves(tree* tree)
{
    //node* pres=tree->root;
    //count=0;
    if(tree->root==NULL)
        return 0
    if(tree->root->left==NULL&&tree->root->right==NULL)
        return 1
    int l=tree_count_leaves(tree->root->left);
    int r=tree_count_leaves(tree->root->right);
    return l+r;
}
node* tree_max(tree* tree)
{   if(tree->root==NULL)
      return NULL
    else
      tree_max(tree->right);
}
node* tree_max(tree* tree)
{

}
node* tree_min(tree* tree)
{

}
int tree_count_nodes(tree* tree)
{

}
int tree_count_internal_nodes(tree* tree)
{

}
void tree_destruct(tree *tree)
{

}
