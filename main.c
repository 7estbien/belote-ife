#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Menus.h"
#include "melange_distri.h"
#include "annonces.h"


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

    //displayMenu(1); We display the n°1 menu, which is the home menu.


init(game);
    mixAndDisrti(game,N,S,E,W,&distrib);
    displayHand(N,S,E,W,distrib);
    distrib=distrib+1;


    do {if (distrib==1 || distrib==5){
        printf("WEST announce ");chooseTrump(W,&trumpW);
        calculOrdi(W,&maxW,trumpW);
        chooseAmount(&bet,maxW,&player,&tour,&pass,trumpW,&distrib,&stop,&lastW);

            } else {if(distrib==0 || distrib==4){
                printf("NORTH announce ");chooseTrump(N,&trumpN);
                calculOrdi(N,&maxN,trumpN);
                chooseAmount(&bet,maxN,&player,&tour,&pass,trumpN,&distrib,&stop,&lastN);

                    } else {if (distrib==3 || distrib==7) {
                        printf("EAST announce ");chooseTrump(E,&trumpE);
                        calculOrdi(E,&maxE,trumpE);
                        chooseAmount(&bet,maxE,&player,&tour,&pass,trumpE,&distrib,&stop,&lastE);
                            } else {action(&player,&tour,&pass,&distrib,&bet,&stop,&lastS,&trumpS);}}}

}while(stop==0);

    if(stop==1){bet=70;}



 winningContract(&trump,lastN,lastS,lastE,lastW,trumpE,trumpN,trumpS,trumpW,&contractNS,&contractEW);

    if(stop==2){}





    return EXIT_SUCCESS;

}
