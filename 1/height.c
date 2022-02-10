#include <stdio.h>

int main() {

    double cm;

    printf("What is your height in centimeters?\n");
    scanf("%lf", &cm);

    printf("Your height in inches is: %lf", cm * 2.54);

    return 0;
}
