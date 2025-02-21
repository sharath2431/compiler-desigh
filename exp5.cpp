#include <stdio.h>
#include <ctype.h>
int isValidIdentifier(const char *identifier) {
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0; 
    }
    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }
    return 1; 
}
int main() {
    char identifier[100];
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("'%s' is a valid identifier.\n", identifier);
    } else {
        printf("'%s' is not a valid identifier.\n", identifier);
    }
    return 0;
}

