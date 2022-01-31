#include<stdio.h>
#include<stdlib.h>
int A[100];

struct node
{
    int data;
    struct node *next;
}*head;

void create(int A[] , int size)
{
    struct node *n , *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i=1 ; i<size ; i++)
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
    while(temp!=NULL)
    {
        printf("%d\t" , temp->data);
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

struct node *insert_at_index(struct node *head , int data , int index)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    temp->data = data;
    int i;
    while(ptr->next!= index-1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->next = temp->next;
    ptr->next = temp;
    return temp;
}

int main()
{
    int data , size , choice , index;
    printf("Enter the size of the linked list that you want to create\n");
    scanf("%d" , &size);
    printf("Enter the value of all the nodes of your linked list\n");
    for(int i = 0; i<size; i++)
    {
        scanf("%d" , &A[i]);
    }
    create(A , size);
    while(1)
    {
        printf("Here is your linked list\n");
        display(head);
        printf("\n1->Insert_at_first\n");
        printf("2->Insert_at_index\n");
        printf("Enter your choice\n");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value that you want  to insert inside the linked list\n");
            scanf("%d" , &data);
            head = insert_at_first(head, data);
            break;

            case 2:
            printf("Enter the value that you want to insert inside the linked list");
            scanf("%d" , &data);
            printf("Enter the index at which your element will be inserted\n");
            scanf("%d" , &index);
            head = insert_at_index(head , data , index);
            break;

            default:
            printf("Invalid chooice");
        }
    }
    

}