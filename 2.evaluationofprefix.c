#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

typedef struct {
    int top;
    char data[SIZE];
}STACK;

void push(STACK *s,float op){
    s->data[++(s->top)] = op;
}

float pop(STACK *s){
    return s->data[(s->top)--];
}


float operate(float op1,float op2,char symbol){
    switch (symbol)
    {
    case '+':return op1+op2;
    case '-':return op1-op2;
    case '/':return op1/op2;
    case '*':return op1*op2;
    case '^':return pow(op1,op2);

}
}

float eval(STACK *s, char prefix[SIZE]){
    char symbol;
    float op1,op2,res;
    for(int i =0;i<strlen(prefix)-1;i++){
        symbol = prefix[i];
        if(isdigit(symbol)){
            push(s,symbol-'0');
        }
        else{
            op2 = pop(s);
            op1 = pop(s);
            res = operate(op1,op2,symbol);
            push(s,res);
        }
    }
    return pop(s);
}

int main(){
    char prefix[SIZE];
    STACK s;
    s.top = -1;
    printf("Enter prefix expression: ");
    scanf("%s",prefix);
    float ans = eval(&s,prefix);
    printf("The answer is : %f",ans);
    return 0;
}