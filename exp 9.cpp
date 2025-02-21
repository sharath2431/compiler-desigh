#include <stdio.h>
#include <string.h>
const char *subjects[] = {"John", "Alice", "He", "She"};
const char *verbs[] = {"eats", "writes", "reads", "loves"};
const char *objects[] = {"apple", "book", "story", "poem"};

int isValidWord(const char *word, const char *list[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, list[i]) == 0) return 1;
    }
    return 0;
}

int checkGrammar(char *input) {
    char subject[20], verb[20], object[20];

    if (sscanf(input, "%s %s %s", subject, verb, object) != 3) {
        return 0; 
    }

    if (isValidWord(subject, subjects, 4) && 
        isValidWord(verb, verbs, 4) && 
        isValidWord(object, objects, 4)) {
        return 1; 
    }

    return 0; 
}

int main() {
    char input[100];

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 
    if (checkGrammar(input))
        printf("Valid sentence according to grammar!\n");
    else
        printf("Invalid sentence!\n");

    return 0;
}

