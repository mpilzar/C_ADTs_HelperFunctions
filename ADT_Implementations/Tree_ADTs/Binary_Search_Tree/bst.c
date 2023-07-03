#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} BSTnode;


BSTnode* bst_create(int data){
    BSTnode* newNode = (BSTnode*)malloc(sizeof(BSTnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


BSTnode* bst_insert(BSTnode* root, int data){
    if(root == NULL){ return bst_create(data);}
    if(data < root->data){ root->left = bst_insert(root->left, data);}
    else if(data > root->data){ root->right = bst_insert(root->right, data);}
    return root;
}


BSTnode* bst_search(BSTnode* root, int data) {
    if(root == NULL || root->data == data){ return root;}
    if(data < root->data){ return bst_search(root->left, data);}
    return bst_search(root->right, data);
}


void bst_inorder(BSTnode* root){
    if(root != NULL){
        bst_inorder(root->left);
        printf("%d ", root->data);
        bst_inorder(root->right);
    }
}


void bst_preorder(BSTnode* root){
    if(root != NULL){
        printf("%d ", root->data);
        bst_preorder(root->left);
        bst_preorder(root->right);
    }
}


void bst_postorder(BSTnode* root){
    if(root != NULL){
        bst_postorder(root->left);
        bst_postorder(root->right);
        printf("%d ", root->data);
    }
}

BSTnode* bst_max(BSTnode* root) {
    if(root == NULL || root->right == NULL){ return root;}
    return bst_max(root->right);
}

BSTnode* bst_min(BSTnode* root) {
    if(root == NULL || root->left == NULL){ return root;}
    return bst_min(root->left);
}