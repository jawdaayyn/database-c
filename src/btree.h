#ifndef BTREE_H
#define BTREE_H

typedef struct User {
    char username[50];
    char email[100];
    int id;
} User;

typedef struct Node {
    User data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(User data);
void insert_node(Node** root, User data);
void delete_tree(Node* root);
void print_tree(Node* root);
Node* find_min(Node* root);
Node* delete_node(Node* root, int id);
Node* search_by_id(Node* root, int id);

extern int nextID; 

#endif
