#include <stdio.h>

void printRightAngleTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printInvertedRightAngleTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHollowRightAngleTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printHollowInvertedRightAngleTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printRightAngleTriangleNumbers(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printNumberPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("%d", k);
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedHollowPyramid(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1 || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printMirroredRightAngleTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printMirroredInvertedRightAngleTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHourglassPattern(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

void printSpiralPattern(int n) {
    int totalElements = n * n;
    int matrix[n][n];
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int value = 1;

    while (value <= totalElements) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = value++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = value++;
        }
        left++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter the number of rows for the patterns: ");
    scanf("%d", &rows);

    printf("\nRight-Angled Triangle:\n");
    printRightAngleTriangle(rows);

    printf("\nInverted Right-Angled Triangle:\n");
    printInvertedRightAngleTriangle(rows);

    printf("\nHollow Right-Angled Triangle:\n");
    printHollowRightAngleTriangle(rows);

    printf("\nHollow Inverted Right-Angled Triangle:\n");
    printHollowInvertedRightAngleTriangle(rows);

    printf("\nRight-Angled Triangle with Numbers:\n");
    printRightAngleTriangleNumbers(rows);

    printf("\nNumber Pyramid:\n");
    printNumberPyramid(rows);

    printf("\nDiamond:\n");
    printDiamond(rows);

    printf("\nInverted Hollow Pyramid:\n");
    printInvertedHollowPyramid(rows);

    printf("\nMirrored Right-Angled Triangle:\n");
    printMirroredRightAngleTriangle(rows);

    printf("\nMirrored Inverted Right-Angled Triangle:\n");
    printMirroredInvertedRightAngleTriangle(rows);

    printf("\nHourglass Pattern:\n");
    printHourglassPattern(rows);

    printf("\nSpiral Pattern:\n");
    printSpiralPattern(rows);

    return 0;
}
