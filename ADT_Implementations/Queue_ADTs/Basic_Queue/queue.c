#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for queue
typedef struct q{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;


Queue* queue_create(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}


int queue_isfull(Queue* queue){
    return queue->rear == MAX_SIZE - 1;
}


int queue_isempty(Queue* queue) {
    return queue->front == -1;
}


void queue_enqueue(Queue* queue, int item) {
    if(isFull(queue)){ printf("Queue is full.\n"); return;}
    if(isEmpty(queue)){ queue->front = 0;}
    queue->rear++;
    queue->items[queue->rear] = item;
}


int queue_dequeue(Queue* queue){
    int item;
    if(isEmpty(queue)){ printf("Queue is empty.\n"); return -1;}
    item = queue->items[queue->front];
    if(queue->front >= queue->rear){ queue->front = -1; queue->rear = -1;}
    else{ queue->front++;}
    return item;
}


void queue_print(Queue* queue) {
    if(isEmpty(queue)){ printf("Queue is empty.\n"); return;}
    printf("Queue elements: ");
    for(int i = queue->front; i <= queue->rear; i++){ printf("%d ", queue->items[i]);}
    printf("\n");
}