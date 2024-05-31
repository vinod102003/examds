#include <stdio.h>
#define max 10
typedef struct stack
{
  int arr[max];
  int top;
}stack;

int isFull(stack *s){
    return (s->top == max)?1:0;
}

int isEmpty(stack *s){
  return (s->top == -1)?1:0;
}

void push( stack *s , int elem){
  if(isFull(s)){
    printf("the stqck is full");
  }else{
    s->arr[++s->top] = elem;
  }
}

int pop(stack *s){
  if(isEmpty(s)){
    printf("the stack is empty");
  }else{
    return s->arr[s->top--];
  }
}

void display(stack *s){
  for(int i=s->top ; i>=0 ; i--){
    printf("%d\n" , s->arr[i]);
  }
}

void main(){
  stack s;
  s.top = -1;

push(&s,10);
push(&s,20);
push(&s,30);
push(&s,40);

printf("the poped element is %d\n",pop(&s));

display(&s);

}