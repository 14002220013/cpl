#include <stdio.h>

int main() {
    char arr[4][4] = {
        '*', '.', '.', '.',
        '.', '.', '*', '.',
        '.', '.', '.', '.',
        '.', '*', '.', '.'
    };

    int count;
    char temp_arr[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == '*') {
                temp_arr[i][j] = '*';
                continue;
            }

            count = 0;

            if (i > 0 && arr[i - 1][j] == '*') count++;
            if (j > 0 && arr[i][j - 1] == '*') count++;
            if (i < 3 && arr[i + 1][j] == '*') count++;
            if (j < 3 && arr[i][j + 1] == '*') count++;
            if (i > 0 && j > 0 && arr[i - 1][j - 1] == '*') count++;
            if (i > 0 && j < 3 && arr[i - 1][j + 1] == '*') count++;
            if (i < 3 && j > 0 && arr[i + 1][j - 1] == '*') count++;
            if (i < 3 && j < 3 && arr[i + 1][j + 1] == '*') count++;

            temp_arr[i][j] = count + '0';
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c ", temp_arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}