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

    while(1) {
        char tempId;
        printf("Enter ID number: ");
        FLUSH;
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
    printf("Id Num = %d", record->id);

    return record;


}

#endif //C_PHONEBOOK_RECORDLIB_H
