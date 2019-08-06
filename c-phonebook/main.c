#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "recordlib.h"
#include "menu.h"




int main() {
    setbuf(stdout, NULL);
    //Menu
    record_t *record;
    //menu(&record);
    record = createRecord();
    //------------------------------------------
    
    //Testing list
    //record_t* head = NULL;
    
    //head = createList();
    //Testing records
    //printList(head);
            
    exit(0);
    //menu(&record);
}

