#include <stdio.h>
#include <stdlib.h>


//Miscellaneous helper functions.


//Function to swap 2 integers.
void swapIntegers(int *a, int *b){
    int temp = *a; *a = *b; *b = temp; }
/*Call by reference is used to avoid errors*/


//Power function.
int power(int base, int pow){
    int result = 1;
    while (pow > 0){ result *= base; pow--;}
    return result; }
/*Used to avoid including the math.h header file.*/


//Factorial function
int factorial(int n){
    int result = 1;
    while (n > 0){ result *= n; n--;}
    return result; }
/*Used to avoid including the math.h header file.*/


//Function returns 1 if the given number is a prime number, else 0.
int isPrime(int num) {
    if (num <= 1){ return 0;} int i;
    for (i = 2; i <= num / 2; i++){
        if (num % i == 0){ return 0;}
    } return 1;
}


//Function returns 1 if character is a decimal number, 0 if it is not.
int isnumber(char ch){ 
  if((ch >= '0') && (ch <= '9')){return 1;}
  else{return 0;} 
}


//Like isnumber but for operators
int isoperator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){return 1;}
  else{return 0;} 
}