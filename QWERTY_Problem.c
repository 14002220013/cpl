#include <stdio.h>

#include <string.h>

#include <ctype.h>


int main() {

char input[100];

printf("Enter a string: ");

fgets(input, sizeof(input), stdin);


// QWERTY keyboard rows

char row1[] = "qwertyuiop[]";

char row2[] = "asdfghjkl;'";

char row3[] = "zxcvbnm,./";


int i, j;

char ch, leftChar;


for (i = 0; input[i] != '\0'; i++) {


ch = tolower(input[i]);


// Special handling for space

if (ch == ' ') {

printf(" ");

continue;

}


// Ignore 'q', 'a', 'z'

if (ch == 'q' || ch == 'a' || ch == 'z') {

continue;

}


leftChar = '\0'; // Reset


// Check in row1

for (j = 0; j < strlen(row1); j++) {

if (row1[j] == ch && j > 0) {

leftChar = row1[j - 1];

break;

}

}


// Check in row2

if (leftChar == '\0') {

for (j = 0; j < strlen(row2); j++) {

if (row2[j] == ch && j > 0) {

leftChar = row2[j - 1];

break;

}

}

}


// Check in row3

if (leftChar == '\0') {

for (j = 0; j < strlen(row3); j++) {

if (row3[j] == ch && j > 0) {

leftChar = row3[j - 1];

break;

}

}

}


if (leftChar != '\0') {

printf("%c", leftChar);

}

}


printf("\n");

return 0;

}