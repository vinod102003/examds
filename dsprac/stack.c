#include <stdio.h>
#define max 10
int stack[max];
int top;

int isFull(){
  return (top == max-1)?1:0;
}

int isEmpty(){
  return (top == -1)?1:0;
}

void push(int elem){

  if(isFull()){
    printf("the stack is full\n");
  }else{
    stack[++top] = elem;
  }
}

int pop(){
  if(isEmpty()){
    printf("the stack is empty");
   
  }else{
    int elem = stack[top];
    top--;
    return elem;
}
}

void display(){
 if(isEmpty()){
  printf("the stack is empty");
 }else{
  for(int i=top ; i>=0 ; i--){
    printf("%d\n" , stack[i]);
  }
 }
  
}


void main(){

top = -1;
push(5);
push(4);
push(3);
push(2);

printf("the poped element is %d\n" , pop());

display();

}

