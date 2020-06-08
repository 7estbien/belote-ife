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
* Create the 32 cards of the game
* @param game - an array containing the 32 cards of the game
**/

void init(CARD game[]);

/**
* display one card
* @param card - a structure containing integers representing the valor and the color of a card
**/

void displayCard(CARD card);

/**
* Mix and distribute cards to the players
* @param game - an array containing all the cards of the game
* @param N - the array containing the cards of the player NORTH
* @param S - the array containing the cards of the player SOUTH
* @param E - the array containing the cards of the player EAST
* @param W - the array containing the cards of the player WEST
* @param distrib - an integer indicating the player that distribute
**/

void mixAndDisrti(CARD game[],CARD N[],CARD S[],CARD E[],CARD W[],int* ditrib);

/**
* distribution of cards by NORTH
* @param tabl - an array used to mix cards
* @param game - an array containing all the cards of the game
* @param N - the array containing the cards of the player NORTH
* @param S - the array containing the cards of the player SOUTH
* @param E - the array containing the cards of the player EAST
* @param W - the array containing the cards of the player WEST
**/

void distribN(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

/**
* distribution of cards by EAST
* @param tabl - an array used to mix cards
* @param game - an array containing all the cards of the game
* @param N - the array containing the cards of the player NORTH
* @param S - the array containing the cards of the player SOUTH
* @param E - the array containing the cards of the player EAST
* @param W - the array containing the cards of the player WEST
**/

void distribE(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

/**
* distribution of cards by SOUTH
* @param tabl - an array used to mix cards
* @param game - an array containing all the cards of the game
* @param N - the array containing the cards of the player NORTH
* @param S - the array containing the cards of the player SOUTH
* @param E - the array containing the cards of the player EAST
* @param W - the array containing the cards of the player WEST
**/

void distribS(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

/**
* distribution of cards by WEST
* @param tabl - an array used to mix cards
* @param game - an array containing all the cards of the game
* @param N - the array containing the cards of the player NORTH
* @param S - the array containing the cards of the player SOUTH
* @param E - the array containing the cards of the player EAST
* @param W - the array containing the cards of the player WEST
**/

void distribW(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

/**
* display the hand of the player
* @param N - the array containing the cards of the player NORTH
* @param S - the array containing the cards of the player SOUTH
* @param E - the array containing the cards of the player EAST
* @param W - the array containing the cards of the player WEST
* @param distrib - an integer indicating the player that distribute
**/

void displayHand(CARD N[],CARD S[],CARD E[],CARD W[],int distrib);

#endif // MELANGEHEADER
