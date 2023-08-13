#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6


void displayWord(const char *word, const char *guessed) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(guessed, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    const char *wordList[] = {"hangman", "programming", "computer", "language", "openai"};
    const int numWords = sizeof(wordList) / sizeof(wordList[0]);


    srand(time(NULL));
    int randomIndex = rand() % numWords;
    const char *selectedWord = wordList[randomIndex];
    int wordLength = strlen(selectedWord);

    char guessedLetters[26] = "";
    int triesLeft = MAX_TRIES;

    printf("Welcome to Hangman!\n");

    while (triesLeft > 0) {
        printf("\n");
        displayWord(selectedWord, guessedLetters);
        printf("Guesses left: %d\n", triesLeft);

        printf("Enter a letter: ");
        char guess;
        scanf(" %c", &guess);


        guess = tolower(guess);


        if (strchr(guessedLetters, guess) != NULL) {
            printf("You already guessed '%c'. Try again.\n", guess);
            continue;
        }

        guessedLetters[strlen(guessedLetters)] = guess;
        guessedLetters[strlen(guessedLetters)] = '\0';


        if (strchr(selectedWord, guess) != NULL) {
            printf("Correct guess!\n");


            if (strlen(guessedLetters) == strlen(selectedWord)) {
                printf("Congratulations, you guessed the word: %s\n", selectedWord);
                break;
            }
        } else {
            printf("Incorrect guess!\n");
            triesLeft--;

            if (triesLeft == 0) {
                printf("You ran out of guesses. The word was: %s\n", selectedWord);
            }
        }
    }

    return 0;
}
