#include <stdio.h>

int min_steps(int x, int y) {
    int dist = y - x;
    int step = 1;
    int total = 0;
    int count = 0;

    while (total < dist) {
        count++;
        total += step;
        if (count % 2 == 0) step++;
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int x[n], y[n], results[n];

    // Read all inputs
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Compute results
    for (int i = 0; i < n; i++) {
        results[i] = min_steps(x[i], y[i]);
    }

    // Print results
    for (int i = 0; i < n; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}
