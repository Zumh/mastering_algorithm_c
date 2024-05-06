#ifndef PAGE_H
#define PAGE_H
    #include "clist.h"
    // Define a structure for information about pages.

    typedef struct Page_{
        int number;
        int reference;
    } Page;

    // Public interface
    int replace_page(CListNode **current);
#endif