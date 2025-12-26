#include <stdio.h>
#define Stack_len 5

int stack[Stack_len];
int top = -1;

void push()
{
    int data;
    if (top == Stack_len - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        printf("Enter value to insert\n");
        scanf("%d", &data);
        stack[++top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("StacK underflow\n");
        return;
    }
    else
    {
        printf("%d Removed\n", stack[top]);
        top--;
        return;
    }
}

void display()
{
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }printf("Displaying Stack\n");
    for(int i=top;i>-1;i--){
        
        printf("%d\n",stack[i]);
    }
}

int main()
{

    int n;

    while (1)
    {
        printf("Enter 1 for push, 2 for pop , 3 for Display Stack & 4 for exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Enter a valid input");
            break;
        }
    }

    return 0;
}