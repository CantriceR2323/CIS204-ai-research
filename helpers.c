#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int spin(char symbol1[], char symbol2[], char symbol3[])
{
    // Choose three random symbols from the slot machine pool and assign them to symbol1, symbol2, and symbol3.
    // For example purposes, let's assume we have a predefined array of symbols.
    const char *symbols[] = {"Cherry", "Lemon", "Bell", "Bar", "Seven"};
     int numSymbols = sizeof(symbols) / sizeof(symbols[0]);

    // Generate random indices for each symbol position.
    int index1 = rand() % numSymbols;
    int index2 = rand() % numSymbols;
    int index3 = rand() % numSymbols;
    // Copy the selected symbol names into symbol1, symbol2, and symbol3.
    strcpy(symbol1, symbols[index1]);
    strcpy(symbol2, symbols[index2]);
    strcpy(symbol3, symbols[index3]);

    // Determine payout based on matches
    if (strcmp(symbol1, symbol2) == 0 && strcmp(symbol2, symbol3) == 0) {
        // All three symbols match
        return 10; // Example payout multiplier for three of a kind
    } else if (strcmp(symbol1, symbol2) == 0 || strcmp(symbol2, symbol3) == 0 || strcmp(symbol1, symbol3) == 0) {
        // Two symbols match
        return 5; // Example payout multiplier for two of a kind
    } else {
        // No symbols match
        return 0; // No payout
    }
}

void updateCoins(Player *player, int bet, int payout)
{
    /// Every spin costs the bet upfront, so subtract the bet from player->coins at the start of the function.  
        player->coins -= bet;
        player->spins += 1; // Increment the number of spins

    // If payout is positive, add the winnings to player->coins.
        if (payout > 0) {
            int winnings = bet * payout; // Calculate total winnings based on bet and payout multiplier
            player->coins += winnings;
            player->totalWon += winnings; // Update total winnings
        } else {
            player->totalLost += bet; // Update total losses
        }
}

void printResult(const char symbol1[], const char symbol2[], const char symbol3[], int bet, int payout)
{
    // Print the three symbols from the current spin.
        printf("Spin result: %s | %s | %s\n", symbol1, symbol2, symbol3);
    // Print whether the player won or lost and how much.
        if (payout > 0) {
            int winnings = bet * payout; // Calculate total winnings based on bet and payout multiplier
            printf("Congratulations! You won %d coins!\n", winnings);
        } else {
            printf("Sorry, you lost %d coins.\n", bet);
        }
    // Use bet and payout to explain the result clearly.    
}

void printSummary(const Player *player)
{
    // Print the final game summary for the player.
    // Include number of spins, total winnings, total losses, and ending balance.
    printf("Game Summary:\n");
    printf("Spins: %d\n", player->spins);
    printf("Total Won: %d\n", player->totalWon);
    printf("Total Lost: %d\n", player->totalLost);
    printf("Ending Balance: %d\n", player->coins);
}
