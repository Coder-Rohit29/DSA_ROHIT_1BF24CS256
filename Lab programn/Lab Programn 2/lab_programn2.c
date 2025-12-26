#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int top =-1;
char stack[MAX];

void push(char c){
    stack[++top] = c;
}

char pop(){
    if(top==-1){
        printf("Stack Underflow");
        return 0;
    }
    return stack[top--];
}

int presidence(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='*' || c== '/'){
        return 2;
    }
    if(c=='+' || c=='-'){
        return 1;
    }
    return 0;
}
int match(char a,char b){
    if(a=='('  && b==')'){
        return 1;
    }
    if(a=='['  && b==']'){
        return 1;
    }
    if(a=='{'  && b=='}'){
        return 1;
    }
    return 0; 
}

int main(){
    char infix[MAX];
    int check;
    int temp=0;
    printf("Enter the expression\n");
    gets(infix);
    for(int i =0;i<strlen(infix);i++){
        if(isalnum(infix[i])){
            printf("%c",infix[i]);
        }
        else if(infix[i]=='(' || infix[i]=='{' || infix[i] =='['){
            push(infix[i]);
        }
        else if(infix[i]==')' || infix[i]=='}' || infix[i] ==']'){
            while(!match(stack[top],infix[i])){
                printf("%c",pop());
            }
            pop();
        }
        else{
            while(top!=-1 && presidence(infix[i])<=presidence(stack[top])){
                printf("%c",pop());
            }
            push(infix[i]);
        }
    }
    while (top!=-1)
    {
        printf("%c",pop());
    }
    return 0;
}
