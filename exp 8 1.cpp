#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct Symbol {
    char name[MAX];
    char type[MAX];
    struct Symbol *next;
} Symbol;
Symbol *head = NULL; 
void insert(char *name, char *type){
    Symbol *newSymbol = (Symbol *)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    strcpy(newSymbol->type, type);
    newSymbol->next = head;
    head = newSymbol;
    printf("Inserted: %s -> %s\n", name, type);
}
Symbol* search(char *name) {
    Symbol *temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void display() {
    Symbol *temp = head;
    printf("\nSymbol Table:\n");
    printf("---------------------\n");
    printf("Name\tType\n");
    printf("---------------------\n");
    while (temp) {
        printf("%s\t%s\n", temp->name, temp->type);
        temp = temp->next;
    }
    printf("---------------------\n");
}
int main() {
    int choice;
    char name[MAX], type[MAX];
    Symbol *found;

    while (1) {
        printf("\nSymbol Table Operations:\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To handle newline character
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter type: ");
                scanf("%s", type);
                insert(name, type);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                found = search(name);
                if (found)
                    printf("Found: %s -> %s\n", found->name, found->type);
                else
                    printf("Symbol not found!\n");
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

