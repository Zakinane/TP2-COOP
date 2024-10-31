// Link to teacher's repo : https://github.com/tfaycal/TNOF

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"
#include "customer.h"

#define BLOCK_SIZE 10
#define MAX_GAMES 10

void initializeTOF(TOF *tof, const char *filename)
{
    strcpy(tof->filename, filename);
    tof->mdata.nbrblocks = 0;
    tof->mdata.lastid = 0;
}

int main()
{
    TOF tof;
    customer cust, foundcustomer;

    initializeTOF(&tof, "customers.txt");

    bool programOn = true;
    int choice;

    printf("Welcome user, choose an action to perform :\n");

    while (programOn)
    {
        printf("\t0 - Salah's test \n\t1- Add a rental\n\t2- Display the list of rentals\n\t3- Search a rental\n\t4- Delete a rental\n\t5- Exit the program.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            openfile(tof.filename, 'N');

            for (int i = 0; i < 3; i++)
            {
                cust.customerID = i + 1;
                sprintf(cust.fname, "Customer%d:fname%d", i + 1, i + 1);
                sprintf(cust.lname, "Customer%d:lname", i + 1, i + 1);
                sprintf(cust.coninfo, "customer%d@example.com", i + 1);
                insertcustomer(&tof, cust);
            }

            for (int i = 1; i <= 3; i++)
            {
                if (searchcustomer(&tof, i, &foundcustomer) == 0)
                    printcustomer(foundcustomer);
                else if (searchcustomer(&tof, i, &foundcustomer) == -1)
                    printf("Customer with ID %d not found.\n", i);
            }

            if (openfile(tof.filename, 'A') == -1)
                fprintf(stderr, "Error opening file in Append mode.\n");

            cust.customerID = 4;
            strcpy(cust.fname, "Customer4fname");
            strcpy(cust.lname, "Customer4lname");
            strcpy(cust.coninfo, "customer4@example.com");
            insertcustomer(&tof, cust);

            if (searchcustomer(&tof, 4, &foundcustomer) == 0)
                printcustomer(foundcustomer);
            else
                printf("Customer with ID 4 not found.\n");
            break;
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