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
    while (input[index] == '+' || input[index] == '-') {
        char op = input[index];
        match(op);
        T();
        printf("Processed operator: %c\n", op);
    }
}

void T() {
    F();
    while (input[index] == '*' || input[index] == '/') {
        char op = input[index];
        match(op);
        F();
        printf("Processed operator: %c\n", op);
    }
}

void F() {
    if (isalnum(input[index])) {
        printf("Processed operand: %c\n", input[index]);
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
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    input = expr;
    E();
    if (input[index] == '\0') {
        printf("Parsing successful\n");
    } else {
        error();
    }
    return 0;
}
