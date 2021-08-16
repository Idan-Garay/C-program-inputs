#include <stdio.h>

int mystrlen(char str[]) {
    int x;

    for (x = 0; str[x] != '\0'; x++) {}
    return x;
}

void mystrrev(char str[]) {
    int x, hLen, len;
    char tmp;
    len = mystrlen(str)-1;
    hLen = len / 2;

    for ( x = 0; x <= hLen; x++ ) {
        tmp = str[x];
        str[x] = str[len-x];
        str[len-x] = tmp;
    }
    printf("reverse: %s", str);
}

int wordCount(char str[]) {
    int x;
    int word = 0;

    for (x = 0; str[x] != '\0'; x++) {
        if (str[x] == ' ' || str[x] == '.' || str[x] == ',')
            word++;
    }

    if (x != 0) 
        word++;

    return word;
}

int main() {
    char str[] = "Hello World. Welcome to Functional Programming";

    printf("wordCount: %d \nlength: %d \n", wordCount(str), mystrlen(str));
    mystrrev(str);

    return 0;
}