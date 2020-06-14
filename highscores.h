#ifndef HIGHSCORES_HEADER
#define HIGHSCORES_HEADER

/**
* Gets the number of lines in a file given its path.
* @param path - The path (relative or absolute) of the file
**/
int lineCount(char* path);

/**
* Writes the score of a player in the highscores file.
* @param name - The name of the player
* @param scores - The players' score
**/
void scoreWrite(char* name, int score);

/**
* Gets the leaderboard of the game
* @param display - Chooses if we need to display it (1 - display, otherwise no)
* @param bestScores - The return array for the scores
* @param bestScores - The return array for the players
**/
void getLeaderboard(int display,int* bestScores, char** bestPlayers);

/**
* Swaps two integers' location
* @param xp - The 1st integer
* @param yp - The 2nd integer
**/
void swapInt(int *xp, int *yp);

/**
* Swaps two strings' location
* @param xp - The 1st string
* @param yp - The 2nd string
**/
void swapCharArray(int *xp, int *yp);

/**
* Sorts an array a and keeps track of position in an array of strings b
* @param a - The integer array
* @param b - The strings array
* @param n - The size of the a array
**/
void bubbleSort(int a[], char** b, int n);

#endif // HIGHSCORES_HEADER
