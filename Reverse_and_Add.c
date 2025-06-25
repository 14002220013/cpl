#include <stdio.h>

// Function to reverse a number
int reverse(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

// Function to check if a number is a palindrome
int is_palindrome(int num) {
    return num == reverse(num);
}

int main() {
    int num, rev, sum, count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (!is_palindrome(num)) {
        rev = reverse(num);
        sum = num + rev;
        printf("%d + %d = %d\n", num, rev, sum);
        num = sum;
        count++;
    }

    printf("Palindrome: %d\n", num);
    printf("Iterations: %d\n", count);

    return 0;
}
