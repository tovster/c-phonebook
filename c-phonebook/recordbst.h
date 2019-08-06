//
// Created by mark on 8/06/19.
//

#ifndef C_PHONEBOOK_RECORDBST_H
#define C_PHONEBOOK_RECORDBST_H
#include "record.h"

struct record_bst {
    record_t *left;
    record_t *node;
    record_t *right;
} recordbst_t;

#endif //C_PHONEBOOK_RECORDBST_H
