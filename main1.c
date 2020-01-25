#include <stdio.h>
#include "frequency_lib.h"

int main(int argc,char *argv[]) {
	node head;
    	head.count = 0;
    	for (int i=0; i < MUN_ABC; i++){
		head.children[i] = NULL;
	}
	textToTree(&head);
	if (argc == 1){
		for (int i = 0; i < MUN_ABC; i++) {
			if (head.children[i] != NULL) {
				char string[LINE] = {0};
				printInorder(head.children[i], string, 0);
			}
		}
	}
	else {
		for (int i = MUN_ABC-1; i >= 0 ; i--) {
			if (head.children[i] != NULL) {
            			char string[LINE] = {0};
            			printPreorder(head.children[i], string, 0);
        		}
    		}
    	}
    	freeTree(&head);
    	return 0;
}
