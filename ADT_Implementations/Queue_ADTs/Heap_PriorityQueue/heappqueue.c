#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct pqueue{
    int count;
    int capacity;
} PQ;


PQ* pq_init(int capacity){
    PQ* queue = malloc(sizeof(PQ));
    queue->capacity = capacity;
    queue->count = 0;
    return queue;
}


PQ* pq_enqueue(int data, MaxHeap* heap, PQ* queue){
    mxh_insert(heap, data);
    queue->count++;
}


PQ* pq_dequeue(MaxHeap* heap, PQ* queue){
    int data = mxh_extract(heap);
    queue->count--;
}


// ------------------------------
// Max heap implementation:
// ------------------------------

typedef struct {
    int* data;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* mxh_create(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mxh_heapify(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < heap->size && heap->data[left] > heap->data[largest]){ largest = left;}
    if(right < heap->size && heap->data[right] > heap->data[largest]){ largest = right;}
    if(largest != index){
        swap(&heap->data[index], &heap->data[largest]);
        mxh_heapify(heap, largest);
    }
}

void mxh_insert(MaxHeap* heap, int value) {
    if(heap->size == heap->capacity){ printf("Error: Heap is full.\n"); return;}
    int index = heap->size;
    heap->data[index] = value;
    while (index > 0 && heap->data[index] > heap->data[(index - 1) / 2]) {
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    heap->size++;
}

int mxh_extract(MaxHeap* heap) {
    if(heap->size == 0){ printf("Error: Heap is empty.\n"); return -1;}
    int max = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    mxh_heapify(heap, 0);
    return max;
}