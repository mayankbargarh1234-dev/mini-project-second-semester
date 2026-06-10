// Draw Rectangle
void drawRectangle(int x, int y, int width, int height) {
    for(int i = y; i < y + height && i < ROWS; i++)
        for(int j = x; j < x + width && j < COLS; j++)
            canvas[i][j] = '*';
}

// Draw Horizontal Line
void drawLine(int x1, int x2, int y) {
    if (y < 0 || y >= ROWS || x1 > x2)
        return;

    int start = x1 < 0 ? 0 : x1;
    int end = x2 >= COLS ? COLS - 1 : x2;

    for(int i = start; i <= end; i++)
        canvas[y][i] = '*';
}
