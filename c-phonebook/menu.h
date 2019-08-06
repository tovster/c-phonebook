//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_MENU_H
#define C_PHONEBOOK_MENU_H

#include <stdio.h>
#include "pbutils.h"
#include "record.h"

void menu(record_t*);

void menu(record_t *head) {
    printf("********** 📞 CONTACTS **********\n\n");
    printf("Please select a menu option\n");
    printf("1.Add\t\t2.View All\t\t3.Modify\n");
    printf("4.Delete\t5.Search\t\t6.Exit\n\n");

    int menuOption = 0;
    char userInput;
    userInput = 'a';
    while (1) {
        printf("Please select an option: ");
        fgets(&userInput, sizeof(int), stdin);
        menuOption = strtol(&userInput, NULL, 0);
        if (menuOption >= 1) {
            if(menuOption <= 6) {
                break;
            } else {
                printf("Invalid option, please try again\n");
            }
        } else {
            printf("Invalid option, please try again.\n");
        }
    }

    switch(menuOption) {
        case 1:
            head = createList();
            menu(head);
        case 2:
            printList(head);
            menu(head);
        case 3:
            menu(head);
        case 4:
            menu(head);
        case 5:
            menu(head);
        case 6:
            menu(head);
    }
}

#endif //C_PHONEBOOK_MENU_H
