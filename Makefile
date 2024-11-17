# Compilateur et flags
CC = gcc
CFLAGS = -Wall -g

# Dossiers
SRC_DIR = src
OBJ_DIR = obj

# Fichiers sources (où il y a le code)
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/btree.c

# Fichiers temporaires objet
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/btree.o

# Fichier éxécutable
EXEC = mysql

# Destinations
all: $(EXEC)

# Lier les fichiers pour créer l'éxecutable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Compiler main.c en main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)  # Create the obj directory if it doesn't exist
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

# Compiler btree.c en btree.o
$(OBJ_DIR)/btree.o: $(SRC_DIR)/btree.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/btree.c -o $(OBJ_DIR)/btree.o

# Nettoyer les fichiers générés
clean:
	rm -rf $(OBJ_DIR) $(EXEC)
