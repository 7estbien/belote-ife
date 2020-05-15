#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "melange.h"



void init(CARD game[]);

void displayCard(CARD card);

void mixAndDisrti(CARD game[],CARD N[],CARD S[],CARD E[],CARD W[]);

void displayHand(CARD N[],CARD S[],CARD E[],CARD W[]);




int main() {

    srand(time(NULL));

    CARD game[32];
    CARD N[8],S[8],W[8],E[8];

    init(game);
    mixAndDisrti(game,N,S,E,W);
    displayHand(N,S,E,W);

}
