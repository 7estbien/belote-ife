#ifndef ANNONCESHEADER
#define ANNONCESHEADER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "melange_distri.h"


void action(int *player,int *tour,int *pass,int *distrib,int *bet,int *stop,int *lastbet,int *trumpS);

void bid(int *bet,int *trumpS);

void trump(int* t);

void amount(int *b,int bet);

void displayTrump(int trump);

void chooseTrump(CARD hand[],int *atrump);

void chooseAmount(int *bet,int maxi,int *player,int *tour,int *pass,int atrump,int *distrib,int *stop,int *lastbet);

void calculOrdi(CARD hand[],int *maxi,int atrump);

void winningContract(int *trump,int lastN,int lastS,int lastE,int lastW,int trumpE,int trumpN,int trumpS,int trumpW,int *contractNS,int *contractEW);


#endif // ANNONCESHEADER
