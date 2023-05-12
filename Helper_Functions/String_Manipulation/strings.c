#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//These functions aid with string manipulation and are not included in the string.h header file.


// Function to duplicate a string with memory allocation. (Initially in memory management file).
// Can also be used to initialize a string.
char* copystring(const char* str) {
    if (str == NULL) {return NULL;}
    size_t len = strlen(str);
    char* str2 = mallocate(len + 1, sizeof(char));
    strcpy(str2, str);
    return str2; }
/*Example useage:
    Initialization: str = copystring("This is a string");
    Duplication: str2 = copystring(str);
*/


//This function reverses a string.
char* strreverse(char* str) {
    size_t length = strlen(str);
    char* reversed = (char*)malloc((length + 1) * sizeof(char));
    if (reversed == NULL){ fprintf(stderr, "Memory allocation failed.\n"); return NULL;}
    for (size_t i = 0; i < length; i++) { reversed[i] = str[length - i - 1]; }
    reversed[length] = '\0';
    return reversed; }
/*Example usage of a string being reversed:
    str = copystring("adopana");
    strrev = strreverse(str);
    printf("%s", strrev); -> anapoda
*/


//Function to count the number of words in a string.
int strwordcount(const char* str) {
    int count = 0, is_word = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !is_word) {
            is_word = 1;
            count++;
        } else if (str[i] == ' ') { is_word = 0;}
    } return count;}
/*Example usage:
    wordcount = strwordcount(str);
*/


//Function to remove every character of string 2 from string 1.
char* str_remove_chars(const char* str, const char* chars) {
    size_t length = strlen(str);
    char* result = (char*)malloc((length + 1) * sizeof(char));
    if (result == NULL){ fprintf(stderr, "Memory allocation failed.\n"); return NULL;}
    size_t j = 0;
    for (size_t i = 0; i < length; i++) { 
        if (strchr(chars, str[i]) == NULL){ result[j] = str[i]; j++; }
    }
    result[j] = '\0'; return result; }
/*Example implementation:
    const char* originalstring = "Hello, World!";
    const char* charstoremove = "o, ";
    char* modifiedstring = str_remove_chars(originalString, charsToRemove);
        original: Hello, world.
        modified: Hellwrld.
*/