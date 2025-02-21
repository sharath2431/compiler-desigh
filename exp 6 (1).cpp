#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char *nonTerminal, char *productions) 
{
    if (productions[0] == nonTerminal[0]) 
	{
        printf("%s -> %s%s'\n", nonTerminal, productions + 1, nonTerminal);
        printf("%s' -> e\n", nonTerminal);
    }
	 else 
	 {
        printf("No left recursion found.\n");
    }
}

int main() 
{
    char nonTerminal[10], productions[100];
    printf("Enter the non-terminal: ");
    scanf("%s", nonTerminal);
    printf("Enter the productions: ");
    scanf("%s", productions);
    eliminateLeftRecursion(nonTerminal, productions);
    return 0;
}

