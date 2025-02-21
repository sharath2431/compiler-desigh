#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring(char *nt, char *p1, char *p2) {
    int i = 0;
    while (p1[i] && p2[i] && p1[i] == p2[i]) i++;
    if (i > 0) {
        printf("%s -> %.*s%s'\n%s' -> %s | %s\n", nt, i, p1, nt, nt, p1 + i, p2 + i);
    } else {
        printf("No left factoring needed.\n");
    }
}

int main() {
    char nt[10], p1[100], p2[100];
    printf("Enter non-terminal: ");
    scanf("%s", nt);
    printf("Enter first production: ");
    scanf("%s", p1);
    printf("Enter second production: ");
    scanf("%s", p2);
    eliminateLeftFactoring(nt, p1, p2);
    return 0;
}

