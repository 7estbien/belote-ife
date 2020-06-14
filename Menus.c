#include <stdlib.h>

void displayMenu(int m, char* name)
{
    switch(m)
    {
    case 1:
        printf("*******************************\n");
        printf("*                             *\n");
        printf("*                             *\n");
        printf("*       Coinche belote        *\n");
        printf("*                             *\n");
        printf("*                             *\n");
        printf("*******************************\n");

        printf("What do you want to do, %s ?\n\n", name);

        printf("1 : Start a new game\n");
        printf("2 : Display the leaderboard\n");
        printf("3 : Exit\n");

        break;

    default:
        printf("Error. Exiting the program...");
        return EXIT_FAILURE;


    }
}
