# CIS204-ai-research

# Program Purpose

This program is a text-based slot machine. The user enters their name, selects a starting coin balance, and a bet amount for each round, then spins for a prize.

What problem does your program solve for users?
The program does not solve a problem, except boredom. Give the user something to do in their free time.

What does your program do? Again, use your creativity here.
The program randomly generates three symbols (plaintext) per spin from a pool of five: Cherry (Chr), Lemon (LMN), Bell (BEL), Star (STR), Diamond (DIA). Different combinations yield different rewards, and 3 diamonds constitute a jackpot. At the end of the Player's game, whether they exit or run out of coins, the program will print the number of spins, the coins won, the coins lost, and the ending balance.

## Input, Output, and Memory Management

User Output will include:
- Their name
- Starting coin balance
- Bet amount each round
- And the desire to continue to play, yes or no

Output:
The program will output
- the three symbols the user spum
- An end-of-game message
- A summary of the user's earning loss and current balance

Variables:
The program will need to define the following variables:
- Player(struct
- bet(int)
- payout(int)
- text-based sybmols(chr)
- play(again)

How much memory will your program require to operate?

| Variable | Memory |
|---|---|
| char name[50] | 50 bytes |
| int coins | 4 bytes |
| int totalWon | 4 bytes |
| int totalLost | 4 bytes |
| int spins | 4 bytes |
| int bet | 4 bytes |
| int payout | 4 bytes |
| char sybmolb1|10 bytes|
| char symbol2|10 bytes|
| char synbol3| 10 bytes
| char playAgain | 1 byte |

The program uses about 105 bytes.

## Functions Needed

- int spin(char symbol1[], char symbol2[], char symbol3[]);
- void updateCoins(Player *player, int bet, int payout);
- void printResult(char symbol1[], char symbol2[], char symbol3[], int bet, int payout);
- void printSummary(Player *player);


## Data Structures

The Player struct has five members: name, coins, totalWon, totalLost, and spins.

## File Responsibilities

- **main.c** - runs the game loop and handles user input.
- **slot_machine.h** - stores the struct and function names.
- **slot_helpers.c** - stores what each function actually does.

## AI Strategy

My strategy for using AI is to break each task down and be as specific as possible about what I need, so instead of dumping the ReadMe into the prompt box and hoping for a finished program, I do. If I am too vague about what I want, I end up with a program that is only half-working or something I didn't initially want. Vague prompts make Copilot guess, and when it guesses, it usually gets it wrong. I will structure prompts using prompt engineering best practices, such as providing Copilot with clear context, a specific task, any constraints it needs to respect, and the exact output format I want.

I started with the struct, then moved to each function individually, and finally wired everything together. I will review the code to make sure I actually understand it before accepting it. As many sites I reviewed stated, AI will confidently suggest the wrong things. I will ask it to explain anything I didn't recognize. I will test each piece of code provided and ensure that everything is working as intended and outputting exactly what I requested.

## AI Prompts

1. Write a C struct called Player with fields for name and coins.
2. Write a C function called updateCoins that takes the memory address of Player and an integer. Add the integer to the Player's coins.
3. Write a main function that creates a Player, calls updateCoins, and prints the result.
