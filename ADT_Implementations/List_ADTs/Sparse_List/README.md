A sparse list is a list with many empty spaces between non-empty elements.

For more efficient memory usage, instead of implementing the sparse list like a 
regular list with many null elements, each listnode struct has 3 different fields in my own implementation:

1.  The listnode's data.
2.  An integer number representing the number of NULL elements before the next non-NULL element,
    which could wither be a NULL element or the end of the list.
3.  The pointer to the next node.

For implementation purposes, the list, whether empty or not, always has a head node, whose data field is always empty.

__________________________________________________

Function included in the implementation for integer sparse list:

-   splist_create (Creates sparse list.)
-   splist_addspaces (Adds X number of spaces at the end of the list.)
-   splist_adddata (Adds data at the end of the list.)
-   splist_print (Prints the list.)
-   splist_free (Deallocates list.)
-   splist_addinpos (Adds data X number of positions after the head node. If position number exceeds list size, adds more spaces.)
-   splist_turntonull (Turns a non-NULL element of the list to NULL.)
-   splist_delete (Removes a non-NULL element.)