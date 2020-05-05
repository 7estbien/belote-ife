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



            break;

        default:
            printf("Error. Exiting the program...");
            return EXIT_FAILURE;


    }
}
