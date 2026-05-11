#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helpers.h"


int main(void)
{
    //seed the random number generator
    srand((unsigned int)time(NULL));

    // Create a Player instance and initialize its fields.
    Player player;
    player.name[0] = '\0';
    player.coins = 0;
    player.totalWon = 0;
    player.totalLost = 0;
    player.spins = 0;


    // Prompt the user for their name and store it in player.name.  
    // Example: "Enter your name: "
        printf("Enter your name: ");
        scanf("%49s", player.name); // Limit input to 49 characters to prevent overflow

    // Prompt the user for a starting coin balance and store it in player.coins.
    // Example: "Enter starting coin balance: " 
        printf("Enter starting coin balance: ");
        scanf("%d", &player.coins);

    // Initialize player.totalWon, player.totalLost, and player.spins to zero.
        player.totalWon = 0;
        player.totalLost = 0;
        player.spins = 0;

    // Game loop begins here.       
    // Use a char variable or boolean flag to track whether the player wants to play again.
        char playAgain = 'y'; // Initialize to 'y' to enter the loop

    // Inside the loop: 

    // - Prompt the user for a bet amount.
    // - Call spin(...) to generate symbols and determine payout.
    // - Call updateCoins(...) to adjust the player's balance.
    // - Call printResult(...) to display the spin outcome.
    // - Ask the user if they want to play another round.
    // - Exit the loop if they answer no or if player.coins is zero or less.
        while (playAgain == 'y' && player.coins > 0) {
            int bet;
            printf("Enter your bet amount: ");
            scanf("%d", &bet);

            // Validate bet amount
            if (bet <= 0 || bet > player.coins) {
                printf("Invalid bet amount. Please enter a positive number up to your current balance.\n");
                continue; // Skip the rest of the loop and prompt again
            }

            char symbol1[20], symbol2[20], symbol3[20];
            int payout = spin(symbol1, symbol2, symbol3);
            updateCoins(&player, bet, payout);
            printResult(symbol1, symbol2, symbol3, bet, payout);

            if (player.coins <= 0) {
                printf("You have run out of coins! Game over.\n");
                break; // Exit the loop if the player has no more coins
            }

            printf("Do you want to play another round? (y/n): ");
            scanf(" %c", &playAgain); // Note the space before %c to consume any leftover newline character
        }

    // After the loop finishes, call printSummary(...) to show the final results.
    printSummary(&player);


    return 0;
}
