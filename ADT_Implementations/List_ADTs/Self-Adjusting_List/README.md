A self-adjusting list is a list where each time an element is accessed, it is brought
to the front of the list (splaying). This means we can only insert nodes at the start, since
inserting a node to the list means accessing it, and thus it must be 'splayed'.

The functions implemented for this data structure are:

-   salist_create
-   salist_insert
-   salist_find
-   salist_print
-   salist_free
