#include <stdio.h>
#include <stdlib.h>

typedef struct list List;
struct list{
    int data;
    List* next;
};

//Function to add an element at the end of the list
List *list_push(List *l, int data){
    List *node = malloc(sizeof(List));
    node->next = NULL;
    node->data = data;
    if(l==NULL){l = node;}
    else{
        List *cur = l;
        while(cur->next!=NULL){cur = cur->next;}
        cur->next = node;
    } return l;
}

//Function to return the first element of the list
List *list_first(List *l){return l;}

//Function to return the last element of a list
List* list_last(List* l){
    if (l == NULL){return l;}
    while (l->next != NULL){l = l->next;}
    return l;
}

//Function de-allocate a list
void list_free(List* l){
    List* cur = NULL;
    while (l != NULL) {
        cur = l->next;
        free(l);
        l = cur;
    }
}

//Helper function to print a list
void list_print(List *l){
    List *cur = l;
    printf("[");
    while(cur!=NULL){
        if(cur->next!=NULL){printf("%d, ",cur->data);}
        else{printf("%d",cur->data);}
        cur = cur->next;
    } printf("]\n");
}

//Function to return the size of a list
int list_size(List *l){
    List *cur = l;
    int count = 0;
    while(cur!=NULL){
        count++;
        cur = cur->next;
    }return count;
}

//Function to return the data from a node
int list_get_data(List *l){return l->data;}

//Function to return the next node in the list
List *list_get_next(List *l){return l->next;}

//Function to add element at the start of the list
List *list_prepend(List *l, int data){
    List *node = malloc(sizeof(List));
    node->next = l;
    node->data = data;
    return node;
}

//Function to add element after the first element
List *list_add_after_first(List *l, int data){
    List *node = malloc(sizeof(List));
    node->next = l->next;
    node->data = data;
    l->next = node;
    return l;
}

//Function to merge 2 lists
List *list_merge(List *l1, List *l2){
    List *temp = l1;
    while(temp->next != NULL){temp = temp->next;}
    temp->next = l2;
    return l1;
}