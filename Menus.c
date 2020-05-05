#include <stdlib.h>

void displayMenu(int m){
    switch(m){
        case 1:
            printf("*******************************\n");
            printf("*                             *\n");
            printf("*                             *\n");
            printf("*       Coinche belote        *\n");
            printf("*                             *\n");
            printf("*                             *\n");
            printf("*******************************\n");

            printf("What do you want to do ?\n\n");

            printf("1 : Start a new game\n");
            printf("2 : Display the leaderboard\n");
            printf("3 : Exit\n");

            break;


        default:
            printf("Error. Exiting the program...");
            return EXIT_FAILURE;


    }
}
