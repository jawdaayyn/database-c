#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data) {
    Node* newNode = createNode(data);  
    if (*root == NULL) { 
        *root = newNode;
        return;
    }

    Node* current = *root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (data < current->data) { 
            current = current->left;
            if (current == NULL) {
                parent->left = newNode;  
                break;
            }
        } else { 
            current = current->right;
            if (current == NULL) {
                parent->right = newNode;  
                break;
            }
        }
    }

    return;
}

// int main() {

//     Node* root = NULL;

//     insert(&root, 20);
//     insert(&root, 10);
//     insert(&root, 30);
//     insert(&root, 5);
//     insert(&root, 15);

//     printf("Node's data is %d", root->right->data);
//     return 0;
// }
