#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "melange&distri.h"


int main() {

    srand(time(NULL));

    CARD game[32];
    CARD N[8],S[8],W[8],E[8];
    int distrib=0;

    init(game);
    mixAndDisrti(game,N,S,E,W,&distrib);
    displayHand(N,S,E,W,distrib);

}
