#include <stdio.h>
#include <stdlib.h>

//These functions aid in input and output.

/*      CONTENTS:
    visit: Function to print an integer, passed as input in other functions.
    setcursorposition: Function to set a cursor's position to the given coordinates.
    clearconsole: Function clears the console.
    showprogressbar: Function to display a progress bar.
    r_ch: Function reads a character variable.
    r_int: Function reads an integer variable.
*/


//Function to print an integer, passed as input in other functions.
void visit(int data) {
    printf("%d ", data); }
/*Example usage:
    void preorder(BSTNode* root, Visit visit)
        (example function to print the contents of a BST)
*/


//Function to set a cursor's position to the given coordinates.
void setcursorposition(int x, int y){
    printf("\033[%d;%dH", y, x); }
/*Example usage:
    setcursorposition(13, 26)
*/


//Function clears the console.
//Only works in a linux environment.
void clearconsole(){
    system("clear"); }
/*Example usage:
    Use clearconsole after scan functions to clear the appearance of the console.
*/


//Function to display a progress bar.
//The clearconsole command can be omitted. It is used to clear the previous version
//of the progress bar before printing the current one.
void showprogressbar(double progress, int barWidth) {
    clearconsole(); printf("[");
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos){ printf("=");
        } else if (i == pos){ printf(">");
        } else{ printf(" "); } }
    printf("] %.2f%%\r", progress * 100);
    fflush(stdout); }
/*Example usage in a for loop:
    int totalSteps = 100;
    for (int i = 0; i <= totalSteps; ++i){
        double progress = (double)i / totalSteps;
        showProgressBar(progress, 20);
*/


//Function reads a character variable.
char r_ch(){
    char ch; scanf(" %c", &ch); return ch; }
/*Example usage:
    char ch = readch;
*/


//Function reads an integer variable.
//(Of course the variables can be adjusted for any variable type and be used to save time and space).
int r_int(){
    int num; scanf("%d", &num); return num; }
/*Example usage:
    int num = readint;
*/


