#include "struct.h"

int openfile(char* filename,char mode);
void writemetadata(mdata mdata,TOF* tof);
void readmetadata(TOF* tof);
void insertcustomer(TOF* tof,customer customer);
int searchcustomer(TOF* tof,int customerID,customer* customer);
int readcustomerblock(TOF* tof,customerblock* blockc,int nbrblocks);
int writecustomerblock(TOF* tof,int nbrblocks,customerblock* blockc);
void printcustomer(customer customer);