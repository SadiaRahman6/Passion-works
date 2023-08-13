#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToArabic(char *english, char *arabic) {
    // Basic mapping for demonstration purposes
    const char *englishChars = "abcdefghijklmnopqrstuvwxyz";
    const char *arabicChars = "أبثدإفغحيجكلمنوبفبغرستثفخجلمنهوببيز";
    
    for (int i = 0; i < strlen(english); i++) {
        if (isalpha(english[i])) {
            char *pos = strchr(englishChars, tolower(english[i]));
            if (pos) {
                int index = pos - englishChars;
                arabic[i] = arabicChars[index];
            } else {
                arabic[i] = english[i];  // Keep non-mapped characters as-is
            }
        } else {
            arabic[i] = english[i];  // Keep non-alphabetic characters as-is
        }
    }
    arabic[strlen(english)] = '\0';
}

int main() {
    char english[100];
    char arabic[100];
    
    printf("Type in English: ");
    fgets(english, sizeof(english), stdin);
    english[strlen(english) - 1] = '\0';  // Remove newline character
    
    convertToArabic(english, arabic);
    
    printf("Equivalent Arabic: %s\n", arabic);
    
    return 0;
}
