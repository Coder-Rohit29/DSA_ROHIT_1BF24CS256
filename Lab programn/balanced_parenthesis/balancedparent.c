#include<stdio.h>
#include<string.h>

#define MAX 100

int  top =-1;
char stack[MAX];

void push(char c){
    stack[++top] = c;
}

char pop(){
    if(top==-1){
        printf("Stack Underflow");
        return -1;
    }
    return stack[top--];
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
    char exp[MAX];
    printf("Enter the string\n");
    gets(exp);

    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top==-1 || (match(pop(),exp[i]))!=1){
                printf("Not Matched");
                return 0;
            }
        }
    }
    if(top==-1){
        printf("Matched");
    }
    else{
        printf("Not Matched\n");
    }
    return 0;
}