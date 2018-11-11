void insert(stuct tnode** t)// as address of root is passed
{
  struct tnode *temp,*prev,*curr;
  temp=(struct tnode )malloc(sizeof(tnode));
  temp->data=x;
  temp->left=temp->right=NULL;
  if(*t==NULL)
    *t=temp;
  else
  {
    prev=NULL;
    curr=*t;
    while(curr!=NULL)
    {
      prev=curr;
      if(x<curr->data)
        curr=curr->left;
      else
          curr=curr->right;

    }
    if(x<prev->data)
      prev->left=temp
    else
      prev->right=temp;

  }



}
