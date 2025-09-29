#include <stdio.h>

#define n 5
int stack[n];
int top = -1;
void push()
{
    int x;
    printf("Enter Data");
    scanf("%d", &x);

    if (top == n - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    int item;
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf(" %d ", item);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("%d", stack[top]);
    }
}

void display(){
    for(int i =top;i>-1;i--){
        printf("%d ",stack[i]);
    }
}

int main()
{

    while (1)
    {
        int c;
        printf("Select 1 for Push , 2 for Pop , 3 for Peek , 4 to display , 5 to exit");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting the loop");
            return 0;
           
        default:
            printf("Enter Valid input!");
            break;
        }
        printf("\n");
    }

    return 0;
}