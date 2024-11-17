#include <stdio.h>
#include <stdlib.h>
#include "btree.c"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Fonction pour afficher le mysql au début
void show_interface() {
  printf("mysql>");
  return;
}

// Fonction pour rechercher un utilisateur
void select_user(Node* root, char* query) {
    // Si la query est "*", on retourne l'arbre entier.
    if (strcmp(query, "*") == 0) {
        if (root == NULL) {
            printf("Aucun utilisateur trouvé.\n");
        } else {
            print_tree(root);
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
        Node* result = search_by_id(root, id);
        if (result != NULL) {
           printf("Utilisateur trouvé ID: %d, Nom d'utilisateur: %s, Email: %s\n", result->data.id, result->data.username, result->data.email);
        } else {
            printf("Aucun utilisateur trouvé correspondant à l'ID %d.\n", id);
        }

    return;
}

// Fonction pour créer un utilisateur
void insert_user(Node** root, char* username, char* email) {
    User user;

    // ici on copie les username et email dans l'username et email du nouvel utilisateur
    strcpy(user.username, username);
    strcpy(user.email, email);

    // Insérer le nouvel utilisateur dans la DB
    insert_node(root, user);

    // on affiche le nouvel utilisateur créé
    printf("Nouvel utilisateur ajouté à la base de données : { nom d'utilisateur : \"%s\", e-mail: \"%s\" }\n", user.username, user.email);
    return;
}


// Fonction pour supprimer un utilisateur
void delete_user(Node** root, char *query) {
    // Si la query est "*", on supprime l'arbre entier.
    if (strcmp(query, "*") == 0) {
        delete_tree(*root);
        *root = NULL;        // On réinitialise la variable de l'arbre
        printf("Tous les utilisateurs ont bien été supprimés.\n");
        return;
    }


    // Sinon on supprime l'utilisateur correspondant à l'ID
    char* endptr;
    int id = strtol(query, &endptr, 10);

    if (*endptr != '\0' && *endptr != '\n') {
        // Si l'id n'est pas de type nombre on retourne une erreur
        printf("Les seules recherches possibles sont soit tous les utilisateurs ('*'), soit par ID (nombre).\n");
        return;
    }

    *root = delete_node(*root, id);  // Pass root as a pointer to pointer
    printf("L'utilisateur correspondant à l'ID %d a bien été supprimé. \n", id);
}



void read_input(char* inputResult, Node** root) { 
    if (fgets(inputResult, 256, stdin) == NULL) {
        printf("Erreur lors de la lecture de l'input.\n");
        return;
    }

    char* token = strtok(inputResult, " ");
    if (token == NULL) {
        printf("Aucune commande donnée.\n");
        return;
    }

    for (int i = 0; token[i]; i++) {
        token[i] = toupper((unsigned char)token[i]);
    }

    int commandCode = -1;
    if (strcmp(token, "SELECT") == 0) {
        commandCode = 1;
    } else if (strcmp(token, "INSERT") == 0) {
        commandCode = 2;
    } else if (strcmp(token, "DELETE") == 0) {
        commandCode = 3;
    }

    switch (commandCode) {
        case 1: {
            char* query = strtok(NULL, "\n");
            if (query != NULL) {
                select_user(*root, query);  
            } else {
                printf("Vous n'avez spécifié aucun ID après votre SELECT, exemple : 'SELECT 3' ou 'SELECT *.\n");
            }
            break;
        }
        case 2: {
            char* username = strtok(NULL, " ");
            char* email = strtok(NULL, "\n");
            if (username != NULL && email != NULL) {
                insert_user(root, username, email);  
            } else {
                printf("Format incorrect. Exemple : 'INSERT test test@gmail.com'\n");
            }
            break;
        }
        case 3:
            char* query = strtok(NULL, "\n");
            if (query != NULL) {
                delete_user(root, query);  
            } else {
                printf("Vous n'avez spécifié aucun ID après votre SELECT, exemple : 'SELECT 3' ou 'SELECT *.\n");
            }
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

    while (true) {  
    show_interface();
    read_input(inputResult, &root);
    }
  
}