#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;

void cq_init(CircularQueue* queue){
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int cq_isfull(CircularQueue* queue){
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1);
}

int cq_isempty(CircularQueue* queue){
    return queue->front == -1;
}

void cq_enqueue(CircularQueue* queue, int data){
    if(isFull(queue)){printf("Queue is full.n"); return;}
    if(isEmpty(queue)){ queue->front = 0;}
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = data;
    queue->size++;
}

int cq_dequeue(CircularQueue* queue){
    if(isEmpty(queue)){ printf("Queue is empty.\n"); return -1;}
    int data = queue->items[queue->front];
    if(queue->front == queue->rear){ cq_init(queue);}
    else{ queue->front = (queue->front + 1) % MAX_SIZE;}
    queue->size--;
    return data;
}

void cq_print(CircularQueue* queue){
    if(isEmpty(queue)){ printf("Queue is empty.\n"); return;}
    printf("Queue elements: ");
    int i = queue->front;
    while(i != queue->rear){
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[i]);
}