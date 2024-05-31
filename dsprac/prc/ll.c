#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* createNode(int x){

node* newNode = (node*)malloc(sizeof(node));
newNode->data = x;
newNode->next = NULL;
newNode->prev = NULL;

return newNode;
}

node* insertAtStart(node* head , int data){
  node* newNode = createNode(data);
  if(head == NULL){
    head = newNode;
  }else{
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  return head;
}

node* insertAtEnd(node* head , int data){
  node* newNode = createNode(data);
  if(head == NULL){
    head = newNode;
  }else{
      node* temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->prev = temp;
  }
  return head;
}

node* deleteAtStart(node* head){
  
  if(head == NULL){
      printf("the ll is empty");
      return NULL;
  }else if(head->next == NULL){
      free(head);
      head = NULL; 
  }else{
      node* temp  = head;
      head = head->next;
      head->prev = NULL;
      free(temp);
  }
  return head;
}

node* deleteAtEnd(node* head){
  
  if(head == NULL){
      printf("the ll is empty");
      return NULL;
  }else if(head->next == NULL){
      free(head);
      head = NULL; 
  }else{
      node* temp  = head;
          while (temp->next != NULL)
          {
            temp = temp->next;
          }
          temp->prev->next = NULL;
        }
  return head;
}


void display(node* head){
  node* temp = head;
  while (temp != NULL)
  {
    printf("the elements are %d\n",temp->data);
    temp  = temp->next;
  }

  
}


void main(){

node* head = NULL;
head = insertAtStart(head , 50);
head = insertAtStart(head , 40);
head = insertAtStart(head , 30);
head = insertAtStart(head , 20);

head = insertAtEnd(head,60);

head = deleteAtEnd(head);
head = deleteAtStart(head);

display(head);

}