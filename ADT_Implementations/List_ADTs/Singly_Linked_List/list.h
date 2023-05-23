typedef struct list List;

//Function to add an element at the end of the list
List *list_push(List *, int );


//Function to return the first element of the list
List *list_first(List *);


//Function to return the last element of a list
List* list_last(List* );


//Function de-allocate a list
void list_free(List* );


//Helper function to print a list
void list_print(List *);


//Function to return the size of a list
int list_size(List *);


//Function to return the  from a node
int list_get_data(List *);


//Function to return the next node in the list
List *list_get_next(List *);


//"Prepend" function to add element at the start of the list
List *list_prepend(List *, int );

//Function to add element after the first element
List *list_add_after_first(List *, int );

//Function to merge 2 lists
List *list_merge(List *, List *);