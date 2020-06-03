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

void displayHand(CARD N[],CARD S[],CARD E[],CARD W[],int distrib);

/**
* mix Cards and distribute cards to the players
**/

void mixAndDisrti(CARD game[],CARD N[],CARD S[],CARD E[],CARD W[],int* ditrib);

/**
* distribution by NORTH
**/

void distribN(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

/**
* distribution by EAST
**/

void distribE(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

/**
* distribution by SOUTH
**/

void distribS(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

/**
* distribution by WEST
**/

void distribW(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

#endif // MELANGEHEADER
