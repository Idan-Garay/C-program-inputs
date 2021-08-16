#include <stdio.h>
#include <ctype.h>

void removeVowels(char *str) {
    int x, y, len;
    char tmp;
    
    for ( x = 0; str[x] != '\0'; x++) {
        str[x] = tolower(str[x]);
        tmp = str[x];
        if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u') {
            for (y = x; str[y] != '\0'; y++) {
                str[y] = str[y+1];
            }
        }
    }

    printf("%s", str);

}


int main() {
    char str[] = "Hello World";

    removeVowels(str);

    return 0;
}