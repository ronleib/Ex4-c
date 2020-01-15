//
// Created by ron on 14/01/2020.
//
#include <stdlib.h>
#include "frequency_lib.h"
#include <stdio.h>
#define  LINE 256
#define  ascii_a 97
#define  MUN_ABC 26

void textToTree(node *head){
    char line[LINE]= {0};
    char *p ;
    int run = 0;
    int sum=0;
    while (!feof(stdin)){
        fgets(line, LINE, stdin);
        p = &line[0];
        while (line[run] != ('\0')){
            if (cheakChar(line[run])){
                sum++;
            }
            else {
                addWord(head, p, sum );
                p + sum + 1;
                sum = 0;
            }
            run++;
        }
        run = 0;
    }
}

void addWord(node *n, char* const p, int size) {
    if (size <= 0) {
        n->count++;
        return;
    }
    char* p2 = p;
    int tempChar = ((convert(*(p2))) - 'a');
    if (n->children[tempChar] == NULL) {
        node *new = (node *) malloc(sizeof(node));
        new->letter = tempChar + ascii_a;
        new->count = 0;
        n->children[tempChar] = new;
        addWord(new, p2, size - 1);
    } else {
        addWord(n->children[tempChar], p2, size - 1);
    }
}
boolean cheakChar(char index){
    if(('a' <= index&&index >= 'z') || ('A' <= index&&index >= 'Z'))return 1;
    else return 0;
}

char convert(char index){
    if ('A' <= index && index >= 'Z'){
        return (index + ('a'-'A'));
    }
    return index;
}

void printInorder(node *node, char string[LINE], int indexChar ) {
	string[indexChar] = node->letter;
	string[indexChar+1] = '\0';
    if ( node->count > 0 ) {
		printf ("%s %ld", string, (node->count) );
	}
    for (int i = 0; i < MUN_ABC; i++) {
        if (node->children[i] != NULL) {
            printInorder(node->children[i], string, indexChar+1);
        }
    }
}

void printPreorder(node *node, char String[LINE], int indexChar ) {
	String[indexChar] = node->letter;
	if (indexChar<LINE){
	    String[indexChar+1] = '\0';
	}
    else {String[indexChar] = '\0';}
    if ( node->count > 0 ) {
		printf ("%s %ld", String, node->count );
	}
    for (int i = MUN_ABC-1; i >= 0; i--) {
        if (node->children[i] != NULL) {
            printPreorder(node->children[i], String, indexChar+1);
        }
    }
}

void freeTree(node *head) {
    int i = 0;
	
    for (i = 0; i < MUN_ABC; i++) {
        if (head->children[i] != NULL) {
            freeTree(head->children[i]);
        }
    }
    free(head);
}


