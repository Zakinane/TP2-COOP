#ifndef STRUCT_H
#define STRUCT_H

typedef struct customer{
    int customerID ;
    char fname[50];
    char lname[50];
    char coninfo[50];
} customer;

typedef struct customerblock{
    customer customertab[10];
    int nbrcustomers;
}customerblock;

typedef struct Game{
    int gameID;
    char gamename[100];
    float price ;
} game;

typedef struct Date{
    int day ;
    int month ;
    int year ;
} date;

typedef struct rentalram{  // this will call from the disk to get the IDs and save the correct information corresponding to the ID selected
    int rentalID;
    customer customer;
    game game;
    date rentdate;
    date returndate;
    float price;
}rentalram;

typedef struct rentaldisk{  //the information that i will save in the hard drive that consists of only IDs of customers and games and the rent and return dates
    int rentalID;
    int customerID;
    int gameID;
    date rentdate;
    date returndate;
    float price;
}rentaldisk;

typedef struct Block{
    int blockID;
    int numRecords;
    rentalram records[10];
    struct Block* next;
}block;

typedef struct metadata{  //information that is saved at the top of the file everytime it is changed
    int nbrblocks;
    int lastid;
    char path[200];
}mdata;

typedef struct Rentlistptr{
    block* head;
    block* tail;
} rentlistptr;

typedef struct TOF{ // we use this for openfile instead of a normal file so that we can add metadata to the top of the stored file
    char filename[200]; // we must use "r+" mode for this file so that the metadata wil be placed at the top of the file and then the rest of the info after it
    mdata mdata;
}TOF;

#endif