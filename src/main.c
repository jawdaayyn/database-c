#include <stdio.h>
#include <stdlib.h>
#include "btree.c"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void show_interface() {
  printf("mysql>");
  return;
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>


void select_user(Node* root, char* query) {
  
    // Si la query est "*", on retourne l'arbre entier.
    if (strcmp(query, "*") == 0) {
        if (root == NULL) {
            printf("Aucun utilisateur trouvé.\n");
        } else {
            printTree(root);
        }
        return;
    } 
        // Sinon on retourne l'utilisateur trouvé par ID
        char* endptr;
        int id = strtol(query, &endptr, 10);

        if (*endptr != '\0' && *endptr != '\n') {
            // Si l'id n'est pas de type nombre on retourne une erreur
            printf("Les seules recherches possibles sont soit tous les utilisateurs ('*'), soit par ID (nombre).\n");
            return;
        }

        // On effectue la recherche par ID
        Node* result = searchByID(root, id);
        if (result != NULL) {
           printf("Utilisateur trouvé ID: %d, Nom d'utilisateur: %s, Email: %s\n", result->data.id, result->data.username, result->data.email);
        } else {
            printf("Aucun utilisateur trouvé correspondant à l'ID %d.\n", id);
        }
}



void read_input(char* inputResult, Node* root) {
    // On lit l'input
    if (fgets(inputResult, 256, stdin) == NULL) {
        printf("Erreur lors de la lecture de l'input.\n");
        return;
    }

    // On assigne le premier mot de l'input dans une variable
    char* token = strtok(inputResult, " ");
    if (token == NULL) {
        printf("Aucune commande donnée.\n");
        return;
    }

    // On le met en majuscule pour formatter la commande 
    for (int i = 0; token[i]; i++) {
        token[i] = toupper((unsigned char)token[i]);
    }



    // On va assigner la commande à utiliser grâce au token
    int commandCode = -1;
    if (strcmp(token, "SELECT") == 0) {
        commandCode = 1;
    } else if (strcmp(token, "INSERT") == 0) {
        commandCode = 2;
    } else if (strcmp(token, "DELETE") == 0) {
        commandCode = 3;
    }

    // On utilise un switch case pour vérifier efficacement la méthode à utiliser pour la requête SQL
    switch (commandCode) {
        case 1:
            char* query = strtok(NULL, "\n");
            if (query != NULL) {
                select_user(root, query);
            } else {
                printf("Vous n'avez spécifié aucun ID après votre SELECT, exemple : 'SELECT 3' ou 'SELECT *.\n");
            }
            break;

        case 2:
            printf("Inserting row command\n");
            break;
         case 3:
            printf("Deleting row command\n");
            break;
        default:
            printf("Commande inconnue, les seules commandes possibles sont : INSERT, SELECT, DELETE.\n");
            break;
    }
}



void main(int argc, char* argv[], char* envp[]){
    char inputResult[30];

    // noeud initial
    Node* root = NULL;

    User user1 = {"Jawdan", "jawdan@gmail.com"}; 
    User user2 = {"Test", "test@gmail.com"};    
    User user3 = {"Mike", "mike@gmail.com"}; 

    insert(&root, user1);
    insert(&root, user2);
    insert(&root, user3);


    while (true) {  
    show_interface();
    read_input(inputResult, root);
    }
  
}