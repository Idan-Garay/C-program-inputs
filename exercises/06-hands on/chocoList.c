#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int prodID;    /* product ID, uniquely identifies an element */
    char prodDesc[15];      /* product description */
    float prodPrice;        /* product price */
    int prodQty;            /* product count or quantity*/
}product;                   /* product record */

typedef struct cell{
    product item;
    struct cell *next;
}*listType;                 /* Definition of the ADT List */

typedef enum {
    TRUE, FALSE
} boolean;

void insertFirst(listType *L, product X) {
    listType temp = (listType) calloc(1, sizeof(struct cell));
    
    if (temp != NULL) {
        temp->item = X;
        temp->next = *L;
        *L = temp;
    }
        printf("hey$$ \n");
}

void insertFirstUnique(listType *L, product X) {
    listType trav;

    for (trav = *L; trav != NULL && trav->item.prodID != X.prodID; trav = trav->next) {}
    if (trav == NULL) {
        trav = (listType) calloc(1, sizeof(struct cell));
        if (trav != NULL) {
            trav->item = X;
            trav->next = *L;
            *L = trav;
        } else {
            trav->item.prodQty++;
        }
    }
}

/* more efficient way is to insert a node with product X to the list first and then use merge sort
    but the problem states to only insert once the list is sorted
*/
int insertSorted(listType *L, product X) { 
    listType *trav, *curr, ptr, temp;
    int ID;
    
    for (curr = L; *curr != NULL; curr = &(*curr)->next) {
        ID = (*curr)->item.prodID;
        for (trav = curr; *trav != NULL && (*trav)->item.prodID > ID; trav = &(*trav)->next) {}
        if (*trav != *curr) {
            ptr = *trav;
            *trav = (*trav)->next;
            ptr->next = *curr;
            *curr = ptr;
        }
    }

    temp = (listType) calloc(1, sizeof(struct cell));
    if (temp != NULL) {
        for (trav = L; *trav != NULL && (*trav)->item.prodID < X.prodID; trav = &(*trav)->next){}
        temp->item = X;
        temp->next = *trav;
        *trav = temp;
        printf("Success\n");
    }
    return (temp != NULL)? 1: 0;
}

product delete (listType *L, unsigned int prodId) {
    listType *trav, ptr;
    product X;

    for (trav = L; *trav != NULL && (*trav)->item.prodID != prodId; trav = &(*trav)->next) {}
    if (*trav != NULL) {
        ptr = *trav;
        *trav = (*trav)->next;
        X = ptr->item; 
        free(ptr);
    }
    return X;
}

void displayProduct(product X) {
    printf("\n%d %s %.2f %d", X.prodID, X.prodDesc, X.prodPrice, X.prodQty);
}

void populateList(listType *L) {
    int x;
    listType temp, *trav;
    product arr[10] = {
        {1, "A yummy donut", 8.88, 17},
        {22, "A yummy pizza", 12.50, 2},
        {35, "A yummy orange", 5.50, 18},
        {14, "A yummy apple", 2, 17},
        {5, "A yummy bread", 5, 64},
        {3, "A yummy snack", 6.75, 43},
        {2, "A yummy choco", 20.5, 25},
        {55, "A yummy drink", 15.50, 19},
        {80, "A yummy shake", 72.20, 3},
        {95, "A yummy candy", 1.50, 99},
    };

    for (x = 0; x < 10; x++) {
        insertFirst(L, arr[x]);
    }
}

void populateSortedList(listType *L) {
    product arr[10] = {
        {1, "A yummy donut", 8.88, 17},
        {22, "A yummy pizza", 12.50, 2},
        {35, "A yummy orange", 5.50, 18},
        {14, "A yummy apple", 2, 17},
        {5, "A yummy bread", 5, 64},
        {3, "A yummy snack", 6.75, 43},
        {2, "A yummy choco", 20.5, 25},
        {55, "A yummy drink", 15.50, 19},
        {80, "A yummy shake", 72.20, 3},
        {95, "A yummy candy", 1.50, 99},
    };
    int x;

    for (x = 0; x < 10; x++) {
        insertSorted(L, arr[x]);
    }
}

void displayList(listType L, char *listName) {
    printf("--%s List--\n", listName);
    printf("<ID> <description> <price> <qty>");

    for (; L != NULL; L = L->next) {
        displayProduct(L->item);
    }

}

int main() {
    listType L = NULL;

    populateSortedList(&L);
    displayList(L, "Food");

    return 0;
}