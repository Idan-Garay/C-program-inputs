#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int month, day, year;
}birthday;

typedef struct {
    char fN[24];
    char lN[16];
    char mI;
    birthday bday;
    int age;
}student;

birthday getBday(student stud) {
    char lN[16];
    printf("Enter last name: "); scanf("%s", lN);

    if (strcmp(lN, stud.lN) != 0) {
        printf("\nYou have the wrong student record!\n");
        exit(0);
    }

    return stud.bday;
}

void dispBday(birthday bday) {
    printf("%d/%d/%d", bday.month, bday.day, bday.year);
}

int main() {
    student x = {"Setsuna", "Seiei", 'F', 4, 7, 2291, 16};
    birthday birth;

    birth = getBday(x);
    printf("\n%s's Birthday is ", x.fN);
    dispBday(birth);

    return 0;
}