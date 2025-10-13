#include<stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1,  rear = -1;
void insert(){
    int item ;
    if(rear == MAX -1){
        printf("Queue Underflow! Cannoty insert More items");
        return;
    }
    printf("Enter the elemnt to isert: ");
    scanf("%d",&item);
    if(front==-1){
        front =0;
    }
    rear++;
    queue[rear]=item;
    printf("Inserted %d into the queue\n",item);
}

void delete(){
    if(front==-1 || front>rear){
        printf("Queue Underflow! No element to delete");
        return;
    }
    printf("Deleted item: %d",queue[front]);
    front++;
    if(front>rear){
        front=rear=-1;
    }
}

void display(){
    if(front==-1){
        printf("Queue is Empty!");
    }
    printf("Queue  Element");
    for(int i=front;i<=rear;i++){
        printf("%d",queue[i]);
    }
    printf("/n");
}

int main(){
    int choice;
    while(1){
        printf("/n Queue Operation /n");
        printf("/n 1 Insert /n");
        printf("/n 2 Delete /n");
        printf("/n 3 Display /n");
        printf("/n 4 Exit /n");
        printf("\n Enter your Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n Invalid choice\n");
        }
    }
    return 0;
}


