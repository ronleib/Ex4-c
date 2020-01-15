//
// Created by ron on 14/01/2020.
//

#ifndef EX4_FREQUENCY_LIB_H
#define EX4_FREQUENCY_LIB_H
#define  MUN_Word ((int)26)
#define  LINE 256

typedef enum {
    FALSE=0,
    TRUE=1
} boolean;

typedef struct node {
    char letter;
    long unsigned int count;
    struct node* children [MUN_Word];
} node;

void textToTree(node *head);

void printInorder(node *node, char *string, int indexChar );

void printBackwards(node head);

void addWord(node *head, const char* p, int size);

boolean cheakChar(char index);

char convert(char index);

void freeTree(node *head);

#endif //EX4_FREQUENCY_LIB_H

