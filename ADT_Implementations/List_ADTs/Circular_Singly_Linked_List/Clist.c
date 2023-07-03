#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Clist;


Clist* clist_create(int data){
    Clist* newnode = (Clist*)malloc(sizeof(Clist));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


Clist* clist_insertatstart(Clist* head, int data){
    Clist* newnode = clist_create(data);
    if(head == NULL){ newnode->next = newnode; return newnode;}
    newnode->next = head->next;
    head->next = newnode;
    return head;
}


Clist* clist_insertatend(Clist* head, int data){
    Clist* newnode = createNode(data);
    if(head == NULL){ newnode->next = newnode; return newnode;}
    newnode->next = head->next;
    head->next = newnode;
    return newnode;
}


void clist_print(Clist* head){
    if(head == NULL){ printf("List is empty.\n"); return;}
    Clist* temp = head->next;
    printf("Circular Linked List: ");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("\n");
}


void clist_destroy(Clist* head){
    if(head == NULL){ return;}
    Clist* cur = head->next;
    Clist* temp;
    while(cur != head){
        temp = cur;
        cur = cur->next;
        free(temp);
    } free(head);
}


int clist_size(Clist* head){
    if(head == NULL){return 0;}
    int count = 0;
    Clist* temp = head->next;
    do{
        count++;
        temp = temp->next;
    } while (temp != head->next);
    return count;
}


int clist_isempty(Clist* head){
    return head == NULL ? 1 : 0;
}


Clist* list_delete(Clist* head, int data){
    if(head == NULL){ return NULL;}
    Clist* cur = head->next;
    Clist* prev = head;
    if(cur->data == data){ 
        prev->next = cur->next;
        if(head == cur){head = prev;}
        free(cur);
        return head;
    }
    while(cur != head){
        if (cur->data == data) {
            prev->next = cur->next;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Node containing data %d not found.\n", data);
    return head;
}


Clist* list_sort_asc(Clist* head){
    if(head == NULL || head->next == head){return head;}
    Clist* cur = head->next;
    Clist* temp;
    int swapped;
    do{
        swapped = 0;
        temp = head->next;
        while (temp->next != head) {
            if (temp->data > temp->next->data) {
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = 1;
            }
            temp = temp->next;
        }
        cur = temp;
    } while (swapped);
    return head;
}

// Function to sort the circular linked list in descending order
Clist* list_sort_dsc(Clist* head){
    if(head == NULL || head->next == head){return head;}
    Clist* cur = head->next;
    Clist* temp;
    int swapped;
    do{
        swapped = 0;
        temp = head->next;
        while (temp->next != head) {
            if (temp->data < temp->next->data) {
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = 1;
            }
            temp = temp->next;
        }
        cur = temp;
    } while (swapped);
    return head;
}