# C ADTs & Helper Functions

An ever-expanding codebase of helper functions and implementations for data structures.

Code is licensed under the unlicense, so feel free to copy, reproduce, etc.

This project aims to build a reuseable codebase for in C.


## STATE OF THE PROJECT:
All helper functions complete. ADTs largely incomplete. No tests implemented yet.


## How to compile & test
____________________________________________________
NO TESTS IMPLEMENTED FOR NOW. IF YOU NEED THE CODE, JUST COPY & PASTE IT!
____________________________________________________

If the folder with the ADT you desire is incomplete, meaning it's lacking a makefile I haven't implemented a main function
to test the ADT yet. The code should still work, however, and you're free to copy and paste it.

If the folder is completed, meaning it has a completed header file, a main file and a makefile, run the following:
```
cd (folder of choice)
make
./main
```
If there is also a test file, you can run:
```
make test
./test
```

# Goal Checklist


## Helper Functions:
- [x] Array Management [arrays.c](Helper_Functions/Array_Management/arrays.c)
- [x] Input & Output [inout.c](Helper_Functions/Input_Output/inout.c)
- [x] Memory Management [memory.c](Helper_Functions/Memory_Management/memory.c)
- [x] Miscellaneous [misc.c](Helper_Functions/Miscellaneous/misc.c)
- [x] String Manipulation [strings.c](Helper_Functions/String_Manipulation/strings.c)
- [x] Sorting algorithms (For arrays) [sort.c](Helper_Functions/Sorting_Algorithms/sort.c)


## Advanced Data Types

### List ADTs:
- [x] Singly Linked List [list.c](ADT_Implementations/List_ADTs/Singly_Linked_List/list.c)
- [x] Doubly Linked List [dlist.c](ADT_Implementations/List_ADTs/Doubly_Linked_List/dlist.c)
- [x] Unrolled Linked List [UnrolledList.c](ADT_Implementations/List_ADTs/Unrolled_Linked_List/UnrolledList.c)
- [x] Circular Singly Linked List [Clist.c](ADT_Implementations/List_ADTs/Circular_Singly_Linked_List/Clist.c)
- [x] Circular Doubly Linked List [Cdlist.c](ADT_Implementations/List_ADTs/Circular_Doubly_Linked_List/Clist.c)
- [x] Sparse List [SparseList.c](ADT_Implementations/List_ADTs/Sparse_List/SparseList.c)
- [x] Self Sorting Ascending List [asclist.c](ADT_Implementations/List_ADTs/Asc_List/asclist.c)
- [x] Self Sorting Descending list [dsclist.c](ADT_Implementations/List_ADTs/Dsc_List/dsclist.c)
- [x] Self-Adjusting List [salist.c](ADT_Implementations/List_ADTs/Self-Adjusting_List/salist.c)

### Tree ADTs:
- [ ] Basic Tree
- [ ] Binary Search Tree (BST)
- [ ] AVL Tree
- [ ] 234 (2-4) Tree
- [ ] Min Heap
- [ ] Max Heap
- [ ] B Tree
- [ ] Red-Black Tree

### Graph ADTs:
- [ ] Directed Graph
- [ ] Undirectd Graph
- [ ] Directed Weighted Graph
- [ ] Undirected Weighted Graph

### Queue ADTs:
- [ ] Basic Queue
- [ ] Priority Queue with Max Heap
- [ ] Priority Queue with Array
- [ ] Double-Ended Queue
- [ ] Circular Queue

### Other ADTs:
- [ ] Vector
- [ ] Stack
- [ ] Hash Table
- [ ] Bloom Filter
