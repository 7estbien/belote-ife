#ifndef MELANGEHEADER
#define MELANGEHEADER

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int valeur;
    int color;
}CARD;

void action();

void bid();

void trump(int* t);

void amount(int *b);




#endif // MELANGEHEADER
