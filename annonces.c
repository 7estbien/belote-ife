#include "annonces.h"

/**
* asks the user what he wants to do and gets an answer
**/

void action() {

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
        printf("You pass\n");
    } else { if(act==2){
        bid();
        } else { if(act==3){
            printf("You announce capot");
            } else { if(act==4){
                printf("You announce general");
                } else { if(act==5){
                    printf("You announce coinche");
                    } else { printf("You have to input a number between 1 and 5\n");}}}}}

} while ((act<1) || (act>5));

}

/**
* allow the user to bid
**/

void amount(int* b) {

   do { printf("You can bid between 80 and 180\nHow much do you want to bid ? ");
    scanf("%d",&*b);

} while ((*b<80) || (*b>180) || (*b%10!=0);

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

    amount(&b);
    trump(&t);

    printf("You announce %d ",b);

     if(t==1){
        printf("club\n");
    } else { if(t==2){
        printf("spade\n");
        } else { if(t==3){
            printf("heart\n");
            } else { if(t==4){
                printf("diamond\n");}}}}

     *bet=b;

}


void calculOrdi(CARD player[]) {

    int i;
    int ind_card=0;

    for(i=0;i<8;i++) {
        if(player[i].valeur>1 || player[i].valeur<5 || player[i].valeur==10) {
            } else {ind_card=ind_card+1;}
    }
if

}
