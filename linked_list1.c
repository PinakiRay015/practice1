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
    struct node *new , *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i = 1 ; i<size ; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = A[i];
        new->next = NULL;
        last->next = new;
        last = new;
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
    return head;
}

struct node *insert_at_index(struct node *head , int data , int index)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    int i = 0;
    while(i!=index-1)
    {
        ptr = ptr->next;
        i++;
    }
    temp->data = data;
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

struct node *insert_at_end(struct node *head , int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node ));
    struct node *ptr = head;
    temp->data = data;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = NULL;
    return head;
}

int main(){

    int size , choice , data , index;
    printf("Enter the size of the linked list you want to create\n");
    scanf("%d" , &size);
    printf("Enter the value of the %d nodes of your linked list\n");
    for(int i = 0 ; i<size ; i++)
    {
        scanf("%d" , &A[i]);    
    }
    create(A , size);
    while(1)
    {
        printf("\nHere is your linked list\n");
        display(head);
        printf("\n1-> INSERT AT FIRST\n");
        printf("2-> INSERT AT INDEX\n");
        printf("3-> INSERT AT END\n");

        printf("Enter your choice\n");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the value of the data that you want to insert\n");
            scanf("%d" , &data);
            head = insert_at_first(head , data);
            display(head);
            break;

            case 2:
            printf("Enter the value of the data that you want to insert\n");
            scanf("%d" , &data);
            printf("Enter the index\n");
            scanf("%d" , &index);
            head = insert_at_index(head , data , index);
            display(head);
            break;

            case 3:
            printf("Enter the value of the data that you want to insert\n");
            scanf("%d" , &data);
            head = insert_at_end(head , data);
            display(head);
            break;

            default:
            printf("INVALID CHOICE!!!!");
        }
    }

return 0;
}