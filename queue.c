#include<stdio.h>
int size;
int queue[100];
void enqueue();
void dequeue();
int rear =0;
int front = 0;
int main(){

    int choice;
    printf("Enter the size of the queue\n");
    scanf("%d" , &size);
    printf("Queue of size %d is created\n" , size);
    while(1)
    {
        printf("\n1->Enqueue operation\n");
        printf("2->Dequeue operation\n");
        printf("Enter the choice\n");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            default:
            printf("INVALID CHOICE\n");
        }
    }
return 0;
}

void enqueue()
{
    int data;
    if(rear==size)
    {
        printf("QUEUE OVERFLOW\n");
    }
    else{
        printf("Enter the value\n");
        scanf("%d" , &data);
        queue[rear] = data;
        rear = rear+1;
    }
}

void dequeue()
{
    if(front==rear)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else{
        printf("%d is removed from the stack\n" , queue[front]);
        front=front+1;
    }
}