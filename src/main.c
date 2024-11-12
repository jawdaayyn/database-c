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


 void read_input(char* inputResult) {
    scanf("%s", inputResult);

    // Tokenize the input and make it uppercase
    char* token = strtok(inputResult, " - ");
    for (int i = 0; token[i]; i++) {
        token[i] = toupper(token[i]);
    }

    // Determine the command by setting an integer code
    int commandCode = -1;
    if (strcmp(token, "SELECT") == 0) {
        commandCode = 1;
    } else if (strcmp(token, "INSERT") == 0) {
        commandCode = 2;
    }

    // Use a switch statement on the integer code
    switch (commandCode) {
        case 1:
            printf("Selecting row(s)\n");
            break;
        case 2:
            printf("Inserting row command\n");
            break;
        default:
            exit(1);  
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