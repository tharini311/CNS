#include <stdio.h> 
#include <string.h> 
// Function to perform Caesar cipher encryption/decryption 
void caesar(char text[], int shift) {
 for (int i = 0; text[i] != '\0'; ++i) {
 if (text[i] >= 'a' && text[i] <= 'z') {
 text[i] = 'a' + (text[i] - 'a' + shift + 26) % 26;
 } else if (text[i] >= 'A' && text[i] <= 'Z') {
 text[i] = 'A' + (text[i] - 'A' + shift + 26) % 26;
 } 
 } 
} 
int main() {
 char message[100]; 
 int key; 
 // Asking user for the message 
 printf("Enter a message to encrypt: ");
 fgets(message, sizeof(message), stdin);
 // Removing the newline character, if present 
 message[strcspn(message, "\n")] = '\0'; 
 // Asking user for the key 
 printf("Enter a key: ");
 scanf("%d", &key);
 // Encryption 
 caesar(message, key);
 printf("Encrypted message: %s\n", message);
 // Decryption 
 caesar(message, -key);
 printf("Decrypted message: %s\n", message);
 return 0; 
} 
