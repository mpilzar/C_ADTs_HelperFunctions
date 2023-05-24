#include <stdio.h>
#include <stdlib.h>

List *list_create();
int list_size(List *);
int list_isempty(List *);
int list_getfirst(List *);
int list_getlast(List *);
int list_getprev(List *, int );
int list_getnext(List *, int );
List *list_addbefore(List *, int , int );
List *list_addafter(List *, int , int );
List *list_addfirst(List *, int );
List *list_addlast(List *, int );
List *list_remove(List *, int );
void list_print(List *);
void list_free(List *l);
