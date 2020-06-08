#ifndef ENCHERESHEADER
#define ENCHERESHEADER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "melange_distri.h"

/**
* asks the user what he wants to do and gets his answer
* @param player - the number of player that played in this tour, modified by this function
* @param tour - the number of tours, modified by this function
* @param pass - the number of players in a row that have indicated they want to pass, modified by this function
* @param distrib - the number of the player, modified by this function
* @param bet - the amount the player wants to bet, modified by this function
* @param stop - an indicator, modified by this function
* @param lastbet - the last bet of the player, modified by this function
* @param trumpS - the trump chosen by the player, modified by this function
**/

void action(int *player,int *tour,int *pass,int *distrib,int *bet,int *stop,int *lastbet,int *trumpS);

/**
* Get and check the input of the player
* @param number - the input of the user, modified by this function
**/

void GetAndCheck(int *number);

/**
* allow the player to enter the amount of his bet
* @param b - the amount the player wants to bet, modified by this function
* @param bet - the maximum bet announced by other players, modified by this function
**/

void amount(int *b,int bet);

/**
* allow the player to choose the trump
* @param t - the input of the player, modified by this function
**/

void trump(int* t);

/**
* Sum up the information inputed by the player and print the announce of the player
* @param bet - the maximum bet announced by other players, modified by this function
* @param trumpS - the trump chosen by the player, modified by the function
**/


void bid(int *bet,int *trumpS);

/**
* automatically choose the trump for the AI
* @param hand[] - a structure containing the cards of the AI
* @param atrump - the trump chosen by the function, modified by the function
**/

void chooseTrump(CARD hand[],int *atrump);

/**
* display the trump
* @param trump - the trump to display
**/

void displayTrump(int trump);

/**
* Compute the maximum of points that the AI can win
* @param hand - a structure containing the cards of the AI
* @param maxi - the maximum of points that the AI can win, modified by the function
* @param atrump - the trump chosen by the AI
**/

void calculOrdi(CARD hand[],int *maxi,int atrump);

/**
* allow the IA to choose the amount to bet
* @param bet - the maximum bet announced by other players, modified by this function
* @param maxi - the maximum of points that the AI can win
* @param player - the number of player that played in this tour, modified by this function
* @param tour - the number of tours, modified by this function
* @param pass - the number of players in a row that have indicated they want to pass, modified by this function
* @param atrump - the trump chosen by the AI
* @param distrib - the number of the player, modified by this function
* @param stop - an indicator, modified by this function
* @param lastbet - the last bet of the player, modified by this function
**/

void chooseAmount(int *bet,int maxi,int *player,int *tour,int *pass,int atrump,int *distrib,int *stop,int *lastbet);

/**
* Compare the last announcements of every player and announce the winning contract and the trump of the round
* @param trump - the trump of the round, modified by the function
* @param lastN - the last announce of NORTH
* @param lastS - the last announce of SOUTH (the player)
* @param lastE - the last announce of EAST
* @param lastW - the last announce of WEST
* @param trumpE - the trump announced by EAST
* @param trumpN - the trump announced by NORTH
* @param trumpS - the trump announced by SOUTH (the player)
* @param trumpW - the trump announced by WEST
* @param contractNS - the number of points the team NORTH SOUTH have to win, modified by the function
* @param contractEW - the number of points the team EAST WEST have to win, modified by the function
**/

void winningContract(int *trump,int lastN,int lastS,int lastE,int lastW,int trumpE,int trumpN,int trumpS,int trumpW,int *contractNS,int *contractEW);


#endif // ENCHERESHEADER
