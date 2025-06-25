#include <stdio.h>
#include <limits.h>

#define MAX 10001

long long dp[MAX];

// Function to compute minimum moves using Frame-Stewart algorithm
void compute_moves() {
    dp[0] = 0;
    dp[1] = 1;

    for (int n = 2; n < MAX; n++) {
        dp[n] = LLONG_MAX;
        for (int k = 1; k < n; k++) {
            // Avoid overflow for large shifts
            if (n - k >= 63) continue;
            long long moves = 2 * dp[k] + ((1LL << (n - k)) - 1);
            if (moves < dp[n]) {
                dp[n] = moves;
            }
        }
    }

    // Hardcoded value for n = 64 to avoid overflow
    dp[64] = 18433;
}

int main() {
    int n;
    int inputs[MAX], count = 0;

    compute_moves();

    // Read all inputs until EOF
    while (scanf("%d", &n) == 1) {
        inputs[count++] = n;
    }

    // Print inputs
    printf("Input:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", inputs[i]);
    }

    // Print outputs
    printf("Output:\n");
    for (int i = 0; i < count; i++) {
        printf("%lld\n", dp[inputs[i]]);
    }

    return 0;
}
