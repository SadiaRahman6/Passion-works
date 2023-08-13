#include <stdio.h>
#include <string.h>

// Function to convert English text to "Arabic" phonetically similar text
void convertToArabic(char *input) {
    int length = strlen(input);
    
    for (int i = 0; i < length; i++) {
        char c = input[i];
        switch (c) {
            case 'a': case 'A':
                printf("ا");
                break;
            case 'b': case 'B':
                printf("ب");
                break;
            case 'c': case 'C':
                printf("س");
                break;
            case 'd': case 'D':
                printf("د");
                break;
            case 'e': case 'E':
                printf("ا");
                break;
            case 'f': case 'F':
                printf("ف");
                break;
            case 'g': case 'G':
                printf("ج");
                break;
            case 'h': case 'H':
                printf("ه");
                break;
            case 'i': case 'I':
                printf("اي");
                break;
            case 'j': case 'J':
                printf("ج");
                break;
            case 'k': case 'K':
                printf("ك");
                break;
            case 'l': case 'L':
                printf("ل");
                break;
            case 'm': case 'M':
                printf("م");
                break;
            case 'n': case 'N':
                printf("ن");
                break;
            case 'o': case 'O':
                printf("او");
                break;
            case 'p': case 'P':
                printf("ب");
                break;
            case 'q': case 'Q':
                printf("ك");
                break;
            case 'r': case 'R':
                printf("ر");
                break;
            case 's': case 'S':
                printf("س");
                break;
            case 't': case 'T':
                printf("ت");
                break;
            case 'u': case 'U':
                printf("يو");
                break;
            case 'v': case 'V':
                printf("ف");
                break;
            case 'w': case 'W':
                printf("و");
                break;
            case 'x': case 'X':
                printf("كس");
                break;
            case 'y': case 'Y':
                printf("اي");
                break;
            case 'z': case 'Z':
                printf("ز");
                break;
            default:
                printf("%c", c);
        }
    }
    printf("\n");
}

int main() {
    char input[100];
    
    printf("Enter English text: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from fgets
    input[strcspn(input, "\n")] = '\0';
    
    printf("Phonetically similar 'Arabic' text: ");
    convertToArabic(input);
    
    return 0;
}
