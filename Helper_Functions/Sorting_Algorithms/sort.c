#include <stdio.h>
#include <stdlib.h>

//List of sorting algorithms, implemented for integer arrays.
/*      CONTENTS:
    Bubble Sort
    Quick Sort
    Insertion Sort
    Selection Sort
*/



//Bubble sort.
int* arrbubblesort(int* arr, int size){
    int i, j, temp;
    for(i = 0 ; i < size ; i++){
        for(j = 0 ; j < size - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    } return arr;
}



void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Quick sort.
int* arrquicksort(int* arr, int size){
    quicksort(arr, 0, size - 1);
    return arr;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Partition function for Quick Sort
int partition(int* arr, int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}



//Selection sort.
int* arrselectionsort(int* arr, int size){
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++){
        minIndex = i;
        for (j = i + 1; j < size; j++){
            if (arr[j] < arr[minIndex]){minIndex = j;}
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    } return arr;
}



//Insertion sort.
int* arrinsertionsort(int* arr, int size){
    int i, j, key;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    } return arr;
}