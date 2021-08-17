#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

typedef struct {
    char author[30], title[30], publisher[30];
}PrimeInfoType;

typedef struct {
    PrimeInfoType BkInfo;
    int YearPub;
    float BookPrice;
}Book;

typedef struct {
    Book bks[SIZE];
    int ctr; /* contains the actual # of books in bks*/
}ArrBooks;

Book inputBook(void);
int addBooks(Book bk, ArrBooks *A);
void displayBooks(ArrBooks A);
Book* searchBooks(float price, ArrBooks A);

int main() {
    ArrBooks newList;
    Book b, *list;
    int x, num, catch;
    float price;
    newList.ctr = 0; /*no books yet*/

    printf("\nEnter no. of books to input: ");
    scanf("%d", &num);

    for (x = 0; x < num; x++) {
        b= inputBook();
        catch = addBooks(b, &newList);
        switch(catch) {
            case 1: printf("\nSuccessfully added!\n");
                    break;
            case 2: printf("\nOverflow of books!");
                    break;
        }
    }

    displayBooks(newList);
    printf("\n\nEnter book price: ");
    scanf("%f", &price);
    list = searchBooks(price, newList);

    for (x = 0; x < 3; x++) {
        printf("%d %s created by %s published by %s", list[x].YearPub, list[x].BkInfo.title, list[x].BkInfo.author, list[x].BkInfo.publisher);
    }
}

Book inputBook(void) {
    Book bk;
    printf("Enter Book details: \n");
    printf("author: \n"); scanf("%s", bk.BkInfo.author);
    printf("title: \n"); scanf("&s", bk.BkInfo.title);
    printf("publisher: \n"); scanf("%s", bk.BkInfo.publisher);
    printf("price: \n"); scanf("%f", &bk.BookPrice);
    printf("yearPub: \n"); scanf("%d", &bk.YearPub);
    return bk;
}

int addBooks(Book bk, ArrBooks *A) {
    int status = 2;

    if (A->ctr < SIZE) {
        A->bks[A->ctr++] = bk;
        status = 1;
    }
    return status;
}

void displayBooks(ArrBooks A) {
    int x, len;
    len = A.ctr;

    for (x = 0; x < len; x++) {
        printf("%d %s created by %s published by %s", A.bks[x].YearPub, A.bks[x].BkInfo.title, A.bks[x].BkInfo.author, A.bks[x].BkInfo.publisher);
    }
}

Book* searchBooks(float price, ArrBooks A) {
    Book *bks = (Book*) calloc(1000, sizeof(Book));
    int x, len, count;
    len = A.ctr;
    count = 0;

    if (bks != NULL) {
        for (x = 0; x < len; x++) {
            if (A.bks[x].BookPrice == price) 
                bks[count++] = A.bks[x];
        }

        bks = realloc(bks, sizeof(Book) * count);
    }
    return bks;
}
