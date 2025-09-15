#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_SIZE 26
void countFrequency(const char *text, int *frequency) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            frequency[text[i] - 'a']++;}}
}
intfindMaxFrequencyIndex(const int *frequency) {
    int maxIndex = 0;
    for (int i = 1; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > frequency[maxIndex]) {
            maxIndex = i;}
        }
        return maxIndex;
}
void decrypt(const char *cipherText, int shift) {
    printf("Decrypted text with shift %d: ", shift);
    for (int i = 0; cipherText[i] != '\0'; i++) {
        if (cipherText[i] >= 'a' && cipherText[i] <= 'z') {
            char decryptedChar = 'a' + (cipherText[i] - 'a' - shift + ALPHABET_SIZE)
            % ALPHABET_SIZE;
            printf("%c", decryptedChar);
        } else {
            printf("%c", cipherText[i]);}
        }
        printf("\n");
}
int main() {
    char cipherText[] =
    "xultpaajcxitltlxaarpjhtiwtgxktghidhipxciwtvgtpilpithlxiwiwtxgqadds";
    int frequency[ALPHABET_SIZE] = {0};
    countFrequency(cipherText, frequency);
    int maxFreqIndex = findMaxFrequencyIndex(frequency);
    int shift = (maxFreqIndex + ALPHABET_SIZE - ('e' - 'a')) % ALPHABET_SIZE;
    decrypt(cipherText, shift);
    return 0;
}
