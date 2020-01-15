#include <stdio.h>
#include "frequency_lib.h"

int main() {
    const node head;
    textToTree(&head);
    printBackwards(head);
    freeTree(&head);
    return 0;
}