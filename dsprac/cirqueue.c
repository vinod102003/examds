#include <stdio.h>
#define max 10
int queue[max];
int front , rear;

int isEmpty(){
  return (front == -1 && rear == -1)?1:0;
}

int isFull(){
  return (rear+1) % max == front ? 1 :0;
}

void enqueue(int elem){
  
 
  
  if(isFull()){
    printf("the queue is full");
  }else{ 
     if(front == -1){
    front = 0;
  }   
    rear = (rear + 1) % max;
    queue[rear] = elem;
  }
  
}

int dequeue(){
  
  int res;
  if(isEmpty()){
    printf("the queue is empty");
  }else if(front == rear){
      res = queue[front];
      front = rear = -1;
  }else{
 res = queue[front];
 front = (front + 1) % max;   
  }
  return res;
}


void display(){
 if(isEmpty()){
  printf("the empty");
  return;
 }
 int i = front;
 while (1)
 {
      printf("%d\n" , queue[i]);

      if(i == rear){
        break;
      }
      i = (i + 1) % max;
 }
 

}


void main(){

front = rear = -1;

enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
enqueue(50);

printf("the dequeued element is %d\n" , dequeue());


display();

}