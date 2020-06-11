#include "encheres.h"

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
* @param coinche - an integer indicating if the player announced coinche
**/

void action(int *player,int *tour,int *pass,int *distrib,int *bet,int *stop,int *lastbet,int *trumpS,int *coinche) {

    int act=0;

    //display the different actions

    printf("1: Pass\n");
    printf("2: Bid\n");
    printf("3: Capot\n");
    printf("4: General\n");
    printf("5: Coinche\n");


do {
    printf("What do you want to announce ?\n");
    GetAndCheck(&act);

    if(act==1){
        printf("\nYou pass\n\n");
            *pass=*pass+1;
            if(*pass==3 && *bet!=70){*stop=2;}
            if(*tour==0 && *pass==4){ //if all the players pass during the first tour
                    *stop=1; //variable enabling to get back to the beginning of the program
                    printf("everyone has passed, cards are distributed again\n\n");
                    sleep(3);}

    } else { if(act==2){
        bid(&*bet,&*trumpS);
        *lastbet=*bet;
        *pass=0;
        } else { if(act==3){

            *pass=0;
            *bet=162;
            *lastbet=*bet;
            trump(&*trumpS);
            *trumpS=*trumpS-1;
            printf("\nYou announce capot ");
            displayTrump(*trumpS);

            } else { if(act==4){

        	*pass=0;
            *bet=162;
            *lastbet=*bet;
            trump(&*trumpS);
            *trumpS=*trumpS-1;
            printf("\nYou announce general ");
            displayTrump(*trumpS);

                } else { if(act==5){ if(*bet<80) {printf("You can't announce coinche if nobody announced a contract\n");
                                        act=6;}
                else {printf("\nYou announce coinche\n\n");
        	    *pass=0;
        	    *coinche=1;}
                    } else { printf("You have to input a number between 1 and 5\n");}}}}}

} while ((act<1) || (act>5)); //the loop continues until the player input an expected value

*player=*player+1; //indicates the number of players that have played during one tour

    //at the end of the tour when each player have announced something
    if(*player==4) {
            *tour=*tour+1;
            *player=0;
            *distrib=*distrib-3; //we go back to the player at the left of the distributor
} else {*distrib=*distrib+1;}

}

/**
* Get and check the input of the player
* @param number - the input of the user, modified by this function
**/

void GetAndCheck(int *number){

    char input[5];

    fgets(input,5,stdin);
    *number=atoi(input);

}

/**
* allow the player to enter the amount of his bet
* @param b - the amount the player wants to bet, modified by this function
* @param bet - the maximum bet announced by other players, modified by this function
**/

void amount(int* b,int bet) {

   do { printf("You can bid between 80 and 170 and more than the others\nHow much do you want to bid ? ");
        GetAndCheck(&*b);

} while ((*b<80) || (*b>170) || (*b%10!=0) || (*b<bet+10)); //the loop continues until the player input a correct value

}

/**
* allow the player to choose the trump
* @param t - the input of the player, modified by this function
**/

void trump(int* t) {

    do { printf("Which trump ? 1: Heart, 2: Diamond, 3: Club, 4: Spade : ");
    GetAndCheck(&*t);
    printf("You have to choose a number between 1 and 4\n");

    }while((*t<1) || (*t>4)); //the loop continues until the player input a correct value

}

/**
* Sum up the information inputed by the player and print the announce of the player
* @param bet - the maximum bet announced by other players, modified by this function
* @param trumpS - the trump chosen by the player, modified by the function
**/

void bid(int *bet,int *trumpS) {

    int t=0;
    int b=0;

    amount(&b,*bet);
    trump(&t);

    printf("You announce %d ",b);

    //attribute the number of the trump corresponding to the input of the user

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

     *bet=b; //the value of the last bet is updated

}

/**
* automatically choose the trump for the AI
* @param hand[] - a structure containing the cards of the AI
* @param atrump - the trump chosen by the function, modified by the function
**/

void chooseTrump(CARD hand[],int *atrump){

    int i,nbh=0,nbd=0,nbc=0,nbs=0;

    //count the number of cards of each color

    for(i=0;i<8;i++){if(hand[i].color==0) {nbh=nbh+1;
        }else{if(hand[i].color==1){nbd=nbd+1;
            }else{if(hand[i].color==2){nbc=nbc+1;
                }else{nbs=nbs+1;}}}}

    //compare the number of cards of each color

    if(nbh>nbc && nbh>nbd && nbh>nbs){*atrump=0;}
    if(nbd>nbh && nbd>nbc && nbd>nbs){*atrump=1;}
    if(nbc>nbh && nbc>nbd && nbc>nbs){*atrump=2;}
    if(nbs>nbh && nbs>nbd && nbs>nbc){*atrump=3;}

}

/**
* display the trump
* @param trump - the trump to display
**/

void displayTrump(int trump) {

    if(trump==0) {printf("heart\n\n");
    }else{if(trump==1) {printf("diamond\n\n");
        }else{if(trump==2){printf("club\n\n");
            }else{if(trump==3){printf("spade\n\n");}}}}

}

/**
* Compute the maximum of points that the AI can win
* @param hand - a structure containing the cards of the AI
* @param maxi - the maximum of points that the AI can win, modified by the function
* @param atrump - the trump chosen by the AI
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

void chooseAmount(int *bet,int maxi,int *player,int *tour,int *pass,int atrump,int *distrib,int *stop,int *lastbet) {

    if((*bet+10)>maxi) { //test if the AI can announce higher than the last player
            printf("pass\n\n");
            *pass=*pass+1;
                   if(*tour==0 && *pass==4){ //if all the players pass during the first tour
                    *stop=1; //variable enabling to get back to the beginning of the program
                    printf("everyone has passed, cards are distributed again\n\n");
                    sleep(3);}

                     }
            else {*bet=*bet+10;
                    printf("%d ",*bet);
                    displayTrump(atrump);
                    *lastbet=*bet;
                    *pass=0;
                    }
    if(*pass==3 && *bet!=70){*stop=2;}

    *player=*player+1;

//at the end of the tour when every player announced something

    if(*player==4) {
            *tour=*tour+1;
            *player=0;
            *distrib=*distrib-3; //we go back to the player at the left of the distributor
} else {*distrib=*distrib+1;} //next player

}

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

void winningContract(int *trump,int lastN,int lastS,int lastE,int lastW,int trumpE,int trumpN,int trumpS,int trumpW,int *contractNS,int *contractEW, int *distrib){

    if(lastE>lastN && lastE>lastW && lastE>lastS){*trump=trumpE;
                                                    *contractEW=lastE;
                                                    *contractNS=0;
                                                    printf("team E/W must realize %d\n",*contractEW);
                                                    printf("Trump : ");
                                                    displayTrump(*trump);
                                                    *distrib=3;}

    if(lastN>lastE && lastN>lastW && lastN>lastS){*trump=trumpN;
                                                    *contractNS=lastN;
                                                    *contractEW=0;
                                                    printf("team N/S must realize %d\n",*contractNS);
                                                    printf("Trump : ");
                                                    displayTrump(*trump);
                                                    *distrib=0;}

    if(lastW>lastE && lastW>lastN && lastW>lastS){*trump=trumpW;
                                                    *contractEW=lastW;
                                                    *contractNS=0;
                                                    printf("team E/W must realize %d\n",*contractEW);
                                                    printf("Trump : ");
                                                    displayTrump(*trump);
                                                    *distrib=1;}

    if(lastS>lastE && lastS>lastW && lastS>lastN){*trump=trumpS;
                                                    *contractNS=lastS;
                                                    *contractEW=0;
                                                    printf("team N/S must realize %d\n",*contractNS);
                                                    printf("Trump : ");
                                                    displayTrump(*trump);
                                                    *distrib=2;}


}



void squareTest(CARD hand[],int *pts,int *square){

    int i,k,nbr=0;
    int value=2;

    for(k=0;k<6;k++){

        for(i=0;i<8;i++){
            if(hand[i].valeur==value){nbr=nbr+1;}
        }

        if(nbr==4){ switch(value) {

                    case 2 :
                        *pts=150;
                        break;
                    case 3 :
                        *pts=100;
                        break;
                    case 4 :
                        *pts=200;
                        break;
                    case 5 :
                        *pts=100;
                        break;
                    case 6 :
                        *pts=100;
                        break;
                    case 7 :
                        *pts=100;
                        break;

                    default :
                        printf("Error");
        }
        *square=1;
    }
    nbr=0;
    value=value+1; //we go to the next value
}}


void sequence5Test(CARD hand[],int *pts){

    int k,col;

    for(col=0;col<4;col++){

        int ace=0,king=0,queen=0,jack=0,ten=0,nine=0,eight=0,seven=0;

            for(k=0;k<8;k++){

            if(hand[k].color==col && hand[k].valeur==7){ace=1;}

            if(hand[k].color==col && hand[k].valeur==6){king=1;}

            if(hand[k].color==col && hand[k].valeur==5){queen=1;}

            if(hand[k].color==col && hand[k].valeur==4){jack=1;}

            if(hand[k].color==col && hand[k].valeur==3){ten=1;}

            if(hand[k].color==col && hand[k].valeur==2){nine=1;}

            if(hand[k].color==col && hand[k].valeur==1){eight=1;}

            if(hand[k].color==col && hand[k].valeur==0){seven=1;}
            }



if(ace==1 && king==1 && queen==1 && jack==1 && ten==1){*pts=100;}
if(king==1 && queen==1 && jack==1 && ten==1 && nine==1){*pts=100;}
if(queen==1 && jack==1 && ten==1 && nine==1 && eight==1){*pts=100;}
if(jack==1 && ten==1 && nine==1 && eight==1 && seven==1){*pts=100;}

}}

void sequence4Test(CARD hand[],int *pts){
int k,col;

    for(col=0;col<4;col++){

        int ace=0,king=0,queen=0,jack=0,ten=0,nine=0,eight=0,seven=0;

            for(k=0;k<8;k++){

            if(hand[k].color==col && hand[k].valeur==7){ace=1;}

            if(hand[k].color==col && hand[k].valeur==6){king=1;}

            if(hand[k].color==col && hand[k].valeur==5){queen=1;}

            if(hand[k].color==col && hand[k].valeur==4){jack=1;}

            if(hand[k].color==col && hand[k].valeur==3){ten=1;}

            if(hand[k].color==col && hand[k].valeur==2){nine=1;}

            if(hand[k].color==col && hand[k].valeur==1){eight=1;}

            if(hand[k].color==col && hand[k].valeur==0){seven=1;}
            }

if(ace==1 && king==1 && queen==1 && jack==1){*pts=50;}
if(king==1 && queen==1 && jack==1 && ten==1){*pts=50;}
if(queen==1 && jack==1 && ten==1 && nine==1){*pts=50;}
if(jack==1 && ten==1 && nine==1 && eight==1){*pts=50;}
if(ten==1 && nine==1 && eight==1 && seven==1){*pts=50;}

}}


void sequence3Test(CARD hand[],int *pts){

int k,col;

    for(col=0;col<4;col++){

        int ace=0,king=0,queen=0,jack=0,ten=0,nine=0,eight=0,seven=0;

            for(k=0;k<8;k++){

            if(hand[k].color==col && hand[k].valeur==7){ace=1;}

            if(hand[k].color==col && hand[k].valeur==6){king=1;}

            if(hand[k].color==col && hand[k].valeur==5){queen=1;}

            if(hand[k].color==col && hand[k].valeur==4){jack=1;}

            if(hand[k].color==col && hand[k].valeur==3){ten=1;}

            if(hand[k].color==col && hand[k].valeur==2){nine=1;}

            if(hand[k].color==col && hand[k].valeur==1){eight=1;}

            if(hand[k].color==col && hand[k].valeur==0){seven=1;}
            }

if(ace==1 && king==1 && queen==1){*pts=20;}
if(king==1 && queen==1 && jack==1){*pts=20;}
if(queen==1 && jack==1 && ten==1){*pts=20;}
if(jack==1 && ten==1 && nine==1){*pts=20;}
if(ten==1 && nine==1 && eight==1){*pts=20;}
if(nine==1 && eight==1 && seven==1){*pts=20;}


}}

void announcementsAI(CARD hand[],int *square,int *pts,int *distrib,int *player,int *stop){

    squareTest(hand,&*pts,&*square);

            switch (*square) {

            case 1 :
                printf("all four\n");
                break;

            case 0 :
                sequence5Test(hand,&*pts);
                switch (*pts){
                case 100 :
                    printf("hundred\n");
                    break;

                case 0 :
                    sequence4Test(hand,&*pts);
                        switch(*pts){
                    case 50:
                        printf("fifty\n");
                        break;

                    case 0 :
                        sequence3Test(hand,&*pts);
                            switch(*pts){
                            case 20 :
                                printf("tierce\n");
                                break;

                            case 0 :
                                printf("pass\n");
                                break;

                            default :
                                printf("error\n");
                                break;}}}}

    *player=*player+1;

    if(*player==4){*stop=3;
                    *distrib=*distrib-3;
            }else{*distrib=*distrib+1;}

}


void announcePlayer(int *player,int *distrib,int *stop,int *square,int *pts){

    int act=0;

    //display choices of the player

    printf("1: All four\n");
    printf("2: Tierce\n");
    printf("3: Fifty\n");
    printf("4: A Hundred\n");

    do {
    printf("What do you want to announce ?\n");
    GetAndCheck(&act);




} while ((act<1) || (act>5));


    *player=*player+1; //indicates the number of players that have played during one tour

    //at the end of the tour when each player have announced something
    if(*player==4) {*stop=3;
                    *distrib=*distrib-3;
        } else {*distrib=*distrib+1;}

}



