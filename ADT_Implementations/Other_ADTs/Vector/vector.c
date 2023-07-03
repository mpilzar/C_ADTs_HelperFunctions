#include <stdio.h>
#include <stdlib.h>


typedef int datatype;

typedef struct vector_struct {
    datatype*   array;
    int size;
    int capacity;
} Vector;


Vector* vector_create(int capacity){
    Vector* v = malloc(sizeof(Vector));
    v->array = malloc(sizeof(datatype) * capacity);
    v->capacity = capacity;
    v->size = 0;
    return v;
}


void vector_free(Vector* vector){
    free(vector);
}


datatype vector_at(Vector* vector, int index){
    return vector->array[index];     
}


void vector_set_at(Vector* vector, int index, datatype data){
    if((index) < vector->capacity){
        if(vector->array[index] = 0){ vector->size++;}
        vector->array[index] = data;
    }
}


void vector_push_back(Vector* vector, datatype data){
    if(vector->size >= vector->capacity){
        vector->capacity *= 2;
        vector->array = realloc(vector ->array, sizeof(datatype) * vector->capacity);
    }
    vector->array[vector->size] = data;
    vector->size++;
}


int vector_size(Vector* vector){
    return vector->size;
}


int vector_capacity(Vector* vector){
    return vector->capacity;
}