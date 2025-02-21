#include <stdio.h>

int main() {
    char input[100];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);
    
    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            printf("%c ", input[i]);
    
    return 0;
}
