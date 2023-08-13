#include <stdio.h>


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int start, end, count = 0;

    printf("Enter the first number: ");
    scanf("%d", &start);

    printf("Enter the second number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    for (int num = start; num <= end; ++num) {
        if (is_prime(num)) {
            printf(RED "%d " RESET, num);
            ++count;
        }
    }

    printf("\nTotal prime numbers: " GREEN "%d\n" RESET, count);

    return 0;
}
