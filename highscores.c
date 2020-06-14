#include "highscores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lineCount(){

	FILE* file = fopen("highscores.txt","r");
	int lines=0;
	char chr;


	chr=getc(file);
	while (chr != EOF){

		 if (chr == '\n'){
	            lines = lines + 1;
	     }
		 chr = getc(file);
	}

	fclose(file);
	return lines;
}


void scoreWrite(char* name, int score){

	FILE* file = fopen("highscores.txt","a"); //open highscores file in adding

    fprintf(file, "%s:%d\n", name, score);

	fclose(file); //close the file
}

void getLeaderboard(){

    FILE* file = fopen("highscores.txt","r"); //open highscores file in reading

    // Variables declaration
    char board[25];
    char* name;
    char* scoreS;
    int score;
    int k = 0;
    int lines = lineCount();
    int* bestScores;
    char** bestPlayers;
    int currentLine = 0;

    // We create 2 arrays : one array of strings for the players, and one array of integers for the scores.
    bestScores = (int*) malloc(lines * sizeof(int));
    bestPlayers = (char**) malloc(lines * sizeof(char*));

    for(int i = 0; i < lines; i++){
        bestPlayers[i] = malloc(15 * sizeof(char));
    }

    while(fgets(board, sizeof board, file) != NULL){
        for(int i = 0; i < strlen(board); i++){
            if(board[i] == ':'){
                k = i;
            }
        }

        name = (char*) malloc((k+1) * sizeof(char));
        scoreS = (char*) malloc((k+1) * sizeof(char));

        for(int j = 0; j < k; j++){
            name[j] = board[j];
            scoreS[j] = board[j+k+1];
        }

        score = atoi(scoreS);
        bestScores[currentLine] = score;
        bestPlayers[currentLine] = name;

        currentLine++;
    }

    bubbleSort(bestScores, bestPlayers, lines);

    printf("\nLEADERBOARD\n");
    for(int i = 0; i < lines; i++){
        printf("%d) %s - %d points\n", i+1, bestPlayers[i], bestScores[i]);

    }
	fclose(file); //closes the file

}

void swap(int *xp, int *yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}


void bubbleSort(int a[], char** b, int n)
{
   int i,j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (a[j] > a[j+1])
              swap(&a[j], &a[j+1]);
              swap(&b[j], &b[j+1]);
}
