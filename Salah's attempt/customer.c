#include "struct.h"
#include "customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int openfile(char* filename,char mode){
    TOF tof;
    strcpy(tof.filename,filename);
    switch(mode){
        case 'N':;
            FILE* f=fopen(filename,"w");
            tof.mdata.nbrblocks=0;
            tof.mdata.lastid=0;
            writemetadata(tof.mdata,&tof);
            fclose(f);
            break;
        case 'A':;
            FILE* g=fopen(filename,"r+b");
            readmetadata(&tof);
            fclose(g);
            break;
        default:
            fprintf(stderr, "Invalid mode: %c\n", mode);
            return -1;
    }
    return 0;
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
    customerblock blockc;
    int read = readcustomerblock(tof,&blockc,tof->mdata.nbrblocks-1);
    if(read == -1 || blockc.nbrcustomers == 10 ){  /*i chose 10 as the max number of records*/
        customerblock newblockc;
        newblockc.customertab[0]= cust;
        newblockc.nbrcustomers = 1;
        writecustomerblock(tof,tof->mdata.nbrblocks,&newblockc);
        tof->mdata.nbrblocks++;
    }
    else{
        blockc.customertab[blockc.nbrcustomers] = cust;
        blockc.nbrcustomers++;
        writecustomerblock(tof,tof->mdata.nbrblocks-1,&blockc);
    }
    
}

int searchcustomer(TOF* tof,int customerID,customer* foundcustomer){
    customerblock blockc;
    for (int i = 0; i < tof->mdata.nbrblocks; i++) {
        if (readcustomerblock(tof, &blockc, i) == -1) {
            return -1;
        }

        for (int j = 0; j < blockc.nbrcustomers; j++) {
            
            if (blockc.customertab[j].customerID == customerID) {
                *foundcustomer = blockc.customertab[j];
                return 0;
            }
        }
    }
    return -1;
}

int writecustomerblock(TOF* tof,int nbrcustomers,customerblock *blockc){
    
    FILE* f = fopen(tof->filename, "r+b");

    fseek(f, nbrcustomers * sizeof(customerblock), SEEK_SET);
    size_t found = fwrite(blockc, sizeof(customerblock), 1, f);
    fclose(f);

    if(found == 1){
        return 0;
    }else{
        return -1;
    }
}


int readcustomerblock(TOF* tof,customerblock* blockc,int nbrcustomers){

    FILE* f = fopen(tof->filename, "r+b");

    fseek(f,nbrcustomers * sizeof(customerblock), SEEK_SET);
    size_t found = fread(blockc, sizeof(customerblock), 1, f);
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
    printf("%s\n\n",str);
}