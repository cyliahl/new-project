#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void createGame(Game *game) {
    printf("Enter game title: ");
    scanf("%s", game->title);
    printf("Enter rental price: ");
    scanf("%f", &game->rentalPrice);
}

void displayGame(Game game) {
    printf("Title: %s, Rental Price: %.2f\n", game.title, game.rentalPrice);
}