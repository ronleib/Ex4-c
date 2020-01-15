#include <stdio.h>
#include "frequency_lib.h"

int main() {
    const node head;
    textToTree(&head);
	char[LINE] String = {0};
    printInorder(&head, &String, 0);
    freeTree(&head);
    return 0;
}