#include<stdio.h>
#include<stdlib.h>
int size;
int stack[100];
void push();
void pop();
int top = -1;
int main(){

    int choice;
    printf("Enter the size of the stack you want to create\n");
    scanf("%d" , &size);
    printf("The stack of size %d is created\n" , size);
    while(1)
    {
        printf("\n1->Insert an element inside stack\n");
        printf("2-> Remove an element from the stack\n");
        printf("Enter your choice\n");
        scanf("%d" , &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;
        
        default:
            printf("Invalid choice\n");
        }
    }

return 0;
}

void push()
{
    int data;
    if(top==size-1)
    {
        printf("****STACK OVERFLOW***\n");
    }
    else
    {
        printf("Enter the value of the element of which you want to insert inside stack\n");
        scanf("%d" , &data);
        top = top+1;
        stack[top] = data;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("****STACK UNDERFLOW\n");
    }
    else
    {
        printf("%d is removed from the stack\n" , stack[top]);
        top = top-1;
    }
}