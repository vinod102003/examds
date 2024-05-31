#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;


node* createNode(int data){
  
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

node* insert(node* root , int data){

  if(root == NULL){
    return createNode(data);
  }else if(root->data > data){
      root->left = insert(root->left , data);
  }else{
    root->right = insert(root->right , data);
  }

return root;
}

int search(node* root , int data){

  if(root == NULL){
    return 0;
  }else if(root->data == data){
    return 1;
  }else if(root->data > data){
      return search(root->left , data);
  }else{
    return search(root->right,data);
  }

}

int minElem(node* root){
  if (root == NULL){
    return -1;
    }
    if(root->left != NULL){
      return minElem(root->left);
    }else{
      return root->data;
    }
}


int maxElem(node* root){
  if (root == NULL){
    return -1;
    }
    if(root->right != NULL){
      return maxElem(root->right);
    }else{
      return root->data;
    }
}

void inorder(node* root){
  if(root!=NULL){
    inorder(root->left);
    printf("%d->" , root->data);
    inorder(root->right);
  }
  
}


void preorder(node* root){
  if(root!=NULL){
    printf("%d->" , root->data);
    preorder(root->left);
    preorder(root->right);
  }
  
}

void postorder(node* root){
  if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d->" , root->data);
  }
  
}
int main(){

node *root = NULL;

root = insert(root ,4);
root = insert(root ,24);
root = insert(root ,42);
root = insert(root ,46);
root = insert(root ,25);
root = insert(root ,98);
root = insert(root ,122);

inorder(root);
printf("\n");
preorder(root);
printf("\n");
postorder(root);
printf("\n");

int res = search(root , 458);
printf("the element 458 is present? %s\n",res ? "true" : "false");

int res1 = minElem(root);
printf("the smallest element is %d\n",res1);

int res2 = maxElem(root);
printf("the largest element is %d\n",res2);
  return 0;
}

