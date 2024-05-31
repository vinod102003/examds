#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
  int data;
  struct node *left;  
  struct node *right;
}node;

node* createNode(int data){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

node* insertLeft(node*root , int data){
  root->left = createNode(data);
  return root->left;
}

node* insertRight(node*root , int data){
  root->right = createNode(data);
  return root->right;
}

void inorder(node* root){
  if(root!=NULL)
 {
  /* code */
  inorder(root->left);
  printf("%d->",root->data);
  inorder(root->right);
 }
 
 
  
}
void main(){
  node *root;

  root = createNode(10);
        insertLeft(root , 6);
        insertRight(root , 16);
    
        insertLeft(root->left , 4);
        insertRight(root->left , 7);
      
        insertLeft(root->right , 15);
        insertRight(root->right , 56);
  
inorder(root);

}
