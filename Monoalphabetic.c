
//Monoalphabetic Cipher

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

void generateFullKey(char key[], char fullKey[]) {
    int used[ALPHABET_SIZE] = {0}, index = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        if (!used[key[i] - 'A']) {
            fullKey[index++] = key[i];
            used[key[i] - 'A'] = 1;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            fullKey[index++] = ch;
        }
    }
    fullKey[index] = '\0';
}
void Monoalphabetic(char message[], char key[], int mode) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (mode == 1) ? key[message[i] - 'A'] : 'A' + (strchr(key, message[i]) - key);
        }
    }
}
int main() {
    char plain[1000], key[ALPHABET_SIZE + 1], fullKey[ALPHABET_SIZE + 1];
    
    printf("Enter plaintext (uppercase letters only): ");
    scanf("%99[^\n]", &plain);
    
    printf("Enter encryption key (uppercase letters only): ");
    scanf("%s", key);
    
    generateFullKey(key, fullKey);
    printf("Generated full key: %s\n", fullKey);
    
    Monoalphabetic(plain, fullKey, 1);
    printf("Encrypted text: %s\n", plain);
    
    Monoalphabetic(plain, fullKey, 0);
    printf("Decrypted text: %s\n", plain);
    
    return 0;
}
