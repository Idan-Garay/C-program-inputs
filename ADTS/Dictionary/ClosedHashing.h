#include <stdio.h>

#define MAX 10
#define EMPTY -1
#define DELETED -2

typedef char Dictionary[MAX];

void initHT(Dictionary D) {
    int x;

    for (x = 0; x < MAX; x++) 
        D[x] = EMPTY;
}

int hash(int val) {
    return val % MAX;
}

void insert(Dictionary D, char data) {
    int checksum = hash(data);
}