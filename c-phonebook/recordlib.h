//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_RECORDLIB_H
#define C_PHONEBOOK_RECORDLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "pbutils.h"

#define MAX_LEN 25

record_t *createRecord();

record_t *createList();

record_t *rebuildList(record_t *root);

void displayList(record_t *root);

void deleteRecord(record_t *record);

void deleteList(record_t *root);

void insertRecord(record_t *root);
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
        printf("Enter ID number: ");
        fgets(&tempId, MAX_LEN, stdin);

        id = strtol(&tempId, NULL, 0);
        if (id > 0) {
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
        free(record->id);
        free(record);
        record = NULL;
        return record;
    }
    memcpy(record->gender, &gender, 1);

    //filling phone number
    
    //filling email
    
    //filling next node
    //Node should be null as it is independent of the linked list
    record->next == NULL;
    
    printf("ID: %d,\n", record->id);
    printf("Name: %s,\n", record->name);
    printf("Address: %s,\n", record->address);
    printf("Gender: %s,\n", record->gender);

    return record;


}

record_t insertRecord(record_t *head){
    record_t* newRecord;
    newRecord = createRecord();
    newRecord->next = head;
    head = newRecord;
    
    return head;
            
}

void printList(record_t *head){
    
    record_t *current = head;
    while(current != NULL) {
        printf("%d", current->id);
        printf("%s", current->name);
        current = current->next;
    }
}



#endif //C_PHONEBOOK_RECORDLIB_H
