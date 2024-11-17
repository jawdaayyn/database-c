# Projet MYSQL C (TABLE UTILISATEURS)

## Aperçu

Ce projet est un simulateur simple d'interface en ligne de commande (CLI) pour gérer une liste d'utilisateurs. Le programme permet aux utilisateurs d'interagir avec une structure d'arbre pour effectuer des opérations de base telles que l'insertion, la sélection et la suppression d'utilisateurs, à l'aide de commandes similaires à SQL. La structure de données est un arbre binaire (BST), et le programme prend en charge les commandes suivantes :

- **SELECT** : Récupérer des utilisateurs en fonction de l'ID ou afficher tous les utilisateurs (`SELECT *`).
- **INSERT** : Ajouter un nouvel utilisateur avec un nom d'utilisateur et un email.
- **DELETE** : Supprimer un utilisateur par ID ou supprimer tous les utilisateurs (`DELETE *`).

## Commandes

### `SELECT [ID|*]`
- **`SELECT *`** : Affiche tous les utilisateurs du système.
- **`SELECT [ID]`** : Trouve et affiche l'utilisateur avec l'ID spécifié.

### `INSERT [username] [email]`
- Ajoute un nouvel utilisateur au système avec le `nom d'utilisateur` et l'`email` fournis.

### `DELETE [ID|*]`
- **`DELETE *`** : Supprime tous les utilisateurs du système.
- **`DELETE [ID]`** : Supprime l'utilisateur avec l'ID spécifié.



### Lancer le projet
Cela va créer le fichier à éxecuter pour lancer le programme :
```bash
make
```

Pour lancer le programme :
```bash
./mysql
```

Pour nettoyer les fichiers :
```bash
make clean
```

### Exemple d'utilisation

```bash
mysql> INSERT testuser testuser@example.com
- Nouvel utilisateur ajouté à la base de données : { nom d'utilisateur : "testuser", e-mail: "testuser@example.com" 

mysql> SELECT *
- Utilisateur trouvé ID: 1, Nom d'utilisateur: testuser, Email: testuser@example.com

mysql> DELETE 1
- L'utilisateur correspondant à l'ID 1 a bien été supprimé.
