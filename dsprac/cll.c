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
  newNode->next = newNode; 
  return newNode;
}

node* insertAtStart(node* head, int data){
  node *newNode = createNode(data);
  
  if(head == NULL){
    head = newNode;
  } else {
    newNode->next = head;
   node* temp = head;
   while (temp->next != NULL)
   {
      temp = temp->next;
   }
   temp->next = newNode;
   head = newNode;
  }
  return head;
}

node* insertAtEnd(node* head, int data){
  node* newNode = createNode(data);
  
  if(head == NULL){
    head = newNode;
  } else {
    node* temp = head;
    while(temp->next != head) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }
  return head;
}

node* delStart(node* head){
  if(head == NULL){
    printf("The linked list is empty\n");
    return head;
  } else if(head->next == head){
    free(head);
    head = NULL;
  } else {
    node* temp = head;
    node* last = head;
    while(last->next != head) {
      last = last->next;
    }
    last->next = head->next;
    head = head->next;
    free(temp);
  }
  return head;
}

node* deleteLast(node* head){
  if(head == NULL){
    printf("The linked list is empty\n");
  } else if(head->next == head){
    free(head);
    head = NULL;
  } else {
    node* temp = head;
    while(temp->next->next != head) {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
  }
  return head;
}

void insertAfter(node* prev, int data){
  if(prev == NULL){
    printf("The previous node cannot be null\n");
    return;
  }
  node* newNode = createNode(data);
  newNode->next = prev->next;
  prev->next = newNode;
}

void display(node* head){
  if(head == NULL) {
    printf("The linked list is empty\n");
    return;
  }
  node* temp = head;
  do {
    printf("%d->", temp->data);
    temp = temp->next;
  } while(temp != head);
  printf("(head)\n");
}

void sum(node* head){
  if(head == NULL) {
    printf("The linked list is empty\n");
    return;
  }
  node* temp = head;
  int sum = 0;
  do {
    sum += temp->data;
    temp = temp->next;
  } while(temp != head);
  printf("The sum of all nodes is: %d\n", sum);
}

int main(){
  node *head = NULL;

  head = insertAtStart(head, 40);
  head = insertAtStart(head, 30);
  head = insertAtStart(head, 20);
  head = insertAtStart(head, 10);
  head = insertAtEnd(head, 50);

  head = delStart(head);
  head = deleteLast(head);

  node* temp = head->next;
  insertAfter(temp, 10);

  display(head);
  sum(head);

  return 0;
}
