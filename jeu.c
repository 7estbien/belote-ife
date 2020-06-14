#include "jeu.h"



void cardsTrump(int trump,CARD T[],int *nbtrump){

    int i;

    for(i=0;i<8;i++){
        if(T[i].color==trump) {*nbtrump=*nbtrump+1;}
    }
    printf("%d",*nbtrump);

}


void play(int trump,CARD pcard,CARD T[],int nbtrump){

    int cval=0;

    if(nbtrump==0){
        do{ cval=rand()%8;} while(cval<pcard.valeur);
    }
    }







