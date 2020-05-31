#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "melange&distri.h"
#include "annonces.h"


int main() {

    srand(time(NULL));

    CARD game[32];
    CARD N[8],S[8],W[8],E[8];
    int distrib=0;

    init(game);
    mixAndDisrti(game,N,S,E,W,&distrib);
    displayHand(N,S,E,W,distrib);
    

    if (distrib==0){
        printf("WEST announce ");
        bidOrdi(&bet,W);
        chooseTrump(W);
            } else {if(distrib==1){
                printf("NORTH announce ");
                bidOrdi(&bet,N);
                chooseTrump(N);
                    } else {if (distrib==2) {
                        printf("EAST announce ");
                        bidOrdi(&bet,E);
                        chooseTrump(E);
                            } else {action();}}}


}
