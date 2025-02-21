#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *input;
int index = 0;

void E();
void T();
void F();

void error() {
    printf("Error in parsing\n");
    exit(1);
}

void match(char expected) {
    if (input[index] == expected) {
        index++;
    } else {
        error();
    }
}

void E() {
    T();
    while (input[index] == '+') {
        match('+');
        T();
    }
}

void T() {
    F();
    while (input[index] == '*') {
        match('*');
        F();
    }
}

void F() {
    if (isalnum(input[index])) {
        index++;
    } else if (input[index] == '(') {
        match('(');
        E();
        match(')');
    } else {
        error();
    }
}

int main() {
    char expr[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);
    input = expr;
    E();
    if (input[index] == '\0') {
        printf("Parsing successful\n");
    } else {
        error();
    }
    return 0;
}

