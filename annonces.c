#include "annonces.h"

/**
* asks the user what he wants to do and gets an answer
**/

void action(int *player,int *tour,int *pass,int *distrib,int *bet,int *stop) {

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
        bid(&*bet);
        *pass=0;
        } else { if(act==3){
            printf("You announce capot\n\n");
            *pass=0;
            } else { if(act==4){
                printf("You announce general\n\n");
        	*pass=0;
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

   do { printf("You can bid between 80 and 180\nHow much do you want to bid ? ");
    scanf("%d",&*b);

} while ((*b<80) || (*b>180) || (*b%10!=0) || (*bet<bet+10));

}

/**
* allow the user to choose the trump
**/

void trump(int* t) {

    do { printf("Which trump ? 1: Club, 2: Spade, 3: Heart, 4: Diamond : ");
    scanf("%d",&*t);
    printf("You have to choose a number between 1 and 4\n");

    }while((*t<1) || (*t>4));

}

void bid(int *bet) {

    int t=0;
    int b=0;

    amount(&b,*bet);
    trump(&t);

    printf("You announce %d ",b);

     if(t==1){
        printf("heart\n");
    } else { if(t==2){
        printf("diamond\n");
        } else { if(t==3){
            printf("club\n");
            } else { if(t==4){
                printf("spade\n");}}}}

     *bet=b;

}

/**
* automatically choose the trump for the IA
**/

void chooseTrump(CARD hand[]){

    int i,nbh=0,nbd=0,nbc=0,nbs=0,atrump=0;

    for(i=0;i<8;i++){if(hand[i].color==0) {nbh=nbh+1;
        }else{if(hand[i].color==1){nbd=nbd+1;
            }else{if(hand[i].color==2){nbc=nbc+1;
                }else{nbs=nbs+1;}}}}

    if(nbh>nbc && nbh>nbd && nbh>nbs){atrump=0;}
    if(nbd>nbh && nbd>nbc && nbd>nbs){atrump=1;}
    if(nbc>nbh && nbc>nbd && nbc>nbs){atrump=2;}
    if(nbs>nbh && nbs>nbd && nbs>nbc){atrump=3;}

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

void chooseAmount(int *bet,int maxi,int *player,int *tour,int *pass,int atrump,int *distrib,int *stop) {

    if((*bet+10)>maxi) {
            printf("pass\n\n");
            *pass=*pass+1;
                   if(*tour==0 && *pass==4){
                    *stop=1;
                    printf("everyone has passed, cards are distributed again\n\n");}

                     }
            else {*bet=*bet+10;
                    printf("%d ",*bet);
                    displayTrump(atrump);
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


