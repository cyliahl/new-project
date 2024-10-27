#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "games.h"
#include "customer.h"
#include "rund.h"

// Function prototypes
void afficher_menu();
void gerer_menu(int choice);

int main() {
    int choice;

    do {
        afficher_menu();
        printf("Choix : ");
        scanf("%d", &choice);
        gerer_menu(choice);
    } while (choice != 0);

    printf("Exiting the program.\n");
    return 0;
}

void afficher_menu() {
    printf("\n---- Menu ----\n");
    printf("1. Create a rental\n");
    printf("2. Display rentals\n");
    printf("3. Save rentals to file\n");
    printf("4. Load rentals from file\n");
    printf("0. Quit\n");
    printf("----------------\n");
}

void gerer_menu(int choice) {
    switch (choice) {
        case 1:
            createRental(); // Function to create rental
            break;
        case 2:
            displayRentals(); // Function to display rentals
            break;
        case 3:
            saveRentals(); // Function to save rentals to file
            break;
        case 4:
            loadRentals(); // Function to load rentals from file
            break;
        case 0:
            printf("Quitter.\n");
            break;
        default:
            printf("Choix non valide.\n");
            break;
    }
}