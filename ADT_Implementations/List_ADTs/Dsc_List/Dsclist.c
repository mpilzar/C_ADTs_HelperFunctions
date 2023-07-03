#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int data;
    struct List* next;
} List;


List* list_create(){
    List* head = (List*)malloc(sizeof(List));
    head = NULL;
    return head;
}

List* list_insert(List* head, int data) {
    List* new_List = (List*)malloc(sizeof(List));
    new_List->data = data;
    new_List->next = NULL;
    if (head == NULL || data > head->data) {
        new_List->next = head;
        head = new_List;
    } else {
        List* current = head;
        while (current->next != NULL && current->next->data > data) {
            current = current->next;
        }
        new_List->next = current->next;
        current->next = new_List;
    }
    return head;
}

void list_print(List* head){
    List* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void list_free(List* head){
    List* current = head;
    while(current != NULL){
        List* temp = current;
        current = current->next;
        free(temp);
    }
}