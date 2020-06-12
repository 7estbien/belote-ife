#ifndef ANNONCESHEADER
#define ANNONCESHEADER

#include "encheres.h"

void squareTest(CARD hand[],int *pts,int *square);

/**
* Tests if the AI has a sequence of 5 cards
* @param hand - an array containing the cards of the AI
* @param pts - points corresponding to the cards that the AI have, modified by this function
**/

void sequence5Test(CARD hand[],int *pts);

/**
* Tests if the AI has a sequence of 4 cards
* @param hand - an array containing the cards of the AI
* @param pts - points corresponding to the cards that the AI have, modified by this function
**/

void sequence4Test(CARD hand[],int *pts);

/**
* Tests if the AI has a sequence of 3 cards
* @param hand - an array containing the cards of the AI
* @param pts - points corresponding to the cards that the AI have, modified by this function
**/

void sequence3Test(CARD hand[],int *pts);

/**
* Compares the results of the tests and display the announce of the AI
* @param hand - an array containing the cards of the AI
* @param square - an indicator, takes the value 1 if the AI has four cards with the same value, modified by this function
* @param pts - points corresponding to the cards that the AI have, modified by this function
* @param distrib - the number of the player, modified by this function
* @param player - the number of player that played in this tour, modified by this function
* @param stop - an indicator, modified by this function
**/

void announcementsAI(CARD hand[],int *square,int *pts,int *distrib,int *player,int *stop);

/**
* Ask the player what he wants to do and get his answer
* @param act - input of the user corresponding to the action he wants to do
**/

void GetPlayer(int *act);

/**
* check if the input of the player is conform with his cards
* @param hand - an array containing the cards of the AI
* @param stop - an indicator, modified by this function
* @param square - an indicator, takes the value 1 if the AI has four cards with the same value, modified by this function
* @param pts - points corresponding to the cards that the AI have, modified by this function
* @param act - input of the user corresponding to the action he wants to do
**/

void checkPlayer(CARD hand[],int *stop,int *square,int *pts,int act);

/**
* Display the announce of the player
* @param hand - an array containing the cards of the AI
* @param player - the number of player that played in this tour, modified by this function
* @param distrib - the number of the player, modified by this function
* @param stop - an indicator, modified by this function
* @param square - an indicator, takes the value 1 if the AI has four cards with the same value, modified by this function
* @param pts - points corresponding to the cards that the AI have, modified by this function
**/

void announceP(CARD hand[],int *player,int *distrib,int *stop,int *square,int *pts);

#endif // ANNONCESHEADER
