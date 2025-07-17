#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 80
#define MAX_LINES 100  

// Structure pour représenter une ligne du fichier
typedef struct {
    char nom[MAX_NAME_LENGTH];
    char article[MAX_NAME_LENGTH];
    int nombre;
    int prix;
} Ligne;

int main() {
    // Tableau de structures pour stocker les données
    Ligne lignes[MAX_LINES];
    int nbLignes = 0;  // Compteur de lignes lues

    // Ouverture du fichier en mode lecture
    FILE *fp = fopen("donnees.txt", "r");
    if (fp == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return EXIT_FAILURE;
    }

    // Lecture des données depuis le fichier
    while (nbLignes < MAX_LINES && fscanf(fp, "%79s %79s %d %d",
                                         lignes[nbLignes].nom,
                                         lignes[nbLignes].article,
                                         &lignes[nbLignes].nombre,
                                         &lignes[nbLignes].prix) == 4) {
        nbLignes++;
    }

    // Fermeture du fichier
    fclose(fp);

    // Affichage du contenu du tableau de structures
    for (int i = 0; i < nbLignes; i++) {
        printf("Ligne %d:\n", i + 1);
        printf("Nom: %s\n", lignes[i].nom);
        printf("Article: %s\n", lignes[i].article);
        printf("Nombre: %d\n", lignes[i].nombre);
        printf("Prix: %d\n\n", lignes[i].prix);
    }

    return EXIT_SUCCESS;
}
