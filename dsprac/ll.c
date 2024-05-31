#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;

node* createNode(int data){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

node* insertAtStart(node* head , int data){
  node *newNode = createNode(data);
  
  if(head == NULL){
    head = newNode;
  }else{
  newNode->next = head;
  head=newNode;
}

return head;
}

node* insertATEnd(node* head, int data){
 
  node* newNode = createNode(data);
  
  if(head == NULL){
    head = newNode;
  }else{
       node *temp = head;
      while (temp->next != NULL)
    {
    temp = temp->next;
   }
   temp->next = newNode;
  }
    
   return head;
}

node* delStart(node* head){


if(head == NULL){
  printf("the ll is empty");
}else if(head->next == NULL){
  free(head);
  head = NULL;
}else{

  node* temp = head;
  head = head->next;
  free(temp);
}
  return head;
}

node* deleteLast(node* head){

  if(head == NULL){
    printf("the ll is empty");
  }else if(head->next == NULL){
    free(head);
    head = NULL;
  }else{
    node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    
  }
  return head;
}


void insertAfter(node* prev , int data){
  node* newNode = createNode(data);
  if(prev == NULL){
    printf("the previous node cannot be null");
  }else{
      newNode->next = prev->next;
      prev->next = newNode;
  }
  
}



void display(node* head){
  node* temp = head;
  while (temp != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->next;
  }
  printf("\n");
}


void sum(node* head){
  node* temp = head;
  int sum = 0;
  while (temp != NULL)
  {
    int r = temp->data;
    sum+=r;
    temp = temp->next; 
  }
  printf("the sum of all nodes are: %d",sum);
  
}


void main(){

node *head = NULL;

head  = insertAtStart(head , 40);
head  = insertAtStart(head , 30);
head  = insertAtStart(head , 20);
head  = insertAtStart(head , 10);
head = insertATEnd(head,50);

head = delStart(head);
head = deleteLast(head);

 node* temp = head->next;
insertAfter(temp,10);

display(head);
sum(head);

}



