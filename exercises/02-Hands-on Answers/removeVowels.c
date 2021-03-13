#include <stdio.h>
#include <string.h>

void removeVowels(char str[]) {
    int x, y, ctr, len = strlen(str);
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    char temp[len];

    for (ctr = x = 0; str[x] != '\0'; x++) {
        for (y = 0; y < 5 && vowels[y] != str[x]; y++) {}
        if (y == 5)
            temp[ctr++] = str[x];
    }
    printf("%s", temp);
}

int main() {
    char str[100];

    scanf("%[^\n]s", str);
    removeVowels(str);

    return 0;
}