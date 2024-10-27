#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "customer.h"
#include "games.h"
#define MAX_RENTALS 100

Rental rentals[MAX_RENTALS]; // Array to store rentals
int rentalCount = 0; // Count of rentals

void createRental() {
    if (rentalCount >= MAX_RENTALS) {
        printf("Rental limit reached!\n");
        return;
    }

    Rental rental;
    createCustomer(&rental.customer);

    printf("Enter rental date (DD MM YYYY): ");
    scanf("%d %d %d", &rental.rentalDate.day, &rental.rentalDate.month, &rental.rentalDate.year);

    printf("Enter return date (DD MM YYYY): ");
    scanf("%d %d %d", &rental.returnDate.day, &rental.returnDate.month, &rental.returnDate.year);

    printf("Enter number of games rented: ");
    scanf("%d", &rental.numberOfGames);

    for (int i = 0; i < rental.numberOfGames; i++) {
        createGame(&rental.games[i]);
    }

    rentals[rentalCount++] = rental; // Add rental to array
    printf("Rental created successfully!\n");
}

void displayRentals() {
    for (int i = 0; i < rentalCount; i++) {
        printf("Rental ID: %d\n", rentals[i].rentalID);
        displayCustomer(rentals[i].customer);
        printf("Rental Date: %02d/%02d/%04d\n", rentals[i].rentalDate.day, rentals[i].rentalDate.month, rentals[i].rentalDate.year);
        printf("Return Date: %02d/%02d/%04d\n", rentals[i].returnDate.day, rentals[i].returnDate.month, rentals[i].returnDate.year);
        printf("Games rented:\n");
        for (int j = 0; j < rentals[i].numberOfGames; j++) {
            displayGame(rentals[i].games[j]);
        }
        printf("\n");
    }
}

void saveRentals() {
    FILE *file = fopen("rentals.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }
    fwrite(rentals, sizeof(Rental), rentalCount, file);
    fclose(file);
    printf("Rentals saved successfully!\n");
}

void loadRentals() {
    FILE *file = fopen("rentals.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for loading!\n");
        return;
    }
    rentalCount = fread(rentals, sizeof(Rental), MAX_RENTALS, file);
    fclose(file);
    printf("Rentals loaded successfully!\n");
}