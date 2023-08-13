#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Color codes
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_RESET "\x1b[0m"

// Player stats
int playerHealth = 100;
int playerCoins = 0;
int playerLevel = 1;

// Function to simulate a battle
void battle() {
    printf("A wild enemy appears!\n");

    int enemyHealth = 50 + (playerLevel - 1) * 10; // Scales with player level

    while (playerHealth > 0 && enemyHealth > 0) {
        int playerAttack = rand() % 20 + 5;
        int enemyAttack = rand() % 15 + 3;

        printf("Player Health: " COLOR_GREEN "%d" COLOR_RESET "  |  Coins: " COLOR_YELLOW "%d" COLOR_RESET "  |  Level: %d\n", playerHealth, playerCoins, playerLevel);
        printf("Enemy Health: " COLOR_RED "%d" COLOR_RESET "\n", enemyHealth);
        printf("1. Attack\n");
        printf("2. Use Potion (+20 health, -10 coins)\n");
        printf("3. Run\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enemyHealth -= playerAttack;
                printf("You hit the enemy for %d damage!\n", playerAttack);
                break;
            case 2:
                if (playerCoins >= 10) {
                    playerCoins -= 10;
                    playerHealth += 20;
                    printf("You used a potion and gained 20 health!\n");
                } else {
                    printf("You don't have enough coins for a potion!\n");
                }
                break;
            case 3:
                printf("You managed to escape!\n");
                return;
            default:
                printf("Invalid choice!\n");
                break;
        }

        if (enemyHealth > 0) {
            playerHealth -= enemyAttack;
            printf("The enemy hits you for %d damage!\n", enemyAttack);
        }
    }

    if (playerHealth <= 0) {
        printf("You were defeated!\n");
    } else {
        int coinsEarned = rand() % 20 + 10 + (playerLevel - 1) * 5; // Scales with player level
        playerCoins += coinsEarned;
        printf("You defeated the enemy and earned " COLOR_YELLOW "%d" COLOR_RESET " coins!\n", coinsEarned);
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Ultimate RPG Adventure!\n");
    printf("You are a legendary hero embarking on an epic quest.\n");

    while (playerHealth > 0) {
        printf("1. Continue exploring\n");
        printf("2. Visit the Shop\n");
        printf("3. Check inventory\n");
        printf("4. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                battle();
                // Level up if enough experience earned
                if (playerCoins >= playerLevel * 50) {
                    playerCoins -= playerLevel * 50;
                    playerLevel++;
                    printf("Congratulations! You leveled up to level %d!\n", playerLevel);
                }
                break;
            case 2:
                printf("Welcome to the Shop!\n");
                printf("1. Buy Potion (+20 health) - 10 coins\n");
                printf("2. Leave Shop\n");

                int shopChoice;
                printf("Enter your choice: ");
                scanf("%d", &shopChoice);

                switch (shopChoice) {
                    case 1:
                        if (playerCoins >= 10) {
                            playerCoins -= 10;
                            playerHealth += 20;
                            printf("You bought a potion and gained 20 health!\n");
                        } else {
                            printf("You don't have enough coins to buy a potion!\n");
                        }
                        break;
                    case 2:
                        printf("Thank you for visiting the Shop!\n");
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
            case 3:
                printf("Current Health: " COLOR_GREEN "%d" COLOR_RESET "\n", playerHealth);
                printf("Coins: " COLOR_YELLOW "%d" COLOR_RESET "\n", playerCoins);
                printf("Level: %d\n", playerLevel);
                break;
            case 4:
                printf("Thanks for playing!\n");
                printf(COLOR_GREEN "Made by Zombie12k\n" COLOR_RESET);
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    printf("Game over! Your adventure ends.\n");
    printf(COLOR_GREEN "\n\nMade by Zombie12k\n" COLOR_RESET);
    return 0;
}
