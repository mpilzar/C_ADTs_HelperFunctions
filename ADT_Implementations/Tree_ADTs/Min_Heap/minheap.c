#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* mnh_create(int capacity){
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mnh_heapify(MinHeap* heap, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < heap->size && heap->data[left] < heap->data[smallest]){ smallest = left;}
    if(right < heap->size && heap->data[right] < heap->data[smallest]){ smallest = right;}
    if(smallest != index){
        swap(&heap->data[index], &heap->data[smallest]);
        mnh_heapify(heap, smallest);
    }
}

void mnh_insert(MinHeap* heap, int value){
    if(heap->size == heap->capacity){ printf("Error: Heap is full.\n"); return;}
    int index = heap->size;
    heap->data[index] = value;
    while(index > 0 && heap->data[index] < heap->data[(index - 1) / 2]){
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    heap->size++;
}

int mnh_extract(MinHeap* heap){
    if(heap->size == 0){ printf("Error: Heap is empty.\n"); return -1;}
    int min = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    mnh_heapify(heap, 0);
    return min;
}

void mnh_print(MinHeap* heap){
    printf("Min Heap: ");
    for(int i = 0; i < heap->size; i++){ printf("%d ", heap->data[i]);}   
    printf("\n");
}