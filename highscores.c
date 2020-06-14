#include "highscores.h"
#include <stdio.h>

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

    fprintf(file, "%s:%d", name, score);

	fclose(file); //close the file
}

void getLeaderboard(){

    FILE* file = fopen("highscores.txt","r"); //open highscores file in reading
    char* board[15];
    int i = 0;

    while(!feof(file)){
        fgets(board,30,file);
        printf(board);
        i++;
    }

    if(i == 0){
        printf("\nThe leaderboard is empty !\n");
    }
	fclose(file); //closes the file

}
