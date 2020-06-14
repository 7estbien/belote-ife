#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Menus.h"
#include "melange_distri.h"
#include "encheres.h"
#include "annonces.h"
#include "highscores.h"


int main()
{

    srand(time(NULL));

    // Variables initialization
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
    int choice = 0;
    int size = 15;
    char * name = (char *) malloc(size * sizeof(char));

    displayMenu(1); // We display the n°1 menu, which is the home menu.
    scanf("%d", &choice);


    switch (choice)
    {
    case 1:
        do
        {
            init(game);
            mixAndDisrti(game,N,S,E,W,&distrib);
            displayHand(N,S,E,W,distrib);
            distrib++; // we go to the next player
            stop=0;

            do
            {
                if (distrib==1 || distrib==5)
                {
                    printf("WEST announces ");
                    chooseTrump(W,&trumpW);
                    calculOrdi(W,&maxW,trumpW);
                    chooseAmount(&bet,maxW,&player,&tour,&pass,trumpW,&distrib,&stop,&lastW);

                }
                else
                {
                    if(distrib==0 || distrib==4)
                    {

                        printf("NORTH announces ");
                        chooseTrump(N,&trumpN);
                        calculOrdi(N,&maxN,trumpN);
                        chooseAmount(&bet,maxN,&player,&tour,&pass,trumpN,&distrib,&stop,&lastN);

                    }
                    else
                    {
                        if (distrib==3 || distrib==7)
                        {

                            printf("EAST announces ");
                            chooseTrump(E,&trumpE);
                            calculOrdi(E,&maxE,trumpE);
                            chooseAmount(&bet,maxE,&player,&tour,&pass,trumpE,&distrib,&stop,&lastE);

                        }
                        else
                        {
                            action(&player,&tour,&pass,&distrib,&bet,&stop,&lastS,&trumpS,&coinche);
                        }
                    }
                }

            }
            while(stop==0);

        }
        while(stop==1);

        winningContract(&trump,lastN,lastS,lastE,lastW,trumpE,trumpN,trumpS,trumpW,&contractNS,&contractEW,&distrib);
        player=0;

        do
        {
            if (distrib==1 || distrib==5)
            {
                printf("WEST announces ");
                announcementsAI(W,&squareW,&Wpts,&distrib,&player,&stop);


            }
            else
            {
                if(distrib==0 || distrib==4)
                {
                    printf("NORTH announces ");
                    announcementsAI(N,&squareN,&Npts,&distrib,&player,&stop);


                }
                else
                {
                    if (distrib==3 || distrib==7)
                    {
                        printf("EAST announces ");
                        announcementsAI(E,&squareE,&Epts,&distrib,&player,&stop);

                    }
                    else
                    {
                        announceP(S,&player,&distrib,&stop,&squareS,&Spts);
                    }
                }
            }

            printf("\n\nGame finished. Your score is %d.\n", bet);
            printf("\nPlease enter your name : ");

            scanf("%s", &*name);
            scoreWrite(name, bet);

            free(name);

            printf("\nThanks for playing !");
            return EXIT_SUCCESS;


        }
        while(stop!=3);

        break;

    case 2:
        printf("Leaderboard :\n");
        getLeaderboard();
        break;

    case 3:
        printf("See you later !");
        return EXIT_SUCCESS;
        break;
    }


    return EXIT_SUCCESS;

}
