#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 500
void encrypt() {
    char text[MAX_SIZE], ch;
    int key, i;

    printf("Enter a message to encrypt: ");
    scanf("%s", text);
    
    printf("Enter the key: ");
    scanf("%d", &key);

    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isalnum(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            } else if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            } else if (isdigit(ch)) {
                ch = (ch - '0' + key) % 10 + '0';
            }
        }  else {
            printf("Invalid Message");
            return;
        }
        text[i] = ch;
    }

    printf("Encrypted message: %s\n", text);
}

void decrypt() {
    char text[MAX_SIZE], ch;
    int key, i;
    printf("Enter a message to decrypt: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%d", &key);
    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isalnum(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' - key + 26) % 26 + 'a';
            }     else if (isupper(ch)) {
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            }  else if (isdigit(ch)) {
                ch = (ch - '0' - key + 10) % 10 + '0';
            }
        }  else {
            printf("Invalid Message");
            return;
        }
        text[i] = ch;
    }
printf("Decrypted message: %s\n", text);

printf("\n\n\t\tLAB by Utshav Paudel");
}
int main() {
    encrypt();
    decrypt();

    return 0; 
}


