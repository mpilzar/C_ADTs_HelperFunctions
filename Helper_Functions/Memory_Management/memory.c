#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*These functions aid with memory allocation.*/


//Memory allocation (malloc) with error handling.
void* mallocate(size_t num_elements, size_t element_size){
    void* ptr = malloc(num_elements * element_size);
    if (ptr == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE); 
    } return ptr;}
/*Example usage to allocate memory for an integer array with 5 elements:
    int* numbers = allocate_memory(5, sizeof(int));
*/


//Memory reallocation (realloc) with error handling.
void* reallocate(void* ptr, size_t new_size) {
    void* ptr2 = realloc(ptr, new_size);
    if (ptr2 == NULL && new_size > 0) {
        fprintf(stderr, "Memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    } return ptr2;}
/*Example usage to turn a 5 element array into a 10 element array:
    int* numbers = malloc(5 * sizeof(int));
    int* resized_numbers = resize_memory(numbers, 10 * sizeof(int));
*/


// Function to duplicate a string with memory allocation.
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
