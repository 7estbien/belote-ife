#include "melange.h"



/**
* Initialize the cards
**/

void init(CARD game[]){
    int val,col,i=0;
    for(col=0;col<4;col++)
    {
        for(val=0;val<8;val++)
        {
            game[i].valeur=val;
            game[i].color=col;
            i++;
        }
    }
}

/**
* display one card
**/

void displayCard(CARD card)
{
char *ValCard[]={"seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"};
char *ColCard[]={"hearts", "diamonds", "clubs", "spades"};


printf(" %s of",ValCard[card.valeur]);
printf(" %s ",ColCard[card.color]);

}

/**
* mix Cards and distribute cards to the players
**/


void mixAndDisrti(CARD game[],CARD N[],CARD S[],CARD E[],CARD W[])
{
    int i,r,temp=0;
	int tab[32];

    for (i=0; i<32; i++){
            tab[i]=i;
            }
    for (i=0; i<32; i++) {
            r = i + rand() % (32-i);
            temp = tab[i];
            tab[i] = tab[r];
            tab[r] = temp;
            }

    int k=0;

    for(i=0;i<8;i++){
        N[i]=game[tab[k]];
        E[i]=game[tab[k+1]];
        S[i]=game[tab[k+2]];
        W[i]=game[tab[k+3]];
        k=k+4;
    }

}


/**
* display the hand of the player
**/

void displayHand(CARD N[],CARD S[],CARD E[],CARD W[])
{
    int i;

    printf("\t\t\t\t\tNORTH\n\n\n\n\n");

    printf("EAST");

    printf("\t\t\t\t\t\t\t\t\t\tWEST\n\n\n\n\n");

    printf("\t\t\t\t\tSOUTH\n\n \t\t\t\tHere is your hand :\n\n\t\t\t\t");

    for(i=0;i<8;i++){
    displayCard(S[i]);
    printf("\n\t\t\t\t");}
}
