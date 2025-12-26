#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;

struct Node* createLinked(int n){
    struct Node *newNode, *temp;
    int data;

    printf("Enter value of element 1:\n");
    scanf("%d",&data);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node *head = newNode;
    temp = head;

    for(int i = 2; i <= n; i++){
        printf("Enter value of element %d:\n", i);
        scanf("%d",&data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

void display(struct Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    int temp;
    for(struct Node* i = head; i != NULL; i = i->next){
        for(struct Node* j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List Sorted\n");
}

struct Node* reverse(struct Node* head){
    struct Node *curr = head, *prev = NULL, *next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printf("List Reversed\n");
    return prev;
}

struct Node* concatenate(struct Node* head1, struct Node* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    struct Node* temp = head1;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    printf("Lists Concatenated\n");
    return head1;
}

int main(){
    int choice, n1, n2;

    while(1){
        printf("\n1. Create List 1\n2. Create List 2\n3. Display List 1\n4. Display List 2\n5. Sort List 1\n6. Sort List 2\n7. Reverse List 1\n8. Reverse List 2\n9. Concatenate\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d",&n1);
                head1 = createLinked(n1);
                break;

            case 2:
                printf("Enter number of nodes: ");
                scanf("%d",&n2);
                head2 = createLinked(n2);
                break;

            case 3:
                display(head1);
                break;

            case 4:
                display(head2);
                break;

            case 5:
                sortList(head1);
                break;

            case 6:
                sortList(head2);
                break;

            case 7:
                head1 = reverse(head1);
                break;

            case 8:
                head2 = reverse(head2);
                break;

            case 9:
                head1 = concatenate(head1, head2);
                printf("Final List: ");
                display(head1);
                break;

            case 10:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
