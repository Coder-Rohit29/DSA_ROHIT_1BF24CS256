#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, end = -1;

void insert(int data)
{
    if (end == MAX - 1)
    {
        printf("Queue is FULL\n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            end = 0;
            queue[end] = data;
            return;
        }
        queue[++end] = data;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d Removed\n", queue[front]);
    if(front==end){
        front=end=-1;
    }
    else{
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty");
        return;
    }
    printf("Printing Queue\n");
    for (int i = front; i <= end; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{

    int value;
    int num;
    while(1){
    printf("Enter 1 for insert , 2 for delete , 3 for display,4 exit\n");
    scanf("%d", &value);
    switch (value)
    {
    case 1:
        printf("Enter value to insert\n");
        scanf("%d", &num);
        insert(num);
        break;
    case 2:
        delete();
        break;
    case 3:
        display();
        break;
    case 4:
        return 0;
    default:
        break;
    }}
    return 0;
}