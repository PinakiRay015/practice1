#include <stdio.h>
int size;
int top = -1;
void push();
void pop();
int stack[];
int main()
{

    int choice;
    printf("What is the size of the stack you want to create\n");
    scanf("%d" , &size);
    printf("A STACK OF SIZE %d IS CREATED\n", size);
    while (1)
    {
        printf("\n1-> Insert an element inside the stack\n");
        printf("2-> Remove an element from the stack\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        default:
            printf("INVALID CHOICE\n");
        }
    }

    return 0;
}

void push()
{
    int data;
    if (top == size - 1)
    {
        printf("\nStack overflow\n");
    }
    else
    {
        printf("Enter the element you want to push inside the stack\n");
        scanf("%d", &data);
        top = top + 1;
        stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack underflow\n");
    }
    else
    {
        printf("\n%d is removed from the stack\n", stack[top]);
        top = top - 1;
    }
}