#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "customer.h"

void initializeTOF(TOF* tof, const char* filename) {
    strcpy(tof->filename, filename);
    tof->mdata.nbrblocks = 0;
    tof->mdata.lastid = 0;
}

int main() {
    TOF tof;
    customer cust,foundcustomer;
    
    initializeTOF(&tof, "customers.txt");


    openfile(tof.filename, 'N');

    for (int i = 0; i < 3; i++) {
        cust.customerID = i+1;
        sprintf(cust.fname, "Customer%d:fname%d", i + 1,i+1);
        sprintf(cust.lname, "Customer%d:lname", i + 1);
        sprintf(cust.coninfo, "customer%d@example.com", i + 1);
        insertcustomer(&tof, cust);
    }

    for (int i = 1; i <= 3; i++) {
        if (searchcustomer(&tof, i, &foundcustomer) == 0) {
            printcustomer(foundcustomer);
        } else if (searchcustomer(&tof, i, &foundcustomer) == -1){
            printf("Customer with ID %d not found.\n", i);
        }
    }

    if (openfile(tof.filename, 'A') == -1) {
        fprintf(stderr, "Error opening file in Append mode.\n");
    }

    cust.customerID = 4;
    strcpy(cust.fname, "Customer4fname");
    strcpy(cust.lname, "Customer4lname");
    strcpy(cust.coninfo, "customer4@example.com");
    insertcustomer(&tof,cust);

    if (searchcustomer(&tof, 4, &foundcustomer) == 0) {
        printcustomer(foundcustomer);
    } else {
        printf("Customer with ID 4 not found.\n");
    }
    return 0;
}