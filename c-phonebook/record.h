//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_RECORD_H
#define C_PHONEBOOK_RECORD_H

typedef struct record {
    int *id;
    char *name;
    char *address;
    char *gender;
    long *p_num;
    char *e_mail;
    struct record *left;
    struct record *right;
} record_t;

#endif //C_PHONEBOOK_RECORD_H
