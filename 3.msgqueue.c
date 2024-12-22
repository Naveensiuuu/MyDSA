#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct{
    int front,rear;
    char data[SIZE][20];
}QUEUE;

void send(QUEUE *q, char msg[SIZE]){
    if(q->front==(q->rear+1)%SIZE){
        printf("Queue is full");
    }
    else{
        q->rear = (q->rear+1)%SIZE;
        strcpy(q->data[q->rear],msg);

    }
    if(q->front==-1){
        q->front = 0;
    }
}

char* recieve(QUEUE *q){
    char *del;
    if(q->front==-1){
        printf("Queue is Empty!");
        return NULL;
    }
    else{
        del = q->data[q->front];
        if(q->front==q->rear){
            q->front = -1;
            q->rear = -1;
        }
        else{
            q->front = (q->front+1)%SIZE;   
        }
    return del;
    }
}

void display(QUEUE q){
    int i;
    if(q.front==-1){
        printf("Queue is empty!");
    }
    for(i=q.front;i!=q.rear;i=(i+1)%SIZE){
        printf("%s\n",q.data[i]);
    }
     printf("%s\n",q.data[i]);
}

int main(){
    int in;
    char* del;
    char mg[SIZE];
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    for(;;){
        printf("1.Send\n 2.Recieve\n 3.Display\n 4.Exit");
        printf("\nEnter your choice");
        scanf("%d",&in);
        getchar();

        switch(in){
            case 1:
            printf("Enter the msg to send: ");
            gets(mg);
            send(&q,mg);
            break;
            case 2:
            del = recieve(&q);
            printf("%s",del);
            break;
            case 3:
            display(q);
            break;
            default: exit(0);
        }
    }


}