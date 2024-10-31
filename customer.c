#include "struct.h"
#include "customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

/*TOF* openfile(char* path,char mode, TOF* tof){ //this is my version of the code with a TOF pointer as a parameter
    switch(mode){
        case 'N':
            FILE *f=fopen(path,"w");
            strcpy(path,tof->filename);
            tof->metadata.nbrblocks=0;
            tof->metadata.lastid=0;
            writemetadata(tof->metadata,tof->filename);
            fclose(f);
            return tof;
        case 'A':
            FILE *f=fopen(path,"r+");
            readmetadata(tof);
            fclose(f);
            return tof;
        default:
            fprintf(stderr, "Invalid mode: %c\n", mode);
            return NULL;
    }
}*/

int openfile(char* path,char mode){
    TOF tof;
    switch(mode){
        case 'N':;
            FILE* f=fopen(path,"w");
            strcpy(tof.filename,path);
            tof.mdata.nbrblocks=0;
            tof.mdata.lastid=0;
            writemetadata(tof.mdata,&tof);
            fclose(f);
            break;
        case 'A':;
            FILE* g=fopen(path,"r+b");
            readmetadata(&tof);
            fclose(g);
            break;
        default:
            fprintf(stderr, "Invalid mode: %c\n", mode);
            return -1;
    }
    return -2;
}

void writemetadata(mdata metadata,TOF* tof){
    FILE *f=fopen(tof->filename,"r+");
    fwrite(&metadata,sizeof(mdata),1,f);
    fclose(f);
}

void readmetadata(TOF* tof){
    FILE *f=fopen(tof->filename,"r+");
    fread(& tof->mdata,sizeof(mdata),1,f);
    fclose(f);
}

void insertcustomer(TOF* tof,customer cust){
    block blockc;
    int read = readblock(tof,&blockc,tof->mdata.nbrblocks);
    if(read == -1 || blockc.numRecords == MAX_RECORDS ){  /*10 as the max number of records*/
        block newblockc;
        newblockc.records[0].customer= cust;
        newblockc.numRecords = 1;
        writeblock(tof,tof->mdata.nbrblocks,&newblockc);
        tof->mdata.nbrblocks++;
        writemetadata(tof->mdata,tof);
        
    }
    else{
        blockc.records[blockc.numRecords].customer = cust;
        blockc.numRecords++;
        writeblock(tof,tof->mdata.nbrblocks-1,&blockc);
        tof->mdata.nbrblocks++;
        writemetadata(tof->mdata,tof);
    }
}

int searchcustomer(TOF* tof,int customerID,customer* foundcustomer){
    block blockc;
    for (int i = 0; i < tof->mdata.nbrblocks; i++) {
        if (readblock(tof, &blockc, i) == -1) {
            return -1;
        }

        for (int j = 0; j < blockc.numRecords; j++) {
            
            if (blockc.records[j].customer.customerID == customerID) {
                *foundcustomer = blockc.records[j].customer;
                return 0;
            }
        }
    }
    return -1;
}

int writeblock(TOF* tof,int nbrblocks,block *blockc){
    
    FILE* f = fopen(tof->filename, "r+b");

    fseek(f, nbrblocks * sizeof(block), SEEK_SET);
    int found = fwrite(blockc, sizeof(block), 1, f);
    fclose(f);

    if(found == 1){
        return 0;
    }else{
        return -1;
    }
}


int readblock(TOF* tof,block* blockc,int nbrblocks){

    FILE* f = fopen(tof->filename, "rb");

    fseek(f,nbrblocks * sizeof(block), SEEK_SET);
    int found = fread(blockc, sizeof(block), 1, f);
    fclose(f);

    if(found == 1){
        return 0;
    }else{
        return -1;
    }
}

void printcustomer(customer cust){
    char str[200];
    sprintf(str, "Customer Information:\nCustomer ID: %d\nFirst Name: %s\nLast Name: %s\nContact Info: %s\n",cust.customerID,cust.fname,cust.lname,cust.coninfo);
    printf("\n\n%s",str);
}