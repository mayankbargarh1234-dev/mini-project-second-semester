#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

// Clear canvas
void clearCanvas() {
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

// Display canvas
void displayCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
}
