#include <stdio.h>
#define max 10
int queue[max];
int front , rear;

int isFull(){
 return (rear == max-1) ? 1:0;
}

int isEmpty(){
  return (rear == -1 && front == -1)?1:0;
}

void enqueue(int elem){
 
 
 
 
  if(isFull()){
    printf("the queue is full");
  }else{
    if(front == -1){
    front = 0;
    };
      queue[++rear] = elem;
  }
}

int dequeue(){
  int res;
  if(isEmpty()){
    printf("the queue is empty");
  }else if(front  == rear){
    res = queue[front];
    front = rear = -1;
  }else{
    res = queue[front++];
  }
  return res;
}


void display(){
  for (int i = front; i <= rear; i++)
  {
    /* code */
    printf("%d\n" , queue[i]);
  }
  
}


void main(){
  front = rear = -1;

enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);

printf("the dequeued element is %d\n" , dequeue());

display();

}