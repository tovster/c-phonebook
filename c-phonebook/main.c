#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "recordlib.h"
#include "menu.h"

#define FLUSH stdin=freopen(NULL, "r", stdin)


int main() {
    record_t record;
    char temp;
    printf("Please choose an option: ");
    scanf("%c", temp);
    if (temp != '\n') {
        switch (temp) {
            case '1':
                printf("Add");
                FLUSH;
                //do something
                break;
            case '2':
                printf("View");
                FLUSH;
                //do something
                break;
            case '3':
                printf("Modify");
                FLUSH;
                //do something
                break;
            case '4':
                printf("Delete");
                FLUSH;
                //do something
                break;
            case '5':
                printf("Search");
                FLUSH;
                //do something
                break;
            case '6':
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid input, please try again\n\n");
        }
    } else {
        printf("Invalid input, please try again\n\n");
    }
    return 0;
}

