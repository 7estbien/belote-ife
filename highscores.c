#include "highscores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to get the number of lines in a file given its path.
int lineCount(char* path)
{

    FILE* file = fopen(path,"r"); // File opening in reading mode
    int lines = 0; // Counter initialization
    char chr; // Character tracker


    chr=getc(file); // Getting the character in the file
    while (chr != EOF)  // While we're not at the end of the file
    {

        if (chr == '\n')  // If we're at the end of a line
        {
            lines = lines + 1; // Increment the counter
        }
        chr = getc(file); // We get a a new character
    }

    fclose(file); // We close the file
    return lines; // We return the number of lines

}

// Function to write a score in the file
void scoreWrite(char* name, int score)
{

    FILE* file = fopen("highscores.txt","a"); // We open the file in adding mode

    fprintf(file, "%s:%d\n", name, score); // We print the name of the player and his score under the format "NAME:SCORE"

    fclose(file); // We close the file
}

// Function to get and print the sorted leaderboard
void getLeaderboard()
{

    FILE* file = fopen("highscores.txt","r"); //open highscores file in reading


    // Variables declaration
    char board[25];
    char* name;
    char* scoreS;
    int score;
    int k = 0;
    int lines = lineCount("highscores.txt");
    int* bestScores;
    char** bestPlayers;
    int currentLine = 0;

    // We create 2 arrays with dynamic memory allocation : one array of strings for the players, and one array of integers for the scores.
    bestScores = (int*) malloc(lines * sizeof(int));
    bestPlayers = (char**) malloc(lines * sizeof(char*));

    for(int i = 0; i < lines; i++)  // We loop through the array of strings to allocate memory to the strings themselves
    {
        bestPlayers[i] = malloc(15 * sizeof(char));
    }

    while(fgets(board, sizeof board, file))  // We loop through the file
    {
        for(int i = 0; i < strlen(board); i++)  // We get the position of the ':' separator
        {
            if(board[i] == ':')
            {
                k = i;
                break;
            }
        }

        // We dynamically allocate memory for 2 strings, one before the separator and one after it.
        name = (char*) malloc((k+1) * sizeof(char));
        scoreS = (char*) malloc((k+1) * sizeof(char));

        // We set the strings to the content of the splitted string.
        for(int j = 0; j < k; j++)
        {
            name[j] = board[j];
            scoreS[j] = board[j+k+1];
        }

        // We convert the score string into an integer
        score = atoi(scoreS);
        bestScores[currentLine] = score; // We put the current score value into an array outside of the while loop
        bestPlayers[currentLine] = name;  // We put the current name value into an array outside of the while loop

        currentLine++; // We increment the counter
    }

    bubbleSort(bestScores, bestPlayers, lines); // We sort the best scores array using a bubble sort. We also keep a track of the name arrays.

    printf("\nLEADERBOARD\n");
    for(int i = 0; i < lines; i++)  // We print the content of the arrays to display the leaderboard.
    {
        printf("%d) %s - %d points\n", i+1, bestPlayers[i], bestScores[i]);

    }
    fclose(file); // We close the file

}

// Function to swap two integers
void swap(int *xp, int *yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

// Function to bubble sort an array of int and keep track of an array of strings
void bubbleSort(int a[], char** b, int n)
{
    int i,j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
    swap(&b[j], &b[j+1]);
}
