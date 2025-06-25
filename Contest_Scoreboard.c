#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (getchar() != '\n'); // consume newline
    while (T--) {
        int solved[101] = {0};
        int penalty[101] = {0};
        int submissions[101][10] = {0}; // incorrect submissions per problem
        int solved_flag[101][10] = {0}; // whether problem is solved
        int active[101] = {0}; // whether contestant has submitted

        char line[100];
        while (fgets(line, sizeof(line), stdin)) {
            if (line[0] == '\n' || line[0] == '\0') break;

            int c, p, t;
            char L;
            sscanf(line, "%d %d %d %c", &c, &p, &t, &L);
            active[c] = 1;

            if (L == 'C' && !solved_flag[c][p]) {
                solved[c]++;
                penalty[c] += t + 20 * submissions[c][p];
                solved_flag[c][p] = 1;
            } else if (L == 'I' && !solved_flag[c][p]) {
                submissions[c][p]++;
            }
        }

        // Sort and print
        for (int i = 1; i <= 100; i++) {
            for (int j = i + 1; j <= 100; j++) {
                if (active[i] && active[j]) {
                    if (solved[j] > solved[i] ||
                        (solved[j] == solved[i] && penalty[j] < penalty[i]) ||
                        (solved[j] == solved[i] && penalty[j] == penalty[i] && j < i)) {
                        // Swap all relevant data
                        int temp;
                        temp = solved[i]; solved[i] = solved[j]; solved[j] = temp;
                        temp = penalty[i]; penalty[i] = penalty[j]; penalty[j] = temp;
                        temp = active[i]; active[i] = active[j]; active[j] = temp;

                        for (int k = 1; k <= 9; k++) {
                            temp = submissions[i][k]; submissions[i][k] = submissions[j][k]; submissions[j][k] = temp;
                            temp = solved_flag[i][k]; solved_flag[i][k] = solved_flag[j][k]; solved_flag[j][k] = temp;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= 100; i++) {
            if (active[i]) {
                printf("%d %d %d\n", i, solved[i], penalty[i]);
            }
        }

        if (T) printf("\n");
    }

    return 0;
}
