#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

bool insert(Node** root, int data) {
    if (!(*root)){
        *root = newNode(data);
        return true;
    }

    if (data < (*root)->data) {
        return insert(&((*root)->left), data);
    } else if (data > (*root)->data) {
        return insert(&((*root)->right), data);
    } else { 
        return false; 
    }
}

bool search(Node* root, int data){
    if(!root){
        return false;
    }
    if(data == root->data){
        return true;
    }

    if(data < root->data){
        return search(root->left, data);
    }
    return search(root->right, data);
}

Node* getMaxValueNode(Node* root) {
    Node* current = root;

    while (current && current->right) {
        current = current->right;
    }
    return current;
}

Node* delete(Node* root, int data) {
    if (!root) return root;

    
    if (data < root->data) {
        root->left = delete(root->left, data);
    }
    
    else if (data > root->data) {
        root->right = delete(root->right, data);
    }
    
    else {
        
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        
        Node* temp = getMaxValueNode(root->left);
        root->data = temp->data;
        root->left = delete(root->left, temp->data);
    }
    return root;
}


void print(Node* root) {
    if (!root) return;

    printf("(");
    print(root->left);
    printf("%d", root->data);
    print(root->right);
    printf(")");
}

int main(){
    Node *root = NULL;
    char command;
    int num;
    while(scanf("%c", &command) != EOF){
        if(command == 'i'){
            scanf("%d", &num);
            if(insert(&root, num)){
                printf("inserted\n");
            }else{
                printf("not inserted\n");
            }
        }
        else if(command == 's'){
            if(search(root, num)){
                printf("present\n");
            }
            else{
                printf("absent\n");
            }
        }else if (command == 'p') {
            print(root);
            printf("\n");
        }
        else if (command == 'd') {
        scanf("%d", &num);
        if (!search(root, num)) {
            printf("absent\n");
        } else {
            root = delete(root, num);
            printf("deleted\n");
    }
}

    }
    return 0;
}
