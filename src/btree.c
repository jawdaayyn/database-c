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
int nextID = 1; 

// Fonction pour créer un noeud
Node* createNode(User data) {
    

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

void insert(Node** root, User data) {
    // Ici on génère automatiquement l'id du nouveau noeud
    data.id = nextID++; 
    Node* newNode = createNode(data);
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

void printTree(Node* root) {
    if (root != NULL) {
        // Cette méthode permet de chercher à la fois les éléments d'à droite de l'arbre et d'à gauche, donc tous les éléments seront montrés.
        printTree(root->left);
        printf("ID: %d, Username: %s, Email: %s\n",
               root->data.id, root->data.username, root->data.email);
        printTree(root->right);
    }
}

Node* searchByID(Node* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root; // Fin de la recherche => Soit un élément est trouvé soit rien.
    }

    if (id < root->data.id) {
        return searchByID(root->left, id); // Chercher à gauche
    } else {
        return searchByID(root->right, id); // Chercher à droite
    }
}

