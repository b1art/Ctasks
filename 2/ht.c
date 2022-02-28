#include <stdio.h>
#include <float.h>

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    return 0;
}

int task1() {

    double amount, suc;
    double sum, q;
    sum = 0;

    printf("Input amount of numbers:\n");
    suc = scanf("%lf", &amount);

    if (suc == 0 || amount < 1) {
        printf("Wrong input.");
        return 0;
    }

    int i;
    for (i = 0; i < amount; i++) {
        suc = scanf("%lf", &q);
        if (suc == 0) {
            printf("Wrong input.");
            return 0;
        }
        sum += q;
    }

    printf("The sum is %f \n", sum);
    return 0;
}

int task2() {

    double k, suc, el;
    int ans = 0;
    printf("Input number:\n");
    suc = scanf("%lf", &k);

    if (suc == 0) {
        printf("Wrong input.");
        return 0;
    }

    int len = 5;
    int i;
    printf("Enter %d numbers: \n", len);
    for (i = 0; i < len; i++) {
        suc = scanf("%lf", &el);
        if (suc == 0) {
            printf("Wrong input.");
            return 0;
        }
        if (el > k && ans == 0) {
            ans = i + 1;
        }
    }

    if(ans == 0) {
        printf("There is no number bigger than %f \n", k);
        return 0;
    }
    printf("%d element is the first element bigger than %f", ans, k);
    return 0;
}

int task3() {
    double suc, el, pel = -DBL_MAX;
    int i, len = 5, ans = 0;

    printf("Enter %d numbers: \n", len);
    for (i = 0; i < len; i++) {
        suc = scanf("%lf", &el);
        if (suc == 0) {
            printf("Wrong input.");
            return 0;
        }
        if (el < pel) {
            ans = 1;
        }
        pel = el;
    }
    if (ans == 0) {
        printf("This sequence increases");
        return 0;
    }

    printf("This sequence does not increase");
    return 0;
}

int task4() {
    int i = 0, amount = 0;
    double cur, next;
    printf("Enter numbers: \n");
    while ((scanf("%lf",&next))&(next!=EOF)){
        i++;
        if (i == 1){
            cur = next;
        }
        else {
            if (next < cur) {
                printf("Element number %d is smaller than its left neighbor \n",i);
                amount++;
            }
            cur = next;
        }
    }
    printf("Number of elements more than their left neighbor = %d",amount);
    return 0;
}

int task5() {
    int i = 0, amount = 0;
    double next, min = DBL_MAX;
    while ((scanf("%lf",&next))&(next!=EOF)){
        i++;
        if (next < min) {
            amount = i - 1;
            min = next;
        }
    }
    printf("Number of elements before the first smallest element = %d \n",amount);
    return 0;
}

int task6() {
    int i = 0, amount = 0, next, max = 0, cur;
    printf("Enter numbers: \n");
    while ((scanf("%d",&next))&(next!=EOF)){
        i++;
        if (i == 1){
            cur = next;
            if(cur % 2 == 0){amount = 1; max = 1;}
        }
        else {
            if ((next % 2 == 0) & (cur % 2 == 0)) {
                amount++;
                if (amount > max){max = amount;}
            }
            else {
                if ((next % 2 == 0) & (cur % 2 == 1)) {
                    if (amount > max){max = amount;}
                    amount = 1;
                }
            }
            cur = next;
        }
    }
    printf("The answer is %d \n", max);
    return 0;
}

int task7() {
    int i = 0, amount = 0, next, cur;
    printf("Enter numbers: \n");
    while ((scanf("%d",&next))&(next!=EOF)){
        i++;
        if (i == 1){
            cur = next;
            amount = 1;
        }
        else {
            if (next % 2 == cur % 2) {
                amount++;
            }
            else {
                if (next % 2 == 0) {printf("There was %d odd numbers before this one. \n", amount);}
                else {printf("There was %d even numbers before this one. \n", amount);}
                amount = 1;
            }
            cur = next;
        }
}
    return 0;
}

int task8() {
    int i = 0, amount = 0, next, cur;
    printf("Enter numbers: \n");
    while ((scanf("%d",&next))&(next!=EOF)){
        i++;
        if (i == 1){
            cur = next;
            amount = 1;
        }
        else {
            if (next > cur) {
                amount++;
            }
            else {
                printf("Length of the ascending sequence is %d. \n", amount);
                amount = 1;
            }
            cur = next;
        }
    }
    return 0;
}

int task9() {
    int i = 0, amount = 0, next, cur, max = 1, pos;
    printf("Enter numbers: \n");
    while ((scanf("%d",&next))&(next!=EOF)){
        i++;
        if (i == 1){
            cur = next;
            amount = 1;
            pos = 1;
        }
        else {
            if (next == cur) {
                amount++;
                if(amount > max) {max = amount;pos = i;}
            }
            else {
                amount = 1;
            }
            cur = next;
        }
    }

    printf("The longest subsequence has %d elements and its first element position is %d. \n", max, pos - max + 1);
    return 0;
}

