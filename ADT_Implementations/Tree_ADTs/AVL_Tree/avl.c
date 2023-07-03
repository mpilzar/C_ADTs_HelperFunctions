#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} AVLnode;



AVLnode* avl_createnode(int key){
    AVLnode* node = (AVLnode*)malloc(sizeof(AVLnode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return node;
}


int getHeight(AVLnode* node){
    if(node == NULL){return 0;}
    return node->height;
}


int getBalance(AVLnode* node){
    if(node == NULL){return 0;}
    return getHeight(node->left) - getHeight(node->right);
}


void updateHeight(AVLnode* node){
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


AVLnode* rotateRight(AVLnode* y){
    AVLnode* x = y->left;
    AVLnode* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}


AVLnode* rotateLeft(AVLnode* x){
    AVLnode* y = x->right;
    AVLnode* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}


AVLnode* avl_insert(AVLnode* node, int key) {
    if(node == NULL){ return newNode(key);}
    if(key < node->key){ node->left = insert(node->left, key);}   
    else if(key > node->key){ node->right = insert(node->right, key);}
    else{ return node;}
    updateHeight(node);
    int balance = getBalance(node);
    if(balance > 1 && key < node->left->key){ return rotateRight(node);}
    if(balance < -1 && key > node->right->key){ return rotateLeft(node);}
    if(balance > 1 && key > node->left->key){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}


AVLnode* avl_delete(AVLnode* root, int key) {
    if(root == NULL){ return root;}
    if(key < root->key){ root->left = avl_delete(root->left, key);}
    else if(key > root->key){ root->right = avl_delete(root->right, key);}  
    else{
        if ((root->left == NULL) || (root->right == NULL)){
            AVLnode* temp = root->left ? root->left : root->right;
            if(temp == NULL){
                temp = root;
                root = NULL;
            }else{ *root = *temp; } 
            free(temp);
        }else {
            AVLnode* temp = findMinNode(root->right); 
            root->key = temp->key;
            root->right = avl_delete(root->right, temp->key);
        }
    }
    if(root == NULL){ return root;}
    updateHeight(root);
    int balance = getBalance(root);
    if(balance > 1 && getBalance(root->left) >= 0){ return rotateRight(root);}
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(balance < -1 && getBalance(root->right) <= 0){ return rotateLeft(root);}
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}


void avl_inorder(AVLnode* root){
    if(root != NULL){
        avl_inorder(root->left);
        printf("%d ", root->key);
        avl_inorder(root->right);
    }
}


void avl_preorder(AVLnode* root){
    if(root != NULL){
        printf("%d ", root->key);
        avl_preorder(root->left);
        avl_preorder(root->right);
    }
}


void avl_postorder(AVLnode* root){
    if(root != NULL){
        avl_postorder(root->left);
        avl_postorder(root->right);
        printf("%d ", root->key);
    }
}

AVLnode* avl_max(AVLnode* root) {
    if(root == NULL || root->right == NULL){ return root;}
    return avl_max(root->right);
}

AVLnode* avl_min(AVLnode* root) {
    if(root == NULL || root->left == NULL){ return root;}
    return avl_min(root->left);
}