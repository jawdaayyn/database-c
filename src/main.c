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

void read_input(char* inputResult) {
    // Read the whole line of input
    if (fgets(inputResult, 256, stdin) == NULL) {
        printf("Error reading input\n");
        return;
    }

    // Tokenize to extract the first word
    char* token = strtok(inputResult, " ");
    if (token == NULL) {
        printf("No input detected\n");
        return;
    }

    // Convert the token to uppercase
    for (int i = 0; token[i]; i++) {
        token[i] = toupper((unsigned char)token[i]);
    }

    // Determine the command by setting an integer code
    int commandCode = -1;
    if (strcmp(token, "SELECT") == 0) {
        commandCode = 1;
    } else if (strcmp(token, "INSERT") == 0) {
        commandCode = 2;
    } else if (strcmp(token, "DELETE") == 0) {
        commandCode = 3;
    }

    // Use a switch statement on the integer code
    switch (commandCode) {
        case 1:
            printf("Selecting row(s)\n");
            break;
        case 2:
            printf("Inserting row command\n");
            break;
         case 3:
            printf("Deleting row command\n");
            break;
        default:
            printf("Unrecognized command, try again. Please know that available commands are INSERT, SELECT, DELETE.\n");
            break;
    }
}



void main(int argc, char* argv[], char* envp[]){
  char inputResult[30];

  while (true) {  
   show_interface();
   read_input(inputResult);
  }
  
}