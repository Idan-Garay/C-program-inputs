#include <stdio.h>
#include <stdlib.h>

#define RATING_SIZE 10
#define RESPONSE_SIZE 40

void displayStudyHabitsFrequencies(int arr[]) {
    int *freq, x;

    freq = (int*) calloc(RATING_SIZE, sizeof(int));

    if (freq != NULL) {
        for (x = 0; x < RESPONSE_SIZE; x++) 
            freq[arr[x]-1]++;

        printf("Rating\tFrequency");

        for (x = 0; x < RATING_SIZE; x++) 
            printf("\n%d\t %d", x+1, freq[x]);
    }
    free(freq);
}

int main() {
    int stud_ratings[] = {
        1, 2, 6, 4, 8, 5, 9, 7, 8, 10,
        1, 6, 3, 8, 6, 10, 3, 8, 2, 7,
        6, 5, 7, 6, 8, 6, 7, 5, 6, 7,
        5, 6, 7, 5, 6, 4, 8, 6, 8, 10
    };
    displayStudyHabitsFrequencies(stud_ratings);

    return 0;
}