#include <stdio.h>
#include <float.h>
#include <math.h>
#define swap(a, b, buff) {buff = *(b); *(b) = *(a); *(a) = buff;}

int main() {
    distance(-1,-1,1,1);
    gcd(42, 9);
    reverse(123);
    primeQ(13);
    primeQ(14);
    lower(2.,3.,1.);
    factorial(5);
}

int distance(x1,y1,x2,y2) {
    printf("The answer is %f \n", sqrt(pow(x1-x2,2)+pow(y1 - y2, 2)));
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        printf("The answer is %d \n", a);
        return 0;
    }
    else {
        return gcd(b, a % b);
    }
}

int reverse(a) {
    int b = 0;
    while(a){
        b = b*10 + (a%10);
        a /= 10;
    }
    printf("The answer is %d \n" ,b);
}

int primeQ( a) {
    if (a < 2) {
        printf("The answer is Yes \n");
        return 0;
    }
    int i = 2;
    while (i*i <= a) {
        if (a % i == 0) {
            printf("The answer is No \n");
            return 0;
        }
    i++;
    }
    printf("The answer is Yes \n");
    return 0;
}

int lower(double a, double b, double c) {
    int ans;
    if (a < b) {
        if (a < c) {
            ans = a;
        }
    }
    else {
        if (b < c) {
            ans = b;
        }
        else {
            ans = c;
        }
    }
    printf("The answer is %d \n", ans);
    return 0;
}

int factorial(int a) {
    if (a == 1) {
        return 1;
    }
    return a * factorial(a - 1);
}

