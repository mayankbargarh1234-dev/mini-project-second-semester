// Draw Triangle
void drawTriangle(int x, int y, int h) {
    if (x < 0 || y < 0 || h <= 0)
        return;

    for(int i = 0; i < h; i++) {
        int row = y + i;
        if (row < 0 || row >= ROWS)
            break;

        for(int j = 0; j <= i; j++) {
            int col = x + j;
            if (col < 0 || col >= COLS)
                continue;
            canvas[row][col] = '*';
        }
    }
}

// Draw Simple Circle
void drawCircle(int cx, int cy, int r) {
    if (r < 0)
        return;

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
