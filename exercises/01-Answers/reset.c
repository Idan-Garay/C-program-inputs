#include <stdio.h>
#include <conio.h>

void resetPIN(int *pin) {
    *pin = 1234;
}

int matchAccPIN(int pin, int acc) {
    int val = 3;
    if (acc == 32767) {
        val = 2;
        
        if (pin == 1234 || pin == 4128)
            val = 1;
    }

    return val;
}


int main() {
    int chances = 3, acc, pin, catch;
    char choice = 'N';
    do {
        printf("Enter account #: "); scanf("%d", &acc);
        printf("Enter pin #: "); scanf("%d", &pin);
        if (pin > 999 && pin < 10000) {
            catch = matchAccPIN(pin, acc);
            if (catch == 1) {
                printf("You have successfully access your account!\n");
                break;
            } else if (catch == 2) {
                printf("Do you want to reset your PIN? (Y/N): ");
                fflush(stdin);
                scanf("%c ", &choice);
                if (choice == 'Y') {
                    resetPIN(&pin);
                }
            } else {
                printf("The inputted pin number is not a valid pin number.\n");
            }
        }
        chances--;
    } while (chances > 0 || catch != 3);
        if (chances == 0 && choice != 'Y')
            printf("\nYour account has been blocked!"); 
        getch();
    return 0;
}