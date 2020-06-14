#include "melange_distri.h"



void init(CARD game[]){
    int val,col,i=0;
    for(col=0;col<4;col++)
    {
        for(val=0;val<8;val++)
        {
            game[i].valeur=val; //attribute a value to the cards
            game[i].color=col; //attribute a color to the card
            i++;
        }
    }
}


void displayCard(CARD card)
{
    char *ValCard[]={"seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"};
    char *ColCard[]={"hearts", "diamonds", "clubs", "spades"};


    printf(" %s of",ValCard[card.valeur]);
    printf(" %s ",ColCard[card.color]);

}



void mixAndDisrti(CARD game[],CARD N[],CARD S[],CARD E[],CARD W[],int* distrib)
{
    int i,r,temp=0;
	int tab[32];

	//create an array of 32 values

    for (i=0; i<32; i++){
            tab[i]=i;}

    //mix the array previously created

    for (i=0; i<32; i++) {
            r = i + rand() % (32-i);
            temp = tab[i];
            tab[i] = tab[r];
            tab[r] = temp;
            }
    //appoint the player that distribute

    *distrib=rand()%4;

if (*distrib==0){
    distribN(tab,game,N,S,E,W);
	} else {if(*distrib==1){
    		distribW(tab,game,N,S,E,W);
			} else {if (*distrib==2) {
        			distribS(tab,game,N,S,E,W);
					} else {distribE(tab,game,N,S,E,W);}
    }
}

}


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


void displayHand(CARD N[],CARD S[],CARD E[],CARD W[],int distrib)
{
    int i;

/**
            printf("SOUTH\n");
    for(i=0;i<8;i++){
    displayCard(S[i]);
    printf("\n");}

    printf("NORTH\n");
    for(i=0;i<8;i++){
    displayCard(N[i]);
    printf("\n");}

    printf("EAST\n");
    for(i=0;i<8;i++){

    displayCard(E[i]);
    printf("\n");}


            printf("WEST\n");
for(i=0;i<8;i++){
    displayCard(W[i]);
    printf("\n");}


**/
  //display the players

    printf("\t\t\t\t\tNORTH\n\n\n\n\n");

    printf("EAST");

    printf("\t\t\t\t\t\t\t\t\t\tWEST\n\n\n\n\n");

    printf("\t\t\t\t\tSOUTH\n\n \t\t\t\tHere is your hand :\n\n\t\t\t\t");

    //display the cards of the player

    for(i=0;i<8;i++){
    displayCard(S[i]);
    printf("\n\t\t\t\t");}

    //display the player that distributed cards

    if (distrib==0){
    printf("\nNORTH distribute\n\n");
    } else {if(distrib==1){
        printf("\nWEST distribute\n\n");} else {if (distrib==2) {
            printf("\nSOUTH distribute\n\n");} else {
                printf("\nEAST distribute\n\n");}
    }
}
}
