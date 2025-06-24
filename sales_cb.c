#include <stdio.h>

#define MAX 5

int main() {
int sock_count[MAX] = {0};
int n, sock_type;

printf("Enter the total number of socks: ");
scanf("%d", &n);

int socks[n];
printf("Enter the types of socks (between 0 and 4):\n");
for (int i = 0; i < n; i++) {
scanf("%d", &sock_type);
if (sock_type >= 0 && sock_type < MAX) {
socks[i] = sock_type;
} else {
printf("Invalid sock type. Please enter a type between 0 and 4.\n");
i--; // To re-enter the sock type
}
}

for (int i = 0; i < n; i++) {
sock_count[socks[i]]++;
}

printf("\nMatching pairs of socks for each type:\n");
for (int i = 0; i < MAX; i++) {
if (sock_count[i] > 0) {
int type_pairs = sock_count[i] / 2;
if (type_pairs > 0) {
printf("Sock type %d: %d pairs\n", i, type_pairs);
}
}
}
printf("\nUnmatched socks for each type:\n");

for (int i = 0; i < MAX; i++) {

if (sock_count[i] % 2 != 0) {

printf("Sock type %d: %d left unmatched\n", i, sock_count[i] % 2);

}

}


printf("\n");

return 0;
}