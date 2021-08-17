#include <stdio.h>
#include <stdlib.h> //1
#include <string.h> //5

typedef struct {
    unsigned int prodID;
    char prodDesc[15];
    float prodPrice;
    int prodQty;
}product;

typedef struct cell {
    product item;
    struct cell *next;
}*listType;

typedef enum {
    TRUE, FALSE
}boolean; //2

void insertFirst(listType *L, product X);
int insertSorted(listType *L, product X);
void displayProduct(product X);

const product items[10] = {
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
}; //3

void populateList(listType *L) {
    int x;

    for (x = 0; x < 10; x++) {
        insertFirst(L, items[x]);
    }
}

void populateSortedList(listType *L) {
    int x;

    for (x = 0; x < 10; x++) {
        insertSorted(L, items[x]);
    }
} //4

void displayList(listType L, char * listName) {
    printf("%s\n", listName);//6 deliberate understanding of the problem again
    for (; L != NULL; L = L->next) {
        displayProduct(L->item);
        printf("\n");
    }
}

void insertFirst(listType *L, product X) //7 dilemma with where to put fn. def. and should I start so I started directly since it's what matter the most
{
    listType newNode = (listType) calloc(1, sizeof(struct cell));
    //question: is accessing address the same as accessing the element
    //answer: accessing the address means accessing the value within that address
    // since an element is just a label for an address in memory.
    if (newNode != NULL) {
        newNode->item = X;
        newNode->next = *L;
        *L = newNode;
    }
}

void insertFirstUnique(listType *L, product X) {
    listType newNode, trav = *L;

    for (; trav != NULL; trav = trav->next) {
        if (trav->item.prodID == X.prodID) {
            trav->item.prodQty++;
            trav->item.prodPrice = X.prodPrice;
        } 
    }

    if (trav == NULL) {
        newNode = (listType) calloc(1, sizeof(struct cell));
        if (newNode != NULL) {
            newNode->item = X;
            newNode->next = *L;
            *L = newNode;
        }
    }
}

int insertSorted(listType *L, product X) {
    int ID, status = 0;
    listType *trav, *spot, newNode;

    spot = trav = L;
    ID = 0;
    
    while ( *trav != NULL && ID < (*trav)->item.prodID) {
        ID = (*trav)->item.prodID;
        trav = &(*trav)->next;
        if (ID < X.prodID)
            spot = trav;
    }

    if (*trav == NULL) {

        newNode = (listType) calloc(1, sizeof(struct cell));
        if (newNode != NULL) {
            newNode->item = X;
            newNode->next = *spot;
            *spot = newNode;
            status = 1;
        }
    }
    return status;
}

product delete(listType *L, unsigned int prodId) { //this is a bug
    product X = {0, "XXX", 0, 0};

    if (*L != NULL) {
        for(; *L != NULL && (*L)->item.prodID != prodId; L = &(*L)->next) {}

        if (*L != NULL) {
            listType tmp = *L;
            *L = tmp->next;
            X = tmp->item;
            free(tmp);
        }
    }
    return X;
}

void displayProduct(product X) {
    printf("ID: %d Desc: %s Price: %.2f Qty: %d", X.prodID, X.prodDesc, X.prodPrice, X.prodQty);
}