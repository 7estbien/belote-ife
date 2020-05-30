#include "melange&distri.h"



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


void mixAndDisrti(CARD game[],CARD N[],CARD S[],CARD E[],CARD W[],int* distrib)
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

    *distrib=rand()%4;

if (*distrib==0){
    distribN(tab,game,N,S,E,W);
	} else {if(*distrib==1){
    		distribE(tab,game,N,S,E,W);
			} else {if (*distrib==2) {
        			distribS(tab,game,N,S,E,W);
					} else {distribW(tab,game,N,S,E,W);}
    }
}


}

/**
* distribution by NORTH
**/

void distribN(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]){
int i,k=0;

    for(i=0;i<8;i++){
        E[i]=game[tabl[k]];
        S[i]=game[tabl[k+1]];
        W[i]=game[tabl[k+2]];
        N[i]=game[tabl[k+3]];
        k=k+4;
    }
}
/**
* distribution by EAST
**/

void distribE(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]){
int i,k=0;

    for(i=0;i<8;i++){
        S[i]=game[tabl[k]];
        W[i]=game[tabl[k+1]];
        N[i]=game[tabl[k+2]];
        E[i]=game[tabl[k+3]];
        k=k+4;
    }
}
/**
* distribution by SOUTH
**/

void distribS(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]){
int i,k=0;

    for(i=0;i<8;i++){
        W[i]=game[tabl[k]];
        N[i]=game[tabl[k+1]];
        E[i]=game[tabl[k+2]];
        S[i]=game[tabl[k+3]];
        k=k+4;
    }
}

/**
* distribution by WEST
**/

void distribW(int tabl[],CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]){
int i,k=0;

    for(i=0;i<8;i++){
        N[i]=game[tabl[k]];
        E[i]=game[tabl[k+1]];
        S[i]=game[tabl[k+2]];
        W[i]=game[tabl[k+3]];
        k=k+4;
    }
}


/**
* display the hand of the player
**/

void displayHand(CARD N[],CARD S[],CARD E[],CARD W[],int distrib)
{
    int i;

    printf("\t\t\t\t\tNORTH\n\n\n\n\n");

    printf("EAST");

    printf("\t\t\t\t\t\t\t\t\t\tWEST\n\n\n\n\n");

    printf("\t\t\t\t\tSOUTH\n\n \t\t\t\tHere is your hand :\n\n\t\t\t\t");

    for(i=0;i<8;i++){
    displayCard(S[i]);
    printf("\n\t\t\t\t");}


    printf("\n");

    if (distrib==0){
    printf("NORTH distribute");
    } else {if(distrib==1){
        printf("EAST distribute");} else {if (distrib==2) {
            printf("SOUTH distribute");} else {
                printf("WEST distribute");}
    }
}
    printf("\n");
}
