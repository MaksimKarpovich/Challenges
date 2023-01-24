
# Binary search tree


## The Challenge


You are given a list of numbers stored in a list, *A*. Your challenge is to build a [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree) to store these numbers. You will need to:

- [x] Represent each node of the tree (including its data, left child and right child).
- [x] Print the tree out in an understandable form.
- [x] Add value lookup by key.
- [x] Make correct node deletion by key.
- [x] Make a function to insert a list of numbers (*A*) into the tree.
- [x] Check if you can insert all the numbers in *A* into your tree, and that it prints out as expected.

 ### Intermediate difficulty

- [ ] Write a function to check if the [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree) that you’ve created is [balanced](https://en.wikipedia.org/wiki/Binary_search_tree#Balanced_binary_search_trees). 

A tree is considered balanced when the difference between the min depth and max depth does not exceed 1, i.e. if the list had *n* elements in it the height of the tree would be log<sub>2</sub>(*n*).


### Hard Difficulty


- [ ] Adapt your function to insert a list of n numbers so that it runs in O(*n* log *n*) time. 

Bear in mind that this is just the average case for a random sequence of numbers. If the list *A* was sorted it would take O(*n*<sup> 2</sup>). Adapt your function to check if the tree is balanced so that it runs in O(*n*) time. If your BST is balanced then the insert function would have only taken O(*n* log *n*) time.