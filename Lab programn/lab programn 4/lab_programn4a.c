#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createLinkedList(int n)
{
    struct Node *newNode, *temp;
    int data;
    if (head == NULL)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the value \n");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
    }
    temp = head;
    for (int i = 1; i < n; i++)
    {

        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the value \n");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp=temp->next;      
    }
}

void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node ));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtSpecific(int data , int pos){
    struct Node* newNode =  (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if(pos<0){
        printf("Index out of Bound");
        return;
    }
    if(pos==1){
        insertAtBeginning(data);
        return;
    }
    else{
        struct Node * temp = head;
        for(int i=1;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main(){
int choice, n, data, pos;

    while (1)
    {
        printf("\n---- LINKED LIST MENU ----\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createLinkedList(n);
            break;

        case 2:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;

        case 3:
            printf("Enter value to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtSpecific(data, pos);
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}