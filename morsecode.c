#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a character to Morse code
const char* charToMorse(char c) {
    switch (toupper(c)) {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return "";
    }
}

int main() {
    char input[1000];
    printf("Enter a string in English: ");
    fgets(input, sizeof(input), stdin);

    printf("Morse code translation: ");

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\n') {
            printf("   "); // Three spaces between words
        } else {
            const char* morse = charToMorse(input[i]);
            if (strlen(morse) > 0) {
                printf("%s ", morse);
            }
        }
    }

    printf("\n");
    return 0;
}
