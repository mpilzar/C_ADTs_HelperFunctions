#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode* next;
} SAlist;

SAlist* salist_create(int data){
    SAlist* newNode = (SAlist*)malloc(sizeof(SAlist));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

SAlist* salist_insert(SAlist* head, int data){
    SAlist* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

SAlist* salist_find(SAlist* list, int data){
    if(list == NULL || list->data == data){ return list;}
    SAlist* prev = list;
    SAlist* current = list->next;
    while(current != NULL){
        if(current->data == data){
            prev->next = current->next;
            current->next = list;
            return current;
        }
        prev = current;
        current = current->next;
    } return NULL;
}

void salist_print(SAlist* list){
    SAlist* current = list;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    } printf("\n");
}

void salist_free(SAlist* list){
    SAlist* current = list;
    while (current != NULL){
        SAlist* temp = current;
        current = current->next;
        free(temp);
    }
}