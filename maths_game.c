#include <stdio.h> 

  

int main() { 

    int product = 1; 

    int choice; 

    char currentPlayer = 'A'; 

  

    const int MAX_LIMIT = 500; 

  

    printf(" Welcome to the Multiplication Maths Game!\n"); 

    printf("Two players (A and B) take turns picking a number from 2 to 9.\n"); 

    printf("Each number is multiplied with the running total.\n"); 

    printf("Whoever causes the product to exceed %d wins!\n\n", MAX_LIMIT); 

  

    while (product <= MAX_LIMIT) { 

        printf("Player %c, enter a number (2-9): ", currentPlayer); 

        scanf("%d", &choice); 

  

        // Validate the input 

        if (choice < 2 || choice > 9) { 

            printf(" Invalid input. Please enter a number between 2 and 9.\n"); 

            continue; // Ask the same player again 

        } 

  

        product *= choice; 

  

        printf("Current product: %d\n", product); 

  

        if (product > MAX_LIMIT) { 

            printf(" Player %c wins by exceeding %d!\n", currentPlayer, MAX_LIMIT); 

            break; 

        } 

  

        // Switch player 

        currentPlayer = (currentPlayer == 'A') ? 'B' : 'A'; 

    } 

  

    printf("Game Over. Final product: %d\n", product); 

  

    return 0; 

} 

 

Picture 