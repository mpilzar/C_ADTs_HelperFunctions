typedef struct listnode List;

List *dlist_create();
int dlist_size(List *);
int dlist_isempty(List *);
int dlist_getfirst(List *);
int dlist_getlast(List *);
int dlist_getprev(List *, int );
int dlist_getnext(List *, int );
List *dlist_addbefore(List *, int , int );
List *dlist_addafter(List *, int , int );
List *dlist_addfirst(List *, int );
List *dlist_addlast(List *, int );
List *dlist_remove(List *, int );
void dlist_print(List *);
void dlist_free(List *);
int* dlist_toarray(List* );
List* dlist_reverse(List* );
