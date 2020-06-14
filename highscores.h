#ifndef HIGHSCORES_HEADER
#define HIGHSCORES_HEADER

int lineCount(char* path);
void scoreWrite(char* name, int scores);
void getLeaderboard();
void swap(int *xp, int *yp);
void bubbleSort(int a[], char** b, int n);

#endif // HIGHSCORES_HEADER
