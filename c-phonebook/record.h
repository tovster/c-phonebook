//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_RECORD_H
#define C_PHONEBOOK_RECORD_H
#define MAX_LEN 25

typedef struct record {
    char *name;
    char *address;
    char *gender;
    long *p_num;
    char *e_mail;
} record_t;

#endif //C_PHONEBOOK_RECORD_H
