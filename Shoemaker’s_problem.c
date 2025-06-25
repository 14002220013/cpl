#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int time[1000], fine[1000], index[1000];
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &time[i], &fine[i]);
            index[i] = i + 1;
        }

        // Sort jobs by fine/time ratio (descending), then by index (ascending)
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                double ratio_i = (double)fine[i] / time[i];
                double ratio_j = (double)fine[j] / time[j];

                if (ratio_j > ratio_i || (ratio_j == ratio_i && index[j] < index[i])) {
                    // Swap time
                    int temp = time[i];
                    time[i] = time[j];
                    time[j] = temp;

                    // Swap fine
                    temp = fine[i];
                    fine[i] = fine[j];
                    fine[j] = temp;

                    // Swap index
                    temp = index[i];
                    index[i] = index[j];
                    index[j] = temp;
                }
            }
        }

        // Print result
        for (int i = 0; i < N; i++) {
            printf("%d", index[i]);
            if (i < N - 1) printf(" ");
        }
        printf("\n");
        if (T) printf("\n");
    }

    return 0;
}
