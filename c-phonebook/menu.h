//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_MENU_H
#define C_PHONEBOOK_MENU_H

#include <stdio.h>
#define FLUSH stdin=freopen(NULL, "r", stdin)

void menu(record_t*);

void menu(record_t *root) {
    printf("********** 📞 CONTACTS **********\n\n");
    printf("Please select a menu option\n");
    printf("1.Add\t\t2.View All\t\t3.Modify\n");
    printf("4.Delete\t5.Search\t\t6.Exit\n\n");

    int menuOption = 0;
    while (1) {
        char *userInput;
        printf("Please select an option: ");
        fgets(userInput, sizeof(int), stdin);
        menuOption = strtol(userInput, NULL, 0);
        if (menuOption >= 1) {
            if(menuOption <= 6) {
                printf("\n%d, is your option", menuOption);
                break;
            } else {
                printf("Invalid option, please try again\n");
            }
        } else {
            printf("Invalid option, please try again.\n");
        }
    }
}

#endif //C_PHONEBOOK_MENU_H
