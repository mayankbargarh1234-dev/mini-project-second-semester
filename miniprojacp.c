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

// Draw Rectangle
void drawRectangle(int x, int y, int width, int height) {
    for(int i = y; i < y + height && i < ROWS; i++)
        for(int j = x; j < x + width && j < COLS; j++)
            canvas[i][j] = '*';
}

// Draw Horizontal Line
void drawLine(int x1, int x2, int y) {
    for(int i = x1; i <= x2 && i < COLS; i++)
        canvas[y][i] = '*';
}

// Draw Triangle
void drawTriangle(int x, int y, int h) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j <= i; j++) {
            canvas[y + i][x + j] = '*';
        }
    }
}

// Draw Simple Circle
void drawCircle(int cx, int cy, int r) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int dx = j - cx;
            int dy = i - cy;

            if(dx*dx + dy*dy <= r*r)
                canvas[i][j] = '*';
        }
    }
}

// Delete Object (replace area with '_')
void deleteArea(int x, int y, int width, int height) {
    for(int i = y; i < y + height && i < ROWS; i++)
        for(int j = x; j < x + width && j < COLS; j++)
            canvas[i][j] = '_';
}

int main() {
    clearCanvas();

    // Add objects
    drawRectangle(2, 2, 8, 4);
    drawLine(15, 30, 5);
    drawTriangle(5, 10, 5);
    drawCircle(30, 12, 3);

    printf("Picture after adding objects:\n");
    displayCanvas();

    // Delete rectangle
    deleteArea(2, 2, 8, 4);

    printf("\nAfter deleting rectangle:\n");
    displayCanvas();

    // Modify line (delete old line and draw new line)
    deleteArea(15, 5, 16, 1);
    drawLine(10, 25, 7);

    printf("\nAfter modifying line:\n");
    displayCanvas();

    return 0;
}