#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Qnode;

typedef struct {
    struct Node* front;
    struct Node* rear;
} DEQ;


DEQ* deq_create(){
    DEQ* deque = (DEQ*)malloc(sizeof(DEQ));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

int deq_isempty(DEQ* deque){
    return (deque->front == NULL);
}


void deq_insertfront(DEQ* deque, int data){
    Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if(deque->front == NULL){ deque->rear = newNode;}
    else{ deque->front->prev = newNode;}
    deque->front = newNode;
}


void deq_insertrear(DEQ* deque, int data){
    Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
    newNode->data = data;
    newNode->prev = deque->rear;
    newNode->next = NULL;
    if(deque->rear == NULL){ deque->front = newNode;}
    else{ deque->rear->next = newNode;}
    deque->rear = newNode;
}

void deq_deletefront(DEQ* deque){
    if(isEmpty(deque)){ printf("Deque is empty.\n"); return;}
    Qnode* temp = deque->front;
    deque->front = deque->front->next;
    if(deque->front == NULL){ deque->rear = NULL;}
    else{ deque->front->prev = NULL;}
    free(temp);
}


void deq_deleterear(DEQ* deque){
    if(isEmpty(deque)){ printf("Deque is empty.\n"); return;}
    Qnode* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if(deque->rear == NULL){ deque->front = NULL;}
    else{ deque->rear->next = NULL;}  
    free(temp);
}


int deq_getfront(DEQ* deque){
    if (isEmpty(deque)){ printf("Deque is empty.\n"); return -1;}
    return deque->front->data;
}


int deq_getrear(DEQ* deque){
    if (isEmpty(deque)){ printf("Deque is empty.\n"); return -1;}
    return deque->rear->data;
}