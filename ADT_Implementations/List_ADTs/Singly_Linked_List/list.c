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

int list_isempty(List *l){
    if(l==NULL){return 1;}
    else{return 0;}
}

List* list_addpos(List* l, int value, int pos){
    List* newNode = createNode(value);
    if (l == NULL) {l = newNode;}
    else if (pos == 0) {
        newNode->next = l;
        l = newNode;
    } else {
        List* cur = l;
        int currentpos = 0;
        while (cur != NULL && currentpos < pos - 1) {
            cur = cur->next;
            currentpos++;
        }
        if (cur == NULL){cur->next = newNode;}
        else {
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

List* list_reverse(List* l){
    List* prev = NULL;
    List* cur = l;
    List* next = NULL;
    while (cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    l = prev;
}

List* list_deletefirst(List *l){
    List* temp = l;
    l = l->next;
    free(temp);
    return l;
}

List* list_deletelast(List* l){
    List* cur = l;
    List* prev = NULL;
    while (cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    return l;
}

int* list_toarray(List* l){
    int size = list_size(l);
    int arr[size];
    List* cur = l;
    int i = 0;
    while (cur != NULL){
        arr[i] = cur->data;
        cur = cur->next;
        i++;
    }
    return arr;
}

List* list_sortasc(List* l){
    int size = list_size(l);
    int arr[size];
    List* cur = l;
    int i = 0;
    while (cur != NULL){
        arr[i] = cur->data;
        cur = cur->next;
        i++;
    }
    int temp;
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    List* newlist = NULL;
    for (int i = 0; i < size; i++){
        newlist = list_push(newlist, arr[i]);
    }
    return newlist;
}

List* list_sortdesc(List* l){
    int size = list_size(l);
    int arr[size];
    List* cur = l;
    int i = 0;
    while (cur != NULL){
        arr[i] = cur->data;
        cur = cur->next;
        i++;
    }
    int temp;
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    List* newlist = NULL;
    for (int i = 0; i < size; i++){
        newlist = list_push(newlist, arr[i]);
    }
    return newlist;
}