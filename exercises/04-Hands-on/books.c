#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

Book inputBook();
int addBooks(Book bk, ArrBooks *A);
void displayBooks(ArrBooks A);
Book * searchBooks(float price, ArrBooks A);

int main() {
    ArrBooks newList;
    Book b, *list;
    int x, num, catch;
    newList.ctr = 0; /*no books yet*/
    float price;

    printf("\nEnter the no. of books to input: ");
    scanf("%d", &num);

    for (x = 0; x < num, x++) {
        b = inputBook();
        catch = addBooks(b, &newList); /* add books to func call */
        switch() {
            case 1: printf("\nSuccessfully added!\n");
                    break;
            case 2: printf("\nOverflow of books!");
                    break;
        }
    }

    displayBooks(A); /*displayBooks() func call*/
    printf("\n\nEnter book price: ");
    scanf("%f", &price);
    list = searchBooks(price, newList) /*searchList() func. call*/

    for (x = 0; x < 3; x++) { /* prints only the first 3 search results */
        b = list[x];
        printf("%d %s %s created by %s published by %s", b.YearPub, b.BkInfo.title, b.BkInfo.author, b.BkInfo.publisher); /*print format is the same with displayBooks() */
    }

    getch();
    return 0;

    return 0;
}

Book inputBook() {
    Book bk;

    printf("<author> <title> <publisher> <YearPub> <price>");
    scanf("%s %s %s %d %f", bk.BkInfo.author, bk.BkInfo.title, bk.BkInfo.publisher, &bk.YearPub, &bk.BookPrice);

    return bk;
}

int addBooks(Book bk, ArrBooks *A) {
    int val = 0;

    if (A->ctr < SIZE) {
        A->bks[A->ctr++] = bk;
        val = 1;
    }
    return val;
}

void displayBooks(ArrBooks A) {
    Book bk;
    int x, len;

    len = A.ctr;
    for (x = 0; x < len; x++) {
        bk = A.bks[x];
        printf("%d %s %s created by %s published by %s", bk.YearPub, bk.BkInfo.title, bk.BkInfo.author, bk.BkInfo.publisher);
    } 
}

Book * searchBooks(float price, ArrBooks A) {
    Book *bks = (Book *) malloc(SIZE*sizeof(Book));

    if (bks != 0) {
        int x, ctr;

        for (ctr = x = 0; x < A.ctr; x++) {
            if (A.bks[x].BookPrice == price) 
                bks[ctr++] = A.bks[x];
        }
        bks = realloc(bks, ctr);
    }
    return bks;
}
