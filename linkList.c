#include <stdio.h>
#include <stdlib.h>
int A[100];
struct node
{
    int data;
    struct node *next;
} * head;

void create(int A[], int size)
{
    struct node *n, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < size; i++)
    {
        n = (struct node *)malloc(sizeof(struct node));
        n->data = A[i];
        n->next = NULL;
        last->next = n;
        last = n;
    }
}

void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

struct node *insert_at_first(struct node *head , int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return temp;
}

int main()
{

    int size, choice , data;
    printf("Enter the size of linked list you want\n");
    scanf("%d" , &size);
    printf("Enter the values of all the %d nodes of your linked list\n" , size);
    for(int i=0 ; i<size ; i++)
    {
        scanf("%d" , &A[i]);
    }
    create(A , size);
    while(1)
    {
        printf("Here is your linked list\n");
        display(head);
        printf("\n1->Insert at begginning\n");
        printf("2->Display\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value of the data you want to insert\n");
            scanf("%d" , &data);
            head = insert_at_first(head , data);
            break;
        case 2:
            display(head);
        }
    }

    return 0;
}