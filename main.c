#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Menus.h"
#include "melange_distri.h"
#include "encheres.h"


int main()
{

srand(time(NULL));

    CARD game[32];
    CARD N[8],S[8],W[8],E[8];
    int distrib=0;
    int bet=70;
    int maxW=0,maxE=0,maxN=0;
    int player=0;
    int tour=0;
    int pass=0;
    int stop=0;
    int trump=0;
    int trumpN=0,trumpE=0,trumpW=0,trumpS=0;
    int lastN=0,lastE=0,lastW=0,lastS=0;
    int contractNS=0,contractEW=0;
    int coinche=0;
    int squareN=0,squareE=0,squareW=0,squareS=0;
    int Spts=0,Npts=0,Epts=0,Wpts=0;

    //displayMenu(1); We display the n°1 menu, which is the home menu.


do {init(game);
    mixAndDisrti(game,N,S,E,W,&distrib);
    displayHand(N,S,E,W,distrib);
    distrib=distrib+1; // we go to the next player
    stop=0;

    do {if (distrib==1 || distrib==5){
        printf("WEST announce ");
        chooseTrump(W,&trumpW);
        calculOrdi(W,&maxW,trumpW);
        chooseAmount(&bet,maxW,&player,&tour,&pass,trumpW,&distrib,&stop,&lastW);

            } else {if(distrib==0 || distrib==4){
                printf("NORTH announce ");
                chooseTrump(N,&trumpN);
                calculOrdi(N,&maxN,trumpN);
                chooseAmount(&bet,maxN,&player,&tour,&pass,trumpN,&distrib,&stop,&lastN);

                    } else {if (distrib==3 || distrib==7) {
                        printf("EAST announce ");
                        chooseTrump(E,&trumpE);
                        calculOrdi(E,&maxE,trumpE);
                        chooseAmount(&bet,maxE,&player,&tour,&pass,trumpE,&distrib,&stop,&lastE);
                            } else {action(&player,&tour,&pass,&distrib,&bet,&stop,&lastS,&trumpS,&coinche);}}}

}while(stop==0);

}while(stop==1);

 winningContract(&trump,lastN,lastS,lastE,lastW,trumpE,trumpN,trumpS,trumpW,&contractNS,&contractEW,&distrib);
 player=0;

    if(stop==2){do{if (distrib==1 || distrib==5){
        printf("WEST announce ");
        announcementsAI(W,&squareW,&Wpts,&distrib,&player,&stop);


            } else {if(distrib==0 || distrib==4){
                printf("NORTH announce ");
                announcementsAI(N,&squareN,&Npts,&distrib,&player,&stop);


                    } else {if (distrib==3 || distrib==7) {
                        printf("EAST announce ");
                        announcementsAI(E,&squareE,&Epts,&distrib,&player,&stop);


                            } else {announcePlayer(&player,&distrib,&stop,&squareS,&Spts);}}}


    }while(stop!=3);

    return EXIT_SUCCESS;

}}
