  #include <stdio.h>
  #include <windows.h>

  #define AC_RED "\x1b[31m"
  #define AC_YELLOW "\x1b[33m"
  #define AC_GREEN "\x1b[32m"
  #define AC_NORMAL "\x1b[0m"


  int main()

  {

   char yrn[] = "Md. Tanvir Ahsan";
   int idn;
   double cdn;
   printf("Your name is %s.", yrn);
   printf("\n\nWhat is your ID number? Ans: ");
   scanf("%d", &idn);
   printf("\nWhat is your code number? Ans: ");
   scanf("%lf", &cdn);
   printf("\n\nYour ID number is %d, and your code number is %f", idn, cdn,AC_GREEN,AC_NORMAL);

    float inches, centimeters;
    const float inches_to_cm = 2.54;

    printf("\n\nEnter the length in inches: ");
    scanf("%f", &inches);

    centimeters = inches * inches_to_cm;

    printf("\n\n%.2f inches is equal to %.2f centimeters.", inches, centimeters);

    float celsius, fahrenheit;
    const float celsius_to_fahrenheit =  (celsius * 9 / 5) + 32;

    printf("\n\nEnter the temperature in celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf ("\n\n%.2f degree celsius is equal to %.2f degree fahrenheit.", celsius, fahrenheit);

    printf("\n\n%sNVA miss said, \"Quiz on next Tuesday. And attendance should be 100%%."%s\",AC_RED,AC_NORMAL);

    printf("%s\n\n\n\t\t\tWritten by Md. Tanvir Ahsan (2322663)\t%s",AC_YELLOW,AC_NORMAL);

    Beep(540, 1000);

    return 0;

    }
