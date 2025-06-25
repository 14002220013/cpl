#include <stdio.h>

#include <string.h>

#include <ctype.h>


#define MAX_LEN 150

#define MAX_RUNS 100


// Function to extract digits only

void extract_digits(char *src, char *digits) {

int j = 0;

for (int i = 0; src[i]; i++) {

if (isdigit(src[i])) {

digits[j++] = src[i];

}

}

digits[j] = '\0';

}


// Function to check if two strings match exactly

int is_exact_match(char *s1, char *s2) {

return strcmp(s1, s2) == 0;

}


// Function to check if digit sequences match

int is_digit_match(char *s1, char *s2) {

char digits1[MAX_LEN], digits2[MAX_LEN];

extract_digits(s1, digits1);

extract_digits(s2, digits2);

return strcmp(digits1, digits2) == 0;

}


int main() {

int runs;

char standard[MAX_LEN], team[MAX_LEN];


printf(" Enter number of test runs: ");

scanf("%d", &runs);

getchar(); // clear newline


for (int i = 1; i <= runs; i++) {

printf("\nRun #%d:\n", i);


printf(" Enter Standard Solution: ");

fgets(standard, MAX_LEN, stdin);

standard[strcspn(standard, "\n")] = '\0'; // Remove newline


printf("Enter Team Output: ");

fgets(team, MAX_LEN, stdin);

team[strcspn(team, "\n")] = '\0'; // Remove newline


if (is_exact_match(standard, team)) {

printf("Run #%d: Accepted\n", i);

} else if (is_digit_match(standard, team)) {

printf("Run #%d: Presentation Error\n", i);

} else {

printf("Run #%d: Wrong Answer\n", i);

}

}


return 0;

}