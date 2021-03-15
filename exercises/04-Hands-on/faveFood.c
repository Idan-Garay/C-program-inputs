#include <stdio.h>
#include <string.h>
#define N 5

typedef struct {
    char fname[30], lname[30];
}name;

typedef struct {
    name stud_name;
    char favoritefood[30];
    char gender; /* F for female and M for male*/
    int age;
}student;

void input(student *s, int x) {
    int a;

    printf("<fname> <lname> <food> <gender(M/F)> <age>\n");
    for (a = 0; a < x; a++) {
        scanf("%s %s %s %c %d", s[x].stud_name.fname, s[x].stud_name.lname, s[x].favoritefood,  &s[x].gender, &s[x].age);
    }
}

void display(student *s, int x) {
    int a;
    student stud;

    for (a = 0; a < x; a++) {
        stud = s[x];
        printf("%s %s %c %s %d\n", stud.stud_name.lname, stud.stud_name.fname, stud.gender, stud.favoritefood, stud.age);
    }
}

int maleAppetite(student *s, int x, char FOOD[]) {
    int  a, count = 0;

    for (a = 0; a < x; a++) {
        if (strcmp(s[a].favoritefood, FOOD) == 0)
            count++;
    }
    return count;
}

int main() {
    student stud[N];
    char FOOD[10];
    int i;

    input(stud, N);
    printf("\n\n");
    display(stud, N);
    printf("Enter food to search: ");
    scanf("%s", FOOD);
    printf("%d", maleAppetite(stud, N, FOOD));

    return 0;
}