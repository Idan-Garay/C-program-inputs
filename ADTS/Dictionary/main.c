#include "Dictionary.h"

int main() {
    SET A = {{4,5001,72,214,1,4213}, 6};

    Dictionary D;

    initDict(D);
    populateDictionary(D, A);

    displayDictionary(D);

    return 0;
}