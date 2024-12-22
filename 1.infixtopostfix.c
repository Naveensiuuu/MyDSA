#include <stdio.h>
#include <ctype.h>

#define SIZE 20

typedef struct {
    int top;
    char data[SIZE];
}STACK;

void push(STACK *s,char ch){
    s->data[++(s->top)] = ch;
}

char pop(STACK *s){
    return s->data[(s->top)--];
}

char peek(STACK *s){
    return s->data[s->top];
}

int prcd(char ch){
    switch(ch){
        case '^': return 5;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 1;
    }
}

void infixToPostfix(STACK *s,char infix[SIZE]){
    int j = 0;
    char postfix[SIZE],symbol,temp;

    for(int i = 0;infix[i]!='\0';i++){
        symbol = infix[i];
        if(isalnum(symbol)){
            postfix[j++] = symbol;
        }
        else{
            switch(symbol){
            case '(': push(s,symbol);
            case ')': temp  = pop(s);
            while(temp!='('){
                postfix[j++] = pop(s);
                temp = pop(s);
            }
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
            if(s->top==-1 || peek(s)=='('){
                push(s,symbol);
            }
            else{
                while(prcd(peek(s))>=prcd(symbol) && s->top!=-1 && s->top!='('){
                    postfix[j++] = pop(s);
                }
                push(s,symbol);
            }
            }
        }
    }
    while(s->top!=-1){
        postfix[j++] = pop(s);
    }
    postfix[j++] = '\0';
    printf("Postfix: %s",postfix);
}

int main(){
    STACK s;
    s.top = -1;
    char infix[SIZE];
    printf("Enter infix Expression: ");
    scanf("%s",infix);
    infixToPostfix(&s,infix);
    return 0;
}