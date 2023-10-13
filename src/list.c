#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;

void insert(int n){
    Node *ptr = head;
    Node *newNode = malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;

      if (!head || head->data > n) {
        newNode->next = head;
        head = newNode;
        return;
    }

    while(ptr->next != NULL && ptr->next->data < newNode->data){
        if(ptr->next->data == newNode->data){
            free(newNode);
            return;
        }
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;

}

void delete(int n){
    if(head == NULL){
        return;
    }

    if(head->data == n){
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node *ptr = head;
    Node *preptr = head;

    while(ptr != NULL && ptr->data != n){
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr != NULL && ptr->data == n){
        preptr->next = ptr->next;
        free(ptr);
    }
}

void print() {
    Node *ptr = head;
    int count = 0;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    
    printf("%d :", count);

    ptr = head;
    while (ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    char command;
    int num;

    while (scanf("%c %d\n", &command, &num) != EOF) {
        if (command == 'i') {
            insert(num);
        } else if (command == 'd') {
            delete(num);
        }
        print();
    }

    Node *ptr = head;
    while (ptr != NULL) {
        Node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    return 0;
}
