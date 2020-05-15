#ifndef MELANGEHEADER
#define MELANGEHEADER

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int valeur;
    int color;
}CARD;

/**
* Initialize cards
**/

void init(CARD game[]);

/**
*display cards
**/

void displayCard(CARD card);


/**
* display the hand of the player
**/

void displayHand(CARD N[],CARD S[],CARD E[],CARD W[]);

/**
* mix Cards and distribute cards to the players
**/

void mixAndDisrti(CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);



#endif // MELANGEHEADER
