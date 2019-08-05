//
// Created by mark on 8/04/19.
//

#ifndef C_PHONEBOOK_PBUTILS_H
#define C_PHONEBOOK_PBUTILS_H

#include <ctype.h>
#define FLUSH stdin=freopen(NULL, "r", stdin)

int txtSort (char*, char*);
int numSort (int*, int*);
record_t* sortRecordList (record_t*, char);

// Sorts text based on char ascii values
// by cycling through each string character
// and comparing the values
// 0 = string1 is first
// 1 = string2 is first
// 2 = strings are equal, put longer string after
int txtSort (char *string1, char *string2) {
    int lowestLen;
    if (strlen(string1) > strlen(string2)) {
        lowestLen = strlen(string2);
    } else {
        lowestLen = strlen(string1);
    }
    register int i;
    for (i = 0; i < lowestLen; ++i) {
        if (tolower(string1[i]) < tolower(string2[i])) {
            return 0;
        }
        if (tolower(string1[i]) > tolower(string2[i])) {
            return 1;
        }
    }
    return 2;
}

int numSort (int *number1, int *number2) {
    return 1;
}

record_t* sortRecordList (record_t* head, char sortBy) {
    return NULL;
}

#endif //C_PHONEBOOK_PBUTILS_H
