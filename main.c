// Link to teacher's repo : https://github.com/tfaycal/TNOF

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"

#define BLOCK_SIZE 10
#define MAX_GAMES 10

int main()
{

    bool programOn = true;
    int choice;

    printf("Welcome user, choose an action to perform :\n");

    while (programOn)
    {
        printf("\t1- Add a rental\n\t2- Display the list of rentals\n\t3- Search a rental\n\t4- Delete a rental\n\t5- Exit the program.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // adding rental
            break;
        case 2:
            // Display list
            break;
        case 3:
            // search
            printf("Enter the Rental ID to search: ");
            int searchID;
            scanf("%d", &searchID);
            break;
        case 4:
            // deleting rental
            printf("Enter the Rental ID to delete: ");
            int deleteID;
            scanf("%d", &deleteID);
            break;
        case 5:
            // exit
            programOn = false;
            system("clear");
            printf("Goodbye user!");
            break;

        default:
            system("clear");
            printf("Please choose a correct action : \n");
            break;
        }
    }
    return 0;
}