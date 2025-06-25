#include <stdio.h>

#include <string.h>


void encrypt(char text[], int shift) {

for (int i = 0; i < strlen(text); i++) {

if (text[i] != ' ') {

text[i] = text[i] + shift;

}

}

}


void decrypt(char text[], int shift) {

for (int i = 0; i < strlen(text); i++) {

if (text[i] != ' ') {

text[i] = text[i] - shift;

}

}

}


void show_as_asterisks(char text[], char asterisks[]) {

for (int i = 0; i < strlen(text); i++) {

if (text[i] != ' ') {

asterisks[i] = '*';

} else {

asterisks[i] = ' ';

}

}

asterisks[strlen(text)] = '\0';

}


int main() {

char text[100], encrypted_text[100], asterisks[100];

int shift = 6;


printf("Enter a line to encrypt: ");

fgets(text, sizeof(text), stdin);

text[strcspn(text, "\n")] = '\0';


// strcpy(encrypted_text, text);

encrypt(text, shift);

printf("\n Encrypted line: %s\n", text);


show_as_asterisks(text, asterisks);

printf("\n Encrypted line with asterisks: %s\n", asterisks);


decrypt(text, shift);

printf("\n Decrypted line: %s\n", text);


return 0;

}