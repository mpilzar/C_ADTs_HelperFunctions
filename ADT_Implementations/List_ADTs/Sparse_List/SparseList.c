#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
    int data;
    int nullcount;
    struct listnode *next;
} SPlist;



SPlist* splist_create(){
    SPlist* head = malloc(sizeof(SPlist));
    head->data = NULL;
    head->nullcount = 0;
    head->next = NULL;
}


SPlist* splist_addspaces(SPlist* head, int number_of_spaces){
    if(head == NULL){printf("Empty list"); return head;} 
    //This condition should never be true if list is created with splist_create.
    //Therefore it will not be added to any other function.

    SPlist* cur = head;
    while(cur->next != NULL){cur = cur->next;}
    cur->nullcount += number_of_spaces;
    return head;
}


SPlist* splist_adddata(SPlist* head, int data){
    SPlist* cur = head;
    while(cur->next != NULL){cur = cur->next;}
    SPlist* newnode = malloc(sizeof(SPlist));
    newnode->data = data;
    newnode->next = NULL;
    newnode->nullcount = 0;
    cur->next = newnode;
    return head;
}


void splist_print(SPlist* head){
    printf("The '-' character represents a null element. 'H' represents the head node.\n");
    SPlist* cur = head;
    int i;
    printf("H");
    while(cur != NULL){
        if(cur->data != NULL){printf("%d ", cur->data);}
        for(i = 0 ; i < cur->nullcount ; i++){printf("-");}
        cur = cur->next;
    } return;
}

void splist_free(SPlist* head){
    SPlist* cur = head;
    while(cur != NULL){
        SPlist* temp = cur;
        cur = cur->next;
        free(temp);  
    }        
}


SPlist* splist_addinpos(SPlist* head, int pos, int data){
    //Important to note that the head node is NOT taken into account as a node when calculation position.
    //Meaning the space after the head node has the position 1.
    int temppos = pos;
    SPlist* cur = head;
    if(cur->nullcount < pos){
        SPlist* newnode = malloc(sizeof(SPlist));
        newnode->nullcount = cur->nullcount - pos;
        newnode->data = data;
        newnode->next = cur->next;
        cur->next = newnode;
        cur->nullcount = pos - 1;
        return head;
    } else if(cur->nullcount = pos){
        SPlist* newnode = malloc(sizeof(SPlist));
        newnode->nullcount = 0;
        newnode->data = data;
        newnode->next = cur->next;
        cur->next = newnode;
        return head;
    } else{
        if(cur->next = NULL){
            cur->nullcount = temppos - 1;
            SPlist* newnode = malloc(sizeof(SPlist));
            newnode->nullcount = 0;
            newnode->data = data;
            newnode->next = NULL;
            cur->next = newnode;
            return head;
        } else{
            temppos -= cur->nullcount + 1;
            splist_addinpos(cur->next, cur->nullcount+1, data);
        }
    }
}


SPlist* splist_delete(SPlist* head, int data){
    SPlist* cur = head;
    if(cur->next == NULL){printf("Empty list.\n"); return head;}
    while(cur->next->data != data){
        cur = cur->next;
        if(cur->next == NULL){printf("Item not found.\n."); return head;}
    }
    SPlist* temp = cur->next;
    cur->nullcount += 1 + cur->next->nullcount;
    cur->next = temp->next;
    free(temp);
}


SPlist* splist_turntonull(SPlist* head, int data){
    SPlist* cur = head;
    if(cur->next == NULL){printf("Empty list.\n"); return head;}
    while(cur->next->data != data){
        cur = cur->next;
        if(cur->next == NULL){printf("Item not found.\n."); return head;}
    }
    SPlist* temp = cur->next;
    cur->nullcount += cur->next->nullcount;
    cur->next = temp->next;
    free(temp);
}
