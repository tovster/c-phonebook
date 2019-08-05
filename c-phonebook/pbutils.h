//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_PBUTILS_H
#define C_PHONEBOOK_PBUTILS_H

#define FLUSH stdin=freopen(NULL, "r", stdin)

int txtSort (char*, char*);
int numSort (int*, int*);
record_t* sortRecordList (record_t*, char);

int txtSort (char *string1, char *string2) {
    return 1;
}

int numSort (int *number1, int *number2) {
    return 1;
}

record_t* sortRecordList (record_t* head, char sortBy) {
    return NULL;
}

#endif //C_PHONEBOOK_PBUTILS_H
