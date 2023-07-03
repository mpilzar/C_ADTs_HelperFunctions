#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Clist;

Clist* clist_create(int data) {
    Clist* newnode = (Clist*)malloc(sizeof(Clist));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

Clist* clist_insertatstart(Clist* head, int data) {
    Clist* newnode = clist_create(data);
    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }
    newnode->next = head->next;
    newnode->prev = head;
    head->next->prev = newnode;
    head->next = newnode;
    return head;
}

Clist* clist_insertatend(Clist* head, int data) {
    Clist* newnode = clist_create(data);
    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }
    newnode->next = head->next;
    newnode->prev = head;
    head->next->prev = newnode;
    head->next = newnode;
    return newnode;
}

void clist_print(Clist* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Clist* temp = head->next;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("\n");
}

void clist_destroy(Clist* head) {
    if (head == NULL) {
        return;
    }
    Clist* curr = head->next;
    Clist* temp;
    while (curr != head) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(head);
}

int clist_size(Clist* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    Clist* temp = head->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != head->next);
    return count;
}

int clist_isempty(Clist* head) {
    return head == NULL ? 1 : 0;
}

Clist* list_delete(Clist* head, int data) {
    if (head == NULL) {
        return NULL;
    }
    Clist* curr = head->next;
    while (curr != head) {
        if (curr->data == data) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if (head == curr) {
                head = curr->next;
            }
            free(curr);
            return head;
        }
        curr = curr->next;
    }
    printf("Node containing data %d not found.\n", data);
    return head;
}

Clist* list_sort_asc(Clist* head) {
    if (head == NULL || head->next == head) {
        return head;
    }
    Clist* curr = head->next;
    Clist* temp;
    int swapped;
    do {
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
        curr = temp;
    } while (swapped);
    return head;
}

Clist* list_sort_dsc(Clist* head) {
    if (head == NULL || head->next == head) {
        return head;
    }
    Clist* curr = head->next;
    Clist* temp;
    int swapped;
    do {
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
        curr = temp;
    } while (swapped);
    return head;
}