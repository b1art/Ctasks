#include <stdio.h>


int main(){

    double n = 5, current, sum = 0;

    printf("Input numbers:\n");

    int i;
    for (i = 0; i < n; i++) {
        scanf("%lf", &current);
        sum += current;
    }

    printf("The answer is %f", sum / n);

    return 0;
}
