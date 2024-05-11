/*
The passage describes the Second-Chance (or Clock) algorithm, a technique for replacing pages in virtual memory systems. It aims to approximate Least Recently Used (LRU) by keeping track of recently accessed pages.

- A circular list stores pages in memory along with a "reference bit" (0 or 1).
- When a new page needs a frame, the algorithm scans the list.
  - If a page's reference bit is 1, it's considered "recently used" and the bit is reset to 0 (given a second chance).
  - If a page's reference bit is 0, it's replaced and removed from the list.
- If all pages have been referenced since the last scan, the first page is replaced (completing a cycle).

A circular list allows the algorithm to efficiently cycle through pages. The time complexity to replace a page is O(n), where n is the number of pages. 
*/

#include "clist.h"
#include "page.h"


// replace_page 
int replace_page(CListNode **current){
    // Circle through a list of pages until one is found to replace.

    while(((Page *) (*current)->data)->reference != 0 ){
        // reseting reference zeros for replacement
        ((Page *) (*current)->data)->reference = 0;
        *current = clist_next(*current);
    } 

    return ((Page *) (*current)->data)->number;
    
}