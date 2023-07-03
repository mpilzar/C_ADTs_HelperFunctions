#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int data;
    int priority;
} QueueElement;

typedef struct{
    QueueElement elements[MAX_SIZE];
    int size;
} PriorityQueue;



void pqueue_init(PriorityQueue* queue){
    queue->size = 0;
}


int pqueue_isfull(PriorityQueue* queue){
    return queue->size == MAX_SIZE;
}


int pqueue_isempty(PriorityQueue* queue){
    return queue->size == 0;
}


void pqueue_enqueue(PriorityQueue* queue, int data, int priority){
    if(isFull(queue)){ printf("Queue is full.\n"); return;}
    QueueElement newElement;
    newElement.data = data;
    newElement.priority = priority;
    int i;
    for(i = queue->size - 1; i >= 0; i--){
        if(queue->elements[i].priority > priority){queue->elements[i + 1] = queue->elements[i];}
        else{ break;}
    }
    queue->elements[i + 1] = newElement;
    queue->size++;
}


QueueElement pqueue_dequeue(PriorityQueue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty.\n");
        QueueElement emptyElement = {0, 0};
        return emptyElement;
    }
    QueueElement front = queue->elements[0];
    int i;
    for(i = 0; i < queue->size - 1; i++){ queue->elements[i] = queue->elements[i + 1];}
    queue->size--;
    return front;
}


void pqueue_print(PriorityQueue* queue){
    printf("Priority Queue: ");
    for(int i = 0; i < queue->size; i++){ printf("(%d, %d) ", queue->elements[i].data, queue->elements[i].priority);}
    printf("\n");
}