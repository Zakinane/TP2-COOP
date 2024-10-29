#### UMBB, Faculty of Sciences Computer Engineering, 2nd Year, 3rd Semester Department of Computer Science Subject : SFSD

## Lab Work No. 2 File organisation

### Context

To manage the rental system of a video game store, you are tasked with creating a program. The rental information for each game is stored in files as data blocks. Each block can contain multiple rental records, and each rental may vary in length depending on the number of games rented by a customer. Efficient processing of this data is crucial for providing a smooth customer experience.

### Objective

Write a program in C language to extract and display rental information from data block files. Additionally, add functions to save this information to a file and load it from a file.

A rental record should include fields for the customers name, the game title(s), rental date, return date, and rental price. A customer is represented by their ID, first name, last name, and contact details.

```typedef
typedef struct Customer{
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
float rentalrice;
} Game;

typedef struct Rental
{
int rentalID;
Customer c;
Game game;
Date rentalDate;
Date returnDate;
} Rental;
```

The rental management system uses a TOF approach for storing the records in blocks, which are organized for efficient data retrieval.

### Rental Management and Disk Storage

When managing a large number of game rentals, it is essential to store this information efficiently on disk. Using a block-based data storage approach helps optimize data reading and writing. Instead of storing each rental separately on disk, we group them into blocks. Each block can contain multiple rentals, and these blocks are organized to facilitate data search and management.

When searching for a specific rental, we avoid scanning the entire disk. Instead, a logical search is performed on the information loaded from the disk, improving performance by reducing the number of read/write operations.

In your application, rentals and customers are organized using ordered linked lists (OLL). Each block contains a set of rental records or customer information, and these blocks are linked to form a logical structure for storing the data.

### Suggested Steps

1. Define the necessary data structures to represent a customer, a game, and a rental block.
2. Create a function createCustomer that allows input of customer information and returns a structure representing this information.
3. Create a function createRental that allows input of rental information, including game titles, rental and return dates, and calculates the total rental price.
4. Propose a function searchRental that searches for a rental based on its ID.
5. Display the information of each rental, including the customers name, game titles, rental date, return date, and total price.
6. Add a function saveRental
7. Add a function loadRental to save rental information to a file.to load rental information from a file.
8. Test your program by saving rental data to a file, then reloading it to ensure the data is correctly retrieved.
