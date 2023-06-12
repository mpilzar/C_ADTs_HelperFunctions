# C ADTs & Helper Functions

An ever-expanding codebase of helper functions and implementations for data structures.

Code is licensed under the unlicense, so feel free to copy, reproduce, etc.

This project aims to build a reuseable codebase for in C.

## How to compile & test

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
- [ ] Unrolled Singly Linked List
- [ ] Unrolled Doubly Linked List
- [ ] Circular Singly Linked List
- [ ] Sparse List
- [ ] Self Sorting Ascending List
- [ ] Self Sorting Descending list
- [ ] Self-Adjusting List

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
