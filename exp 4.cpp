#include <stdio.h>
void countWhitespacesAndNewlines(const char *input, int *whitespaceCount, int *newlineCount) {
    *whitespaceCount = 0;
    *newlineCount = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\t') {
            (*whitespaceCount)++;
        } else if (input[i] == '\n') {
            (*newlineCount)++;
        }
    }
}

int main() {
    char input[1000];
    int whitespaceCount, newlineCount;
    printf("Enter the text (Press Ctrl+D to end input on Unix/Linux, Ctrl+Z on Windows):\n");
    fgets(input, sizeof(input), stdin);
    countWhitespacesAndNewlines(input, &whitespaceCount, &newlineCount);
    printf("Number of whitespaces: %d\n", whitespaceCount);
    printf("Number of newline characters: %d\n", newlineCount);
    
    return 0;
}

