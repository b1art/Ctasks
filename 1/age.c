#include <stdio.h>

int main() {

    int yr;

    printf("What is your age?\n");
    scanf("%i", &yr);

    printf("You are %i days old.", yr * 365);

    return 0;
}
