//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_RECORDLIB_H
#define C_PHONEBOOK_RECORDLIB_H
#include "record.h"

record_t *createRecord();
record_t *createList();
record_t *rebuildList(record_t *root);
void displayList(record_t *root);
void deleteRecord(record_t *record);
void deleteList(record_t *root);
record_t modifyRecord(record_t *record);
record_t searchRecord(int id, char *name);

#endif //C_PHONEBOOK_RECORDLIB_H
