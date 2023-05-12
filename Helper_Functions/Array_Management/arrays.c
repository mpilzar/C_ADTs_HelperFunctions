#include <stdio.h>
#include <stdlib.h>


//Functions that aid with array management.
//All functions work on integer arrays, but can be modified as necessary.


//Function to calculate the average of an array.
double arrayaverage(int* array, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){sum += array[i];}
    return (double)sum / size; 
}


//Function to print anarray.
void printarray(int* array, int size){
    for (int i = 0; i < size; i++){printf("%d ", array[i]);}
    printf("\n");
}


//Function to find the minimum element in an array.
int arraymin(int* array, int size){
    int min = array[0];
    for (int i = 1; i < size; i++){
        if (array[i] < min){min = array[i];}
    } return min;
}


//Function to find the maximum element in an array.
int arraymax(const int* array, int size){
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max){max = array[i];}
    } return max;
}


//Linear search method for the array.
int arrlinsearch(int array[], int size, int key) {
    for (int i = 0; i < size; i++){
        if (array[i] == key){ return i;}
    } return -1;
}


//Function to sort an array (insertion sort algorithm).
void arrsort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++){
        key = arr[i]; j = i - 1;
        while (j >= 0 && arr[j] > key){arr[j + 1] = arr[j]; j--;}
        arr[j + 1] = key;
    }
}


//Function to perform binary sort on an array
int arrbinsearch(int arr[], int size, int target){
    arrsort(arr, size);
    int left = 0, right = size - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {return mid;}
        else if (arr[mid] < target) {left = mid + 1;}
        else {right = mid - 1;}
    } return -1;
}


//Function to flip an array.
void arrflip(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


