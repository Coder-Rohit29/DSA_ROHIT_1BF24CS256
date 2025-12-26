#include <stdio.h>
#define MAX 5

int front = -1;
int rear = -1;
int queue[MAX];

void enque(int data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
        return;
    }
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is FULL\n");
        return;
    }
    rear=(rear+1)%MAX;
    queue[rear]=data;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
        return;
    }
    front = (front + 1) % MAX;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("Printing QUEUE\n");

    int temp = front;
    while (1)
    {
        printf("%d ", queue[temp]);

        if (temp == rear)
            break;

        temp = (temp + 1) % MAX;
    }

    printf("\n");
}


int main()
{
    int value;
    int data;
    while (1)
    {
        printf("Enter 1 for enque,2 for dequeue ,3 for display & 4 for exit\n");
        scanf("%d", &value);

        switch (value)
        {
        case 1:
            printf("Enter the data to insert\n");
            scanf("%d", &data);
            enque(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }

    return 0;
}