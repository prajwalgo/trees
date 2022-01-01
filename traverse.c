#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int item;
  struct node *llink;
  struct node *rlink;
}NODE;
NODE*getnode()
{
  NODE* x;
  x=(NODE*)malloc(sizeof(struct node));
  scanf("%d",&x->item);
  return x;
}
NODE* insert(NODE* root)
{
  NODE *temp,*cur,*prev;
  temp=getnode();
  if(root==NULL)
  {
    root=temp;
  }
  else
  {
    prev=NULL;
    cur=root;
    while(cur!=NULL)
    {
      prev=cur;
      if(temp->item<cur->item)
      cur=cur->llink;
      else
      cur=cur->rlink;
    }
    if(temp->item<prev->item)
    prev->llink=temp;
    else
    prev->rlink=temp;
  }
  return root;
}
void search(NODE *root)
{
  int item;
  NODE *cur;
  cur=root;
  if(root==NULL)
  {
    printf("tree is empty\n");
  }
  else
  {
    printf("enter the item to be searched:");
    scanf("%d",&item);
    while(cur!=NULL)
    {
      if(cur->item==item)
      break;
      if(cur->item<item)
      cur=cur->rlink;
      else
      cur=cur->llink;
    }
    if(cur!=NULL)
    {
      printf("item found\n");

    }
    else
    {
      printf("item not found");
    }
  }
}
void preorder(NODE *root)
{
  if(root==NULL)return;
  printf("%d\t",root->item);
  preorder(root->llink);
  preorder(root->rlink);
}
void postorder(NODE *root)
{
  if(root==NULL)return;
  
  postorder(root->llink);
  postorder(root->rlink);
  printf("%d\t",root->item);
}
void inorder(NODE *root)
{
  if(root==NULL)return;
  inorder(root->llink);
  printf("%d\t",root->item);
  inorder(root->rlink);
 
}
int find_height(NODE *root)
{
  if(root==NULL)
  {
    return -1;
  }
  else
{
  int lheight=find_height(root->llink);
  int rheight=find_height(root->rlink);
  if(lheight>rheight)
  return(lheight+1);
  else
  return(rheight+1);
}
}
int main()
{
  int ch,i,n,ht;
  NODE *root=NULL;
  while(ch<5)
  {
    printf("\n1.create\t2.traverse\t3.search\t4.height\t5.Exit\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("enter the number of nodes to be inserted:");
      scanf("%d",&n);
      printf("enter the tree nodes\n");
      for(i=0;i<n;i++)
      {
        root=insert(root);
      }
      break;
      case 2:printf("\npreorder traversal");
      preorder(root);
      printf("\ninorder traversal");
      inorder(root);
      printf("\npostorder traversal");
      postorder(root);
      break;
      case 3:search(root);
      break;
      case 4:ht=find_height(root);
      printf("\nheight of the tree=%d\n",ht);
      break;
      case 5:exit(0);
      default:printf("\ninvalid choice\n");
      break;
    }
  }
  return 0;
}
