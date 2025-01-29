#include <stdio.h>
#include <ctype.h>  // For isalpha, toupper, and tolower functions
#include <string.h> // For string length

void capitalizeWords(char text[]) {
    int newWord = 1; // Flag to capitalize the first letter of each word

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (newWord) {
                text[i] = toupper(text[i]); // Capitalize the first letter
                newWord = 0;
            } else {
                text[i] = tolower(text[i]); // Lowercase the rest of the letters
            }
        } else {
            newWord = 1; // Set flag to capitalize the next alphabetic character
        }
    }
}

int main() {
    char text[1000];

    printf("Enter a sentence: ");
    fgets(text, sizeof(text), stdin); // Read the input sentence

    capitalizeWords(text);

    printf("Sentence after capitalizing each word:\n%s\n", text);

    return 0;
}
