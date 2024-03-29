//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_MENU_H
#define C_PHONEBOOK_MENU_H

#include <stdio.h>
#include "pbutils.h"
#include "record.h"

void menu(record_t *);

void menu(record_t *head) {
    printf("********** 📞 CONTACTS **********\n\n");
    printf("Please select a menu option\n");
    printf("(* signifies incomplete functionality)\n");
    printf("1.Add\t\t2.View All\t\t3.Modify\n");
    printf("4.Delete\t5.(*)Search\t\t6.Exit\n\n");


    int menuOption = 0;
    char userInput;
    userInput = 'a';
    while (1) {
        printf("Please select an option: ");
        fgets(&userInput, sizeof(int), stdin);
        menuOption = strtol(&userInput, NULL, 0);
        if (menuOption >= 1) {
            if (menuOption <= 6) {
                break;
            } else {
                printf("Invalid option, please try again\n");
            }
        } else {
            printf("Invalid option, please try again.\n");
        }
    }
    switch (menuOption) {
        case 1:
            if (head == NULL) {
                head = createList();
            } else {
                appendRecord(head);
            }
            menu(head);
        case 2:
            printList(head);
            menu(head);
        case 3:
            //Ask for index, and field
            while (1) {
                printf("Please choose an ID number you would like to edit: ");
                fgets(&userInput, 2, stdin);
                int index = strtol(&userInput, NULL, 0);
                if (index < id && index >= 0) {
                    FLUSH;
                    printf("(n)AME, (a)DDRESS, (g)ENDER, (p)HONE, (e)MAIL: ");
                    fgets(&userInput, 2, stdin);
                    if (userInput == 'n' || userInput =='a' || userInput =='g' || userInput =='p' || userInput =='e') {
                        modifyRecord(head, index, userInput);
                        break;
                    } else {
                        printf("Invalid input, please try again");
                    }
                } else {
                    printf("Invalid option, please try again\n");
                }
            }
            menu(head);
        case 4:
            //Ask for index
            while (1) {
                printf("Please choose an ID number you would like to edit: ");
                char input = 0;
                fgets(&input, sizeof(int), stdin);
                int index = strtol(&input, NULL, 0);
                FLUSH;
                if (index < id - 1 && index > 0) {
                    deleteRecord(&head, index);
                    break;
                } else {
                    printf("Invalid input, please try again. \n");
                }
            }
            menu(head);
        case 5:
            menu(head);
        case 6:
            exit(0);
    }
}

#endif //C_PHONEBOOK_MENU_H
