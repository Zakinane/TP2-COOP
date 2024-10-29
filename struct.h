#ifndef STRUCT_H
#define STRUCT_H

#define BLOCK_SIZE 10
#define MAX_GAMES 10

typedef struct Customer
{
    int customerID;
    char firstName[50];
    char lastName[50];
    char contactInfo[100];
} Customer;

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

typedef struct Game
{
    char title[100];
    float rentalPrice;
} Game;

typedef struct Rental
{
    int rentalID;
    Customer c;
    Game games[MAX_GAMES];
    Date rentalDate;
    Date returnDate;
} Rental;

#endif