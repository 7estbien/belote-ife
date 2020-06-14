#include "encheres.h"



void action(int *player,int *tour,int *pass,int *distrib,int *bet,int *stop,int *lastbet,int *trumpS,int *coinche)
{

    int act=0;

    //display the different actions

    printf("1: Pass\n");
    printf("2: Bid\n");
    printf("3: Capot\n");
    printf("4: General\n");
    printf("5: Coinche\n");


    do
    {
        printf("What do you want to announce ?\n");
        GetAndCheck(&act);

        if(act==1)
        {
            printf("\nYou pass\n\n");
            *pass=*pass+1;
            if(*pass==3 && *bet!=70)
            {
                *stop=2;
            }
            if(*tour==0 && *pass==4)  //if all the players pass during the first tour
            {
                *stop=1; //variable enabling to get back to the beginning of the program
                printf("everyone has passed, cards are distributed again\n\n");

            }

        }
        else
        {
            if(act==2)
            {
                bid(&*bet,&*trumpS);
                *lastbet=*bet;
                *pass=0;
            }
            else
            {
                if(act==3)
                {

                    *pass=0;
                    *bet=162;
                    *lastbet=*bet;
                    trump(&*trumpS);
                    *trumpS=*trumpS-1;
                    printf("\nYou announce capot ");
                    displayTrump(*trumpS);

                }
                else
                {
                    if(act==4)
                    {

                        *pass=0;
                        *bet=162;
                        *lastbet=*bet;
                        trump(&*trumpS);
                        *trumpS=*trumpS-1;
                        printf("\nYou announce general ");
                        displayTrump(*trumpS);

                    }
                    else
                    {
                        if(act==5)
                        {
                            if(*bet<80)
                            {
                                printf("You can't announce coinche if nobody announced a contract\n");
                                act=6;
                            }
                            else
                            {
                                printf("\nYou announce coinche\n\n");
                                *pass=0;
                                *coinche=1;
                            }
                        }
                        else
                        {
                            printf("You have to input a number between 1 and 5\n");
                        }
                    }
                }
            }
        }

    }
    while ((act<1) || (act>5));   //the loop continues until the player input an expected value

    *player=*player+1; //indicates the number of players that have played during one tour

    //at the end of the tour when each player have announced something
    if(*player==4)
    {
        *tour=*tour+1;
        *player=0;
        *distrib=*distrib-3; //we go back to the player at the left of the distributor
    }
    else
    {
        *distrib=*distrib+1;
    }




}



void GetAndCheck(int *number)
{

    char input[6];

    fgets(input,6,stdin);
    *number=atoi(input);

}



void amount(int* b,int bet)
{

    do
    {
        printf("You can bid between 80 and 170 and more than the others\nHow much do you want to bid ? ");
        GetAndCheck(&*b);

    }
    while ((*b<80) || (*b>170) || (*b%10!=0) || (*b<bet+10));   //the loop continues until the player input a correct value

}



void trump(int* t)
{

    do
    {
        printf("Which trump ? 1: Heart, 2: Diamond, 3: Club, 4: Spade\n");
        printf("You can also play with 'All Trump' (5) or 'No Trump' (6).\n");
        printf("You have to choose a number between 1 and 6\n\nChoice : ");
        GetAndCheck(&*t);
    }
    while((*t<1) || (*t>6));   //the loop continues until the player input a correct value

}


void bid(int *bet,int *trumpS)
{

    int t=0;
    int b=0;

    amount(&b,*bet);
    trump(&t);

    printf("You announce %d ",b);

    //attribute the number of the trump corresponding to the input of the user

    displayTrump(t);

    *bet=b; //the value of the last bet is updated

}


void chooseTrump(CARD hand[],int *atrump)
{

    int i,nbh=0,nbd=0,nbc=0,nbs=0;

    //count the number of cards of each color

    for(i=0; i<8; i++)
    {
        if(hand[i].color==0)
        {
            nbh++;
        }
        else
        {
            if(hand[i].color==1)
            {
                nbd++;
            }
            else
            {
                if(hand[i].color==2)
                {
                    nbc++;
                }
                else
                {
                    nbs++;
                }
            }
        }
    }

    //compare the number of cards of each color

    if(nbh>nbc && nbh>nbd && nbh>nbs)
    {
        *atrump=0;
    }
    if(nbd>nbh && nbd>nbc && nbd>nbs)
    {
        *atrump=1;
    }
    if(nbc>nbh && nbc>nbd && nbc>nbs)
    {
        *atrump=2;
    }
    if(nbs>nbh && nbs>nbd && nbs>nbc)
    {
        *atrump=3;
    }

}


void displayTrump(int trump)
{

    switch(trump){
        case 0:
            printf("Heart\n\n");
            break;

        case 1:
            printf("Diamond\n\n");
            break;

        case 2:
            printf("Club\n\n");
            break;

        case 3:
            printf("Spade\n\n");
            break;

        case 4:
            printf("All Trump\n\n");
            break;

        case 5:
            printf("No Trump\n\n");
            break;

    }

}


void calculOrdi(CARD hand[],int *maxi,int atrump)
{

    int i,loose=0;

    for(i=0; i<8; i++)
    {
        if(hand[i].color!=atrump && (hand[i].valeur!=7 || hand[i].valeur!=3))
        {
            loose++;
        }
        else
        {
            if(hand[i].color!=atrump && (hand[i].valeur<2 || hand[i].valeur==5))
            {
                loose++;
            }
        }
    }
    *maxi= 170-loose*15 ;
}



void chooseAmount(int *bet,int maxi,int *player,int *tour,int *pass,int atrump,int *distrib,int *stop,int *lastbet)
{

    if((*bet+10)>maxi)   // Test if the AI can announce higher than the last player
    {
        printf("Pass\n\n");
        *pass=*pass+1;
        if(*tour==0 && *pass==4)  // If all the players pass during the first tour
        {
            *stop=1; //variable enabling to get back to the beginning of the program
            printf("Everyone has passed, cards are distributed again.\n\n");

        }

    }
    else
    {
        *bet=*bet+10;
        printf("%d ",*bet);
        displayTrump(atrump);
        *lastbet=*bet;
        *pass=0;
    }
    if(*pass==3 && *bet!=70)
    {
        *stop=2;
    }

    *player=*player+1;

    // At the end of the tour when every player announced something

    if(*player==4)
    {
        *tour=*tour+1;
        *player=0;
        *distrib=*distrib-3; // We go back to the player at the left of the distributor
    }
    else
    {
        *distrib=*distrib+1;
    } //next player

}



void winningContract(int *trump,int lastN,int lastS,int lastE,int lastW,int trumpE,int trumpN,int trumpS,int trumpW,int *contractNS,int *contractEW, int *distrib)
{

    if(lastE>lastN && lastE>lastW && lastE>lastS)
    {
        *trump=trumpE;
        *contractEW=lastE;
        *contractNS=0;
        printf("team E/W must realize %d\n",*contractEW);
        printf("Trump : ");
        displayTrump(*trump);
        *distrib=3;
    }

    if(lastN>lastE && lastN>lastW && lastN>lastS)
    {
        *trump=trumpN;
        *contractNS=lastN;
        *contractEW=0;
        printf("team N/S must realize %d\n",*contractNS);
        printf("Trump : ");
        displayTrump(*trump);
        *distrib=0;
    }

    if(lastW>lastE && lastW>lastN && lastW>lastS)
    {
        *trump=trumpW;
        *contractEW=lastW;
        *contractNS=0;
        printf("team E/W must realize %d\n",*contractEW);
        printf("Trump : ");
        displayTrump(*trump);
        *distrib=1;

    }

    if(lastS>lastE && lastS>lastW && lastS>lastN)
    {
        *trump=trumpS;
        *contractNS=lastS;
        *contractEW=0;
        printf("team N/S must realize %d\n",*contractNS);
        printf("Trump : ");
        displayTrump(*trump);
        *distrib=2;
    }


}


