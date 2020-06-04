#include "annonces.h"

/**
* asks the user what he wants to do and gets an answer
**/

void action(int *player,int *tour,int *pass,int *distrib,int *bet,int *stop,int *lastbet,int *trumpS) {

    int act=0;

    printf("1: Pass\n");
    printf("2: Bid\n");
    printf("3: Capot\n");
    printf("4: General\n");
    printf("5: Coinche\n");


do {
    printf("What do you want to announce ?\n");
    scanf("%d",&act);

    if(act==1){
        printf("You pass\n\n");
            *pass=*pass+1;
            if(*tour!=0 && *pass==3){*stop=2;}

    } else { if(act==2){
        bid(&*bet,&*trumpS);
        *lastbet=*bet;
        *pass=0;
        } else { if(act==3){

            *pass=0;
            *bet=170;
            *lastbet=*bet;
            trump(&*trumpS);
            *trumpS=*trumpS-1;
            printf("You announce capot ");
            displayTrump(*trumpS);

            } else { if(act==4){

        	*pass=0;
            *bet=170;
            *lastbet=*bet;
            trump(&*trumpS);
            *trumpS=*trumpS-1;
            printf("You announce general ");
            displayTrump(*trumpS);

                } else { if(act==5){
                    printf("You announce coinche\n\n");
        	    *pass=0;
                    } else { printf("You have to input a number between 1 and 5\n");}}}}}

} while ((act<1) || (act>5));

*player=*player+1;

    if(*player==4) {
            *tour=*tour+1;
            *player=0;
            *distrib=*distrib-3;
} else {*distrib=*distrib+1;}

}

/**
* allow the user to bid
**/

void amount(int* b,int bet) {

   do { printf("You can bid between 80 and 160 and more than the others\nHow much do you want to bid ? ");
    scanf("%d",&*b);

} while ((*b<80) || (*b>160) || (*b%10!=0) || (*b<bet+10));

}

/**
* allow the user to choose the trump
**/

void trump(int* t) {

    do { printf("Which trump ? 1: Heart, 2: Diamond, 3: Club, 4: Spade : ");
    scanf("%d",&*t);
    printf("You have to choose a number between 1 and 4\n");

    }while((*t<1) || (*t>4));

}

void bid(int *bet,int *trumpS) {

    int t=0;
    int b=0;

    amount(&b,*bet);
    trump(&t);

    printf("You announce %d ",b);

     if(t==1){
        printf("heart\n");
	*trumpS=0;
    } else { if(t==2){
        printf("diamond\n");
	*trumpS=1;
        } else { if(t==3){
            printf("club\n");
		*trumpS=2;
            } else { if(t==4){
                printf("spade\n");
		*trumpS=3;}}}}

     *bet=b;

}

/**
* automatically choose the trump for the IA
**/

void chooseTrump(CARD hand[],int *atrump){

    int i,nbh=0,nbd=0,nbc=0,nbs=0;

    for(i=0;i<8;i++){if(hand[i].color==0) {nbh=nbh+1;
        }else{if(hand[i].color==1){nbd=nbd+1;
            }else{if(hand[i].color==2){nbc=nbc+1;
                }else{nbs=nbs+1;}}}}

    if(nbh>nbc && nbh>nbd && nbh>nbs){*atrump=0;}
    if(nbd>nbh && nbd>nbc && nbd>nbs){*atrump=1;}
    if(nbc>nbh && nbc>nbd && nbc>nbs){*atrump=2;}
    if(nbs>nbh && nbs>nbd && nbs>nbc){*atrump=3;}

}

/**
* display the trump
**/

void displayTrump(int trump) {

    if(trump==0) {printf("heart\n\n");
    }else{if(trump==1) {printf("diamond\n\n");
        }else{if(trump==2){printf("club\n\n");
            }else{if(trump==3){printf("spade\n\n");}}}}

}

/**
* Compute the maximum of point that the IA can win
**/

void calculOrdi(CARD hand[],int *maxi,int atrump) {

    int i,loose=0;

    for(i=0;i<8;i++) {
        if(hand[i].color!=atrump && (hand[i].valeur!=7 || hand[i].valeur!=3)) {
                loose=loose+1;} else {if(hand[i].color!=atrump && (hand[i].valeur<2 || hand[i].valeur==5)){
                    loose=loose+1;}}}
    *maxi=170-loose*15;
}

/**
* allow the IA to choose the amount of the bid
**/

void chooseAmount(int *bet,int maxi,int *player,int *tour,int *pass,int atrump,int *distrib,int *stop,int *lastbet) {

    if((*bet+10)>maxi) {
            printf("pass\n\n");
            *pass=*pass+1;
                   if(*tour==0 && *pass==4){
                    *stop=1;
                    printf("everyone has passed, cards are distributed again\n\n");
                    sleep(3);}

                     }
            else {*bet=*bet+10;
                    printf("%d ",*bet);
                    displayTrump(atrump);
		    *lastbet=*bet;
                    *pass=0;
                    }
    if(*tour!=0 && *pass==3){*stop=2;}

    *player=*player+1;

    if(*player==4) {
            *tour=*tour+1;
            *player=0;
            *distrib=*distrib-3;
} else {*distrib=*distrib+1;}

}


void winningContract(int *trump,int lastN,int lastS,int lastE,int lastW,int trumpE,int trumpN,int trumpS,int trumpW,int *contractNS,int *contractEW){

printf("contrats : SOUTH %d, NORTH %d, EAST %d, WEST %d\n\n",lastS,lastN,lastE,lastW);

    if(lastE>lastN && lastE>lastW && lastE>lastS){*trump=trumpE;
                                                    *contractEW=lastE;
                                                    *contractNS=0;
                                                    printf("team E/W must realize %d\n",*contractEW);
                                                    printf("Trump : ");
                                                    displayTrump(*trump);}

    if(lastN>lastE && lastN>lastW && lastN>lastS){*trump=trumpN;
                                                    *contractNS=lastN;
                                                    *contractEW=0;
                                                    printf("team N/S must realize %d\n",*contractNS);
                                                    printf("Trump : ");
                                                    displayTrump(*trump);}

    if(lastW>lastE && lastW>lastN && lastW>lastS){*trump=trumpW;
                                                    *contractEW=lastW;
                                                    *contractNS=0;
                                                    printf("team E/W must realize %d\n",*contractEW);
                                                    printf("Trump : ");
                                                    displayTrump(*trump);}

    if(lastS>lastE && lastS>lastW && lastS>lastN){*trump=trumpS;
                                                    *contractNS=lastS;
                                                    *contractEW=0;
                                                    printf("team N/S must realize %d\n",*contractNS);
                                                    printf("Trump : ");
                                                    displayTrump(*trump);}


}
