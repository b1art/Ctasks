#include <stdio.h>

void blanks(char* s) {
    int c_spaces = 0;
    int c_tabs = 0;
    int c_lines = 0;
    while (*s!='\0') {
        if (*s == ' ') {
            c_spaces++;
            s++;
        } else if (*s == '\t') {
            c_tabs++;
            s++;
        } else if (*s == '\n') {
            c_lines++;
            s++;
        } else {
            s++;
        }
    }
    printf("There are %d spaces, %d tabs and %d new lines.\n", c_spaces, c_tabs, c_lines);
}

void byLines(char* s)
{
    while (*s != '\0') {
        if (*s != ' ') {
            printf("%c", *s);
            s++;
        } else {
            printf("\n");
            s++;
        }
    }
    printf("\n");
}

void long80(char* s) {
    if (strlen(s) > 80) {
        while (*s != '\0') {
            printf("%c", *s);
            s++;
        }
        printf("\n");
    } else {
        printf("Less than 80 symbols!\n");
    }
}

void histogramm(char* s) {
    int c = 0;
    while (*s != '\0') {
       if (*s != ' ') {
            c++;
            s++;
        } else {
            while (c != 0) {
                printf("[]");
                c--;
            }
            printf("\n");
            c = 0;
            s++;
        }
    }
    while (c != 0) {
        printf("[]");
        c--;
    }
}



void reverse(char* s) {
    int len = strlen(s);
    char myString[len];
    int i;
    for (i = len - 1; i >= 0; i--) {
        if (*s == '\0') {
            break;
        }
        myString[i] = *s;
        s++;
    }
    for (i = 0; i < len; i++) {
        printf("%c", myString[i]);
    }
}

int main() {
    printf("Blanks and stuff.\n________\n");
    blanks("This is  a totally   random text.\t\n Another part of\t it.\n The end. ");
    printf("\n\nBy lines.\n________\n");
    byLines("Advantages and disadvantages of traveling by air.");
    printf("\n\nBar chart.\n________\n");
    histogramm("Pain demands to be felt.");
    printf("\n\nLength 80.\n________\n");
    long80("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    long80("\n\nShort string");
    printf("\n\nReverse.\n________\n");
    reverse("sdrawkcab delleps ratS");
}
