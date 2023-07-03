#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4

typedef struct Node {
    int count;               
    int elements[BLOCK_SIZE];
    struct Node* next;         
} UList;

UList* ulist_create(){
    UList* newnode = malloc(sizeof(UList));
    newnode->count = 0;
    newnode->next = NULL;
    return newnode;
}

UList* ulist_insert(UList* head, int data){
    if(head == NULL){ head = ulist_create(); head->elements[0] = data; head->count++; return head;}
    UList* cur = head;
    while(cur->next != NULL && cur->count == BLOCK_SIZE){ cur = cur->next;}
    if(cur->count < BLOCK_SIZE){ cur->elements[cur->count] = data; cur->count++;}
    else if(cur->next == NULL){
        UList* newnode = ulist_create();
        newnode->elements[0] = data;
        newnode->count++;
        cur->next = newnode;
    } return head;
}

int ulist_size(UList *head){
    int size = 0;
    while(head != NULL){ size += head->count; head = head->next;}
    return size;
}

void ulist_print(UList* head){
    if(head == NULL){printf("Empty list."); return;}
    int i;
    while(head != NULL){
        for(i = 0 ; i < head->count ; i++){ printf("%d ", head->elements[i]);}
        head = head->next;
        printf("\n");
    }
}

void ulist_free(UList* head) {
    UList* cur = head;
    while (cur != NULL) {
        UList* temp = cur;
        cur = cur->next;
        free(temp->elements);  
        free(temp);  
    }        
}

int ulist_isempty(UList* head){
    return head == NULL ? 1 : 0;
}

int* ulist_first(UList* head){
    if(head == NULL){printf("Empty list."); return 0;}
    return head->elements;
}

int* ulist_last(UList* head){
    if(head == NULL){printf("Empty list."); return 0;}
    while(head->next != NULL){head = head->next;}
    return head->elements;
}

UList* ulist_delete(UList* head, int data) {
    if (head == NULL){printf("Empty list.\n"); return head;}
    UList* cur = head;
    int i, temppos = -1;
    while(cur != NULL){
        for(i = 0; i < cur->count; i++){
            if(cur->elements[i] == data){
                temppos = i;
                break;  
            }
        }
        if(temppos != -1) {
            for(i = temppos; i < cur->count - 1; i++){cur->elements[i] = cur->elements[i + 1];}
            cur->count--;
            printf("Item deleted.\n");
            return head;
        } cur = cur->next;
    }
    printf("Item not found.\n");
    return head;
}

UList* ulist_merge(UList* list1, UList* list2){
    if(list1 == NULL){ return list2;}
    UList* current = list1;
    while(current->next != NULL){ current = current->next;}
    current->next = list2;
    return list1;
}
