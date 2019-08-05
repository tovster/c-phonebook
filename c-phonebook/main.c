#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "recordlib.h"
#include "menu.h"




int main() {
    //Menu
    //record_t record;
    //menu(&record);
    
    //------------------------------------------
    //Testing list
    record_t* head = createList();
    //Testing records
    head = createList();
    printList(head);
            
    exit(0);
    //menu(&record);
}

