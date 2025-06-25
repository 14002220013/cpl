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
            long long moves = 2 * dp[k] + ((1LL << (n - k)) - 1);
            if (moves < dp[n]) {
                dp[n] = moves;
            }
        }
    }
}

int main() {
    int n;

    compute_moves();

    while (scanf("%d", &n) == 1) {
        printf("%lld\n", dp[n]);
    }

    return 0;
}
