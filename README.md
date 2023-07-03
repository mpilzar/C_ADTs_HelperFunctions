# C ADTs & Helper Functions

This project aims to build an ever-expanding codebase of helper functions and implementations for
data structures in the C programming language.

Code is licensed under the unlicense, so feel free to copy, reproduce, etc. as you please.


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
- [x] Binary Search Tree (BST) [bst.c](ADT_Implementations/Tree_ADTs/Binary_Search_Tree/bst.c)
- [x] AVL Tree [avl.c](ADT_Implementations/Tree_ADTs/AVL_Tree/avl.c)
- [ ] 234 (2-4) Tree
- [x] Min Heap [minheap.c](ADT_Implementations/Tree_ADTs/Min_Heap/minheap.c)
- [x] Max Heap [maxheap.c](ADT_Implementations/Tree_ADTs/Max_Heap/maxheap.c)
- [ ] Red-Black Tree

### Graph ADTs:
- [ ] Directed Graph
- [ ] Undirected Graph
- [ ] Directed Weighted Graph
- [ ] Undirected Weighted Graph

### Queue ADTs:
- [x] Basic Queue [queue.c](ADT_Implementations/Queue_ADTs/Basic_Queue/queue.c)
- [x] Priority Queue with Max Heap [heappqueue.c](ADT_Implementations/Queue_ADTs/Heap_PriorityQueue/heappqueue.c)
- [x] Priority Queue with Array [arrpqueue.c](ADT_Implementations/Queue_ADTs/Array_PriorityQueue/arrpqueue.c)
- [x] Double-Ended Queue [dequeue.c](ADT_Implementations/Queue_ADTs/Double_Ended_Queue/dequeue.c)
- [x] Circular Queue [cqueue.c](ADT_Implementations/Queue_ADTs/CircularQueue/cqueue.c)

### Other ADTs:
- [x] Vector [vector.c](ADT_Implementations/Other_ADTs/Vector/vector.c)
- [x] Stack [stack.c](ADT_Implementations/Other_ADTs/Stack/stack.c)


