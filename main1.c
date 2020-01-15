#include <stdio.h>
#include "frequency_lib.h"

int main() {
    node head;
    head.count = 0;
    for (int i=0;i<MUN_ABC;i++){
        head.children[i] = NULL;
    }
    textToTree(&head);
    for (int i = 0; i < MUN_ABC; i++) {
        if (head.children[i] != NULL) {
            char string[LINE] = {0};
            printInorder(head.children[i], string, 0);
        }
    }
    freeTree(&head);

    return 0;
}