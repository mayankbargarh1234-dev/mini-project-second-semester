#include <stdio.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

// Initialize canvas with '_'
void initCanvas() {
    int i, j;
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

// Display canvas
void displayCanvas() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++)
            printf("%c ", canvas[i][j]);
        printf("\n");
    }
}

// Draw Rectangle
void drawRectangle(int x, int y, int width, int height) {
    int i, j;

    for(i = x; i < x + height; i++) {
        for(j = y; j < y + width; j++) {
            if(i < ROWS && j < COLS)
                canvas[i][j] = '*';
        }
    }
}

// Draw Horizontal Line
void drawLine(int row, int startCol, int endCol) {
    int i;
    for(i = startCol; i <= endCol && i < COLS; i++)
        canvas[row][i] = '*';
}

// Draw Right Triangle
void drawTriangle(int x, int y, int height) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j <= i; j++) {
            if(x+i < ROWS && y+j < COLS)
                canvas[x+i][y+j] = '*';
        }
    }
}

// Draw Circle (simple)
void drawCircle(int cx, int cy, int r) {
    int x, y;
    for(x = 0; x < ROWS; x++) {
        for(y = 0; y < COLS; y++) {
            int d = (x-cx)*(x-cx) + (y-cy)*(y-cy);
            if(d <= r*r)
                canvas[x][y] = '*';
        }
    }
}

int main() {
    initCanvas();

    drawRectangle(1, 1, 8, 4);
    drawLine(10, 5, 20);
    drawTriangle(5, 25, 5);
    drawCircle(14, 30, 3);

    displayCanvas();

    return 0;
}