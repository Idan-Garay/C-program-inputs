#include <stdio.h>
#include <stdlib.h>

const int RATING_SIZE = 10;
const int RESPONSE_SIZE = 40;

void displayStudyHabitsFrequencies(int arr[]) {
    int *freqs = (int*) calloc(RATING_SIZE+1, sizeof(int));

    if (freqs != NULL) {
        int x = 0;

        for (x = 0; x < RESPONSE_SIZE; x++) {
            freqs[arr[x]]++;
        }
        
        printf("Rating Frequencies\n");
        for (x = 1; x < 11; x++) {
            printf("%d  %d\n", x, freqs[x]);
        }
    }
}

int main() {
    int stud_ratings[] = {
        1, 2, 6, 4, 8, 5, 9, 7, 8, 10,
        1, 6, 3, 8, 6, 10, 3, 8, 2, 7,
        6, 5, 7, 6, 8, 6, 7, 5, 6, 6,
        5, 6, 7, 5, 6, 4, 8, 6, 8, 10
    };
    
    displayStudyHabitsFrequencies(stud_ratings);

    return 0;
}