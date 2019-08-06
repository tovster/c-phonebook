//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_RECORDLIB_H
#define C_PHONEBOOK_RECORDLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "record.h"
#include "pbutils.h"

#define MAX_LEN 25

record_t *createRecord();

record_t *createList();

record_t *rebuildList(record_t *root);

void displayList(record_t *root);

void deleteRecord(record_t *record);

void deleteList(record_t *root);

void printList(record_t *head);

record_t modifyRecord(record_t *record);

record_t searchRecord(int id, char *name);

record_t *createRecord() {

    // mallocing record_t
    record_t *record = (record_t *) malloc(sizeof(record_t));
    if (record == NULL) {
        printf("Can not allocate memory for this contact.\n");
        return record;
    }

    // filling id
    int id;

    while (1) {
        char tempId;
        FLUSH;
        printf("Enter ID number: (Enter 0 to exit)");
        fgets(&tempId, MAX_LEN, stdin);

        id = strtol(&tempId, NULL, 0);
        //Go back to main menu if input == 0
        if (id == 0){
            //Back method to go back to the main menu
            printf("Exiting record creation");
            return NULL;
        }
        else if(id > 0) {
            break;
        } else {
            printf("Incorrect value! Please try again.");
        }
    }
    record->id = (int *) malloc(sizeof(&id));
    if (record->id == NULL) {
        free(record);
        printf("Can not allocate memory for this contact. \n");
        return NULL;
    }
    
    memcpy(&record->id, &id, sizeof(&id));  // copying the id into the record

    //filling name

    while (1) {
        char tempName[MAX_LEN];
        FLUSH;
        printf("Please enter a name: ");
        fgets(tempName, MAX_LEN, stdin);

        if (strlen(tempName) > 1) {
            record->name = (char *) malloc(sizeof(tempName) + 1);
            if (record->name == NULL) {
                printf("Can't allocate memory for this record's name!");
                free(record->id);
                free(record);
                record = NULL;
                return record;
            }
            strncpy(record->name, tempName, sizeof(tempName));
            record->name[strcspn(record->name, "\n")] = 0;
            break;
        } else {
            printf("Invalid input! Please try again.");
        }
    }
    
    //filling address
    while (1) {
        char tempAddress[MAX_LEN * 2];
        FLUSH;
        printf("Please enter a address: ");
        fgets(tempAddress, MAX_LEN*2, stdin);

        if (strlen(tempAddress) > 1) {
            record->address = (char *) malloc(sizeof(tempAddress) + 1);
            if (record->address == NULL) {
                printf("Can't allocate memory for this record's address!");
                free(record->id);
                free(record);
                record = NULL;
                return record;
            }
            strncpy(record->address, tempAddress, sizeof(tempAddress));
            record->address[strcspn(record->address, "\n")] = 0;
            break;
        } else {
            printf("Invalid input! Please try again.");
        }
    }
    FLUSH;
    //filling gender
    char gender;

    while (1) {
        char tempGender;

        printf("Please enter your gender (M, F, X): ");
        fgets(&tempGender, 2, stdin);

        if (tempGender == 'M' || tempGender == 'F' || tempGender == 'X') {
            gender = tempGender;
            break;
        } else {
            printf("Invalid input! Please try again.");
        }
    }
    record->gender = (char *) malloc(gender);
    if (record->gender == NULL) {
        printf("Can't allocate memory for this record's gender!");
        free(record->address);
        free(record->id);
        free(record);
        record = NULL;
        return record;
    }
    memcpy(record->gender, &gender, 1);

    //WORK IN PROGRESS, STILL NEEDS TESTING
    //filling phone number
    //Phone number must be 10 digits
    long p_num;

    while(1){
        char temp_p_num[11];
        FLUSH;
        printf("Please enter a 10 digit phone number: ");
        fgets(temp_p_num, 11, stdin);
        //phone number must only contain digits
        p_num = strtol(temp_p_num, NULL, 0);
        if (p_num > 999999999) {
            record->p_num = (long *) malloc(sizeof(long));
            if (record->p_num == NULL) {
                printf("Can't allocate memory for this record's phone number!");
                free(record->gender);
                free(record->address);
                free(record->id);
                free(record);
                record = NULL;
                return record;
            }

            memcpy(record->p_num, &p_num, sizeof(p_num));
            break;
        } else {
            printf("Invalid input! Please try again.");
        }
    }
    
    // filling email
    while (1) {
        char tempEmail[MAX_LEN * 2];
        FLUSH;
        printf("Please enter e-mail: ");
        fgets(tempEmail, MAX_LEN*2, stdin);

        if (strlen(tempEmail) > 1) {
            record->e_mail = (char *) malloc(sizeof(tempEmail) + 1);
            if (record->e_mail == NULL) {
                printf("Can't allocate memory for this record's e_mail!");
                free(record->p_num);
                free(record->gender);
                free(record->address);
                free(record->id);
                free(record);
                record = NULL;
                return record;
            }
            strncpy(record->e_mail, tempEmail, sizeof(tempEmail));
            record->e_mail[strcspn(record->e_mail, "\n")] = 0;
            break;
        } else {
            printf("Invalid input! Please try again.");
        }
    }

    return record;
}

record_t *createList(){
    record_t *record=NULL, *current=NULL, *head=NULL;

    while((record=createRecord()) != NULL){
        if(head == NULL) {
            head = record;
        }
        else {
            current->next = record;
        }
        current = record;
    }
    printf("\nDone getting records");
    return head;
}

//Broke 
void printList(record_t *head){
    if (head == NULL) {
        printf("Contact list is empty\n");
    } else {
        printf("Your contacts: \n\n");
        record_t* current = head;
        while (current != NULL) {
            printf("ID: %d\n", current->id);
            printf("Name: %s\n", current->name);
            printf("Address: %s\n", current->address);
            printf("Gender: %s\n", current->gender);
            printf("Phone Number: %ld\n", *(current->p_num));
            printf("Email: %s\n\n", current->e_mail);
            current = current -> next;
        }
    }
}




#endif //C_PHONEBOOK_RECORDLIB_H
