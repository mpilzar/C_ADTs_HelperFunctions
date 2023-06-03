#include <stdio.h>
#include <stdlib.h>

typedef struct listnode List;
struct listnode{  //Doubly linked list
    List *prev;
    int data;
    List *next;
};

List *list_create(){    //Creates a new list with just a head (first) node and tail (last) node and returns it. Head and tail nodes don't store any data.
    List *head = NULL;
    head = malloc(sizeof(List));
    head->prev = NULL;
    List *tail = NULL;
    tail = malloc(sizeof(List));
    tail->next = NULL;
    head->next = tail;  //All subsequent nodes will be added between "head" and "tail".
    tail->prev = head;
    return head;
}

int dlist_size(List *l){     //Head and tail nodes not included.
    int i = 0;
    List *cur = l;  
    cur = cur->next;   //Skips head node.
    while(cur->next != NULL){ cur = cur->next;i++;}
    //i++ would be required here if the tail node didn't exist.
    return i;
}

int dlist_isempty(List *l){   //If there are no nodes between head and tail, the list is classified as empty.
    List *cur = l;       
    cur = cur->next;         //Skips head node.
    if(cur->next != NULL){return 1;}       
    else{return 0;}
}

int dlist_getfirst(List *l){    //Doesn't return head node, but the node after the head node.
    List *cur = l;
    cur = cur->next;    //Skips head node.
    return cur->data;
}

int dlist_getlast(List *l){
    List *cur = l;
    cur = cur->next;  //Skips head node
    while(cur->next != NULL){ cur = cur->next;}
    cur = cur->prev;  //This time going backwards, skips tail node.
    return cur->data;  //Returns last node before tail node.
}

int dlist_getprev(List *l, int i){  //No input check
    List *cur = l;
    int j;
    for(j = 0 ; j < i ; j++){   cur = cur -> next;}
    return cur->prev->data;

}

int dlist_getnext(List *l, int i){  //No input check
    List *cur = l;
    int j;
    for(j = 0 ; j < i ; j++){ cur = cur -> next;}
    return cur->next->data;
}

List *dlist_addbefore(List *l, int data, int i){
    List *node = malloc(sizeof(List));      //Creates new node
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    List *cur = l;
    int j;
    for(j = 0 ; j < i ; j++){cur = cur->next;}
    node->prev = cur->prev;   //Adds node before node i.
    node->next = cur;
    (cur->prev)->next = node;
    cur->prev = node;
    return l;
}


List *dlist_addafter(List *l, int data, int i){
    List *node = malloc(sizeof(List));
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    List *cur = l;
    int j;
    for(j = 0 ; j < i+1 ; j++){ cur = cur->next;}
    node->prev = cur->prev;     
    node->next = cur;
    (cur->prev)->next = node;
    cur->prev = node;
    return l;
}

List *dlist_addfirst(List *l, int data) {   //Adds node after head node.
    List *node = malloc(sizeof(List));
    node->next = l->next;
    node->prev = l;            //Initializes node and adds it to the list at the same time.
    node->data = data;
    l->next->prev = node;
    l->next = node;
    return l;
}


List *dlist_addlast(List *l, int data){
    List *node = malloc(sizeof(List));    //This time the node is initialized before being added to the list.
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    List *cur = l;
    while(cur->next !=NULL){cur = cur->next;}
    node->prev = cur->prev;       //Adds node before tail node.
    node->next = cur;   
    (cur->prev)->next = node;
    cur->prev = node;
    return l;
}

List *dlist_remove(List *l, int data){   //I didn't check for correct input.
    List *cur = l;
    cur = cur->next;  //Skip head node.
    while(cur->data != data){cur = cur->next;}
    (cur->prev)->next = cur->next;
    (cur->next)->prev = cur->prev;
    free(cur);
    return l;
}

void dlist_print(List *l){      //Prints list
    List *cur = l->next;
    while(cur->next != NULL){ 
        printf("%d  ", cur->data);
        cur = cur->next;
    }
}


void dlist_free(List *l){  //Not required, but i used it for the unit tests.
    List* cur = NULL;
    while (l != NULL) {
        cur = l->next;
        free(l);
        l = cur;
    }
}