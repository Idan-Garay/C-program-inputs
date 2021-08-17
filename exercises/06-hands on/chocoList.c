#include "chocoListHeader.h"

int main() {
    listType list, sortedList;
    sortedList = list = NULL;

    populateList(&list);
    displayList(list, "Unordered List");
    populateSortedList(&sortedList);
    displayList(sortedList, "\nOrdered List");

    product P = delete(&sortedList, 5);
    printf("Deleted-> ");
    displayProduct(P);
    displayList(sortedList, "\nOrdered List");
    printf("\n");

    insertFirstUnique(&sortedList, P);
    displayList(sortedList, "\nOrdered List");
    return 0;
}

/*
    Read & Understand the Problem
    Nuance in Implementation
    :   Understand the Data Structure Used
        The Flow of accessing the data
            (cond., arrangement of variables, scope)
    Read -> Understand -> Implement
*/