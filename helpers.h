#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>

typedef struct {
    char name[50];
    int coins;
    int totalWon;
    int totalLost;
    int spins;
} Player;

int spin(char symbol1[], char symbol2[], char symbol3[]);
void updateCoins(Player *player, int bet, int payout);
void printResult(const char symbol1[], const char symbol2[], const char symbol3[], int bet, int payout);
void printSummary(const Player *player);

#endif // HELPERS_H
