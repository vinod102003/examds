// Online C compiler to run C program online
#include <stdio.h>
#include <ctype.h>
#define max 20

int stack[max];
int top = -1;

void push(int x){
if(top == max -1 ){
    printf("full");
}else{
    stack[++top] = x;
}    
}

int pop(){
    if(top == -1){
        return -1;
    }else{
        return stack[top--];
    }
}

int postfix_eval(char exp[]){
    int v1 , v2 , res;
    for(int i=0 ; exp[i] != '\0' ;i++){
        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }else{
            v2 = pop();
            if(top == -1){
                printf("the stack is empty");
            }
            v1 = pop();
            
            switch(exp[i]){
                case '+':
                    res = v1 + v2;
                    break;
                case '-':
                    res = v1 - v2;
                    break;
                case '*':
                    res = v1 * v2;
                    break;
                case '/':
                    if(v2 == 0){
                        printf("zero error");
                    }else{
                    res = v1 / v2;
                    break;
                }    
            }
            push(res);
       }
       
    }

return pop();
}




int main() {
    // Write C code here
   char expr[] = "27+";
   int  res = postfix_eval(expr);
   printf("%d" ,res);

    return 0;
}