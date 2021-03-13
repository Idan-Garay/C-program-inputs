#include <stdio.h>
#include <string.h>

int wordCount(char str[]) {
    int x, count = 0;
    int len = strlen(str);

    if (len > 0) {
        for (x = 0; str[x] != '\0'; x++) {
            if (str[x] == ' ' || str[x+1] == '\0') {
                count++;
            }
        }
    }
    return count;
}   

int mystrlen(char str[]) {
    int x = 0;

    while (str[x++] != '\0') {}
    return x-1;
}

void strrev(char str[]) {
    int x, len = mystrlen(str)-1;
    char temp;

    for (x = 0; x <= len/2; x++) {
        temp = str[x];
        str[x] = str[len-x];
        str[len-x] = temp;
    }
}

int main() {
    char str[100];

    scanf("%[^\n]s", str);
    printf("%d\n", wordCount(str));
    printf("%d\n", mystrlen(str));
    strrev(str);
    printf(" %s\n", str);

}