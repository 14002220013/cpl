#include <stdio.h>

#define SIZE 4

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '0';
        }
    }
    // Predefined mine positions (example: mines at (1,1), (2,2), (3,3))
    board[1][1] = '*';
    board[2][2] = '*';
    board[3][3] = '*';
}

void printBoard(char board[SIZE][SIZE]) {
    printf("Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void calculateHints(char board[SIZE][SIZE]) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '*') continue;
            int minesCount = 0;
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE && board[ni][nj] == '*') {
                    minesCount++;
                }
            }
            board[i][j] = '0' + minesCount;
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    calculateHints(board);
    printBoard(board);
    return 0;
}