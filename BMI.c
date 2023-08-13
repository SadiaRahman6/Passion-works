#include <stdio.h>


#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"


double calculateBMI(double weight, int feet, int inches) {
    double heightInMeters = (feet * 12 + inches) * 0.0254;
    return weight / (heightInMeters * heightInMeters);
}

int main() {
    double weight;
    int feet, inches;

    printf("Enter your weight in kilograms: ");
    scanf("%lf", &weight);

    printf("\nEnter your height in feet and inches (e.g. 5 8): ");
    scanf("%d %d", &feet, &inches);

    double bmi = calculateBMI(weight, feet, inches);
    printf("\nYour BMI is: %.2f\n", bmi);

    if (bmi < 16.0) {
        printf(COLOR_RED "\nYou are severely underweight.\n");
    } else if (bmi >= 16.0 && bmi < 16.9) {
        printf(COLOR_RED "\nYou are underweight.\n");
    } else if (bmi >= 17.0 && bmi < 18.4) {
        printf(COLOR_YELLOW "\nYou are mildly underweight.\n");
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf(COLOR_GREEN "\nYou are normal weight.\n");
    } else if (bmi >= 25.0 && bmi < 29.9) {
        printf(COLOR_YELLOW "\nYou are overweight.\n");
    } else if (bmi >= 30.0 && bmi < 34.9) {
        printf(COLOR_RED "\nYou are moderately obese.\n");
    } else if (bmi >= 35.0 && bmi < 39.9) {
        printf(COLOR_RED "\nYou are severely obese.\n");
    } else {
        printf(COLOR_RED "\nYou are very severely obese.\n");
    }

    printf(COLOR_RESET);

    printf("\nIdeal BMI range: ");
    if (bmi < 18.5) {
        printf("16.0 - 18.4\n");
    } else if (bmi >= 18.5 && bmi < 25.0) {
        printf("18.5 - 24.9\n");
    } else {
        printf("18.5 - 24.9\n");
    }

    return 0;
}
