#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Type du user
typedef struct User {
    char username[50];
    char email[100];
    int id;
} User;


// Type du noeud dans l'arbre
typedef struct Node {
    User data;
    struct Node* left;
    struct Node* right;
} Node;

// Prochain ID qui va être utilisé lors d'une création d'un utilisateur
int nextID = 0; 

// Fonction pour créer un noeud
Node* create_node(User data) {
    

    // On alloue la mémoire
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Si on a pas réussi à allouer de la mémoire
        exit(1);
    }


    // On assigne ce qu'on va mettre dans le noeud
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert_node(Node** root, User data) {
    // Ici on génère automatiquement l'id du nouveau noeud
    data.id = nextID++; 
    Node* newNode = create_node(data);
    if (*root == NULL) {
        // si c'est le premier noeud pas besoin de le placer dans l'arbre
        *root = newNode;
        return;
    }

    Node* current = *root;
    Node* parent = NULL;

    // Ici on cherche où placer le noeud dans le BST


// tant que le noeud où placer l'élément n'existe pas on continue à chercher l'endroit où le placer
    while (current != NULL) {
        parent = current;
        // si l'id du nouvel élément est inférieur à l'élément actuel on cherche à gauche
        if (data.id < current->data.id) {
            current = current->left;
            if (current == NULL) {
                parent->left = newNode;
                break;
            }
        // sinon on cherche à droite
        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = newNode;
                break;
            }
        }
    }
}

// Fonction récursive pour supprimer l'arbre entier
void delete_tree(Node* root) {

    // s'il n'y a pas de noeud on arrête.
    if (root == NULL) {
        return;
    }

    // on supprime les enfant à gauche du noeud
    delete_tree(root->left);
    // on supprime les enfant à gauche du noeud
    delete_tree(root->right);

    // on libère la mémoire de ce noeud
    free(root);
}

void print_tree(Node* root) {
    if (root != NULL) {
        // Cette méthode permet de chercher à la fois les éléments d'à droite de l'arbre et d'à gauche, donc tous les éléments seront montrés.
        print_tree(root->left);
        printf("ID: %d, Nom d'utilisateur: %s, E-mail: %s\n",
               root->data.id, root->data.username, root->data.email);
        print_tree(root->right);
    }
}




Node* search_by_id(Node* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root; // Fin de la recherche => Soit un élément est trouvé soit rien.
    }

    if (id < root->data.id) {
        return search_by_id(root->left, id); // Chercher à gauche
    } else {
        return search_by_id(root->right, id); // Chercher à droite
    }
}

