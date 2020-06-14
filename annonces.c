#include "annonces.h"


void squareTest(CARD hand[],int *pts,int *square){

    int i,k,nbr=0;
    int value=2;

    for(k=0;k<6;k++){ // test for the five values that can do an all four

        for(i=0;i<8;i++){
            if(hand[i].valeur==value){nbr++;}
        }

        if(nbr==4){ switch(value) {

                    case 2 : //all four of nine
                        *pts=150;
                        break;
                    case 3 : //all four of ten
                        *pts=100;
                        break;
                    case 4 : //all four of jack
                        *pts=200;
                        break;
                    case 5 : //all four of queen
                        *pts=100;
                        break;
                    case 6 : //all four of king
                        *pts=100;
                        break;
                    case 7 : //all four of ace
                        *pts=100;
                        break;

                    default :
                        printf("error\n");
        }
        *square=1;
    }
    nbr=0;
    value++; //we go to the next value
}
}


void sequence5Test(CARD hand[],int *pts){

    int k,col;

    for(col=0;col<4;col++){

        //check which cards of a given color are in the hand of the player

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

// check if there is a sequence of 5 cards

            if(ace==1 && king==1 && queen==1 && jack==1 && ten==1){
                    *pts=100;
            }
            if(king==1 && queen==1 && jack==1 && ten==1 && nine==1){
                    *pts=100;
            }
            if(queen==1 && jack==1 && ten==1 && nine==1 && eight==1){
                    *pts=100;
            }
            if(jack==1 && ten==1 && nine==1 && eight==1 && seven==1){
                    *pts=100;
            }

    }
}

void sequence4Test(CARD hand[],int *pts){
int k,col;

    for(col=0;col<4;col++){

        //check which cards of a given color are in the hand of the player

        int ace=0,king=0,queen=0,jack=0,ten=0,nine=0,eight=0,seven=0;

            for(k=0;k<8;k++){
                if(hand[k].color==col && hand[k].valeur==7){
                        ace=1;
                }

                if(hand[k].color==col && hand[k].valeur==6){
                        king=1;
                }

                if(hand[k].color==col && hand[k].valeur==5){
                        queen=1;
                }

                if(hand[k].color==col && hand[k].valeur==4){
                        jack=1;
                }

                if(hand[k].color==col && hand[k].valeur==3){
                        ten=1;
                }

                if(hand[k].color==col && hand[k].valeur==2){
                        nine=1;
                }

                if(hand[k].color==col && hand[k].valeur==1){
                        eight=1;
                }

                if(hand[k].color==col && hand[k].valeur==0){
                        seven=1;
                    }
            }

            if(ace==1 && king==1 && queen==1 && jack==1){
                    *pts=50;
            }
            if(king==1 && queen==1 && jack==1 && ten==1){
                    *pts=50;
            }
            if(queen==1 && jack==1 && ten==1 && nine==1){
                    *pts=50;
            }
            if(jack==1 && ten==1 && nine==1 && eight==1){
                    *pts=50;
            }
            if(ten==1 && nine==1 && eight==1 && seven==1){
                    *pts=50;
            }
// check if there is a sequence of 4 cards

if(ace==1 && king==1 && queen==1 && jack==1){*pts=50;}
if(king==1 && queen==1 && jack==1 && ten==1){*pts=50;}
if(queen==1 && jack==1 && ten==1 && nine==1){*pts=50;}
if(jack==1 && ten==1 && nine==1 && eight==1){*pts=50;}
if(ten==1 && nine==1 && eight==1 && seven==1){*pts=50;}

        }
}


void sequence3Test(CARD hand[],int *pts){

int k,col;

    for(col=0;col<4;col++){

        //check which cards of a given color are in the hand of the player

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

            if(ace==1 && king==1 && queen==1){
                    *pts=20;
            }
            if(king==1 && queen==1 && jack==1){
                    *pts=20;
            }
            if(queen==1 && jack==1 && ten==1){
                    *pts=20;
            }
            if(jack==1 && ten==1 && nine==1){
                    *pts=20;
                    }
            if(ten==1 && nine==1 && eight==1){
                *pts=20;
                }
            if(nine==1 && eight==1 && seven==1){
                *pts=20;
            }

// check if there is a sequence of 3 cards

if(ace==1 && king==1 && queen==1){*pts=20;}
if(king==1 && queen==1 && jack==1){*pts=20;}
if(queen==1 && jack==1 && ten==1){*pts=20;}
if(jack==1 && ten==1 && nine==1){*pts=20;}
if(ten==1 && nine==1 && eight==1){*pts=20;}
if(nine==1 && eight==1 && seven==1){*pts=20;}



        }
}

void announcementsAI(CARD hand[],int *square,int *pts,int *distrib,int *player,int *stop){

    squareTest(hand,&*pts,&*square);

            switch (*square) {

            case 1 : // if the AI has an all four
                printf("all four\n");
                break;

            case 0 : // if the AI doesn't have an all four
                sequence5Test(hand,&*pts);
                switch (*pts){
                case 100 : // if the AI has a sequence of 5 cards
                    printf("hundred\n");
                    break;

                case 0 : // if the AI doesn't have a sequence of 5 cards
                    sequence4Test(hand,&*pts);
                        switch(*pts){
                    case 50: // if the AI has a sequence of 4 cards
                        printf("fifty\n");
                        break;

                    case 0 : // if the AI doesn't have a sequence of 4 cards
                        sequence3Test(hand,&*pts);
                            switch(*pts){
                            case 20 : // if the AI has a sequence of 3 cards
                                printf("tierce\n");
                                break;

                            case 0 : // if the AI has no sequence
                                printf("pass\n");
                                break;

                            default :
                                printf("error\n");
                                break;}}}}

    *player=*player+1; //indicates the number of players that have played during one tour

    //at the end of the tour when each player have announced something

    if(*player==4){*stop=3;
                    *distrib=*distrib-3;
            }else{*distrib=*distrib+1;}

}


void GetPlayer(int *act){

    //display choices of the player

    printf("1: All four\n");
    printf("2: Tierce\n");
    printf("3: Fifty\n");
    printf("4: A Hundred\n");
    printf("5: Pass\n");

    // get the action of the player

    do {
    printf("What do you want to announce ?\n");
    printf("You have to input a number between 1 and 5\n");
    GetAndCheck(&*act);


} while ((*act<1) || (*act>5));}


void checkPlayer(CARD hand[],int *stop,int *square,int *pts,int act){

    switch (act){
case 1 :
    // check if there are four cards of the same value
    squareTest(hand,&*pts,&*square);
        switch (*square){
    case 1 :
        printf("You announce all four\n");
        break;
    case 0 :
        printf("You can't announce something that you don't have\n");
        printf("All four can't be of seven or eight\n");
        *stop=4;
        break;
    default :
        printf("Error all four\n");
        break;
        }
    break;

case 2 :
    // check if there is a sequence of three cards
    sequence3Test(hand,&*pts);
        switch (*pts){
    case 0 :
        printf("You can't announce something that you don't have\n");
        *stop=4;
        break;
    case 20 :
        printf("You announce tierce\n");
        break;
    default :
        printf("Error tierce\n");
        break;
        }
    break;

case 3 :
    // check if there is a sequence of four cards
    sequence4Test(hand,&*pts);
        switch (*pts){
    case 0 :
        printf("You can't announce something that you don't have\n");
        *stop=4;
        break;
    case 50 :
        printf("You announce fifty\n");
        break;
    default :
        printf("Error fifty\n");
        break;
        }
    break;

case 4 :
    // check if there is sequence of five cards
    sequence5Test(hand,&*pts);
        switch(*pts){
    case 0 :
        printf("You can't announce something that you don't have\n");
        *stop=4;
        break;
    case 100 :
        printf("You announce hundred\n");
        break;
    default :
        printf("Error hundred\n");
        break;
        }
    break;

case 5 :
    printf("You announce pass\n");
    break;

default :
    printf("error check\n");
    break;

        }}



void announceP(CARD hand[],int *player,int *distrib,int *stop,int *square,int *pts){

int act=0;

do {
    *stop=0;

    // Get the action of the player

    GetPlayer(&act);

    // Check if the announce of the player is correct

    checkPlayer(hand,&*stop,&*square,&*pts,act);

} while (*stop==4);

    *player=*player + 1; //indicates the number of players that have played during one round

    //at the end of the round when each player have announced something
    if(*player==4) {
            *stop=3;
            *distrib=*distrib-3;
        } else {
            *distrib=*distrib+1;
        }

}

