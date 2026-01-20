#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#define VERSION "20250402"
#define AUTHOR "Votre Nom"
#define EMAIL "votre.email@example.com"
#define MAX_COMMAND_LENGTH 18

void print_help() {
    printf("b: Prints the base\nc: Prints the base country\nd: Prints the base date\nf: Prints the base facilities\n");
    printf("fc COST: Prints the base facilities with the cost equal to COST\n");
    printf("fcge COST: Prints the base facilities with the cost greater than or equal to COST\n");
    printf("fcgt COST: Prints the base facilities with the cost greater than COST\n");
    printf("fcle COST: Prints the base facilities with the cost less than or equal to COST\n");
    printf("fclt COST: Prints the base facilities with the cost less than COST\n");
    printf("fn NAME: Prints the base facilities with the name containing NAME\n");
    printf("h: Prints this help\nn: Prints the base name\nt: Prints the base total cost\nv: Prints the BM version\nq: Quits BM\n");
}

void print_version() {
    printf("BM (Base Manager) %s\n", VERSION);
    printf("Copyright (C) 2025 %s.\n", AUTHOR);
    printf("Written by %s <%s>.\n", AUTHOR, EMAIL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "./bm.out: Invalid number of arguments\n");
        return 1;
    }

    const char *filename = argv[1];
    xmlDoc *doc = xmlParseFile(filename);
    if (doc == NULL) {
        fprintf(stderr, "./bm.out: Unable to parse the document\n");
        return 1;
    }

    char command[MAX_COMMAND_LENGTH + 2];
    printf("BM> ");
    while (fgets(command, sizeof(command), stdin) != NULL) {
        command[strcspn(command, "\n")] = 0;  // Remove newline character
        
        if (strlen(command) > MAX_COMMAND_LENGTH) {
            printf("./bm.out: Too many characters for the command\n");
        } else if (strcmp(command, "h") == 0) {
            print_help();
        } else if (strcmp(command, "v") == 0) {
            print_version();
        } else if (strcmp(command, "q") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("./bm.out: Invalid command\n");
        }
        printf("BM> ");
    }

    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}
