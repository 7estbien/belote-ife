#ifndef ANNONCESHEADER
#define ANNONCESHEADER

#include <stdio.h>
#include <stdlib.h>
#include "melange&distri.h"


void action(int *player,int *tour,int *pass,int *distrib,int *bet,int *stop);

void bid(int *bet);

void trump(int* t);

void amount(int *b,int bet);

void displayTrump(int trump);

void chooseTrump(CARD hand[],int *atrump);

void chooseAmount(int *bet,int maxi,int *player,int *tour,int *pass,int atrump,int *distrib,int *stop);

void calculOrdi(CARD hand[],int *maxi,int atrump);


#endif // ANNONCESHEADER
