#include <stdio.h>
#include <string.h>

void convertToArabicPronunciation(const char *english, char *arabic, int maxLength) {
    const char *englishLetters = "abcdefghijklmnopqrstuvwxyz";
    const char *arabicLetters[] = {
        "ا", "ب", "ك", "د", "اي", "اف", "جي", "ايتش", "اي", "جي", "كاي", "ايم", "اين",
        "او", "بي", "كيو", "ار", "اس", "تي", "يو", "في", "دبليو", "اكس", "واي", "زي"
    };

    int length = strlen(english);
    if (length >= maxLength) {
        printf("Input too long to convert.\n");
        return;
    }

    for (int i = 0; i < length; i++) {
        char ch = english[i];
        if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a';
            strcat(arabic, arabicLetters[index]);
        } else {
            strncat(arabic, &ch, 1);
        }
    }
}

int main() {
    char english[100];
    char arabic[300] = ""; // Assuming the result won't exceed 300 characters

    printf("Type in English: ");
    fgets(english, sizeof(english), stdin);
    english[strcspn(english, "\n")] = '\0'; // Remove the newline character

    convertToArabicPronunciation(english, arabic, sizeof(arabic));

    printf("Arabic Pronunciation: %s\n", arabic);

    return 0;
}
