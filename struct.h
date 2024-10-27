#ifndef HEADER_STRUCT
#define HEADER_STRUCT

#define MAX_REC 100

typedef struct {
    int customerID;
    char firstName[50];
    char lastName[50];
    char contactInfo[100];
} Customer;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char title[100];
    float rentalPrice;
} Game;

typedef struct {
    int rentalID;
    Customer customer;
    Game games[MAX_REC];
    Date rentalDate;
    Date returnDate;
    int numberOfGames; // Number of games rented
} Rental;

#endif // HEADER_STRUCT