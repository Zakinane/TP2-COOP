#include "struct.h"

int openfile(char* filename,char mode);
void writemetadata(mdata mdata,TOF* tof);
void readmetadata(TOF* tof);
void insertcustomer(TOF* tof,customer customer);
int searchcustomer(TOF* tof,int customerID,customer* customer);
int readblock(TOF* tof,block* blockc,int nbrblocks);
int writeblock(TOF* tof,int nbrblocks,block* blockc);
void printcustomer(customer customer);