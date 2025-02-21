#include <stdio.h>
#include <string.h>
int isSingleLineComment(char *line) 
{
    return (strncmp(line, "//", 2) == 0);
}
int isMultiLineComment(char *line) 
{
    return (strncmp(line, "/*", 2) == 0);
}
int main() {
    char code[1000];

    printf("Enter a line of code:\n");
    fgets(code, sizeof(code), stdin); 

    if (isSingleLineComment(code)) {
        printf("This is a Single-line comment.\n");
    } else if (isMultiLineComment(code)) {
        printf("This is a Multi-line comment.\n");
    } else {
        printf("This is NOT a comment.\n");
    }

    return 0;
}
