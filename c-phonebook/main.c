#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "recordlib.h"
#include "menu.h"

#define FLUSH stdin=freopen(NULL, "r", stdin)


int main() {
    record_t record;
    menu(&record);
}

